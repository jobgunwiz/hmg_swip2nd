/*
 * switch_int.c
 *
 *  Created on: 2022. 3. 3.
 *      Author: user
 */

/* Initialize External Request Unit (ERU) */

#include "settings.h"

void init_ERU2(void)
{
    /* ERU Input Channel 2 Setting */
    /* Password Access to unlock WDTSCON0 */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    // Modify Access to clear ENDINIT bit
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) & ~ (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    //Switch 1
    SCU_EICR1 &= ~((0x7) << EXIS0);             // External input 1 is selected
    SCU_EICR1 |= ((0x1) << EXIS0);
   // SCU_EICR1 |= (1 << FEN0);                 // Falling edge enable
    SCU_EICR1 |= (1 << REN0);
    SCU_EICR1 |= ((0x1) << EIEN0);              // The trigger event is enabled
    SCU_EICR1 &= ~((0x7) << INP0);              // An event from input ETL 2 triggers output OGU 1

    //Switch 2
    SCU_EICR1 &= ~((0x7) << EXIS1);             // External input 2 is selected
    SCU_EICR1 |= ((0x2) << EXIS1);
    //SCU_EICR1 |= (1 << FEN1);// Falling edge enable

    SCU_EICR1 |= (1 << REN1);
    SCU_EICR1 |= ((0x1) << EIEN1);              // The trigger event is enabled
    SCU_EICR1 &= ~((0x7) << INP1);              // An event from input ETL 2 triggers output OGU 1
    SCU_EICR1 |= ((0x1) << INP1);

    //LED 1
    SCU_IGCR0 &= ~((0x3) << IGP1);              // IOUT(0) is activated in response to a trigger event
    SCU_IGCR0 |= ((0x1) << IGP1);

    //LED 2
    SCU_IGCR0 &= ~((0x3) << IGP0);              // IOUT(0) is activated in response to a trigger event
    SCU_IGCR0 |= ((0x1) << IGP0);               // The pattern is not considered

    /* Password Access to unlock WDTSCON0 */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) & ~(1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) != 0);

    /* Modify Access to set ENDINIT bit */
    SCU_WDTSCON0 = ((SCU_WDTSCON0 ^ 0xFC) | (1 << LCK)) | (1 << ENDINIT);
    while((SCU_WDTSCON0 & (1 << LCK)) == 0);

    /* SRC Interrupt Setting For ECU */
    SRC_SCUERU0 &= ~((0xFF) << SRPN);           // Set Priority : 0x0A
    SRC_SCUERU0 |= ((0x0C) << SRPN);

    SRC_SCUERU0 &= ~((0x3) << TOS);             // CPU0 services

    SRC_SCUERU0 |= (1 << SRE);                  // Service Request is enabled

    /* SRC Interrupt Setting For ECU */
    SRC_SCUERU1 &= ~((0xFF) << SRPN);           // Set Priority : 0x0A
    SRC_SCUERU1 |= ((0x0D) << SRPN);

    SRC_SCUERU1 &= ~((0x3) << TOS);             // CPU0 services

    SRC_SCUERU1 |= (1 << SRE);                  // Service Request is enabled
}


