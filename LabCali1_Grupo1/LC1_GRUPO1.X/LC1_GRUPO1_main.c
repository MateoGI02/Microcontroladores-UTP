/* 
 * File:   LC1_GRUPO1_main.c
 * Author: Propietario
 *
 * Created on 25 de septiembre de 2018, 07:24 AM
 */


// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
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

/*
 * 
 */

#define _XTAL_FREQ 4000000 

int main(int argc, char** argv) 
{
int a,t; 					// Definir ?a? y ?t? como entero 
int m1[4]={0x0C,0x79,0x12,0x40};	// Definir vector m1 con 4 valores
int m2[4]={0x47,0x41,0x2B,0x08};	// Definir vector m3 con 4 valores
int m3[4]={0x07,0x2F,0x06,0x12};	// Definir vector m2 con 4 valores
int m4[4]={0x21,0x79,0x40,0x12};	// Definir vector m4 con 4 valores

TRISD=0; 					// Definir puerto D como salida
TRISC=3;				// Definir puerto C como entrada módulo 3  
       
INICIO: 					// Definir etiqueta INICIO 
    if(PORTC==0)goto UNO;
	if(PORTC==1)goto DOS;
	if(PORTC==2)goto TRES;
	if(PORTC==3)goto CUATRO;

UNO:
for (a=0;a<4;a++) 			// Establecer for como contador 
{ 
PORTD= m1[a];             	// Salida es el valor a del vector m1
if(PORTC==1)goto DOS;
if(PORTC==2)goto TRES;
if(PORTC==3)goto CUATRO;
for (t=0;t<10;t++) 			// Establecer for como contador 
{ 
__delay_ms(100); 	// Definir retraso 500 microsegundos 
} 
} 
goto INICIO;
 
DOS:
for (a=0;a<4;a++) 			// Establecer for como contador 
{ 
PORTD= m2[a];             	// Salida es el valor a del vector m1
if(PORTC==0)goto UNO;
if(PORTC==2)goto TRES;
if(PORTC==3)goto CUATRO;
for (t=0;t<10;t++) 			// Establecer for como contador 
{ 
__delay_ms(100); 	// Definir retraso 500 microsegundos 
} 
} 
goto INICIO; 

TRES:
for (a=0;a<4;a++) 			// Establecer for como contador 
{ 
PORTD= m3[a];             	// Salida es el valor a del vector m1
if(PORTC==0)goto UNO;
if(PORTC==1)goto DOS;
if(PORTC==3)goto CUATRO;
for (t=0;t<10;t++) 			// Establecer for como contador 
{ 
__delay_ms(100); 	// Definir retraso 500 microsegundos 
} 
} 
goto INICIO; 

CUATRO:
for (a=0;a<4;a++) 			// Establecer for como contador 
{ 
PORTD= m4[a];             	// Salida es el valor a del vector m1
if(PORTC==0)goto UNO;
if(PORTC==1)goto DOS;
if(PORTC==2)goto TRES;
for (t=0;t<10;t++) 			// Establecer for como contador 
{ 
__delay_ms(100); 	// Definir retraso 500 microsegundos 
} 
} 
goto INICIO;

    return (EXIT_SUCCESS);
}

