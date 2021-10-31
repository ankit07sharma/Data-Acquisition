#include"header.h"

//This Function will write one byte to specified memory address in RTC
void i2c_byte_write_frame(u8 sa,u8 mem,u8 d)
{
	bit ret;
	i2c_start();                     //Start bit to take put attention to all slave
	i2c_write(sa);                   //write slave address with write bit
        ret=i2c_ack();                   //the matched slave will give acknowlegement
	if(ret==1)
		goto end;
	i2c_write(mem);                  //write slave specified memory location 
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_write(d);                    //write one byte data to that specified address
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	end: 
	i2c_stop();                      // stop bit which will leave the i2c bus to idle state
}

//This fuction will read one byte at a time from specified memory location of RTC
//Here we used our i2c field  
u8 i2c_byte_read_frame(u8 sa,u8 mem)
{
	bit ret;
	u8 temp;
	i2c_start();                     //Start bit to take put attention to all slave
	i2c_write(sa);                   //write slave address with write bit
	 ret=i2c_ack();                  //the matched slave will give acknowlegement
	if(ret==1)
		goto end;
	i2c_write(mem);                  //write slave specified memory location 
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_start();                     //Again Start bit
	i2c_write(sa|1);                 //write slave address with read bit 
 	 ret=i2c_ack();
	if(ret==1)
		goto end;
	temp=i2c_read();                 //To read one byte from specified location
  i2c_noack();
	end:
	i2c_stop();                      // stop bit which will leave the i2c bus to idle state
	return temp;
}


//Function to create software delay in mili second
void delayms(u16 a)
{
	u8 i;
	for(;a>0;a--)
	{
		i=250;
		while(i--);
		i=247;
		while(i--);
	}

}
