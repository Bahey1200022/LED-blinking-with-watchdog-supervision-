/* 
 * File:   WDGDRV.h
 * Author: moham
 *
 * Created on June 13, 2024, 4:37 PM
 */

#ifndef WDGDRV_H
#define	WDGDRV_H
#include <xc.h> // Include processor files - each processor file is guarded.
#define _XTAL_FREQ 8000000  // Define the clock frequency for delay functions

#include "WDGM.h"

void WDGDrv_Init(void);
void WDGDrv_IsrNotification(void);

#endif	/* WDGDRV_H */

