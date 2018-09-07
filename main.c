#include "mcc_generated_files/mcc.h"
#include "oled.h"
#include "RTC6.h"

void pollClock();
void clock_Interrupt();

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    OLED_Initialize();
    rtc6_Initialize();
    LED_Day_LAT = LOW;
    LED_Night_LAT = LOW;
    rtc6_SetTime2(2018, 9, 6, 9, 10);
    struct tm alarm0;
    alarm0.tm_hour = 9;
    alarm0.tm_min = 10;
    alarm0.tm_sec = 10;
    rtc6_EnableAlarms(true, false);
    rtc6_SetAlarm0(alarm0);
    
    INTERRUPT_GlobalInterruptEnable();

    INTERRUPT_PeripheralInterruptEnable();
    
    //INT_SetInterruptHandler(clock_Interrupt);
    
    OLED_Clear();
    while(1){
        pollClock();
    }
}

void pollClock(){
    volatile time_t getTime;
    struct tm *tm_t;
    memset(tm_t, 0, sizeof (tm_t));
    getTime = 0; //Time in Seconds   
    char timeStr[];
    getTime = rtc6_GetTime();
    tm_t = localtime(&getTime);
    sprintf(timeStr, "%02d:%02d:%02d\n", tm_t->tm_hour, tm_t->tm_min, tm_t->tm_sec);
    Write_String(timeStr);
    __delay_ms(10);
}

void clock_Interrupt(){
    /*
     * read the clock register 0x0D bit 3 to see if alarm 0 was triggered
     * read the clock register 0x14 bit 3 to see if alarm 1 was triggered
     * if alarm 0 was triggered start day and stop night
     * if alarm 1 was triggered start night and stop day
     */
    bool alarm0 = rtcc_read(ALARM0_DAY) >> 2;
    bool alarm1 = rtcc_read(ALARM1_DAY) >> 2;
    
    if(alarm0){
        LED_Day_LAT = HIGH;
        LED_Night_LAT = LOW;
        rtc6_ClearAlarmInterruptFlag(ALARM0_DAY);
    }else if (alarm1){
        LED_Day_LAT = LOW;
        LED_Night_LAT = HIGH;
        rtc6_ClearAlarmInterruptFlag(ALARM1_DAY);
    }
}