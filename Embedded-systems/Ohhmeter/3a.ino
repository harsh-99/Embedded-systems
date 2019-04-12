int analogPin = 0; // reads the resistance of R2
int raw = 0; // variable to store the raw input value
int Vin = 5; // variable to store the input voltage
float Vout = 0; // variable to store the output voltage
float R1 = 1000; // variable to store the R1 value
float R2 = 0; // variable to store the R2 value
float buffer = 0; // buffer variable for calculation
void setup()
{
Serial.begin(9600); // Set up serial
}


void loop()
{
raw = analogRead(analogPin); // reads the input pin
if(raw){
  buffer = raw * Vin;
  Vout = buffer /1024.0; // calculates the voltage on the input pin
  buffer = (Vin / Vout) - 1;
  R2 = R1 / buffer;
  Serial.print("Vout: ");
  Serial.println(Vout); // outputs the information
  Serial.print("R2: "); //
  Serial.println(R2); //
  delay(1000);
  }
}
