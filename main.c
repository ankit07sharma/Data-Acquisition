//This is the main function which will call all the driver function here in infinite loop

#include"header.h"
void main()
{
s16 buf,speed;
u16 buf2;
float t;
UART_INIT(9600);
RTC_TIMESET();
while (1)
{
uart_tx_string("\n\r");
RTC_CONTEXT();
uart_tx_string("\n\r"); 
  
  
uart_tx_string("LDR SENSOR OUTPUT\n\r");
uart_tx_string("Light intensity-");
buf=ADC_READING(1,0);  
buf=(buf/4095.0)*100;  
uart_tx_int(100-buf);
uart_tx_string("%\n\r\n");
delayms(100);

  
uart_tx_string("Output in voltage\n\r");
uart_tx_string("Voltage:-");  
buf2=ADC_READING(0,0); 
if(buf2!=0)
{
  t=(buf2*5.0)/4095;
  uart_tx_float(t);
}
else
uart_tx_string("0.0");   
uart_tx_string("\n\r\n");
delayms(100);  
  
  
uart_tx_string("Speed of Car\n\r");
uart_tx_string("Speed:-");  
speed=ADC_READING(0,1);
speed=(speed*120.0)/4095;
uart_tx_int(speed);
uart_tx_string ("K/hr\n\r"); 
delayms(400);
}  
}
