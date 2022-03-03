/*
 * buzzer.c
 *
 *  Created on: 2022. 2. 25.
 *      Author: user
 */
#include "settings.h"
extern unsigned int d_freq_red;
extern unsigned int d_freq_blue;

void init_BUZZER(void)
{
    PORT02_IOCR0 &= ~((0x1F) << PC3);           // PORT2.3 : Alternate output function 1 (push-pull)
    PORT02_IOCR0 |= ((0x11) << PC3);
}

void init_GTM_TOM0_PWM(void)
{
    /* GTM Enable */
    // Password Access to unlock WDTCPU0CON0
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    // Modify Access to clear ENDINIT bit
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~(1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    GTM_CLC &= ~(1 << DISR);                        // Enable GTM Module

    // Password Access to unlock WDTCPU0CON0
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    // Modify Access to set ENDINIT bit
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((GTM_CLC & (1 << DISS)) != 0);            // Wait until module is enabled

    /* GTM Clock Setting */
    GTM_CMU_FXCLK_CTRL &= ~((0xF) << FXCLK_SEL);    // Input clock of CMU_FXCLK : CMU_GCLK_EN

    GTM_CMU_CLK_EN |= ((0x2) << EN_FXCLK);          // Enable all CMU_FXCLK

    /* GTM TOM0 PWM Setting */
    GTM_TOM0_TGC1_GLB_CTRL |= ((0x2) << UPEN_CTRL3);    // TOM0 channel 1 enable update of
                                                        // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC1_FUPD_CTRL |= ((0x2) << FUPD_CTRL3);   // Enable force update of TOM0 channel 1
    GTM_TOM0_TGC1_FUPD_CTRL |= ((0x2) << RSTCN0_CH3);   // Reset CN0 of TOM0 channel 1 on force update
    GTM_TOM0_TGC1_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL3); // Enable channel 1 on an update trigger
    GTM_TOM0_TGC1_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL3); // Enable channel 1 output on an update trigger
    GTM_TOM0_CH11_CTRL |= (1 << SL);                     // High signal level for duty cycle
    GTM_TOM0_CH11_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH11_CTRL |= (1 << CLK_SRC_SR);

    //GTM_TOM0_CH11_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    //GTM_TOM0_CH11_SR1 = 6250-1;                          // Duty cycle = 50

    GTM_TOUTSEL0 &= ~((0x3) << SEL3);
    GTM_TOM0_TGC1_GLB_CTRL |= (1 << HOST_TRIG);         // Trigger request signal to update
}

void reset_BUZZER(){
    GTM_TOM0_CH11_SR1 = 0;
}

void init_GTM_TOM0_PWM_d(){
    /* GTM Enable */
    // Password Access to unlock WDTCPU0CON0
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    // Modify Access to clear ENDINIT bit
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) & ~(1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    GTM_CLC &= ~(1 << DISR);                        // Enable GTM Module

    // Password Access to unlock WDTCPU0CON0
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) != 0);

    // Modify Access to set ENDINIT bit
    SCU_WDT_CPU0CON0 = ((SCU_WDT_CPU0CON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDT_CPU0CON0 & (1 << LCK)) == 0);

    while((GTM_CLC & (1 << DISS)) != 0);            // Wait until module is enabled

    /* GTM Clock Setting */
    GTM_CMU_FXCLK_CTRL &= ~((0xF) << FXCLK_SEL);    // Input clock of CMU_FXCLK : CMU_GCLK_EN
    GTM_CMU_CLK_EN |= ((0x2) << EN_FXCLK);          // Enable all CMU_FXCLK

    /* GTM TOM0 PWM Setting */
    GTM_TOM0_TGC0_GLB_CTRL |= ((0x2) << UPEN_CTRL1);    // TOM0 channel 1 enable update of
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << FUPD_CTRL1);   // Enable force update of TOM0 channel 1
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << RSTCN0_CH1);   // Reset CN0 of TOM0 channel 1 on force update
    GTM_TOM0_TGC0_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL1); // Enable channel 1 on an update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL1); // Enable channel 1 output on an update trigger
    GTM_TOM0_CH1_CTRL |= (1 << SL);                     // High signal level for duty cycle

    GTM_TOM0_TGC0_GLB_CTRL |= ((0x2) << UPEN_CTRL2);    // register CM0, CM1, CLK_SRC
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << FUPD_CTRL2);   // Enable force update of TOM0 channel 1
    GTM_TOM0_TGC0_FUPD_CTRL |= ((0x2) << RSTCN0_CH2);   // Reset CN0 of TOM0 channel 1 on force update
    GTM_TOM0_TGC0_ENDIS_CTRL |= ((0x2) << ENDIS_CTRL2); // Enable channel 1 on an update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL |= ((0x2) << OUTEN_CTRL2); // Enable channel 1 output on an update trigger
    GTM_TOM0_CH2_CTRL |= (1 << SL);                     // High signal level for duty cycle


    // RED LED
    GTM_TOM0_CH1_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH1_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH1_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH1_SR1 = d_freq_red;                               // Duty cycle = 0 / 12500 = 0
    //GTM_TOM0_CH1_SR1 = 6250-1;                          // Duty cycle = 50 / 12500 = 0
    //GTM_TOM0_CH1_SR1 = 12500 - 1;                       // Duty cycle = 100 / 12500 = 0


    // BLUE LED
    GTM_TOM0_CH2_CTRL &= ~((0x7) << CLK_SRC_SR);        // Clock source : CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH2_CTRL |= (1 << CLK_SRC_SR);
    GTM_TOM0_CH2_SR0 = 12500 - 1;                       // PWM freq. = 6250 kHz / 12500 = 500 Hz
    GTM_TOM0_CH2_SR1 = d_freq_blue;                               // Duty cycle = 0 / 12500 = 0
    //GTM_TOM0_CH1_SR1 = 6250-1;                          // Duty cycle = 50 / 12500 = 0
    //GTM_TOM0_CH1_SR1 = 12500 - 1;                       // Duty cycle = 100 / 12500 = 0

    GTM_TOUTSEL6 &= ~((0x3) << SEL7);                   // TOUT103 : TOM0 channel 1
    GTM_TOUTSEL6 &= ~((0x3) << SEL8);

    GTM_TOM0_TGC0_GLB_CTRL |= (1 << HOST_TRIG);         // Trigger request signal to update
}

