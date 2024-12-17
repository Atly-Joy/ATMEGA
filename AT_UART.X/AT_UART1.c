/*
 * File:   AT_UART1.c
 * Author: ASUS
 *
 * Created on September 26, 2024, 9:16 AM
 */


#include <avr/io.h>
#include<util/delay.h>

void transmit(char a);
char reception(void);
void uart_init();

int main(void) {
    DDRD=0X02;
    DDRC=0xFF;
    uart_init();
    while (1) 
    {
        char a= reception();
        transmit(a);
        if(a=='a')
        {
            PORTC=0x0A;
        }
        else if(a=='b')
        {
            PORTC=0x05;
        }
        else if(a=='c')
        {
            PORTC=0x00;
        }
    }
    return;
}

void transmit(char a)
{
    while((UCSRA&0X20)==0);//checking UDRE bit is 1 or 0 using AND
    UDR=a;
}


char reception(void)
{
    while((UCSRA&0X80)==0);//checking RXC bit is 1 or 0
    return UDR;
}

void uart_init()//uart inetiatilizing
{
    UCSRA=0X40;
    UCSRB=0X18;
    UCSRC=0X86;//8BIT, NO PARITY, 1STOP BIT
    UBRRH=0;
    UBRRL=0X33;
}