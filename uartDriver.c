#include<reg51.h>
#include"header.h"
void UART_INIT(u16 baud)
{	
	SCON=0x50;
	TMOD|=0x20;
	switch(baud)
	{
		case 7200:TH1=252;break;
		case 9600:TH1=253;break;
		case 14400:TH1=254;break;
		case 28800:TH1=255;break;
		case 57600:TH1=255;PCON|=0x80;break;
		default:TH1=253;
	}
	TR1=1;//start baud setting
}
void uart_tx(u8 d)
{
	SBUF=d;
	while(TI==0);
	TI=0;
}
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
void uart_tx_float(float t)
{
float temp;
u16 a;
u16 b=1;
if(t==0)
{
	uart_tx_string("0.0");
	return;
}
if(t<0)
{
uart_tx('-');
t=-t;
}	
a=t;
uart_tx_int(a);
uart_tx('.');
temp=t-a;
  if(temp>0)
	while(b)
	{
    if(1>(temp*10))
		a=0;
    else 
		a=temp*10;
		uart_tx(a+48);
		if(a==0)
		temp=temp*100;
		else
		temp=temp*10-a;
		if(temp==0.0)
			b=0;
	}
	else
		uart_tx(48);
}
