const int lightsensorPin = A0; // the number of the light sensor pin
const int redledPin = 9;
// the number of the red LED pin
const int greenledPin13 = 13; // onboard LED and green LED pin
// variables will change:
int sensorState = 0;
// variable for reading light sensor status
void setup() {
// initialize the LED pins as outputs:
pinMode(redledPin, OUTPUT);
pinMode(greenledPin13, OUTPUT);
// initialize the light sensor pin as an input:
pinMode(lightsensorPin, INPUT);
Serial.begin(9600);
}
void loop(){
// read the state of the pushbutton value:
sensorState = analogRead(lightsensorPin);
Serial.println(sensorState);
// check if the light sensor is activated
if (sensorState >= 402) {
// turn red LED on:
digitalWrite(redledPin, HIGH);
// turn off onboard LED and green LED:
digitalWrite(greenledPin13, LOW);
}
else {
// turn red LED off:
digitalWrite(redledPin, LOW);
// turn on onboard LED and green LED;
digitalWrite(greenledPin13, HIGH);
}
}
