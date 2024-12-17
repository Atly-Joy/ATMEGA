/*
 * File:   AT_ADC_7SEG_HW.c
 * Author: ASUS
 *
 * Created on October 2, 2024, 11:05 AM
 */


#include <avr/io.h>
#include<stdio.h>
#include<util/delay.h>
unsigned char seg[10]={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XFA,0X0E,0XFE,0XCE};
unsigned char port[4]={~0x07,~0x0B,~0x0D,~0x0E};
void segment(char s)
{
    switch(s)
    {
        case ' ' : PORTB=seg[0];
                break;
        case '0' : PORTB=seg[0];
                break;
        case '1' : PORTB=seg[1];
                break;
        case '2' : PORTB=seg[2];
                break;
        case '3' : PORTB=seg[3];
                break;
        case '4' : PORTB=seg[4];
                break;
        case '5' : PORTB=seg[5];
                break;
        case '6' : PORTB=seg[6];
                break;
        case '7' : PORTB=seg[7];
                break;
        case '8' : PORTB=seg[8];
                break;
        case '9' : PORTB=seg[9];
                break;
    }
}
/*unsigned char seg[10]={~0X3F,~0X06,~0X5B,~0X4F,~0X66,~0X6D,~0X7D,~0X07,~0X7F,~0X67};
unsigned char port[4]={~0x0E,~0x0D,~0x0B,~0x07};*/
void main(void)
{
    DDRB=0xFF;
    DDRA=0xBF;
    ADMUX=0X06;
    ADCSRA=0X88;
    //PORTA=0XFF;
    //PORTB=0XFE;
    while(1)
    {
        int adc;//char size=8, integer size=16 we require 10bit thats why we chose int.
        char cnv[15];//adc value convert by sprintf and it store in this array. int to string
        _delay_ms(10);
        ADCSRA=0XC8;//ITS C8 BECAUSE INSTEAD OF GO=1//AFTER THIS ADCSRA BECOME D8 BECAUSE ADIF BECOME 1;
        while((ADCSRA&0X10)==0);
        ADCSRA=ADCSRA&0XEF;//HERE WE HAVE CHANGE ADIF=0 SO WE HAVE DO D8&EF=C8
        adc=ADC;
        sprintf(cnv,"%4d",adc);
        for(int i=0;i<100;i++)
        {
            for(int i=0;i<4;i++)
            {
                PORTA=port[i];
                segment(cnv[i]);
                _delay_ms(10);
            }
        }
        
    }
    return;
}  
