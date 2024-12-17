/*
 * File:   HW_LCD_MTOR_PWM_ADC.c
 * Author: ASUS
 *
 * Created on September 30, 2024, 11:32 AM
 */


#include <xc.h>
#include<stdio.h>
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);
void motor1(int,int);
void motor2(int,int);
void delay(long int);
void main(void) 
{
    TRISC=0x60;
    TRISD=0x00;
     TRISA=0xff;
     TRISB=0x00;
    lcdctrl(0x01);
    lcdctrl(0x0f);
    lcdctrl(0x38);
    T2CON=0x06;
    ADCON0=0x01;
    ADCON1=0X00;
    ADCON2=0x86;
    int c1=-1;
    int adc;
    char chr[15];
    CCP1CON=0x0C;
    while(1)
    {
       GO=1;
       while(ADIF==0);
       ADIF=0;
       adc=ADRES;
       sprintf(chr,"ADC value %4d",adc);
       lcdctrl(0x80);
       lcdstring(chr);
       CCPR1L=adc;
       
        if(RC5==1)
        {            
            if(c1==2)
            {
                c1=-1;
            }
            c1++;
            delay(10000);
            while(RC5==1);
        if(c1==0){
            
            motor1(0,1);
            lcdctrl(0xC0);
            lcdstring("clockwise>>      ");
        }
        else if(c1==1){
            
            motor1(1,0);
            lcdctrl(0xC0);
            lcdstring("anticlockwise<<");
        }
        else if(c1==2){
            
            motor1(0,0);
            lcdctrl(0xC0);
            lcdstring("stop!!         "); 
        }  
        }
       
   
} return;
}

void motor1(int m,int n){
    RB6=m;
    RC4=n;
  

}
/*void motor2(int x,int y){
    RB7=x;
    RB6=y;
}*/
void delay(long int time){
    for(long int i=0;i<time;i++);
}
void lcdctrl(unsigned char a)
{
    RC0=0;
    PORTD=a;
    RC1=1;
    delay(100);
    RC1=0;
    
    delay(5000);
}
void lcddisp(unsigned char a)
{
    RC0=1;
    PORTD=a;
    RC1=1;          //since the enable Rs bit should be 1 and since not bit addressible both enable and Rs bit turned on portc=0000 0011
    delay(100);
    RC1=0;        // here only the enable bit should only be turned off so 0000 0001
    delay(2000);
    
}
void lcdstring(const char *p){
    while(*p)
    { 
        lcddisp(*p);
        p++;
    }
}
