const int xPin   = A0;
const int yPin   = A1;
const int zPin   = A2;
int x = 0;
int y = 0;
int z = 0;

void setup() {
  Serial.begin(38400);// put your setup code here, to run once:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(zPin, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  x = analogRead(xPin);
  y = analogRead(yPin);
  z = analogRead(zPin);
//  Serial.println(z);
//  Serial.write(z);// put your main code here, to run repeatedly:
//  Serial.write(y);
//  Serial.write("\n");
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(y);
  Serial.println("");  

  Serial.print("U*"); //A header
  Serial.print("B");  //a token to indicate the message payload
  Serial.print(x);
  Serial.println("");  
  delay(100);

}
