/*
 * main.c
 *
 *  Created on: 2022. 2. 25.
 *      Author: user
 */

#include <stdio.h>
#include "settings.h"

#define BUZ_GRAD   140800 //64(10^5-10^3)/50

#define DIST_FAR        80
#define DIST_MIDDLE     50
#define DIST_CLOSE      10
#define DIST_CLOSEST    6

#define FARTHEST 0
#define FAR      1
#define CLOSE    2
#define CLOSEST  3
#define WARNING  4

unsigned int R_STATE;

void init_LED(void);    // LED
void init_Switch(void);
////////// gear ADC //////////
void init_VADC(void);
void VADC_startConversion(void);
unsigned int VADC_readResult(void);

void init_RGBLED(void);
void red_RGBLED(void);
void blue_RGBLED(void);
void green_RGBLED(void);

////////// gear P buzzer //////////
void init_BUZZER(void);
void init_GTM_TOM0_PWM(void);

////////// Timer //////////
void init_CCU60_T12(void);
void init_CCU60_T13(void);

void init_ultrasonic(void);
void init_ERU(void);

////////// gear R buzzer //////////
unsigned int timer_cnt;
unsigned int start_time;
unsigned int end_time;
unsigned int interval_time;
unsigned int distance = 100;
unsigned int sonic_dist;
unsigned int duty_ratio;
unsigned int buz_delay;
volatile unsigned int freq[17] = { 9480, 10044, 9480, 10044, 9480, 12655,
                          10641, 11945, 14205,
                          23889, 18691, 14205, 12655,
                          18961, 15049, 12655, 11945};

////////// ultra sonic //////////
void init_ultrasonic(void);
void init_ERU(void);

////////// gear d //////////
volatile int adcResult;
volatile int d_freq_red;
volatile int d_freq_blue;
volatile int cycle = 0;
volatile int d_cnt;
volatile static int blue_switch = 0;
volatile static int red_switch = 0;

void init_LED_d(void);
void init_GTM_TOM0_PWM_d(void);

void init_VADC_photo(void);
void VADC_startConversion_photo(void);
unsigned int VADC_readResult_photo(void);

// function
void reset_LED(void);
void reset_BUZZER(void);

// variable
extern unsigned int gear_mode;
extern unsigned int prev_mode;
static int p_switch_cnt;

void init(){

    init_LED();         // LED
    init_RGBLED();
    init_BUZZER();
    init_Switch();

    // gear ADC
    init_VADC();
    init_GTM_TOM0_PWM();

    prev_mode = 100;

    printf("[Mode Safety Assistant] START\n");
}

void mode_set(){

    unsigned int adcResult;

    VADC_startConversion();
    adcResult = VADC_readResult();

    if (adcResult > 2800) {
        gear_mode = 2;  // Driving mode(2)
        green_RGBLED();
    }
    else if (adcResult > 1400) {
        gear_mode = 1;  // Rear mode(1)
        red_RGBLED();
    }
    else {
        gear_mode = 0;  // Parking mode(0)
        blue_RGBLED();
    }
}

void sensor_reset(){
    reset_LED();
    reset_BUZZER();
    init_LED();
    init_GTM_TOM0_PWM();
}

void init_P(){
    sensor_reset();
    init_CCU60_T12();
}

void init_R(){
    sensor_reset();
    init_ultrasonic();
    init_ERU();
    init_CCU60_T13();
}

void init_D(){
    sensor_reset();
    init_LED_d();
    init_CCU60_T12();
    init_GTM_TOM0_PWM_d();

    init_VADC_photo();
}


void buzzer_P(void){

   int i, j;
   buz_delay = BUZ_GRAD*(distance-5)+64000;

   if((R_STATE == FARTHEST) || (R_STATE == FAR)){

       for(int delay = 0; delay<12800000; delay++); // waiting

       for(i = 0; i < 17; i++){                // 엘리제를 위하여

            mode_set();
            GTM_TOM0_CH11_SR0 = freq[i] - 1;
            GTM_TOM0_CH11_SR1 = 6250-1;
            PORT10_OMR |= (1<<PS2);             // LED BLUE ON

            if((R_STATE == CLOSE) || (R_STATE == CLOSEST)||(gear_mode == 0)||(gear_mode==2)){
                break;
            }
            for(j = 0; j < 10000000; j++){}

            if((i == 8) || (i == 12)||(i == 16))
                for(j = 0; j < 40000000; j++){}
        }
   }
   else if((R_STATE == CLOSE) || (R_STATE == CLOSEST)){
        GTM_TOM0_CH11_SR0 = 8000 - 1;
        GTM_TOM0_CH11_SR1 = 6250-1;
        PORT10_OMR |= (1<<PCL2);                // LED BLUE OFF
        PORT10_OMR |= (1<<PS1);                 // LED RED ON
        for(int l = 0; l < buz_delay; l++){}    // BUZZER/LED ON

        for(int k = 0; k < buz_delay; k++){     // BUZZER/LED OFF
            GTM_TOM0_CH11_SR1 = 0;
            PORT10_OMR |= (1<<PCL1);
        }
  }
  else{
        GTM_TOM0_CH11_SR0 = 8000 - 1;           //WARNING!!!!!!!!!!!!!!!!!!!
        GTM_TOM0_CH11_SR1 = 6250-1;
        PORT10_OMR |= (1<<PS1);
  }
}

void photo_D(){
    unsigned int photoResult;
    VADC_startConversion_photo();
    photoResult = VADC_readResult_photo();

    if(photoResult >= 3800)
    {
        d_freq_red = 0;
        d_freq_blue = 0;
    }
    else if(photoResult >= 3200)
    {
        d_freq_red = 1500;
        d_freq_blue = 1500;
    }
    else if(photoResult >= 2300)
    {
        d_freq_red = 5000;
        d_freq_blue = 5000;
    }
    else
    {
        d_freq_red = 40000;
        d_freq_blue = 40000;
    }
}

void ultra_R(){
    if((PORT15_IN & (1<<P5)) == 0)              // Falling edge
    {
        /* Get distance */
        end_time = (timer_cnt * 500) + CCU60_T13;

        interval_time = end_time - start_time;  // clock per 0.02us

        distance = (interval_time * 20) / 58000; // unit: cm

       if(distance >= 500){
          distance = 5;
       }
       else if(distance >= 100){
          distance = 100;
       }
       else if(distance <= 5){
          distance = 5;
       }

      if(distance > DIST_FAR ) R_STATE = FARTHEST;
      else if((distance <= DIST_FAR)&&(distance > DIST_MIDDLE)) R_STATE = FAR;
      else if((distance <= DIST_MIDDLE)&&(distance > DIST_CLOSE)) R_STATE = CLOSE;
      else if((distance <= DIST_CLOSE)&&(distance >= DIST_CLOSEST)) R_STATE = CLOSEST;
      else R_STATE = WARNING;

    }

    else                                        // Rising edge
    {
        start_time = (timer_cnt * 500) + CCU60_T13;
    }
}

void timer_P (){

    if( (PORT02_IN & (1<<P1) ) == 0){ // pressed
        PORT10_OMR |= ((1<<PCL2));
        PORT10_OMR |= ((1<<PCL1) | (1<<PS1));
        p_switch_cnt++;

        if(p_switch_cnt >= 6 && (p_switch_cnt % 2) == 0){
            GTM_TOM0_CH11_SR0 = 12500 - 1;  // PWM freq. = 6250 kHz / 12500 = 500 Hz
            GTM_TOM0_CH11_SR1 = 6250 - 1;
            PORT10_OMR |= (1<<PS1);
            for(int i; i < 10000000; i++);
            PORT10_OMR |= (1<<PCL1);

        } else if(p_switch_cnt >= 6){
            GTM_TOM0_CH11_SR0 = 12500-1;    // PWM freq. = 6250 kHz / 12500 = 500 Hz
            GTM_TOM0_CH11_SR1 = 11329;
            PORT10_OMR |= (1<<PS1);
            for(int i; i < 10000000; i++);
            PORT10_OMR |= (1<<PCL1);
        }
    } else{
        PORT10_OMR |= (1<<PCL1);
        PORT10_OMR |= (1<<PS2);
        p_switch_cnt = 0;

        GTM_TOM0_CH11_SR0 = 0;              // PWM freq. = 6250 kHz / 12500 = 500 Hz
        GTM_TOM0_CH11_SR1 = 0;
    }
}

void timer_R (){
    timer_cnt++;

    if(timer_cnt == 1)
    {
        /* Set TRIG Pin */
        PORT15_OMR |= (1<<PS4);
    }
    else if(timer_cnt == 2)
    {
        /* Clear TRIG Pin */
        /* Generate 10us Pulse */
        PORT15_OMR |= (1<<PCL4);
    }
    else if(timer_cnt == 10000)
    {
        /* TRIG Period: 100ms */
        timer_cnt = 0;
    }
}

void timer_D(){



    if( (PORT02_IN & (1<<P1) ) == 0){   // BUT RED press



            if(red_switch == 0){
                red_switch = 1;
                blue_switch = 0;

            }
            else{
                red_switch = 0;

            }

    }
    else if((PORT02_IN & (1<<P0)) == 0){//BUT BLUE PRESS

            if(blue_switch == 0){
                blue_switch = 1;
                red_switch = 0;
            }
            else{
                blue_switch = 0;
            }

    }

    if(red_switch){   //press
        //d_freq_blue = 40000;

        if(d_cnt == 1)
        {
            d_freq_red = 40000;
            d_cnt = 0;
        }
        else
        {
            d_freq_red = 0;
            d_cnt = 1;
        }

    }
    else if(blue_switch){    //BUT BLUE PRESS
        //d_freq_red = 40000;

        if(d_cnt == 1)
        {
            d_freq_blue = 40000;
            d_cnt = 0;
        }
        else
        {
            d_freq_blue = 0;
            d_cnt = 1;
        }
    }
    else{
        d_cnt = 0;
        //d_freq_red = 40000;
        //d_freq_blue = 40000;
//        GTM_TOM0_CH11_SR0 = 0;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
//        GTM_TOM0_CH11_SR1 = 0;
    }
    GTM_TOM0_CH1_SR1 = d_freq_red;
    GTM_TOM0_CH2_SR1 = d_freq_blue;
}

void exit(){
    sensor_reset();
    printf("[Mode Safety Assistant] EXIT\n");
}
