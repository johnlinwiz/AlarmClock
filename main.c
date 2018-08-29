#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/RTC6.h"
#include "oled.h"

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
    char timeStr[];
    while (1) {
        getTime = rtc6_GetTime();
        tm_t = localtime(&getTime);
        sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d\n", tm_t->tm_year+1900, tm_t->tm_mon+1, tm_t->tm_mday, tm_t->tm_hour, tm_t->tm_min, tm_t->tm_sec);
        Write_String(timeStr);
    }
}

void SetupClock(){
    volatile time_t setTime;
    struct tm initialTime;
    initialTime.tm_hour = 22;
    initialTime.tm_min = 53;
    initialTime.tm_sec = 0;
    initialTime.tm_year = 99;
    initialTime.tm_mon = 8;
    initialTime.tm_mday = 28;
    
    rtc6_SetTime(setTime);
    __delay_ms(20); 
}