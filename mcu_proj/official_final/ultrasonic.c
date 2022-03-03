/*
 * ultrasonic.c
 *
 *  Created on: 2022. 3. 2.
 *      Author: soo
 */
#include "settings.h"

void init_ultrasonic(void)
{
    /* Init TRIG Pin - P15.4 (Output) */
    PORT15_IOCR4 &= ~((0x1F) << PC4);
    PORT15_IOCR4 |= ((0x10) << PC4);

    /* Init ECHO Pin - P15.5 (Input) */
    PORT15_IOCR4 &= ~((0x1F) << PC5);
}

void init_ERU(void)
{
    /* ERU Input Channel 4 Setting */
    /* Password Access to unlock WDTSCON0 */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    // Modify Access to clear ENDINIT bit
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    SCU_EICR2 &= ~((0x7) << EXIS0);             // External input 3 is selected
    SCU_EICR2 |= ((0x3) << EXIS0);

    SCU_EICR2 |= (1 << REN0);                   // Rising edge enable
    SCU_EICR2 |= (1 << FEN0);                   // Falling edge enable

    SCU_EICR2 |= (1 << EIEN0);                  // The trigger event is enabled

    SCU_EICR2 &= ~((0x7) << INP0);              // An event from input ETL 4 triggers output OGU 0

    SCU_IGCR0 &= ~((0x3) << IGP0);              // IOUT(0) is activated in response to a trigger event
    SCU_IGCR0 |= (1 << IGP0);                   // The pattern is not considered

    /* Password Access to unlock WDTSCON0 */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    /* Modify Access to set ENDINIT bit */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    /* SRC Interrupt Setting For ECU */
    SRC_SCUERU0 &= ~((0xFF) << SRPN);           // Set Priority : 0x0B
    SRC_SCUERU0 |= ((0x0B) << SRPN);

    SRC_SCUERU0 &= ~((0x3) << TOS);             // CPU0 services

    SRC_SCUERU0 |= (1 << SRE);                  // Service Request is enabled
}
