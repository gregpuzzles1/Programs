# Waveshare LCD1602 I2C Module

- [English Version](./README.md)

用惯了传统的的LCD1602液晶屏，来尝试一下我们的I2C通信的LCD1602屏吧，对比传统的占用引脚更少，操作更简单


#产品链接(https://www.waveshare.net/shop/LCD1602-I2C-Module.htm)

    SKU：23991

#目录介绍
* examples：示例源码文件
* ib：LCD1602驱动文件

# 概述

 Waveshare LCD1602 I2C Module 多种背光颜色液晶屏可以显示2x16个字符，支持屏幕滚动，光标移动，背光亮度调节等功能

# 硬件连接
LCD1602 	-> Pico/Pico w/Pico2/Pico2 W

VCC 	-> 3V3
GND  	-> GND
SCL 	-> GP5
SDA 	-> GP4

# 驱动安装

# 函数介绍

```C++

  /**
   *  @brief 液晶屏初始化
   *  @param cols 列数量（暂时无功能）
   *  @param rows 行数量
   */ 
  void LCD1602_init(uint8_t cols, uint8_t rows);

  /**
   *  @brief 打开显示
   */
  void LCD1602_display();

  /**
   *  @brief send command
   *  @param value 发送的命令
   */
  void LCD1602_command(uint8_t value);

  /**
   *  @brief 设置光标位置
   *  @param col 列数 可选范围 0-15 最大为39，需要移动才能观察到大于15的字符
   *  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
   */
  void LCD1602_setCursor(uint8_t col, uint8_t row);
  
  /**
   *  @brief 清除显示并将光标回到初始位置（0位置）
   */
  void LCD1602_clear();

  /**
   *  @brief 写入数据
   *  @param value 写入的数据
   */
  void LCD1602_data(uint8_t value);

  /**
   *  @brief 显示字符串
   *  @param str 显示的字符串
   */
  void LCD1602_send_string(const char *str);

  /**
   *  @brief 关闭下划线光标
   */
  void LCD1602_noCursor();

  /**
   *  @brief 打开下划线光标
   */
  void LCD1602_cursor();

  /**
   *  @brief 向左滚动显示
   */
  void LCD1602_scrollDisplayLeft();

  /**
   *  @brief 向右滚动显示
   */
  void LCD1602_scrollDisplayRight();
 
  /**
   *  @brief 此函数用于从左到右流动的文本
   */
  void LCD1602_leftToRight();
 
  /**
   *  @brief 此函数用于从右到左流动的文本
   */
  void LCD1602_rightToLeft();

  /**
   *  @brief  这将使文本从显示光标处“左对齐”
   */
  void LCD1602_noAutoscroll();
 
  /**
   *  @brief 这将使文本从显示光标处“右对齐”
   */
  void LCD1602_autoscroll();
   
  /**
   *  @brief 允许我们将前8个CGRAM位置填充自定义字符
   *  @param location 代替字符 范围（0-7）
   *  @param charmap  字符数组 大小8个字节
   */
  void LCD1602_createChar(uint8_t location, uint8_t charmap[]);
  
  /**
   *  @brief 背光芯片初始化
   */
  void LCD1602_led_init();

  /**
   *  @brief 设置背光亮度
   *  @param value  背光强度值   范围(0-100)
   */
  void LCD1602_set_brightness(uint8_t value);

  /**
   *  @brief 设置背光模式
   *  @param mode  0x00为正常模式，0x20为呼吸模式
   */
  void LCD1602_set_led_mode(uint8_t mode);
```

# 兼容性

| 开发板	| 工作正常 | 工作错误 | 未测试	| 备注	|
| ---------	|  :-------:  | :-------: | :-------: | :-------: |
| Pico 	    |      √      |           |         	|         	|
| Pico w	  |      √  	  |           |           |         	|
| pico 2	  |      √    	|           |        	  |         	|
| pico 2w	  |           	|           |     √ 	  |         	|


# 历史

- 日期 2025-01-03
- 版本 V1.0.0

