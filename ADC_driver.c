//ADC is to used to convert analog value to digital value. I used MCP3204 ADC which is a 12 bit ADC and it has 4 channels i used 3 channels, and it is SPI based. 

#include<reg51.h>
#include"header.h"
sbit CLK=P2^3;                         //SPI interface
sbit DIN=P2^2;                         //(MISO)SPI interface
sbit DOUT=P2^1;                        //(MOSI)SPI interface
sbit CS=P2^0;                          //SPI interface,helps to identify slave

//Function which will return the 12 bit data of sensor output
u16 ADC_READING(bit d1, bit d2)                                             //It has two argument for channel or sensor identifiction
{
	s8 i;
	u16 temp=0;
	CS=0;                                                              //CS is low means now communication started
	CLK=0;   DIN=1;   CLK=1;
	CLK=0;   DIN=1;   CLK=1;
	CLK=0;   DIN=1;   CLK=1;
	CLK=0;   DIN=d1;  CLK=1;                                           //In 4th and 5th clock pulse we have to send channel bit ,like 0,0(chn-1), 0,1(chn-2)
	CLK=0;   DIN=d2;  CLK=1;
	CLK=0;   CLK=1;
	CLK=0;   CLK=1;
	for(i=11;i>=0;i--)                                                 //sensor will give from 8th clock pulse
	{
		CLK=0;
		if(DOUT==1)
			temp|=(1<<i);
		CLK=1;
	}
	CS=1;
	return temp;                                                       // Returning 12 bit sesnor output
}
