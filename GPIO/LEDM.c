#include "LEDM.h"

static volatile int ledstate=0;
static volatile int ledCounter=0;
void LEDM_Init(void){
    GPIO_Init();
    
}


void LEDM_Manage(void){
    ledCounter=ledCounter+10;
    ///super loop has 10 ms delay 
    if (ledCounter>500){
        ledstate=!ledstate;
        GPIO_Write(5,ledstate);
        ledCounter=0;
    }
  
   WDGM_AlivenessIndication();

    
}