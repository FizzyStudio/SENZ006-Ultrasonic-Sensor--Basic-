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
