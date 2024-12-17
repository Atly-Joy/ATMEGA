/*
 * File:   HW_AT_LED.c
 * Author: ASUS
 *
 * Created on October 1, 2024, 12:33 PM
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
        
        if((PIND&0X10)==0&&count==0)
        {
            for(long i=0;i<=7;i++)
                {
                    PORTC=1<<i;
                    _delay_ms(1000);
                }
                count=1;
        }
        else if((PIND&0X10)==0&&count==1)
        {
            for(long i=0;i<=7;i++)
            {
                PORTC=128>>i;
                _delay_ms(1000);
            }
        
            count=0;
        }
    }
      return;  
 }
    