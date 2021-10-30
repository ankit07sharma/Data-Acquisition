#include"header.h"
typedef struct rtc
{
	u8 min,sec,hr,day,date,month,year;
}RTC;
void RTC_CONTEXT()
{
	RTC m1;
		m1.hr=i2c_byte_read_frame(0xD0,0x2);
		uart_tx((m1.hr/10)+48);
		uart_tx((m1.hr%10)+48);
		uart_tx(':');
		m1.min=i2c_byte_read_frame(0xD0,0x1);
		uart_tx(m1.min/16+48);
		uart_tx((m1.min%16)+48);
		uart_tx(':');
		m1.sec=i2c_byte_read_frame(0xD0,0x0);
		uart_tx((m1.sec/16)+48);
		uart_tx((m1.sec%16)+48);
	  uart_tx_string("  Day-");
	  m1.day=i2c_byte_read_frame(0xD0,0x03);
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
   uart_tx_string("\n\r");
	 uart_tx_string("Date-");
 	 m1.date=i2c_byte_read_frame(0xD0,0x4);   //date
	 m1.month=i2c_byte_read_frame(0xD0,0x5);   //month
	 m1.year=i2c_byte_read_frame(0xD0,0x6);   //year
	 uart_tx((m1.date/16)+48);
	 uart_tx((m1.date%16)+48);
	 uart_tx('/');
	 uart_tx((m1.month/10)+48);
	 uart_tx((m1.month%10)+48);
	 uart_tx('/');
	 uart_tx((m1.year/16)+48);
	 uart_tx((m1.year%16)+48);
}
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