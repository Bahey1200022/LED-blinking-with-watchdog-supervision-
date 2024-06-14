#include "GPIO.h"

void GPIO_Init(void){
        TRISDbits.TRISD5 = 0; // Configure RD5 as an output
        LATDbits.LATD5 = 0;

}

void GPIO_Write(unsigned char PinId, unsigned char PinData){
    
   LATDbits.LATD5 = PinData;
    }