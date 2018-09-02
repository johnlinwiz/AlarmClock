#include "mcc_generated_files/mcc.h"
#include "oled.h"
#include "RTC6.h"

void SetupClock();
void rtc_Example();

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    OLED_Initialize();
    rtc6_Initialize();
    SetupClock();
    
    INTERRUPT_GlobalInterruptEnable();

    INTERRUPT_PeripheralInterruptEnable();
    
    OLED_Clear();
    rtc_Example();
}
void rtc_Example(){
    volatile time_t getTime, setTime;

    struct tm *tm_t;


    memset(tm_t, 0, sizeof (tm_t));

    /*** Variable Initializations ***/
    setTime = 1503870020; //Time in Seconds
    getTime = 0; //Time in Seconds   
    char timeStr[];
    while (1) {
        getTime = rtc6_GetTime();
        tm_t = localtime(&getTime);
        sprintf(timeStr, "%02d:%02d:%02d\n", tm_t->tm_hour, tm_t->tm_min, tm_t->tm_sec);
        Write_String(timeStr);
        __delay_ms(10);
    }
}

void SetupClock(){
  //  rtc6_SetTime2(1999, 8, 30, 10, 2);
    __delay_ms(20);
}