//I2c implemented using Bit and Banging becuase 8051 has no inbuilt pheripherial for i2c
//In this file i defined all fields of i2c which will be used in reading and writing frame for one btye

#include<reg51.h>
#include<intrins.h>
#include"header.h"
sbit SDA=P1^4;                               //i2c interface pin
sbit SCL=P1^5;                               //i2c interface pin

//Fuction for start bit
void i2c_start()
{ 
  SCL=1;                                    //idle condition  optional
  SDA=1;   	                            //idle condition   optional


  SCL=1;
  SDA=1;                                     //SDA will become high to low when SCL is high
  SDA=0;
}

//Function for stop bit
void i2c_stop()
	
{
	SCL=0;
	SDA=0;
	SCL=1;                               //SDA become low to high when SCL is high
	SDA=1;
}


//Fuction to write one byte on i2c bus
void i2c_write(u8 d)
{
s8 i;
	for(i=7;i>=0;i--)
	{
		SCL=0;                       //Master will write when SCL is low           
		SDA=(d>>i)&1;                //one bit writen to SDA line
		SCL=1;                       //Slave will read when SCL is high
	}
}


//Function to read one byte from i2c bus
u8 i2c_read()
{
	s8 i;
	u8 temp=0;
	for(i=7;i>=0;i--)
	{
		SCL=1;                      //Slave will write one bit on i2c bus when SCL is low and master will read one bit from i2c when SCL is low 
		if(SDA==1)
			temp|=(1<<i);
		SCL=0;
	}
	return temp;
}

//Function which will give ack to master
bit i2c_ack()
{
	SCL=0;                             //On 9th clock pulse slave will give ack
	SDA=1;	                           //compalsary
	SCL=1;
	_nop_();                           //delay 1 microsecond
	_nop_();
	_nop_();
	_nop_();
	if(SDA==0)
	{
		SCL=0;
	return 0;
	}
	else{
		SCL=0;
		return 1;
	}
	
}

//Fuction which will given by master after reading one byte
void i2c_noack()
{
	SCL=0;
	SDA=1;
	SCL=1;
}
