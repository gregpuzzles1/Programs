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

# 驱动安装

首先下载示例文件,将arduino示例中的Waveshare_LCD1602复制粘贴到\Arduino\libraries目录中,然后打开examples文件夹并在该文件夹中运行演示.

# 函数介绍

```C++

  /**
   *  @brief 液晶屏以及主控IIC的初始化
   */ 
  void init();

  /**
   *  @brief 打开显示
   */
  void display();

  /**
   *  @brief send command
   *  @param data 发送的命令
   */
  void command(uint8_t data);

  /**
   *  @brief Transfer information
   *  @param data 传输的信息
   *  @param len 传输的信息数量
   */
  void lcd_send(uint8_t *data, uint8_t len);

  /**
   *  @brief 设置光标位置
   *  @param col 列数 可选范围 0-15 最大为39，需要移动才能观察到大于15的字符
   *  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
   */
  void setCursor(uint8_t col, uint8_t row);
  
  /**
   *  @brief 清除显示并将光标回到初始位置（0位置）
   */
  void clear();

  /**
   *  @brief 写入数据
   *  @param value 写入的数据
   */
  void data(uint8_t value);

  /**
   *  @brief 显示字符串
   *  @param str 显示的字符串
   */
  void send_string(const char *str);

  /**
   *  @brief 关闭下划线光标
   */
  void noCursor();

  /**
   *  @brief 打开下划线光标
   */
  void cursor();

  /**
   *  @brief 向左滚动显示
   */
  void scrollDisplayLeft();

  /**
   *  @brief 向右滚动显示
   */
  void scrollDisplayRight();
 
  /**
   *  @brief 此函数用于从左到右流动的文本
   */
  void leftToRight();
 
  /**
   *  @brief 此函数用于从右到左流动的文本
   */
  void rightToLeft();

  /**
   *  @brief  这将使文本从显示光标处“左对齐”
   */
  void noAutoscroll();
 
  /**
   *  @brief 这将使文本从显示光标处“右对齐”
   */
  void autoscroll();
   
  /**
   *  @brief 允许我们将前8个CGRAM位置填充自定义字符
   *  @param location 代替字符 范围（0-7）
   *  @param charmap  字符数组 大小8个字节
   */
  void createChar(uint8_t location, uint8_t charmap[]);
  
  /**
   *  @brief 发送命令跟数据
   *  @param cmd  寄存器地址
   *  @param data 需要配置的值
   */
  void led_send(uint8_t cmd, uint8_t data);

  /**
   *  @brief 设置背光亮度
   *  @param value  背光强度值   范围(0-100)
   */
  void set_brightness(uint8_t value);

  /**
   *  @brief 设置背光模式
   *  @param mode  0x00为正常模式，0x20为呼吸模式
   */
  void set_led_mode(uint8_t mode);
```

# 兼容性

| 开发板	| 工作正常 | 工作错误 | 未测试	| 备注	|
| ---------	|  :-------:  |  :-------: |  :-------:  |  :-------:  |
| Pico 	            |     √     |           |        |         	|
| Pico w	          |     √  	  |           |        |         	|
| pico 2	          |     √    	|           |        |         	|
| pico 2w	          |     √    	|           |        |         	|
| Arduino UNO R3 	  |     √     |           |        |         	|
| Arduino UNO R4	  |     √  	  |           |        |         	|
| Arduino Mega 2560	|     √    	|           |        |         	|
| ESP32S3         	|     √    	|           |        |         	|


# 历史

- 日期 2025-01-03
- 版本 V1.0.0

