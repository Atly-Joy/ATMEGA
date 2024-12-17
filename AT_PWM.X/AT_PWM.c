/*
 * File:   AT_PWM.c
 * Author: ASUS
 *
 * Created on October 2, 2024, 9:46 AM
 */


#include <avr/io.h>
#include<util/delay.h>

//void delay(void)
//{
//    OCR0=125;//fast pwm
//    while((TIFR&0X02)==0);//THIS METHOD USED FOR MULTIPLE PWM PINS eLSE WE ONLY REQUIRE  OCRO=VALUE
//    TIFR= TIFR & 0XFD;
//    
//}
void main(void) 
{
    DDRB=0xFF;
    TCCR0=0x6D;
    while(1)
    {
        for(int i=15;i<255;i++)
        {
            OCR0=i;
            _delay_ms(100);
        }
    }
    return;
}

