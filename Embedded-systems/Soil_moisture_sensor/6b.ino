int sensor_pin = A0;
int output_value ;

void setup() {
   Serial.begin(9600);
   }

void loop() {
   output_value= analogRead(sensor_pin);
   output_value = map(output_value,1023,0,0,100);
   if(output_value > 45)Serial.write(1);
   else Serial.write(0);
   delay(100);

   }
