# 1 "GPIO/WDGM.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "GPIO/WDGM.c" 2
# 1 "GPIO/WDGM.h" 1
# 11 "GPIO/WDGM.h"
typedef enum {OK = 0, NOK = 1}WDGM_StatusType;
void WDGM_Init(void);
void WDGM_MainFunction(void);
WDGM_StatusType WDGM_PovideSuppervisionStatus(void);
void WDGM_AlivenessIndication(void);
# 1 "GPIO/WDGM.c" 2


static volatile int mainFuncCalls = 0;
static volatile int lastCheckTime = 0;
WDGM_StatusType wdgmStatus = OK;
static volatile int wgdmMainFuncTurn = 0;

void WDGM_Init(void) {

    mainFuncCalls = 0;
    lastCheckTime = 0;
    wdgmStatus = OK;
}

void WDGM_MainFunction(void) {




    if (wgdmMainFuncTurn == 2) {
        if (lastCheckTime == 10) {
            if (mainFuncCalls >= 8 && mainFuncCalls <= 12) {
                wdgmStatus = OK;
            } else {
                wdgmStatus = NOK;
            }
            mainFuncCalls = 0;
            lastCheckTime = 0;
        } else {
            lastCheckTime++;
        }
        wgdmMainFuncTurn = 0;
    } else {
        wgdmMainFuncTurn++;
    }
}

WDGM_StatusType WDGM_PovideSuppervisionStatus(void) {

    return wdgmStatus;
}

void WDGM_AlivenessIndication(void) {


    mainFuncCalls++;
}
