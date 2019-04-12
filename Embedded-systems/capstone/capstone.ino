#define ledPin 13
int state = 0;
int potValue = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.write(state);
 }
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, LOW); // LED ON
 }
 if (state == '0') {
  digitalWrite(ledPin, HIGH); // LED ON
 }
// // Reading the potentiometer
// potValue = analogRead(A0);
// int potValueMapped = map(potValue, 0, 1023, 0, 255);
// Serial.write(potValueMapped); // Sends potValue to servo motor
// delay(10);
}
