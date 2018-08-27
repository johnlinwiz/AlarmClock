#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/RTC6.h"
#include "oled.h"

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    OLED_Initialize();
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    char welcomeMsg[] = "Alarm Clock";    
    OLED_Clear();
    Write_String(welcomeMsg);
    __delay_ms(1000);
    volatile time_t getTime, setTime;

    struct tm *tm_t;

    char buffer[80];

    memset(tm_t, 0, sizeof (tm_t));

    /*** Variable Initializations ***/
    setTime = 1503870020; //Time in Seconds
    getTime = 0; //Time in Seconds       
    OLED_Clear();
    while (1) {
        /** Example to Set Time to RTCC */
        rtc6_SetTime(setTime);
        __delay_ms(20);
        char timeStr[];
        while (1) {
            /** Example to Get Time from RTCC */
            getTime = rtc6_GetTime();
            tm_t = localtime(&getTime);
            sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d\n", tm_t->tm_year+1900, tm_t->tm_mon+1, tm_t->tm_mday, tm_t->tm_hour, tm_t->tm_min, tm_t->tm_sec);
            Write_String(timeStr);
            __delay_ms(1000);
        }
    }
}