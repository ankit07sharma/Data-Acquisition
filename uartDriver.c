
//UART will send data of sensor from microcontroller to serial terminal on system

#include<reg51.h>
#include"header.h"


//This function will set the buadrate and initiliaze the UART to use it
void UART_INIT(u16 baud)
{	
	SCON=0x50;                                               //it will set the UART in universal mode
	TMOD|=0x20;                                              //Timer1 should be in MODE2
	switch(baud)
	{
		case 7200:TH1=252;break;
		case 9600:TH1=253;break;
		case 14400:TH1=254;break;
		case 28800:TH1=255;break;
		case 57600:TH1=255;PCON|=0x80;break;
		default:TH1=253;
	}
	TR1=1;                                                  //start baud setting
}


//This Function will transmit the one byte
void uart_tx(u8 d)
{
	SBUF=d;
	while(TI==0);
	TI=0;
}


//This Function will transmit the string
void uart_tx_string(u8 *arr)
{
	while(*arr!=0)
	{
	        SBUF=*arr;
	 	while(TI==0);
		TI=0;
		arr++;
	}
}


//This Function will reverse the string
void my_strrev(u8 *s)
{
	u8 *t=s,i,l=0,temp;
	while(*t)
	{
		l++;
		t++;
	}
	for(i=0,l=l-1;i<l;i++,l--)
	{
		temp=s[i];
		s[i]=s[l];
		s[l]=temp;
	}
}
	

//This Function will transmit integer number
void uart_tx_int(s16 t)
{
	u8 s[7],i=0;
	if(t!=0)
	{
	if(t<0)
		s[i++]='-';
	while(t)
	{
		s[i]=t%10+48;
		t=t/10;
		i++;
	}
	s[i]='\0';
	my_strrev(s);
	uart_tx_string(s);
}
	else
		uart_tx('0');
}



//This Function will transmit the float number 
void uart_tx_float(float t)
{
s8 i;
if(a!=0)
{
	if(a<0)
	{
		uart_tx('-');
		a=-a;
	}
	i=a;
	uart_tx_int(i);
	uart_tx('.');
	i=(a-i)*10;
	uart_tx_int(i);
}
else
	uart_tx('0');
}

