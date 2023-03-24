#include <Servo.h>                     
Servo servo1;                              
                                        
float tempC;                                 
int const sensorPin = A0;            
int temperature;                           
int angle;

void setup()                            	      
{
  Serial.begin(9600);                   
  servo1.attach(9);                      
}

void loop()                                    
{
  int sensorVal = analogRead(sensorPin);          
  float voltage = (sensorVal/1024.0) * 5.0;          
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", Degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.print(temperature);
  Serial.print(", Angle: ");
  Serial.println(angle);

    if (temperature > 30)         
    {                                                              
      temperature = constrain(temperature, 30, 90);        
      angle = map(temperature, 31, 125, 90, 720);            
      servo1.write(angle);                                 	
      
    }
    else                                                   
    {
      angle = map(sensorPin, 0, 1023, 0, 0);           
      servo1.write(angle);                                    
      
    }
  delay(1000);                                                        
}
