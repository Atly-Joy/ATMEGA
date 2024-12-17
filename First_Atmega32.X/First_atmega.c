/*
 * File:   First_atmega.c
 * Author: ASUS
 *
 * Created on September 23, 2024, 10:25 AM
 */


#include <avr/io.h>
#include<util/delay.h>
int main(void) 
{
    DDRC=0xFF;
    DDRD=0X00;
    int count=0;
    while (1) 
    {
        
       for(long i=0;i<=7;i++)
        {
            PORTC=1<<i;
            _delay_ms(1000);
        }
        for(long i=0;i<=5;i++)
        {
            PORTC=64>>i;
            _delay_ms(1000);
        }
        /*other method
         * for(long j=1;j<=128;j<<1)
        {
            PORTC=j;
            _delay_ms(100);
        }*/
    }
}
