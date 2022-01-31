/* 
 * File:   Lab_Cal_2.c
 * Author: Propietario
 *
 * Created on 17 de noviembre de 2018, 12:31 PM
 */

// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = ON         // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 20000000

void __interrupt() tc_int(void);
void TMR0_Init (void);
int cuenta;

void TMR0_Init (void)
{
    INTCONbits.GIE=0;
    T0CONbits.T0CS=0;
    T0CONbits.PSA=0;  
    T0CONbits.T0PS=0b101; //prescaler 256
    T0CONbits.T08BIT=0;
    T0CONbits.TMR0ON=1;
    INTCONbits.TMR0IE=1;
    INTCONbits.TMR0IF=0;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
}

int main(int argc, char** argv) 
{
    TMR0_Init();
    int c[4]={0x01,0x38,0x0C,0x06};
    int m[15]={'C','O','N','T','A','D','O','R',' ','M','O','D',' ','1','0'};
    int a,u;
    TRISC=0;
    TRISD=0;
    cuenta=0;
    
    PORTCbits.RC0=0;
    PORTCbits.RC1=0;
    __delay_ms(20);
    
    for(a=0;a<4;a++)
    {
        PORTD=c[a];
        __delay_ms(20);
        PORTCbits.RC1=1;
        __delay_ms(20);
         PORTCbits.RC1=0;
        __delay_ms(20); 
    }
    
    PORTCbits.RC0=1;
    PORTCbits.RC1=0;
    __delay_ms(20);
    
    for(a=0;a<15;a++)
    {
        PORTD=m[a];
        __delay_ms(20);
        PORTCbits.RC1=1;
        __delay_ms(20);
         PORTCbits.RC1=0;
        __delay_ms(20); 
    }
    
      TMR0L=55770;
      TMR0H=(55770) >>8;   
      
    while(1)
    {
        u=cuenta%10;
        PORTCbits.RC0=0;
        PORTCbits.RC1=0;
        __delay_ms(20);
    
        PORTD=0xC7;
        __delay_ms(20);
        PORTCbits.RC1=1;
        __delay_ms(20);
        PORTCbits.RC1=0;
        __delay_ms(20);
    
        PORTCbits.RC0=1;
        PORTCbits.RC1=0;
        __delay_ms(20);
      
        PORTD=u+0x30;
        __delay_ms(20);
        PORTCbits.RC1=1;
        __delay_ms(20);
        PORTCbits.RC1=0;
        __delay_ms(20);
    }
    return (EXIT_SUCCESS);
}

void __interrupt() tc_int (void)
{
    if(INTCONbits.TMR0IF == 1)
    {
        cuenta++;
        if(cuenta==10)
        {
            cuenta=0;
        }
        INTCONbits.TMR0IF=0;        
    }
}