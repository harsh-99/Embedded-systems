String data; //Store each line of Serial communication
#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);
// 2 is Rx
// 3 is Tx
String pot1String = "0", pot2String = "0";
float pot1, pot2;
int motor_input1 = 4;
int motor_input2 = 5;
int motor_input3 = 6;
int motor_input4 = 7;
void forward(){
  digitalWrite(motor_input1, LOW);
  digitalWrite(motor_input2, HIGH);
  digitalWrite(motor_input3, LOW);
  digitalWrite(motor_input4, HIGH);
}
void stop_bot(){
  digitalWrite(motor_input1, LOW);
  digitalWrite(motor_input2, LOW);
  digitalWrite(motor_input3, LOW);
  digitalWrite(motor_input4, LOW);
}
void backward(){
  digitalWrite(motor_input2, LOW);
  digitalWrite(motor_input1, HIGH);
  digitalWrite(motor_input4, LOW);
  digitalWrite(motor_input3, HIGH);
}
void right(){
  digitalWrite(motor_input1, LOW);
  digitalWrite(motor_input2, HIGH);
  digitalWrite(motor_input3, HIGH);
  digitalWrite(motor_input4, LOW);
}
void left(){
  digitalWrite(motor_input1, HIGH);
  digitalWrite(motor_input2, LOW);
  digitalWrite(motor_input3, LOW);
  digitalWrite(motor_input4, HIGH);
}
void setup() 
{
  //initialize Serial communication 
  Serial.begin(38400);
  bt.begin(38400);
  //read first package
  if (bt.available() > 0)
  {
    data = bt.readStringUntil('\n');
  }
  //Disregard the first reading
  data = "0";
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
//  digitalWrite(6, HIGH);
//  digitalWrite(7, HIGH);
}

void loop() {
  //start reading from serial
  if (bt.available() > 0)
  {
    data = bt.readStringUntil('\n');  
  }
  String payload = ""; 
  if (data != "0")
  {
    int offset = data.indexOf("U*"); //This is the header (0x552A)
    if (offset >= 0)
    {
      payload = data.substring(offset + 3, data.indexOf('\n'));
      char value = data.charAt (offset + 2);
      switch (value)
      {
        case 'A':
          pot1String = payload;
          break;
        case 'B':
          pot2String = payload;
          break;
      //Add more case as the project grow
      }
    }
  }
  //convert strings to float
  pot1 = pot1String.toFloat();
  pot2 = pot2String.toFloat();
  Serial.print(pot1);
  Serial.print("    ");
  Serial.println(pot2);

  if(pot2 < 360 && pot1 < 360 && pot1 > 330 && pot2 > 330){
//    digitalWrite(6, LOW);
//    digitalWrite(7,LOW);
      stop_bot();

    }
  if(pot2 > 320 && pot2 < 360 && pot1 > 390){
//    digitalWrite(6, HIGH);
//    digitalWrite(7,HIGH);
      forward();
 }
    if(pot2 < 365 && pot2 > 320 && pot1 < 300){
//    digitalWrite(6, LOW);
//    digitalWrite(7,HIGH);
      backward();
}
      if(pot2 > 385 && pot1 < 360 && pot1 > 320){
//    digitalWrite(6, HIGH);
//    digitalWrite(7,LOW);
      left();
      }

if(pot2 < 290 && pot1 < 360 && pot1 > 320){
//      digitalWrite(6, HIGH);
//    digitalWrite(7,LOW);
      right();
      }
// Continue with the rest of your project
}
