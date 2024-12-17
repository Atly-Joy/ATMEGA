/*
 * File:   AT_UART_MOTOR2.c
 * Author: ASUS
 *
 * Created on September 26, 2024, 10:21 AM
 */


#include <avr/io.h>
#include<util/delay.h>

void transmit(char a);
char reception(void);
void uart_init();
char rx_tx();
char a;
int main(void) {
    DDRD=0X02;
    DDRC=0xFF;
    DDRB=0xFF;
    uart_init();
    while (1) 
    {
        rx_tx();
        if(a=='a')
        {
            rx_tx();
            if(a=='1')
                PORTC=0x01;
            else if(a=='2')
                PORTC=0x02;
            else if(a=='3')
                PORTC=0x00;
        }
        else if(a=='b')
        {
            rx_tx();
            if(a=='1')
                PORTB=0x01;
            else if(a=='2')
                PORTB=0x02;
            else if(a=='3')
                PORTB=0x00;
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
char rx_tx()
{
    a= reception();
    transmit(a);
}