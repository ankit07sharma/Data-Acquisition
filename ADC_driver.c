#include<reg51.h>
#include"header.h"
sbit CLK=P2^3;
sbit DIN=P2^2;
sbit DOUT=P2^1;
sbit CS=P2^0;
u16 ADC_READING(bit d1, bit d2)
{
	s8 i;
	u16 temp=0;
	CS=0;
	CLK=0;   DIN=1;   CLK=1;
	CLK=0;   DIN=1;   CLK=1;
	CLK=0;   DIN=1;   CLK=1;
	CLK=0;   DIN=d1;  CLK=1;
	CLK=0;   DIN=d2;  CLK=1;
	CLK=0;   CLK=1;
	CLK=0;   CLK=1;
	for(i=11;i>=0;i--)
	{
		CLK=0;
		if(DOUT==1)
			temp|=(1<<i);
		CLK=1;
	}
	CS=1;
	return temp;
}