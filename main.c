#include "mcc_generated_files/mcc.h"
#include "oled.h"
#include "RTC6.h"

void pollClock();
void clock_Interrupt();
void ConfigureInterrupts();
void setAlarms();

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    OLED_Initialize();
    rtc6_Initialize();
    ConfigureInterrupts();
    LED_Day_LAT = LOW;
    LED_Night_LAT = LOW;
    rtc6_SetTime2(2018, 9, 6, 9, 10);
    setAlarms();
    OLED_Clear();
    while(1){
        pollClock();
        clock_Interrupt();
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

void setAlarms(){
    struct tm alarm0;
    alarm0.tm_hour = 9;
    alarm0.tm_min = 11;
    struct tm alarm1;
    alarm1.tm_hour = 9;
    alarm1.tm_min = 12;
    
    rtc6_EnableAlarms(true, true);
    rtc6_SetAlarm0(alarm0);
    rtc6_SetAlarm1(alarm1);
}

void clock_Interrupt(){
    /*
     * read the clock register 0x0D bit 3 to see if alarm 0 was triggered
     * read the clock register 0x14 bit 3 to see if alarm 1 was triggered
     * if alarm 0 was triggered start day and stop night
     * if alarm 1 was triggered start night and stop day
     */
    int alarm0 = rtcc_read(ALARM0_DAY);
    int alarm1 = rtcc_read(ALARM1_DAY);
    
    bool alarm0Triggered = alarm0 & (1 << 3);
    bool alarm1Triggered = alarm1 & (1 << 3);
    
    if(alarm0Triggered){
        LED_Day_LAT = HIGH;
        LED_Night_LAT = LOW;
        rtc6_ClearAlarmInterruptFlag(ALARM0_DAY);
    }else if (alarm1Triggered){
        LED_Day_LAT = LOW;
        LED_Night_LAT = HIGH;
        rtc6_ClearAlarmInterruptFlag(ALARM1_DAY);
    }
}

void ConfigureInterrupts(){
    INTCONbits.PEIE = 1; //enabling global interrupts
    INTCONbits.GIE = 1; //enabling peripheral interrupts
    IOCBP0 = 1;//setting the Interrupt On Change Positive Edge Register
    IOCBF0 = 0;//clearing the interrupt flag for RBO
}

void interrupt INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(PIE0bits.IOCIE == 1 && PIR0bits.IOCIF == 1)
    {
        PIN_MANAGER_IOC();
    }
    else if(INTCONbits.PEIE == 1)
    {
        if(PIE3bits.BCL1IE == 1 && PIR3bits.BCL1IF == 1)
        {
            i2c1_driver_busCollisionISR();
        } 
        else if(PIE3bits.SSP1IE == 1 && PIR3bits.SSP1IF == 1)
        {
            i2c1_driver_i2cISR();
        } 
        else
        {
            //Unhandled Interrupt
        }
    }
    else if (IOCBF0 == 1){
        clock_Interrupt();
        IOCBF0 = 0;
    }
    else
    {
        //Unhandled Interrupt
    }
}