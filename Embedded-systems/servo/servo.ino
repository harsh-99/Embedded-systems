#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9,600,2300);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  myservo.write(0);  // tell servo to go to a particular angle
  delay(1000);
  
  myservo.write(90);              
  delay(1000); 
  
  myservo.write(0);              
  delay(1000);
  
  myservo.write(180);              
  delay(1000);      
  // put your main code here, to run repeatedly:

}
