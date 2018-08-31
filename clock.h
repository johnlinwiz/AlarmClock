/* 
 * File:   clock.h
 * Author: Sean Wernimont
 *
 * Created on August 29, 2018, 8:45 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"

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

typedef struct {
    int sec, min, hr;
    int year, month, date, day;
} DateTime_t;

void clock_Initialize();
void clock_SetHour(int hour);
time_t clock_GetTime(void);
void clock_SetMinute(int minute);

#endif