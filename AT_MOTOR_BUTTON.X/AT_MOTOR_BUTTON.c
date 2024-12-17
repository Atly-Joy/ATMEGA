/*
 * File:   AT_MOTOR_BUTTON.c
 * Author: ASUS
 *
 * Created on September 27, 2024, 9:15 AM
 */


#include <avr/io.h>
#include<util/delay.h>

int main(void) 
{
    DDRD=0x00;
    DDRC=0xFF;
    while (1) 
    {
        if((PIND&0X01)==0)
        {
            PORTC=0x01;
            //_delay_ms(10);
        }
        else if((PIND&0X02)==0)
        {
            PORTC=0x02;
        }
        else if((PIND&0X04)==0)
        {
            PORTC=0x00;
        }
    }
}
