/*
 * File:   AT_TMER.c
 * Author: ASUS
 *
 * Created on October 1, 2024, 10:03 AM
 */


#include <avr/io.h>

void delay(void)
{
    TCNT0=177;
    while((TIFR&0X01)==0);
    TIFR= TIFR | 0X01;
    
}
void main(void) 
{
    DDRC=0xFF;
    TCCR0=0x05;
    while(1)
    {
        PORTC=0xFF;
        delay();
        PORTC=0x00;
        delay();
     
    }
    return;
}
