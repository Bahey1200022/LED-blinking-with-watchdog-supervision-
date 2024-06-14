#include "WDGDRV.h"

#pragma config FOSC = HS    // Oscillator Selection bits (HS oscillator)


static volatile int isr=0;
static volatile int notifications=0;
void WDGDrv_Init(void){
    

    #pragma config WDTPS = 128 // Configure for approximately 32ms timeout with 4MHz oscillator

    // Enable the Watchdog Timer
    WDTCONbits.SWDTEN = 1;

    
}



void WDGDrv_IsrNotification(void){
    
//    The WDGDrv_IsrNotification shall check the following conditions. If both of them are satisfied, it
//shall refresh the watchdog timer otherwise it will leave it to reset. The conditions are:
//1. WDGM_MainFunction is not stuck.
//2. The WDGM State set by the WDGM_MainFunction is OK.
    isr++;
    
    
    if (WDGM_PovideSuppervisionStatus()== OK && (Calls == isr) ){
        //REFRESH

        CLRWDT(); // Clear Watchdog Timer


    }
    else{
               
        
        //reset
    }
    
    
    
}