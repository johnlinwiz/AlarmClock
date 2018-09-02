#include "mcc_generated_files/mcc.h"
#include "oled.h"
#include "RTC6.h"

void pollClock();

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    OLED_Initialize();
    rtc6_Initialize();
    rtc6_EnableAlarms(true, true);
    //INTERRUPT_GlobalInterruptEnable();

    //INTERRUPT_PeripheralInterruptEnable();
    
    OLED_Clear();
    while(1){
        pollClock();
    }
}

void pollClock(){
    volatile time_t getTime, setTime;
    struct tm *tm_t;
    memset(tm_t, 0, sizeof (tm_t));
    setTime = 1503870020; //Time in Seconds
    getTime = 0; //Time in Seconds   
    char timeStr[];
    getTime = rtc6_GetTime();
    tm_t = localtime(&getTime);
    sprintf(timeStr, "%02d:%02d:%02d\n", tm_t->tm_hour, tm_t->tm_min, tm_t->tm_sec);
    Write_String(timeStr);
    __delay_ms(10);
}