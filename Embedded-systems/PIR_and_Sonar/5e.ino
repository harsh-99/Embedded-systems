const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int sensor=9; //The output of PIR sensor connected to pin 7
int sensor_value; //variable to hold read sensor value

void setup() {
   pinMode(sensor,INPUT);
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(pingPin, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   sensor_value=digitalRead(sensor); 
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = 0;
   cm = microsecondsToCentimeters(duration);
//   Serial.println(sensor_value);
   if(sensor_value>0){
    inches = microsecondsToInches(duration);
     
//     Serial.print("in, ");
//     Serial.print(cm);
//     Serial.print("cm");
   }
   Serial.println(inches);
//   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
