/*****************************************************************************
* | File      	:   DEV_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*----------------
* |	This version:   V2.0
* | Date        :   2019-07-08
* | Info        :   Basic version
*
******************************************************************************/
#include "DEV_Config.h"


static int lcd_fd;
static int led_fd;



#if USE_DEV_LIB
int GPIO_Handle;
int SPI_Handle;
pthread_t *t1;
UWORD pwm_dule=100; // 1040
void *BL_PWM(void *arg){
	UWORD i=0;
	for(i=0;;i++){
		if(i>64)i=0;
		if(i<(pwm_dule/16))lgGpioWrite(GPIO_Handle, 18, LG_HIGH);
		else lgGpioWrite(GPIO_Handle, 18, LG_LOW);	
    }
	
}
#endif

/*****************************************
                GPIO
*****************************************/
void DEV_Digital_Write(UWORD Pin, UBYTE Value)
{
#ifdef USE_WIRINGPI_LIB
    digitalWrite(Pin, Value);

#elif  USE_DEV_LIB  
    lgGpioWrite(GPIO_Handle, Pin, Value);
    
#endif
}

UBYTE DEV_Digital_Read(UWORD Pin)
{
    UBYTE Read_value = 0;
#ifdef USE_WIRINGPI_LIB
    Read_value = digitalRead(Pin);

#elif  USE_DEV_LIB  
    Read_value = lgGpioRead(GPIO_Handle,Pin);

#endif
    return Read_value;
}

void DEV_GPIO_Mode(UWORD Pin, UWORD Mode)
{
#ifdef USE_WIRINGPI_LIB
    if(Mode == 0 || Mode == INPUT){
        pinMode(Pin, INPUT);
        pullUpDnControl(Pin, PUD_UP);
    }else{ 
        pinMode(Pin, OUTPUT);
        // printf (" %d OUT \r\n",Pin);
    }

#elif  USE_DEV_LIB  
    if(Mode == 0 || Mode == LG_SET_INPUT){
        lgGpioClaimInput(GPIO_Handle,LFLAGS,Pin);
        // printf("IN Pin = %d\r\n",Pin);
    }else{
        lgGpioClaimOutput(GPIO_Handle, LFLAGS, Pin, LG_LOW);
        // printf("OUT Pin = %d\r\n",Pin);
    }

#endif   
}

/**
 * delay x ms
**/
void DEV_Delay_ms(UDOUBLE xms)
{
#ifdef USE_WIRINGPI_LIB
    delay(xms);

#elif  USE_DEV_LIB  
    lguSleep(xms/1000.0);

#endif
}

/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE DEV_Module_Init(void)
{

 #ifdef USE_WIRINGPI_LIB  
    //if(wiringPiSetup() < 0)//use wiringpi Pin number table  
    if(wiringPiSetupGpio() < 0) { //use BCM2835 Pin number table
        DEBUG("set wiringPi lib failed	!!! \r\n");
        return 1;
    } else {
        DEBUG("set wiringPi lib success  !!! \r\n");
    }

#elif  USE_DEV_LIB
    char buffer[NUM_MAXBUF];
    FILE *fp;

    fp = popen("cat /proc/cpuinfo | grep 'Raspberry Pi 5'", "r");
    if (fp == NULL) {
        DEBUG("It is not possible to determine the model of the Raspberry PI\n");
        return -1;
    }

    if(fgets(buffer, sizeof(buffer), fp) != NULL)  
    {
        GPIO_Handle = lgGpiochipOpen(4);
        if (GPIO_Handle < 0)
        {
            DEBUG( "gpiochip4 Export Failed\n");
            return -1;
        }
    }
    else
    {
        GPIO_Handle = lgGpiochipOpen(0);
        if (GPIO_Handle < 0)
        {
            DEBUG( "gpiochip0 Export Failed\n");
            return -1;
        }
    }
	
#endif
    return 0;
}

/**
 * SPI
**/
void DEV_SPI_WriteByte(uint8_t Value)
{
#ifdef USE_WIRINGPI_LIB
    wiringPiSPIDataRW(0,&Value,1);

#elif  USE_DEV_LIB 
    lgSpiWrite(SPI_Handle,(char*)&Value, 1);
    
#endif
}

void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
#ifdef USE_WIRINGPI_LIB
    wiringPiSPIDataRW(0, (unsigned char *)pData, Len);

#elif  USE_DEV_LIB 
    lgSpiWrite(SPI_Handle,(char*) pData, Len);

#endif
}

/**
 * I2C
**/
void DEV_I2C_Init(uint8_t LCD_Add, uint8_t LED_Add)
{
#ifdef USE_WIRINGPI_LIB
    printf("WIRINGPI I2C Device\r\n");       
    lcd_fd = wiringPiI2CSetup(LCD_Add);
    led_fd = wiringPiI2CSetup(LED_Add);
#elif  USE_DEV_LIB 
    printf("LGPIO I2C Device\r\n");       
    lcd_fd = lgI2cOpen(1,LCD_Add,0);
    led_fd = lgI2cOpen(1,LED_Add,0);
#endif
}

void DEV_I2C_Write(uint8_t addr, uint8_t reg, uint8_t Value)
{
#ifdef USE_WIRINGPI_LIB
    if (addr == 0x6B)
        wiringPiI2CWriteReg8(led_fd, (int)reg, (int)Value);
    else
        wiringPiI2CWriteReg8(lcd_fd, (int)reg, (int)Value);
#elif  USE_DEV_LIB  
    if (addr == 0x6B)
        lgI2cWriteByteData(led_fd, (int)reg, (int)Value);
    else
        lgI2cWriteByteData(lcd_fd, (int)reg, (int)Value);
#endif
}

void DEV_I2C_Write_nByte(uint8_t addr, uint8_t *pData, uint32_t Len)
{
#ifdef USE_WIRINGPI_LIB
    for (int i = 0; i < Len; i++)
    {
        wiringPiI2CWrite(lcd_fd, pData[i]); 
    }
#elif  USE_DEV_LIB 
    lgI2cWriteDevice(lcd_fd,(const char *)pData,Len);
#endif
}

uint8_t DEV_I2C_ReadByte(uint8_t addr, uint8_t reg)
{
    uint8_t buf;
#ifdef USE_WIRINGPI_LIB
    if (addr == 0x6B)
        buf = wiringPiI2CReadReg8(led_fd, (int)reg);
    else
        buf = wiringPiI2CReadReg8(lcd_fd, (int)reg);
    
#elif  USE_DEV_LIB 
    if (addr == 0x6B)
        buf = lgI2cReadByteData(led_fd, (int)reg);
    else
        buf = lgI2cReadByteData(lcd_fd, (int)reg);
#endif
    return buf;
}


/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void DEV_Module_Exit(void)
{
#ifdef USE_WIRINGPI_LIB

#elif USE_DEV_LIB 

#endif
}