/*
 * File:   _PHASE_PWM.c
 * Author: ASUS
 *
 * Created on October 3, 2024, 9:36 AM
 */


/*void delay(void)
{
    OCR0=125;//
    while((TIFR&0X02)==0);//THIS METHOD USED FOR MULTIPLE PWM PINS eLSE WE ONLY REQUIRE  OCRO=VALUE
    TIFR= TIFR & 0XFD;
    
 *
}*/
#include <avr/io.h>
void main(void) 
{
    DDRB=0xFF;
    TCCR0=0x65;
    OCR0=125;
    /*while(1)
    {
        PORTC=0xFF;
        delay();
        PORTC=0x00;
        delay();
     
    }
    return;*/
}