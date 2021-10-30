#include"header.h"
void i2c_byte_write_frame(u8 sa,u8 mem,u8 d)
{
	bit ret;
	i2c_start();
	i2c_write(sa);
  ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_write(mem);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_write(d);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	end: 
	i2c_stop();
}
u8 i2c_byte_read_frame(u8 sa,u8 mem)
{
	bit ret;
	u8 temp;
	i2c_start();
	i2c_write(sa);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_write(mem);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_start();
	i2c_write(sa|1);                   //with read bit 
 	 ret=i2c_ack();
	if(ret==1)
		goto end;
	temp=i2c_read();
  i2c_noack();
	end:
	i2c_stop();
	return temp;
}
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