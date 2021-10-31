//RTC will provide current time to every entry. I used two protocol here in this code one is UART which will send data to serial terminal in system and 
//secod protocol is I2C which is used by microcontroller to read and write in RTC. 

//NOTE- I used DS1307 64 byte storage RTC here in this project.    SLAVE ADDRESS- 11010000,the 8th bit is for write(0) and read(1)

#include"header.h"
//Structure for RTC context
typedef struct rtc
{
	u8 min,sec,hr,day,date,month,year;
}RTC;

//Fuction which will read data from RTC and send data to system. 
void RTC_CONTEXT()
{
	RTC m1;
	m1.hr=i2c_byte_read_frame(0xD0,0x2);         //To read hour, 0x2 is memory location in RTC where hour is storred
	uart_tx((m1.hr/10)+48); 
	uart_tx((m1.hr%10)+48);                      //To send hour to system
	uart_tx(':');
	m1.min=i2c_byte_read_frame(0xD0,0x1);        //To read minute
	uart_tx(m1.min/16+48);
	uart_tx((m1.min%16)+48);                     //To send minute to system
	uart_tx(':');
	m1.sec=i2c_byte_read_frame(0xD0,0x0);        //To read second
	uart_tx((m1.sec/16)+48);
	uart_tx((m1.sec%16)+48);                     //To send second to system
	uart_tx_string("  Day-");
	m1.day=i2c_byte_read_frame(0xD0,0x03);       //RTC will give 1-7 as day, reading day
	switch(m1.day)
  	{
			case 1:uart_tx_string("Sun");break;
			case 2:uart_tx_string("Mon");break;
			case 3:uart_tx_string("Tus");break;
			case 4:uart_tx_string("Wed");break;
			case 5:uart_tx_string("Thu");break;
			case 6:uart_tx_string("Fri");break;
			case 7:uart_tx_string("Sat");break;
	 }
         uart_tx_string("\n\r");                    //Next line
	 uart_tx_string("Date-");
 	 m1.date=i2c_byte_read_frame(0xD0,0x4);     //To read date
	 m1.month=i2c_byte_read_frame(0xD0,0x5);    //To read month
	 m1.year=i2c_byte_read_frame(0xD0,0x6);     //To read year
	 uart_tx((m1.date/16)+48); 
	 uart_tx((m1.date%16)+48);                  //Send date to system
	 uart_tx('/');
	 uart_tx((m1.month/10)+48);
	 uart_tx((m1.month%10)+48);                 //Send month to system   
	 uart_tx('/');
	 uart_tx((m1.year/16)+48);                  //Send year to system
	 uart_tx((m1.year%16)+48);
}

//This Function will write/update RTC context
void RTC_TIMESET()
{
	i2c_byte_write_frame(0xD0,0x0,0x00);   //sec
	i2c_byte_write_frame(0xD0,0x1,0x00);   //min
	i2c_byte_write_frame(0xD0,0x2,0x09);   //hr
	i2c_byte_write_frame(0xD0,0x3,0x03);   //day
	i2c_byte_write_frame(0xD0,0x4,0x05);   //date
	i2c_byte_write_frame(0xD0,0x5,0x0A);   //month
	i2c_byte_write_frame(0xD0,0x6,0x21);   //year
}
