int sensor=9; //The output of PIR sensor connected to pin 7
int sensor_value; //variable to hold read sensor value
void setup()
{
pinMode(sensor,INPUT); // configuring pin 7 as Input
Serial.begin(9600); // To show output value of sensor in serial monitor
}

void loop()
{
sensor_value=digitalRead(sensor); // Reading sensor value from pin 7
Serial.println(sensor_value); // Printing output to serial monitor
delay(10);
}
