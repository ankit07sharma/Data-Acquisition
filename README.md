# DatabAcquisition

The Task of this project is to send the below sensor's data to system.
->Light intensity percentage.
->Speedo meter which will tell speed in between 0-120.
->output voltage value of potentiometer.

Additional Task
---------------
->Send a entry time too.
->And a new entry should come in every one second.

Hardware component->8051 8-bit microcontroller, UART(To establish a connection between system and microcontroller, RTC(Real time clock), I2C Protocol(to interface
RTC with microcontroller), LDR, Speedo meter, Potentiometer, ADC(the all sensor will give analog output), SPI Protocol(to interface ADC to microcontroller)

NOTES
-----
->I2C is implemented using Bit and banging method because 8051 has no inbuilt I2C pheripheral.
->12 Bit ADC is used in this project so it will give 4095 sample in one sec.,so further i used this value to map it according to our measurment scale.
