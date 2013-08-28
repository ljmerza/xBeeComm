#include <Servo.h>

Servo myServo;
Servo myMotor;

int servoPin = 52;
int motorPin = 53;
int led = 51;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  
  myMotor.attach(motorPin);
  myServo.attach(servoPin); 
} // void setup()

void loop() {
 
  if(Serial.available())
  { 
    digitalWrite(led,HIGH);
    int temp = Serial.read();
    if(temp == 'A')
    {
      int temp1 = Serial.read();
      Serial.write(temp1);      
      int temp2 = Serial.read();
      Serial.write(temp2);
      
      myServo.write(temp1);
      myMotor.write(temp2);     

    } // if(Serial.read() == 'A')
  }  // while(Serial.available() > 3)
} // void loop()
