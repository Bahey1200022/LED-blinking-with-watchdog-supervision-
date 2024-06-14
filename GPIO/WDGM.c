#include "WDGM.h"

static volatile int mainFuncCalls = 0;
static volatile int lastCheckTime = 0; // To count for each 100ms, main loop = 10ms
WDGM_StatusType wdgmStatus = OK;
static volatile int wgdmMainFuncTurn = 0; // For each 20ms, main loop = 10ms

void WDGM_Init(void) {
    // The WDGM_Init shall initialize the WDGM_Internal variables.
    mainFuncCalls = 0;
    lastCheckTime = 0;
    wdgmStatus = OK;
}

void WDGM_MainFunction(void) {
    // The WDGM_MainFunction shall check the number of calls of the LEDM_MainFunction within a
    // 100ms period. If the number of calls is between 8 and 12 then the status is OK. otherwise, the
    // status is not OK. The WDGM_MainFunction shall be called periodically every 20ms.

    if (wgdmMainFuncTurn == 2) { // 2 * 10ms = 20ms
        if (lastCheckTime == 10) { // 10 * 10ms = 100ms
            if (mainFuncCalls >= 8 && mainFuncCalls <= 12) {
                wdgmStatus = OK;
            } else {
                wdgmStatus = NOK;
            }
            mainFuncCalls = 0; // Reset for next 100ms period
            lastCheckTime = 0; // Reset the time counter
        } else {
            lastCheckTime++;
        }
        wgdmMainFuncTurn = 0;
    } else {
        wgdmMainFuncTurn++;
    }
}

WDGM_StatusType WDGM_PovideSuppervisionStatus(void) {
    // The WDGM_ProvideSuppervisionStatus shall provide the Status of the LEDM entity to the WDGDrv.
    return wdgmStatus;
}

void WDGM_AlivenessIndication(void) {
    // The WDGM_AlivenessIndication
    // shall be called from the LEDM_Manage function to detect its call at the correct timing.
    mainFuncCalls++;
}
