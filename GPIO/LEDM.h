/* 
 * File:   LEDM.h
 * Author: moham
 *
 * Created on June 13, 2024, 4:31 PM
 */

#ifndef LEDM_H
#define	LEDM_H
#define _XTAL_FREQ 8000000  // Define the clock frequency for delay functions

#include "GPIO.h"
#include "WDGM.h"
#include "WDGDRV.h"


void LEDM_Init(void);
void LEDM_Manage(void);

#endif	/* LEDM_H */

