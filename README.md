# SENZ006-Ultrasonic-Sensor (Basic)

###### Translation

> For `English`, please click [`here.`](https://github.com/FizzyStudio/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/README.md)

> For `Chinese`, please click [`here.`](https://github.com/FizzyStudio/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/README_CN.md)

![](https://github.com/FizzyStudio/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_Front.jpg "SENZ006_Front")
![](https://github.com/FizzyStudio/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_Back.jpg "SENZ006_Back")

### Introduction

> SENZ006 Ultrasonic Sensor (Basic) uses the GPIO communication mode. Its detecting range is from 4cm to 400cm and it has 3mm resolution.


### Specification

- Operating voltage : +5V
- Current: < 20mA
- Detecting range：4cm ~ 400cm
- Interface:  GPIO
- Size : 45 x 20 x 15mm
- Input trigger signal : 10us TTL pulse
- Output return signal : TTL pulse with its width proportional to the detected distance


### Tutorial

#### Pin Definition

|Sensor Pin|Ardunio Pin|Function Description|
|-|:-:|-|
|Pin-1|5V|Power|
|Pin-2|Digital pin|GPIO mode : Trig; Signal Input|
|Pin-3|Digital pin|GPIO mode : Echo; Output|
|Pin-4|GND||

![](https://github.com/FizzyStudio/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_pin.jpg "Pin Definition") 

#### Connecting Diagram

![](https://github.com/FizzyStudio/SENZ006-Ultrasonic-Sensor--Basic-/blob/master/pic/SENZ006_connect.png "Connecting Diagram") 

#### Sample Code


	unsigned int EchoPin = 2; //Connect Pin2 of Arduino to Echo/RX of SENZ006
	unsigned int TrigPin = 3; //Connect Pin3 of Arduino to Trig/TX of SENZ006
	unsigned long Time_Echo_us = 0; 
	unsigned long Len_mm  = 0; 
 
	void setup() 
	{  //Initialize 
		Serial.begin(9600);
		pinMode(EchoPin, INPUT);
		pinMode(TrigPin, OUTPUT); 
	} 
 
	void loop() 
	{   //Make SENZ006 detect the distance via the pulse from Trig Pin
		digitalWrite(TrigPin, HIGH);  
		delayMicroseconds(50);        
		digitalWrite(TrigPin, LOW);       

		Time_Echo_us = pulseIn(EchoPin, HIGH); //Caculate the returned pulse width
		if((Time_Echo_us < 60000) && (Time_Echo_us > 1))//The valid range of pulse(1, 60000)
		{   
			// Len_mm = (Time_Echo_us * 0.34mm/us) / 2 
			Len_mm = (Time_Echo_us*34/100)/2;     
			Serial.print("Present Distance is: ");     
			Serial.print(Len_mm, DEC);       
			Serial.println("mm");          
		}   
		delay(1000);              //Detect per second
	}


### Purchasing [*SENZ006 Ultrasonic Sensor (Basic)*](https://www.ebay.com/).
