#include <AFMotor.h>
int analogInput = A1;


AF_DCMotor motor(2);

void setup() {
  Serial.begin(9600);
    pinMode(analogInput, INPUT);
// set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
 
  motor.run(RELEASE);
}

void loop() {
  uint8_t i;
  int value = analogRead(analogInput);
  int degree = value*5/(1024*0.01);
  Serial.println(degree);
  motor.run(FORWARD);
  if (degree < 15)  {motor.setSpeed(0);  
   delay(1000);}
  
  if (degree < 25){
//    for (i=0; i<175; i++) {
//  //    Serial.println(i);
//      motor.setSpeed(i);  
//      delay(10);
//   }
    motor.setSpeed(150);  
   delay(1000);
  }
  if (degree > 25){
    motor.setSpeed(255);
   delay(1000);
  }
//  for (i=255; i!=0; i--) {
//    motor.setSpeed(i);  
//    delay(10);
// }
//  
//  Serial.print("tock");

//  motor.run(BACKWARD);
//  for (i=0; i<255; i++) {
//    motor.setSpeed(i);  
//    delay(10);
// }
// 
//  for (i=255; i!=0; i--) {
//    motor.setSpeed(i);  
//    delay(10);
// }
//  

//  Serial.print("tech");
  motor.run(RELEASE);
//  delay(1000);
}
