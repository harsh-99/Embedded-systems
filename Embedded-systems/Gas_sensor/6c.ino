int smokeD0 = A0;
// Your threshold value
int sensorThres = 400;

void setup() {

  pinMode(smokeD0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int digitalSensor = analogRead(smokeD0);
  if(digitalSensor > 750) Serial.write(1);
  else Serial.write(0);
  
  // Checks if it has reached the threshold value
  delay(100);
}
