/*
 * File:   AT_BUTTON_DUTYCYCLE.c
 * Author: ASUS
 *
 * Created on October 3, 2024, 9:46 AM
 */


#include <avr/io.h>

int main(void)
{
    DDRB=0xFF;
    DDRC=0X00;
    TCCR0=0x65;
    while(1)
    {
        if(PINC==0x01)
        {
            OCR0=65;
        }
        else if(PINC==0X02)
        {
            OCR0=125;
        }
        else if(PINC==0X04)
        {
            OCR0=250;
        }
    }
}
