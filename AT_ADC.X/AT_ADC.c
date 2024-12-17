/*
 * File:   AT_ADC.c
 * Author: ASUS
 *
 * Created on September 30, 2024, 9:05 AM
 */


#include <avr/io.h>
#include<util/delay.h>
#include <stdio.h>
void start_func(unsigned char a)
{
    PORTD=0x40;//RS=0,RW=0,E=1
    PORTB=a;
    _delay_ms(1);
    PORTD=0x00;//RS=0,RW=0,E=0
    _delay_ms(3);
}
void data(unsigned char a)
{
    PORTD=0x60;//RS=1,RW=0,E=1
    PORTB=a;
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
void main(void)
{
    DDRB=DDRD=0xFF;
    start_func(0x01);//clear
    start_func(0x0C);//cursor and LCD On
    ADMUX=0x40;
    ADCSRA=0X88;
    while(1)
    {
        int adc;//char size=8, integer size=16 we require 10bit thats why we chose int.
        char cnv[15];//adc value convert by sprintf and it store in this array. int to string
        ADCSRA=0XC8;//ITS C8 BECAUSE INSTEAD OF GO=1//AFTER THIS ADCSRA BECOME D8 BECAUSE ADIF BECOME 1;
        while((ADCSRA&0X10)==0);
        ADCSRA=ADCSRA&0XEF;//HERE WE HAVE CHANGE ADIF=0 SO WE HAVE DO D8&EF=C8
        adc=ADC;
        sprintf(cnv,"ADC value %4d",adc);
        start_func(0x80);
        display(cnv);
        
    }
}
