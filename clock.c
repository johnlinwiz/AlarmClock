#include "clock.h"

DateTime_t dateTime;
//rtcc_read = i2c_read
//rtcc_write = i2c_write
static void i2c_write(uint8_t addr, uint8_t data) {
    i2c_write1ByteRegister(RTCC_ADDR, addr, data);
    __delay_ms(5);
}

static uint8_t i2c_read(uint8_t addr) {
    return i2c_read1ByteRegister(RTCC_ADDR, addr);
}

static void setComponent(uint8_t location, uint8_t mask, uint8_t time){
    uint8_t inMemory = i2c_read(location) & mask;
    i2c_write(location, inMemory | (time % 10) | ((time / 10) << 4)); 
}

static uint8_t clock_read(uint8_t location, uint8_t mask){
    uint8_t working = i2c_read(location) & mask;
    return (working & 0x0F) + (((working & (mask & 0xF0)) >> 4) * 10);    
}

void clock_Initialize(){
    uint8_t reg = 0;

    dateTime.day = (i2c_read(RTCC_DAY) & 0x07);
    clock_write(RTCC_DAY, (dateTime.day | 0x08));
    dateTime.sec = i2c_read(RTCC_SECONDS);

    //Configure Control Register - SQWE=1, ALM0 = 00 {No Alarms Activated},
    //                             RS2, RS1, RS0 = 000 {1 HZ}
    clock_write(CONTROL_REG, ALM_NO + SQWE + MFP_01H);

    // Start the external crystal and check OSCON to know when it is running
    clock_write(RTCC_SECONDS, dateTime.sec | ST_SET);
    while (!reg) {
        reg = i2c_read(RTCC_DAY);
        reg &= OSCON;
    }

    // Configure external battery enable BIT and clear the VBAT flag
    clock_write(RTCC_DAY, dateTime.day | (VBATEN & VBAT_CLR));    
}

void clock_SetHour(int hour){    
    setComponent(RTCC_HOUR, 0x00, hour);
}

void clock_SetMinute(int minute){
    setComponent(RTCC_MINUTES, 0x00, minute);
}

time_t clock_GetTime(void){
    struct tm tm_t;
    memset(&tm_t, 0, sizeof (tm_t));
    
    tm_t.tm_year = clock_read(RTCC_YEAR, 0xFF) + 100; // Result only has two digits, this assumes 20xx
    tm_t.tm_mon = clock_read(RTCC_MONTH, 0x1F) - 1; // time.h expects January as zero, clock gives 1
    tm_t.tm_mday = clock_read(RTCC_DATE, 0x3F);
    tm_t.tm_hour = clock_read(RTCC_HOUR, 0x3F);
    tm_t.tm_min = clock_read(RTCC_MINUTES, 0x7F);
    tm_t.tm_sec = clock_read(RTCC_SECONDS, 0x7F);

    return mktime(&tm_t);
}