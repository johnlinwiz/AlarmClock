/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18875
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set OLED_CS aliases
#define OLED_CS_TRIS                 TRISAbits.TRISA3
#define OLED_CS_LAT                  LATAbits.LATA3
#define OLED_CS_PORT                 PORTAbits.RA3
#define OLED_CS_WPU                  WPUAbits.WPUA3
#define OLED_CS_OD                   ODCONAbits.ODCA3
#define OLED_CS_ANS                  ANSELAbits.ANSA3
#define OLED_CS_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define OLED_CS_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define OLED_CS_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define OLED_CS_GetValue()           PORTAbits.RA3
#define OLED_CS_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define OLED_CS_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define OLED_CS_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define OLED_CS_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define OLED_CS_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define OLED_CS_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define OLED_CS_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define OLED_CS_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set SCK2 aliases
#define SCK2_TRIS                 TRISBbits.TRISB1
#define SCK2_LAT                  LATBbits.LATB1
#define SCK2_PORT                 PORTBbits.RB1
#define SCK2_WPU                  WPUBbits.WPUB1
#define SCK2_OD                   ODCONBbits.ODCB1
#define SCK2_ANS                  ANSELBbits.ANSB1
#define SCK2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SCK2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SCK2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SCK2_GetValue()           PORTBbits.RB1
#define SCK2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SCK2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SCK2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SCK2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SCK2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SCK2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SCK2_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define SCK2_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set SDI2 aliases
#define SDI2_TRIS                 TRISBbits.TRISB2
#define SDI2_LAT                  LATBbits.LATB2
#define SDI2_PORT                 PORTBbits.RB2
#define SDI2_WPU                  WPUBbits.WPUB2
#define SDI2_OD                   ODCONBbits.ODCB2
#define SDI2_ANS                  ANSELBbits.ANSB2
#define SDI2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SDI2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SDI2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SDI2_GetValue()           PORTBbits.RB2
#define SDI2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SDI2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SDI2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SDI2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SDI2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SDI2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SDI2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define SDI2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SDO2 aliases
#define SDO2_TRIS                 TRISBbits.TRISB3
#define SDO2_LAT                  LATBbits.LATB3
#define SDO2_PORT                 PORTBbits.RB3
#define SDO2_WPU                  WPUBbits.WPUB3
#define SDO2_OD                   ODCONBbits.ODCB3
#define SDO2_ANS                  ANSELBbits.ANSB3
#define SDO2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SDO2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SDO2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SDO2_GetValue()           PORTBbits.RB3
#define SDO2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SDO2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SDO2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SDO2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SDO2_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SDO2_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SDO2_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SDO2_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set SW_HR aliases
#define SW_HR_TRIS                 TRISBbits.TRISB4
#define SW_HR_LAT                  LATBbits.LATB4
#define SW_HR_PORT                 PORTBbits.RB4
#define SW_HR_WPU                  WPUBbits.WPUB4
#define SW_HR_OD                   ODCONBbits.ODCB4
#define SW_HR_ANS                  ANSELBbits.ANSB4
#define SW_HR_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW_HR_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW_HR_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW_HR_GetValue()           PORTBbits.RB4
#define SW_HR_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW_HR_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW_HR_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW_HR_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW_HR_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW_HR_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW_HR_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SW_HR_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set OLED_DC aliases
#define OLED_DC_TRIS                 TRISCbits.TRISC2
#define OLED_DC_LAT                  LATCbits.LATC2
#define OLED_DC_PORT                 PORTCbits.RC2
#define OLED_DC_WPU                  WPUCbits.WPUC2
#define OLED_DC_OD                   ODCONCbits.ODCC2
#define OLED_DC_ANS                  ANSELCbits.ANSC2
#define OLED_DC_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define OLED_DC_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define OLED_DC_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define OLED_DC_GetValue()           PORTCbits.RC2
#define OLED_DC_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define OLED_DC_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define OLED_DC_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define OLED_DC_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define OLED_DC_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define OLED_DC_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define OLED_DC_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define OLED_DC_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC3
#define SCL1_LAT                  LATCbits.LATC3
#define SCL1_PORT                 PORTCbits.RC3
#define SCL1_WPU                  WPUCbits.WPUC3
#define SCL1_OD                   ODCONCbits.ODCC3
#define SCL1_ANS                  ANSELCbits.ANSC3
#define SCL1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL1_GetValue()           PORTCbits.RC3
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC4
#define SDA1_LAT                  LATCbits.LATC4
#define SDA1_PORT                 PORTCbits.RC4
#define SDA1_WPU                  WPUCbits.WPUC4
#define SDA1_OD                   ODCONCbits.ODCC4
#define SDA1_ANS                  ANSELCbits.ANSC4
#define SDA1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA1_GetValue()           PORTCbits.RC4
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SW_MIN aliases
#define SW_MIN_TRIS                 TRISCbits.TRISC5
#define SW_MIN_LAT                  LATCbits.LATC5
#define SW_MIN_PORT                 PORTCbits.RC5
#define SW_MIN_WPU                  WPUCbits.WPUC5
#define SW_MIN_OD                   ODCONCbits.ODCC5
#define SW_MIN_ANS                  ANSELCbits.ANSC5
#define SW_MIN_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SW_MIN_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SW_MIN_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SW_MIN_GetValue()           PORTCbits.RC5
#define SW_MIN_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SW_MIN_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SW_MIN_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SW_MIN_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SW_MIN_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SW_MIN_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SW_MIN_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SW_MIN_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set OLED_RST aliases
#define OLED_RST_TRIS                 TRISDbits.TRISD0
#define OLED_RST_LAT                  LATDbits.LATD0
#define OLED_RST_PORT                 PORTDbits.RD0
#define OLED_RST_WPU                  WPUDbits.WPUD0
#define OLED_RST_OD                   ODCONDbits.ODCD0
#define OLED_RST_ANS                  ANSELDbits.ANSD0
#define OLED_RST_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define OLED_RST_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define OLED_RST_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define OLED_RST_GetValue()           PORTDbits.RD0
#define OLED_RST_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define OLED_RST_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define OLED_RST_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define OLED_RST_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define OLED_RST_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define OLED_RST_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define OLED_RST_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define OLED_RST_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/