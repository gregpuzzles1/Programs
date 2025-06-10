# Waveshare LCD1602 I2C Module

- [中文版](./README_CN.md)

If you are used to the traditional LCD1602 screens, try our I2C communication LCD1602 screen. Compared with the traditional one, it uses fewer pins and is easier to operate.

# Product Link(https://www.waveshare.com/lcd1602-i2c-module.htm)

    SKU：23991

# Directory Overview
* examples: Example source code files
* lib: LCD1602 driver files

# Overview

The Waveshare LCD1602 I2C Module features an LCD screen with various backlight colors and can display 2x16 characters. It supports screen scrolling, cursor movement, backlight brightness adjustment, and more.

# Hardware connection
LCD1602 	-> Arduino UNO R3/R4/Mega2560

VCC 	-> 3V3
GND  	-> GND
SCL 	-> SCL
SDA 	-> SDA

LCD1602 	-> Pico/Pico w/Pico2/Pico2 w/ESP32S3

VCC 	-> 3V3
GND  	-> GND
SCL 	-> GP5
SDA 	-> GP4

# Driver Installation

First download the example file, copy and paste Waveshare_LCD1602 from the arduino example into the \Arduino\libraries directory, then open the examples folder and run the demo inside that folder.

# Function Descriptions

```C++

    /**
   *  @brief Initialize the LCD and the main IIC control.
   */ 
  void init();

  /**
   *  @brief Turn on the display.
   */
  void display();

  /**
   *  @brief Send command to the LCD.
   *  @param data The command to be sent.
   */
  void command(uint8_t data);

  /**
   *  @brief Transfer data.
   *  @param data The data to be transferred.
   *  @param len The length of the data.
   */
  void lcd_send(uint8_t *data, uint8_t len);

  /**
   *  @brief Set the cursor position.
   *  @param col The column (range: 0-15, maximum 39; characters beyond 15 need to be scrolled to be observed).
   *  @param row The row (range: 0-1, where 0 represents the first row, and 1 represents the second row).
   */
  void setCursor(uint8_t col, uint8_t row);

  /**
   *  @brief Clear the display and return the cursor to the initial position (0, 0).
   */
  void clear();

  /**
   *  @brief Write data.
   *  @param value The data to be written.
   */
  void data(uint8_t value);

  /**
   *  @brief Display a string.
   *  @param str The string to be displayed.
   */
  void send_string(const char *str);

  /**
   *  @brief Turn off the underscore cursor.
   */
  void noCursor();

  /**
   *  @brief Turn on the underscore cursor.
   */
  void cursor();

  /**
   *  @brief Scroll the display to the left.
   */
  void scrollDisplayLeft();

  /**
   *  @brief Scroll the display to the right.
   */
  void scrollDisplayRight();

  /**
   *  @brief Make text flow from left to right.
   */
  void leftToRight();

  /**
   *  @brief Make text flow from right to left.
   */
  void rightToLeft();

  /**
   *  @brief Align the text to the left starting from the cursor position.
   */
  void noAutoscroll();

  /**
   *  @brief Align the text to the right starting from the cursor position.
   */
  void autoscroll();

  /**
   *  @brief Allows filling custom characters in the first 8 CGRAM positions.
   *  @param location The location of the custom character (range: 0-7).
   *  @param charmap The character array (size 8 bytes).
   */
  void createChar(uint8_t location, uint8_t charmap[]);

  /**
   *  @brief Send command and data to the LCD.
   *  @param cmd The register address.
   *  @param data The value to configure.
   */
  void led_send(uint8_t cmd, uint8_t data);

  /**
   *  @brief Set the backlight brightness.
   *  @param value The brightness level (range: 0-100).
   */
  void set_brightness(uint8_t value);

  /**
   *  @brief Set the backlight mode.
   *  @param mode 0x00 for normal mode, 0x20 for breathing mode.
   */
  void set_led_mode(uint8_t mode);

```

## Compatibility

| Board     | Work Well | Work Wrong | Untested | Remarks |
| ---------	|  :-------:  |  :-------: |  :-------:  |  :-------:  |
| Pico 	            |     √     |           |        |         	|
| Pico w	        |     √  	|           |        |         	|
| pico 2	        |     √    	|           |        |         	|
| pico 2w	        |     √    	|           |        |         	|
| Arduino UNO R3 	|     √     |           |        |         	|
| Arduino UNO R4	|     √  	|           |        |         	|
| Arduino Mega 2560	|     √    	|           |        |         	|
| ESP32S3         	|     √    	|           |        |         	|

## History

- Date 2025-01-03
- Version V1.0.0
