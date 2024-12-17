/*
 * File:   AT_LCD1.c
 * Author: ASUS
 *
 * Created on September 24, 2024, 10:01 AM
 */


#include <avr/io.h>
#include<util/delay.h>

void cmd(unsigned char a );
void data(unsigned char a );
void display(const char *p);

void main(void) 
{
    DDRC=DDRD=0xFF;
    cmd(0x01);
    cmd(0x0f);
    display("ATLY");
    while(1);
    return;
}


void cmd(unsigned char a )
{
    PORTD=0x04;//RS=0,RW=0,E=1
    PORTC=a;
    _delay_ms(1);
    PORTD=0x00;//RS=0,RW=0,E=0
    _delay_ms(3);
}
void data(unsigned char a )
{
    PORTD=0x05;//RS=1,RW=0,E=1
    PORTC=a;
    _delay_ms(1);
    PORTD=0x01;//RS=1,RW=0,E=0
    _delay_ms(3);
}

void display(const char *p)
{
    while(*p)
    {
        data(*p);
        p++;
    }
}
