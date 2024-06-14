/* 
 * File:   WDGM.h
 * Author: moham
 *
 * Created on June 13, 2024, 4:38 PM
 */

#ifndef WDGM_H
#define	WDGM_H

typedef enum {OK = 0, NOK = 1}WDGM_StatusType;
void WDGM_Init(void);
void WDGM_MainFunction(void);
WDGM_StatusType WDGM_PovideSuppervisionStatus(void);
void  WDGM_AlivenessIndication(void);

#endif	/* WDGM_H */

