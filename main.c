//This is the main function which will call all the driver function here in infinite loop

#include"header.h"
void main()
{
u16 buf,buf2,speed;
//float t;
UART_INIT(9600);
RTC_TIMESET();
while (1)
{
uart_tx_string("\n\r");
RTC_CONTEXT();
uart_tx_string("\n\r"); 
buf=ADC_READING(1,0);
buf2=ADC_READING(0,0); 
buf2=(buf2*5.0)/4095;
speed=ADC_READING(0,1);
speed=(speed*120)/4095;
uart_tx_string("LDR SENSOR OUTPUT\n\r");
uart_tx_string("Light intensity-");
buf=(buf/4095.0)*100;
uart_tx_int(buf);
uart_tx('%');
uart_tx_string("\n\r\n");
uart_tx_string("Output in voltage\n\r");
uart_tx_string("Voltage:-");
uart_tx_float(buf2);
uart_tx_string("\n\r\n");
uart_tx_string("Speed of Car\n\r");
uart_tx_string("Speed:-");
uart_tx_int(speed);
uart_tx_string ("K/hr\n\r"); 
delayms(200);
}
}
