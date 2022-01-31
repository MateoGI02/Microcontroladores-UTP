#include <xc.h>
#include "Configuracion.h"
#include "LCD.h"
#include <stdio.h>
#include <stdint.h>


/*
 * 
 */
#define _XTAL_FREQ 4000000 

void uno(void) 
{
        OpenXLCD(FOUR_BIT & LINES_5X8);
    while(BusyXLCD());
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);
    LCD_gotoXY(0,0);
    putrsXLCD("0");
    return;
}
void dos(void) 
{
    OpenXLCD(FOUR_BIT & LINES_5X8);
    while(BusyXLCD());
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);
    LCD_gotoXY(0,0);
    putrsXLCD("1");
    LCD_gotoXY(0,2);
    putrsXLCD("2");
    LCD_gotoXY(0,4);
    putrsXLCD("3");
    LCD_gotoXY(0,6);
    putrsXLCD("a");
    LCD_gotoXY(0,8);
    putrsXLCD("b");
    LCD_gotoXY(0,10);
    putrsXLCD("c");
    LCD_gotoXY(0,12);
    putrsXLCD("A");
    LCD_gotoXY(0,14);
    putrsXLCD("B");
    
    LCD_gotoXY(1,0);
    putrsXLCD("@");
    LCD_gotoXY(1,2);
    putrsXLCD("#");
    LCD_gotoXY(1,4);
    putrsXLCD("!");
    LCD_gotoXY(1,6);
    putrsXLCD("%");
    LCD_gotoXY(1,8);
    putrsXLCD(";");
    LCD_gotoXY(1,10);
    putrsXLCD("=");
    LCD_gotoXY(1,11);
    putrsXLCD("(");
    LCD_gotoXY(1,14);
    putrsXLCD("=");
    LCD_gotoXY(1,15);
    putrsXLCD(")");
    return;
}
void tres(void) 
{
    OpenXLCD(FOUR_BIT & LINES_5X8);
    while(BusyXLCD());
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);
IN: LCD_gotoXY(0,2);
    putrsXLCD("Universidad");
    LCD_gotoXY(1,1);
    putrsXLCD("Tecn. del Peru ");
    __delay_ms(1000);
 
     LCD_gotoXY(0,4);
    putrsXLCD("Curso de");
    LCD_gotoXY(1,1);
    putrsXLCD("uControladores");
    __delay_ms(1000);
    goto IN;
    return;
}
void cuatro(void) 
{
    int dato[17];
    int dato1=246;
    float dato2=35.42;
    
    OpenXLCD(FOUR_BIT & LINES_5X8);
    while(BusyXLCD());
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);
    
    sprintf(dato,"Valor 1 = %d",dato1);
    LCD_gotoXY(0,0);
    putrsXLCD(dato);
    sprintf(dato,"Valor 2 = %.2f",dato2);
    LCD_gotoXY(1,0);
    putrsXLCD(dato);
    return;
}

void main(void) 
{
    PORTC=3;
LEE:    if(PORTC==0) goto UNO;
        if(PORTC==1) goto DOS;
        if(PORTC==2) goto TRES;
        if(PORTC==3) goto CUATRO;
goto LEE;
UNO:    uno();
LEE2:if(PORTC==0) goto LEE2;
        goto LEE;
DOS:    dos();
LEE3:if(PORTC==1) goto LEE3;
        goto LEE;
TRES:   tres();
LEE4:if(PORTC==2) goto LEE4;
        goto LEE;
CUATRO: cuatro();
LEE5:if(PORTC==3) goto LEE5;
        goto LEE;
}


/*const char carita[]={0b00000000,
                     0b00000000,
                     0b00001010,
                     0b00000000,
                     0b00010001,
                     0b00001110,
                     0b00000000,
                     0b00000000,0
 };


void main(void) 
{
     OpenXLCD(FOUR_BIT & LINES_5X8);
    while(BusyXLCD());
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);   
    
    LCD_WriteChr_CGRAM(carita,0);
    __delay_ms(500);
    LCD_gotoXY(0,7);
    putcXLCD(0);
    __delay_ms(200);
    FIN: goto FIN;
}
*/