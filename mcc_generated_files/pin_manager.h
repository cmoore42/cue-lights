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
        Device            :  PIC16F15376
        Driver Version    :  2.11
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

// get/set COL0 aliases
#define COL0_TRIS                 TRISAbits.TRISA0
#define COL0_LAT                  LATAbits.LATA0
#define COL0_PORT                 PORTAbits.RA0
#define COL0_WPU                  WPUAbits.WPUA0
#define COL0_OD                   ODCONAbits.ODCA0
#define COL0_ANS                  ANSELAbits.ANSA0
#define COL0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define COL0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define COL0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define COL0_GetValue()           PORTAbits.RA0
#define COL0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define COL0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define COL0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define COL0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define COL0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define COL0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define COL0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define COL0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set COL1 aliases
#define COL1_TRIS                 TRISAbits.TRISA1
#define COL1_LAT                  LATAbits.LATA1
#define COL1_PORT                 PORTAbits.RA1
#define COL1_WPU                  WPUAbits.WPUA1
#define COL1_OD                   ODCONAbits.ODCA1
#define COL1_ANS                  ANSELAbits.ANSA1
#define COL1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define COL1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define COL1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define COL1_GetValue()           PORTAbits.RA1
#define COL1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define COL1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define COL1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define COL1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define COL1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define COL1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define COL1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define COL1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set COL2 aliases
#define COL2_TRIS                 TRISAbits.TRISA2
#define COL2_LAT                  LATAbits.LATA2
#define COL2_PORT                 PORTAbits.RA2
#define COL2_WPU                  WPUAbits.WPUA2
#define COL2_OD                   ODCONAbits.ODCA2
#define COL2_ANS                  ANSELAbits.ANSA2
#define COL2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define COL2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define COL2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define COL2_GetValue()           PORTAbits.RA2
#define COL2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define COL2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define COL2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define COL2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define COL2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define COL2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define COL2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define COL2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set COL3 aliases
#define COL3_TRIS                 TRISAbits.TRISA3
#define COL3_LAT                  LATAbits.LATA3
#define COL3_PORT                 PORTAbits.RA3
#define COL3_WPU                  WPUAbits.WPUA3
#define COL3_OD                   ODCONAbits.ODCA3
#define COL3_ANS                  ANSELAbits.ANSA3
#define COL3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define COL3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define COL3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define COL3_GetValue()           PORTAbits.RA3
#define COL3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define COL3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define COL3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define COL3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define COL3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define COL3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define COL3_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define COL3_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set COL4 aliases
#define COL4_TRIS                 TRISAbits.TRISA4
#define COL4_LAT                  LATAbits.LATA4
#define COL4_PORT                 PORTAbits.RA4
#define COL4_WPU                  WPUAbits.WPUA4
#define COL4_OD                   ODCONAbits.ODCA4
#define COL4_ANS                  ANSELAbits.ANSA4
#define COL4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define COL4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define COL4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define COL4_GetValue()           PORTAbits.RA4
#define COL4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define COL4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define COL4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define COL4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define COL4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define COL4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define COL4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define COL4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set COL5 aliases
#define COL5_TRIS                 TRISAbits.TRISA5
#define COL5_LAT                  LATAbits.LATA5
#define COL5_PORT                 PORTAbits.RA5
#define COL5_WPU                  WPUAbits.WPUA5
#define COL5_OD                   ODCONAbits.ODCA5
#define COL5_ANS                  ANSELAbits.ANSA5
#define COL5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define COL5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define COL5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define COL5_GetValue()           PORTAbits.RA5
#define COL5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define COL5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define COL5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define COL5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define COL5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define COL5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define COL5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define COL5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set COL6 aliases
#define COL6_TRIS                 TRISAbits.TRISA6
#define COL6_LAT                  LATAbits.LATA6
#define COL6_PORT                 PORTAbits.RA6
#define COL6_WPU                  WPUAbits.WPUA6
#define COL6_OD                   ODCONAbits.ODCA6
#define COL6_ANS                  ANSELAbits.ANSA6
#define COL6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define COL6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define COL6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define COL6_GetValue()           PORTAbits.RA6
#define COL6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define COL6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define COL6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define COL6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define COL6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define COL6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define COL6_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define COL6_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set COL7 aliases
#define COL7_TRIS                 TRISAbits.TRISA7
#define COL7_LAT                  LATAbits.LATA7
#define COL7_PORT                 PORTAbits.RA7
#define COL7_WPU                  WPUAbits.WPUA7
#define COL7_OD                   ODCONAbits.ODCA7
#define COL7_ANS                  ANSELAbits.ANSA7
#define COL7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define COL7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define COL7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define COL7_GetValue()           PORTAbits.RA7
#define COL7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define COL7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define COL7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define COL7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define COL7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define COL7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define COL7_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define COL7_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set CFG0 aliases
#define CFG0_TRIS                 TRISBbits.TRISB4
#define CFG0_LAT                  LATBbits.LATB4
#define CFG0_PORT                 PORTBbits.RB4
#define CFG0_WPU                  WPUBbits.WPUB4
#define CFG0_OD                   ODCONBbits.ODCB4
#define CFG0_ANS                  ANSELBbits.ANSB4
#define CFG0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define CFG0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define CFG0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define CFG0_GetValue()           PORTBbits.RB4
#define CFG0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define CFG0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define CFG0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define CFG0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define CFG0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define CFG0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define CFG0_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define CFG0_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set CFG1 aliases
#define CFG1_TRIS                 TRISBbits.TRISB5
#define CFG1_LAT                  LATBbits.LATB5
#define CFG1_PORT                 PORTBbits.RB5
#define CFG1_WPU                  WPUBbits.WPUB5
#define CFG1_OD                   ODCONBbits.ODCB5
#define CFG1_ANS                  ANSELBbits.ANSB5
#define CFG1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define CFG1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define CFG1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define CFG1_GetValue()           PORTBbits.RB5
#define CFG1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define CFG1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define CFG1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define CFG1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define CFG1_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define CFG1_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define CFG1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define CFG1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set COL8 aliases
#define COL8_TRIS                 TRISCbits.TRISC0
#define COL8_LAT                  LATCbits.LATC0
#define COL8_PORT                 PORTCbits.RC0
#define COL8_WPU                  WPUCbits.WPUC0
#define COL8_OD                   ODCONCbits.ODCC0
#define COL8_ANS                  ANSELCbits.ANSC0
#define COL8_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define COL8_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define COL8_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define COL8_GetValue()           PORTCbits.RC0
#define COL8_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define COL8_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define COL8_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define COL8_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define COL8_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define COL8_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define COL8_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define COL8_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set COL9 aliases
#define COL9_TRIS                 TRISCbits.TRISC1
#define COL9_LAT                  LATCbits.LATC1
#define COL9_PORT                 PORTCbits.RC1
#define COL9_WPU                  WPUCbits.WPUC1
#define COL9_OD                   ODCONCbits.ODCC1
#define COL9_ANS                  ANSELCbits.ANSC1
#define COL9_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define COL9_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define COL9_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define COL9_GetValue()           PORTCbits.RC1
#define COL9_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define COL9_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define COL9_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define COL9_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define COL9_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define COL9_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define COL9_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define COL9_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set COL10 aliases
#define COL10_TRIS                 TRISCbits.TRISC2
#define COL10_LAT                  LATCbits.LATC2
#define COL10_PORT                 PORTCbits.RC2
#define COL10_WPU                  WPUCbits.WPUC2
#define COL10_OD                   ODCONCbits.ODCC2
#define COL10_ANS                  ANSELCbits.ANSC2
#define COL10_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define COL10_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define COL10_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define COL10_GetValue()           PORTCbits.RC2
#define COL10_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define COL10_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define COL10_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define COL10_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define COL10_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define COL10_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define COL10_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define COL10_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set COL11 aliases
#define COL11_TRIS                 TRISCbits.TRISC3
#define COL11_LAT                  LATCbits.LATC3
#define COL11_PORT                 PORTCbits.RC3
#define COL11_WPU                  WPUCbits.WPUC3
#define COL11_OD                   ODCONCbits.ODCC3
#define COL11_ANS                  ANSELCbits.ANSC3
#define COL11_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define COL11_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define COL11_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define COL11_GetValue()           PORTCbits.RC3
#define COL11_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define COL11_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define COL11_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define COL11_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define COL11_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define COL11_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define COL11_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define COL11_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set COL12 aliases
#define COL12_TRIS                 TRISCbits.TRISC4
#define COL12_LAT                  LATCbits.LATC4
#define COL12_PORT                 PORTCbits.RC4
#define COL12_WPU                  WPUCbits.WPUC4
#define COL12_OD                   ODCONCbits.ODCC4
#define COL12_ANS                  ANSELCbits.ANSC4
#define COL12_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define COL12_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define COL12_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define COL12_GetValue()           PORTCbits.RC4
#define COL12_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define COL12_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define COL12_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define COL12_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define COL12_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define COL12_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define COL12_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define COL12_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set COL13 aliases
#define COL13_TRIS                 TRISCbits.TRISC5
#define COL13_LAT                  LATCbits.LATC5
#define COL13_PORT                 PORTCbits.RC5
#define COL13_WPU                  WPUCbits.WPUC5
#define COL13_OD                   ODCONCbits.ODCC5
#define COL13_ANS                  ANSELCbits.ANSC5
#define COL13_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define COL13_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define COL13_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define COL13_GetValue()           PORTCbits.RC5
#define COL13_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define COL13_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define COL13_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define COL13_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define COL13_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define COL13_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define COL13_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define COL13_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set COL14 aliases
#define COL14_TRIS                 TRISCbits.TRISC6
#define COL14_LAT                  LATCbits.LATC6
#define COL14_PORT                 PORTCbits.RC6
#define COL14_WPU                  WPUCbits.WPUC6
#define COL14_OD                   ODCONCbits.ODCC6
#define COL14_ANS                  ANSELCbits.ANSC6
#define COL14_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define COL14_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define COL14_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define COL14_GetValue()           PORTCbits.RC6
#define COL14_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define COL14_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define COL14_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define COL14_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define COL14_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define COL14_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define COL14_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define COL14_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set COL15 aliases
#define COL15_TRIS                 TRISCbits.TRISC7
#define COL15_LAT                  LATCbits.LATC7
#define COL15_PORT                 PORTCbits.RC7
#define COL15_WPU                  WPUCbits.WPUC7
#define COL15_OD                   ODCONCbits.ODCC7
#define COL15_ANS                  ANSELCbits.ANSC7
#define COL15_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define COL15_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define COL15_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define COL15_GetValue()           PORTCbits.RC7
#define COL15_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define COL15_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define COL15_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define COL15_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define COL15_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define COL15_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define COL15_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define COL15_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set BTN0 aliases
#define BTN0_TRIS                 TRISDbits.TRISD0
#define BTN0_LAT                  LATDbits.LATD0
#define BTN0_PORT                 PORTDbits.RD0
#define BTN0_WPU                  WPUDbits.WPUD0
#define BTN0_OD                   ODCONDbits.ODCD0
#define BTN0_ANS                  ANSELDbits.ANSD0
#define BTN0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define BTN0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define BTN0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define BTN0_GetValue()           PORTDbits.RD0
#define BTN0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define BTN0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define BTN0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define BTN0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define BTN0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define BTN0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define BTN0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define BTN0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set BTN1 aliases
#define BTN1_TRIS                 TRISDbits.TRISD1
#define BTN1_LAT                  LATDbits.LATD1
#define BTN1_PORT                 PORTDbits.RD1
#define BTN1_WPU                  WPUDbits.WPUD1
#define BTN1_OD                   ODCONDbits.ODCD1
#define BTN1_ANS                  ANSELDbits.ANSD1
#define BTN1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define BTN1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define BTN1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define BTN1_GetValue()           PORTDbits.RD1
#define BTN1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define BTN1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define BTN1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define BTN1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define BTN1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define BTN1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define BTN1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define BTN1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set BTN2 aliases
#define BTN2_TRIS                 TRISDbits.TRISD2
#define BTN2_LAT                  LATDbits.LATD2
#define BTN2_PORT                 PORTDbits.RD2
#define BTN2_WPU                  WPUDbits.WPUD2
#define BTN2_OD                   ODCONDbits.ODCD2
#define BTN2_ANS                  ANSELDbits.ANSD2
#define BTN2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define BTN2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define BTN2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define BTN2_GetValue()           PORTDbits.RD2
#define BTN2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define BTN2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define BTN2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define BTN2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define BTN2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define BTN2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define BTN2_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define BTN2_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set LED0 aliases
#define LED0_TRIS                 TRISDbits.TRISD3
#define LED0_LAT                  LATDbits.LATD3
#define LED0_PORT                 PORTDbits.RD3
#define LED0_WPU                  WPUDbits.WPUD3
#define LED0_OD                   ODCONDbits.ODCD3
#define LED0_ANS                  ANSELDbits.ANSD3
#define LED0_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LED0_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LED0_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LED0_GetValue()           PORTDbits.RD3
#define LED0_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LED0_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISDbits.TRISD4
#define LED1_LAT                  LATDbits.LATD4
#define LED1_PORT                 PORTDbits.RD4
#define LED1_WPU                  WPUDbits.WPUD4
#define LED1_OD                   ODCONDbits.ODCD4
#define LED1_ANS                  ANSELDbits.ANSD4
#define LED1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define LED1_GetValue()           PORTDbits.RD4
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define LED1_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISDbits.TRISD5
#define LED2_LAT                  LATDbits.LATD5
#define LED2_PORT                 PORTDbits.RD5
#define LED2_WPU                  WPUDbits.WPUD5
#define LED2_OD                   ODCONDbits.ODCD5
#define LED2_ANS                  ANSELDbits.ANSD5
#define LED2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LED2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LED2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LED2_GetValue()           PORTDbits.RD5
#define LED2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LED2_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set TXEN aliases
#define TXEN_TRIS                 TRISDbits.TRISD6
#define TXEN_LAT                  LATDbits.LATD6
#define TXEN_PORT                 PORTDbits.RD6
#define TXEN_WPU                  WPUDbits.WPUD6
#define TXEN_OD                   ODCONDbits.ODCD6
#define TXEN_ANS                  ANSELDbits.ANSD6
#define TXEN_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define TXEN_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define TXEN_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define TXEN_GetValue()           PORTDbits.RD6
#define TXEN_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define TXEN_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define TXEN_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define TXEN_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define TXEN_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define TXEN_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define TXEN_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define TXEN_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set RXEN aliases
#define RXEN_TRIS                 TRISDbits.TRISD7
#define RXEN_LAT                  LATDbits.LATD7
#define RXEN_PORT                 PORTDbits.RD7
#define RXEN_WPU                  WPUDbits.WPUD7
#define RXEN_OD                   ODCONDbits.ODCD7
#define RXEN_ANS                  ANSELDbits.ANSD7
#define RXEN_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define RXEN_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define RXEN_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RXEN_GetValue()           PORTDbits.RD7
#define RXEN_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define RXEN_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define RXEN_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define RXEN_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define RXEN_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define RXEN_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define RXEN_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define RXEN_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set CFG2 aliases
#define CFG2_TRIS                 TRISEbits.TRISE0
#define CFG2_LAT                  LATEbits.LATE0
#define CFG2_PORT                 PORTEbits.RE0
#define CFG2_WPU                  WPUEbits.WPUE0
#define CFG2_OD                   ODCONEbits.ODCE0
#define CFG2_ANS                  ANSELEbits.ANSE0
#define CFG2_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define CFG2_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define CFG2_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define CFG2_GetValue()           PORTEbits.RE0
#define CFG2_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define CFG2_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define CFG2_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define CFG2_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define CFG2_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define CFG2_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define CFG2_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define CFG2_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set CFG3 aliases
#define CFG3_TRIS                 TRISEbits.TRISE1
#define CFG3_LAT                  LATEbits.LATE1
#define CFG3_PORT                 PORTEbits.RE1
#define CFG3_WPU                  WPUEbits.WPUE1
#define CFG3_OD                   ODCONEbits.ODCE1
#define CFG3_ANS                  ANSELEbits.ANSE1
#define CFG3_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define CFG3_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define CFG3_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define CFG3_GetValue()           PORTEbits.RE1
#define CFG3_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define CFG3_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define CFG3_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define CFG3_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define CFG3_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define CFG3_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define CFG3_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define CFG3_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

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