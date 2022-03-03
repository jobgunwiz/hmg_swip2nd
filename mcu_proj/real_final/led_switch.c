/*
 * led_switch.c
 *
 *  Created on: 2022. 2. 25.
 *      Author: user
 */
#include "settings.h"

//////////////////// RGB LED ////////////////////
void init_RGBLED(void)
{
    /* Reset IOCR0 bits */
    PORT02_IOCR4 &= ~((0x1F) << PC7);
    PORT10_IOCR4 &= ~((0x1F) << PC5);
    PORT10_IOCR0 &= ~((0x1F) << PC3);

    /* Set PC bits in IOCR0 with push-pull(2b10000) */
    PORT02_IOCR4 |= ((0x10) << PC7);
    PORT10_IOCR4 |= ((0x10) << PC5);
    PORT10_IOCR0 |= ((0x10) << PC3);
}

void red_RGBLED(void){
    PORT02_OMR |= (1<<PS7);            // Set LED RED
    PORT10_OMR |= (1<<PCL5);           // Clear LED GREEN
    PORT10_OMR |= (1<<PCL3);           // Clear LED BLUE
}

void blue_RGBLED(void){
    PORT02_OMR |= (1<<PCL7);            // Clear LED RED
    PORT10_OMR |= (1<<PCL5);            // Clear LED GREEN
    PORT10_OMR |= (1<<PS3);             // Set LED BLUE
}

void green_RGBLED(void){
    PORT02_OMR |= (1<<PCL7);            // Clear LED RED
    PORT10_OMR |= (1<<PS5);             // Set LED GREEN
    PORT10_OMR |= (1<<PCL3);            // Clear LED BLUE
}

/* Initialize Switch2 */
void init_Switch(void)
{
    /* Reset PC1 in IOCR0*/
    PORT02_IOCR0 &= ~((0x1F) << PC1);
    PORT02_IOCR0 &= ~((0x1F) << PC0);

    /* Set PC1 with push-pull(2b0xx10) */
    PORT02_IOCR0 |= ((0x2) << PC1);
    PORT02_IOCR0 |= ((0x2) << PC0);
}

//////////////////// LED ////////////////////
void init_LED(void)
{
    /* Reset PC1 & PC2 in IOCR0*/
    PORT10_IOCR0 &= ~((0x1F) << PC1);
    PORT10_IOCR0 &= ~((0x1F) << PC2);

    /* Set PC1 & PC2 with push-pull(2b10000) */
    PORT10_IOCR0 |= ((0x10) << PC1);
    PORT10_IOCR0 |= ((0x10) << PC2);

    PORT10_OMR |= ((1<<PCL1));          //LED RED
    PORT10_OMR |= ((1<<PCL2));          //LED BLUE
}

void reset_LED(void){
    PORT10_OMR |= (1<<PCL1);            // Clear LED RED
    PORT10_OMR |= (1<<PCL2);            // Clear LED GREEN
}

void init_LED_d(void){
    /* Reset PC1 & PC2 in IOCR0*/
    PORT10_IOCR0 &= ~((0x1F) << PC1);
    PORT10_IOCR0 &= ~((0x1F) << PC2);

    /* Set PC1 & PC2 with push-pull(2b10000) */
    PORT10_IOCR0 |= ((0x11) << PC1);
    PORT10_IOCR0 |= ((0x11) << PC2);
}
