#ifndef __Waveshare_LCD1602_H__
#define __Waveshare_LCD1602_H__

#include "DEV_Config.h"

/*!
 *   LCD1602 Device I2C Arress
 */
#define LCD_ADDRESS     (0x7c>>1)

/*!
 *   commands
 */
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

/*!
 *   flags for display entry mode
 */
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

/*!
 *   flags for display on/off control
 */
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

/*!
 *   flags for display/cursor shift
 */
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

/*!
 *   flags for function set
 */
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x8DOTS 0x00

/*!
 *   LED Device I2C Arress
 */
// SN3193 Backlight control
#define SN3193_IIC_ADDRESS  0x6B  // SN3193 I2C address

// SN3193 Register definitions
#define SHUTDOWN_REG  0x00  // Set software shutdown mode
#define BREATING_CONTROL_REG  0x01  // Set breathing function
#define LED_MODE_REG  0x02  // Set operation mode
#define LED_NORNAL_MODE  0x00  // Normal mode
#define LED_BREATH_MODE  0x20  // Breathing mode

#define CURRENT_SETTING_REG  0x03  // Set output current
#define PWM_1_REG  0x04  // 3 channels PWM duty cycle data
#define PWM_2_REG  0x05  // 3 channels PWM duty cycle data
#define PWM_3_REG  0x06  // 3 channels PWM duty cycle data
#define PWM_UPDATE_REG  0x07  // Load PWM registers and LED control register data

#define T0_1_REG  0x0A  // Set T0 time for OUT1
#define T0_2_REG  0x0B  // Set T0 time for OUT2
#define T0_3_REG  0x0C  // Set T0 time for OUT3

#define T1T2_1_REG  0x10  // Set T1&T2 time for OUT1
#define T1T2_2_REG  0x11  // Set T1&T2 time for OUT2
#define T1T2_3_REG  0x12  // Set T1&T2 time for OUT3

#define T3T4_1_REG  0x16  // Set T3&T4 time for OUT1
#define T3T4_2_REG  0x17  // Set T3&T4 time for OUT2
#define T3T4_3_REG  0x18  // Set T3&T4 time for OUT3

#define TIME_UPDATE_REG  0x1C  // Load time register data
#define LED_CONTROL_REG  0x1D  // Enable OUT1~OUT3
#define RESET_REG  0x2F  // Reset all registers to default values

	
void LCD1602_init(uint8_t cols, uint8_t rows);
void LCD1602_display();
void LCD1602_command(uint8_t value);
void LCD1602_setCursor(uint8_t col, uint8_t row);
void LCD1602_clear();
void LCD1602_data(uint8_t value);
void LCD1602_send_string(const char *str);
void LCD1602_noCursor();
void LCD1602_cursor();
void LCD1602_scrollDisplayLeft();
void LCD1602_scrollDisplayRight();
void LCD1602_leftToRight();
void LCD1602_rightToLeft();
void LCD1602_noAutoscroll();
void LCD1602_autoscroll();
void LCD1602_createChar(uint8_t location, uint8_t charmap[]);

//SN3193
void LCD1602_led_init();
void LCD1602_set_brightness(uint8_t value);
void LCD1602_set_led_mode(uint8_t mode);

#endif