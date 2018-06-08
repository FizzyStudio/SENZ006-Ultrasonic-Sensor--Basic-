# SENZ006 超声波测距 (基础版）

###### 翻译

> `英文`请参考 [`这里`](https://github.com/njustcjj/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/README.md).

> `中文`请参考 [`这里`](https://github.com/njustcjj/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/README_CN.md).

![](https://github.com/njustcjj/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_Front.jpg "SENZ006_Front")
![](https://github.com/njustcjj/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_Back.jpg "SENZ006_Back")
 

### 产品介绍

> SENZ006超声波测距模块可提供4cm~400cm的非接触式距离感测功能，测距精度可达到3mm。使用GPIO接口通信。

> 
> 用途：超声波测距

### 产品参数

* 工作电压 : +5V （ DC ）
* 工作电流 : < 20mA
* 测量距离 : 4cm ~ 400cm
- 最大尺寸 : 45 x 20 x 15mm
- 输入触发信号 : 10us的TTL脉冲
- 输出回响信号 : TTL电平信号，脉冲宽度与射程成比例


### 使用教程

#### 引脚定义

|Sensor Pin|Ardunio Pin|Function Description|
|-|:-:|-|
|Pin-1|5V|Power|
|Pin-2|Digital pin|GPIO mode : Trig; Signal Input|
|Pin-3|Digital pin|GPIO mode : Echo; Output|
|Pin-4|GND||


![](https://github.com/njustcjj/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_pin.jpg "引脚定义") 


#### 连线图

![](https://github.com/njustcjj/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_connect.png "连线图") 


### 示例代码

	unsigned int EchoPin = 2; //将 Arduino 的 Pin2 连接至 SENZ006的 Echo
	unsigned int TrigPin = 3; //将 Arduino 的 Pin3 连接至 SENZ006的 Trig 
	unsigned long Time_Echo_us = 0; 
	unsigned long Len_mm  = 0; 
 
	void setup() 
	{  //Initialize 
		Serial.begin(9600);      
		pinMode(EchoPin, INPUT);
		pinMode(TrigPin, OUTPUT); 
	} 
 
	void loop() 
	{   //通过 Trig Pin 发送脉冲，触发 SENZ006测距 
		digitalWrite(TrigPin, HIGH); //开始通过 TrigPin 发送脉冲 
		delayMicroseconds(50);       //设置脉冲宽度为 50us (>10us) 
		digitalWrite(TrigPin, LOW);  //结束脉冲      

		Time_Echo_us = pulseIn(EchoPin, HIGH); //计算 SENZ006返回的脉冲宽度 
		if((Time_Echo_us < 60000) && (Time_Echo_us > 1))//脉冲有效范围(1, 60000)
		{   
			// Len_mm = (Time_Echo_us * 0.34mm/us) / 2
			Len_mm = (Time_Echo_us*34/100)/2; //通过脉冲宽度计算距离.     
			Serial.print("Present Distance is: ");     
			Serial.print(Len_mm, DEC);               
			Serial.println("mm");                
		}   
		delay(1000);              //每秒（1000ms）测量一次 
	}


### 购买[*SENZ006 超声波测距 (基础版）*](https://www.ebay.com/).