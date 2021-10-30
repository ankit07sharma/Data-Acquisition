//Typedef's
typedef unsigned char u8;
typedef  char s8;
typedef unsigned int  u16;
typedef  int  s16;

//Delay Function Prototype
extern void delayms(u16 a);

//Uart Function Prototype
extern void UART_INIT(u16 );
extern void uart_tx(u8);
extern void uart_tx_string(u8 *);
extern void uart_tx_int(s16 );
extern void uart_tx_float(float );

//I2C Function Prototype
extern void i2c_start();
extern void i2c_stop();
extern void i2c_write(u8);
extern u8 i2c_read();
extern bit i2c_ack();
extern u8 i2c_byte_read_frame(u8 ,u8 );
extern void i2c_byte_write_frame(u8,u8,u8);
extern void i2c_noack();

//RTC function Prototype
extern void RTC_CONTEXT();
extern void RTC_TIMESET();

//ADC Function Prototype
extern u16 ADC_READING(bit, bit);