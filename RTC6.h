 /*
     (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
  * 
  * @ModifiedBy
  * Sean Wernimont (@swernimo)
 */

#ifndef RTC6_H
#define	RTC6_H

#include <time.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int sec, min, hr;
    int year, month, date, day;
} DateTime_t;

#define EEADDR 0x64
#define RTCC_ADDR 0x6F //0x57


/*********************** RTCC Register Addresses ***************************/

#define RTCC_SECONDS                0x00
#define RTCC_MINUTES                0x01
#define RTCC_HOUR                   0x02
#define RTCC_DAY                    0x03
#define RTCC_DATE                   0x04
#define RTCC_MONTH                  0x05
#define RTCC_YEAR                   0x06

#define CONTROL_REG                 0x07
#define CALIBRATION                 0x08

#define ALARM0_SECONDS              0x0A
#define ALARM0_MINUTES              0x0B
#define ALARM0_HOUR                 0x0C
#define ALARM0_DAY                  0x0D
#define ALARM0_DATE                 0x0E
#define ALARM0_MONTH                0x0F

#define ALARM1_SECONDS              0x11
#define ALARM1_MINUTES              0x12
#define ALARM1_HOUR                 0x13
#define ALARM1_DAY                  0x14
#define ALARM1_DATE                 0x15
#define ALARM1_MONTH                0x16

#define PWR_DOWN_MINUTES            0x18
#define PWR_DOWN_HOUR               0x19
#define PWR_DOWN_DATE               0x1A
#define PWR_DOWN_MONTH              0x1B

#define PWR_UP_MINUTES              0x1C
#define PWR_UP_HOUR                 0x1D
#define PWR_UP_DATE                 0x1E
#define PWR_UP_MONTH                0x1F

#define MAC_ADDR_48                 0x02
#define MAC_ADDR_64                 0x00


/******************************************************************************/

#define  SQWE                       0x40            //  Square Wave Enable BIT
#define  ALM_NO                     0x00            //  no alarm activated
#define  MFP_01H                    0x00            //  MFP = SQWAV(01 HERZ)
#define  OSCON                      0x20            //  state of the oscillator(running or not)
#define  VBATEN                     0x08            //  enable battery for back-up
#define  VBAT_CLR                   0xEF            //  Mask to clear VBAT flag BIT
#define  EXTOSC                     0x08            //  enable external 32khz signal
#define  ST_SET                     0x80            //  start oscillator

#define EEPROM_LOCK 0x0C
#define EEPROM_UNLOCK 0x00

#define EEPR_PAGE_SIZE               8

/******************************************************************************/

void rtc6_Initialize(void);

void rtc6_EnableAlarms(bool alarm0, bool alarm1);
void rtc6_SetAlarm0(struct tm tm_t);
void rtc6_SetAlarm1(struct tm tm_t);

void rtc6_ClearAlarm0(void);
void rtc6_ClearAlarm1(void);

void rtc6_SetTime(time_t);
void rtc6_SetTime2(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min);
time_t rtc6_GetTime(void);

uint8_t rtc6_ReadByteEEPROM(uint8_t addr);
void rtc6_WriteByteEEPROM(uint8_t addr, uint8_t data);
uint8_t rtcc_read(uint8_t addr);

#endif
