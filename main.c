#include "mcc_generated_files/mcc.h"
#include "oled.h"
#include "clock.h"
//#include "mcc_generated_files/RTC6.h"

void SetupClock();

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    OLED_Initialize();
    SetupClock();
    
    INTERRUPT_GlobalInterruptEnable();

    INTERRUPT_PeripheralInterruptEnable();
    
    volatile time_t getTime;
    struct tm *tm_t;
    memset(tm_t, 0, sizeof (tm_t));
    getTime = 0; //Time in Seconds   
    char timeStr[];
    OLED_Clear();
    while(1){
        getTime = clock_GetTime();
        tm_t = localtime(&getTime);
        sprintf(timeStr, "%02d:%02d:%02d\n", tm_t->tm_hour, tm_t->tm_min, tm_t->tm_sec);
        Write_String(timeStr);
        __delay_ms(100);
    }
}

void SetupClock(){
    //clock_SetTime(1999, 8, 30, 9, 56);
    //clock_SetHour(10);
    //clock_SetMinute(13);
    __delay_ms(1000);
}