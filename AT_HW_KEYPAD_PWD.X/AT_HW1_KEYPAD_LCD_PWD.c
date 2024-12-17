/*
 * File:   AT_HW1_KEYPAD_LCD_PWD.c
 * Author: ASUS
 *
 * Created on October 3, 2024, 3:52 PM
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <string.h>
#include<util/delay.h>
void cmd(unsigned char a )
{
    PORTD=0x40;//RS=0,RW=0,E=1
    PORTB=a;
    _delay_ms(25);
    PORTD=0x00;//RS=0,RW=0,E=0
    _delay_ms(25);
}
void data(unsigned char a )
{
    PORTD=0x50;//RS=1,RW=0,E=1
    PORTB=a;
    _delay_ms(25);
    PORTD=0x10;//RS=1,RW=0,E=0
    _delay_ms(25);
}

void display(const char *p)
{
    while(*p)
    {
        data(*p);
        p++;
    }
}

char keypad(void)
{
    int count=0;
    while(1)
    {
     //   _delay_ms(500);
        PORTA=0XEF;//1110 0000-output configured in C 1110 1111
        if((PINA&0X0F)==0X0E)// 1110 110
        {
            return '7';
        }
        else if((PINA&0X02)==0)
        {
            return '4';
        }
        else if((PINA&0X04)==0)
        {
            return '1';
        }
        PORTA=0XDF;//1101
        if((PINA&0X01)==0)
        {
            return '8';
        }
        else if((PINA&0X02)==0)
        {
            return '5';
        }
        else if((PINA&0X04)==0)
        {
            return '2';
        }
        
        PORTA=0XBF;//1011
       if((PINA&0X0F)==0X0E)
        {
            return '9';
        }
        else if((PINA&0X02)==0)
        {
            return '6';
        }
        else if((PINA&0X04)==0)
        {
            return '3';
        }
       /*PORTA=0XF3;
       if((PINA&0X20)==0)
        {
            cmd(0x10);
            data(' ');
            cmd(0x10);
            return 'b';//backspace
        }
        if((PINA&0X40)==0)
        {
            return 'c';//clear
        }
        else if((PINA&0X80)==0)
        {
            return '0';
        }*/
    }
}

void main(void) 
{
    DDRD=0XFF;
    DDRB=0XFF;
    //DDRA=0XF0;
    DDRA=0XF0;//
    PORTA=0X0F;//
    char pass[]="1234",inp[]="0000",m;
    int k;
    cmd(0x38);
    cmd(0x01);
    cmd(0x0f);
    cmd(0x80);
    //display("ENTER PWD");
    while(1)
    {
         m=keypad();
            data(m); while((PINA&0X0F)!=0X0F);\
 _delay_ms(500);
            /*
        for(k=0;k<4;k++)
        {
            m=keypad();
            data(m);
            _delay_ms(500);
            inp[k]=m;
           
            while((PINA&0X0F)!=0X0F);
            if(k==3)
            {
                if(strcmp(inp,pass)==0)
                {
                    cmd(0x01);
                    cmd(0x80);
                    display("Correct Password");
                    _delay_ms(10);
                }
                else
                {
                    cmd(0x01);
                    cmd(0x80);
                    display("Wrong Password");
                    _delay_ms(10);  
                }
             * */
            /*switch(m)
            {
                case 'b':
                    k=k-2;
                    break;
                case 'c':
                    for(k=0;k<4;k++)
                    {
                        inp[k]=0;
                    }
                    cmd(0x01);
                    break;
                default :
                    m=keypad();  
                    _delay_ms(10);
                    data(m);
                    inp[k]=m;*/
          //  }
            
      //  }
        /*if(k==3)
        {
            if(strcmp(inp,pass)==0)
            {
                cmd(0x01);
                cmd(0x80);
                display("Correct Password");
                _delay_ms(10);
            }
            else
            {
                cmd(0x01);
                cmd(0x80);
                display("Wrong Password");
                _delay_ms(10);  
            }
        }*/

    }
}
