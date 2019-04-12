int analogInput = A1;
int value = 0;
int threshold = 250;
float degree;
const int buzzer = 11;

void setup(){
  pinMode(analogInput, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  value = analogRead(analogInput);
  degree = value*5/(1024*0.01);
  if (degree > threshold) tone(buzzer, 2000);
  else noTone(buzzer);
  Serial.println(degree);
//  Serial.write(10);
  delay(100);
}
