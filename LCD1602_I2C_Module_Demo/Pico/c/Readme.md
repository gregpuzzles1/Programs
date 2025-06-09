# Waveshare LCD1602 I2C Module

- [中文版](./README_CN.md)

If you're used to the traditional LCD1602 display, give our I2C communication-based LCD1602 module a try. It uses fewer pins and is easier to operate compared to the traditional version.


# Product Link(https://www.waveshare.com/lcd1602-i2c-module.htm)

    SKU：23991

# Directory Overview
* examples: Example source code files
* lib: LCD1602 driver files

# Overview

The Waveshare LCD1602 I2C Module features an LCD screen with various backlight colors and can display 2x16 characters. It supports screen scrolling, cursor movement, backlight brightness adjustment, and more.

# Hardware connection
LCD1602 	-> Pico/Pico w/Pico2/Pico2 W

VCC 	-> 3V3
GND  	-> GND
SCL 	-> GP5
SDA 	-> GP4

# Driver Installation

# Function Descriptions

```C++

  /**
   *  @brief Initialize the LCD screen
   *  @param cols Number of columns (currently not functional)
   *  @param rows Number of rows
   */ 
  void LCD1602_init(uint8_t cols, uint8_t rows);

  /**
   *  @brief Turn on the display
   */
  void LCD1602_display();

  /**
   *  @brief Send a command to the LCD
   *  @param value The command to send
   */
  void LCD1602_command(uint8_t value);

  /**
   *  @brief Set the cursor position
   *  @param col Column number. Valid range is 0-15, up to 39; columns greater than 15 require scrolling
   *  @param row Row number. Valid range is 0-1, where 0 represents the first row and 1 represents the second row
   */
  void LCD1602_setCursor(uint8_t col, uint8_t row);
  
  /**
   *  @brief Clear the display and reset the cursor to position 0
   */
  void LCD1602_clear();

  /**
   *  @brief Write data to the display
   *  @param value The data to write
   */
  void LCD1602_data(uint8_t value);

  /**
   *  @brief Display a string
   *  @param str The string to display
   */
  void LCD1602_send_string(const char *str);

  /**
   *  @brief Disable the underscore cursor
   */
  void LCD1602_noCursor();

  /**
   *  @brief Enable the underscore cursor
   */
  void LCD1602_cursor();

  /**
   *  @brief Scroll the display to the left
   */
  void LCD1602_scrollDisplayLeft();

  /**
   *  @brief Scroll the display to the right
   */
  void LCD1602_scrollDisplayRight();
 
  /**
   *  @brief Make the text flow from left to right on the display
   */
  void LCD1602_leftToRight();
 
  /**
   *  @brief Make the text flow from right to left on the display
   */
  void LCD1602_rightToLeft();

  /**
   *  @brief Disable auto-scrolling (text will not shift as new text is added)
   */
  void LCD1602_noAutoscroll();
 
  /**
   *  @brief Enable auto-scrolling (text will shift as new text is added)
   */
  void LCD1602_autoscroll();
   
  /**
   *  @brief Allows us to fill custom characters in the first 8 CGRAM (Character Generator RAM) locations
   *  @param location The location for the custom character (range 0-7)
   *  @param charmap The character array, size 8 bytes
   */
  void LCD1602_createChar(uint8_t location, uint8_t charmap[]);
  
  /**
   *  @brief Initialize the backlight chip
   */
  void LCD1602_led_init();

  /**
   *  @brief Set the backlight brightness
   *  @param value The brightness value, range (0-100)
   */
  void LCD1602_set_brightness(uint8_t value);

  /**
   *  @brief Set the backlight mode
   *  @param mode 0x00 for normal mode, 0x20 for breathing mode
   */
  void LCD1602_set_led_mode(uint8_t mode);

```

# Compatibility

| Board     | Work Well | Work Wrong | Untested | Remarks |
| ---------	|  :-------:  | :-------: | :-------: | :-------: |
| Pico 	    |      √      |           |         	|         	|
| Pico w	  |      √  	  |           |           |         	|
| pico 2	  |      √    	|           |        	  |         	|
| pico 2w	  |           	|           |     √ 	  |         	|


# History

- 日期 2025-01-03
- 版本 V1.0.0

