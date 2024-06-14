#include "WDGDRV.h"

#pragma config FOSC = HS    // Oscillator Selection bits (HS oscillator)

#pragma config WDTPS = 32768 // Watchdog Timer Postscaler Select bits (1:32768) for ~65.5ms timeout
static volatile int isr=0;
static volatile int notifications=0;
void WDGDrv_Init(void){
    


    // Set up the Watchdog Timer Prescaler to achieve approximately 50ms timeout
    // WDT Timeout Period = (Prescaler * 4) / Fosc
    // Assuming Fosc = 4MHz (since we didn't set it specifically in this example)
    // For 50ms timeout, the prescaler should be:
    // 50ms = (Prescaler * 4) / 4MHz
    // Prescaler = 50ms * 4MHz / 4 = 50 * 1000 / 4 = 12500
    // With the WDT prescaler options, the closest value is 1:128, which gives:
    // 128 * 4 / 4MHz = 32ms (closer to 50ms isn't possible, so we'll use 32ms)

    // Enable the Watchdog Timer
    WDTCONbits.SWDTEN = 1;
    TRISDbits.TRISD4 = 0; // Configure RD5 as an output

    
}



void WDGDrv_IsrNotification(void){
    
//    The WDGDrv_IsrNotification shall check the following conditions. If both of them are satisfied, it
//shall refresh the watchdog timer otherwise it will leave it to reset. The conditions are:
//1. WDGM_MainFunction is not stuck.
//2. The WDGM State set by the WDGM_MainFunction is OK.
    isr++;
    
    
    if (WDGM_PovideSuppervisionStatus()== OK && (Calls == isr) ){
        //REFRESH
        LATDbits.LATD4 = 0;

        CLRWDT(); // Clear Watchdog Timer


    }
    else{
        
        LATDbits.LATD4 = 1;
        

        
        
        //reset
    }
    
    
    
}