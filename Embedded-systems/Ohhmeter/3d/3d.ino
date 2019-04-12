#include <LiquidCrystal.h>     // set up pins on Arduino for LCD and test lead
LiquidCrystal lcd(12,11,5,4,3,2);    // set up the LCD's number of columns and rows


int analogPin = 0; // reads the resistance of R2
int raw = 0; // variable to store the raw input value
int Vin = 5; // variable to store the input voltage
float Vout = 0; // variable to store the output voltage
float R1 = 1000; // variable to store the R1 value
float R2 = 0; // variable to store the R2 value
float buffer = 0; // buffer variable for calculation
float V1=0;

int LED = 8;

#define Xdelay 1900

String a;
String b;
String c;
String d;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.clear();
  backlightOn();
  lcd.print("Group_4 ");
  delay(Xdelay);
  lcd.clear();
  pinMode(LED, OUTPUT);
}

void loop(){
  raw = analogRead(analogPin); // reads the input pin
  if(raw){
    buffer = raw * Vin;
    Vout = buffer /1024.0; // calculates the voltage on the input pin
    buffer = (Vin / Vout) - 1;
    R2 = R1 / buffer;
    V1 = Vin - Vout;
    lcd.print("V_R1: ");
    lcd.print(V1);
    lcd.print("V");
    delay(1000);
    lcd.clear();
    lcd.print("V_R2: ");
    lcd.print(Vout); // outputs the information
    lcd.print("V");
    delay(1000);
    lcd.clear();
    lcd.print("R2: "); //
    lcd.print(R2); //
    lcd.print("ohm");
    delay(1000);
    lcd.clear();
    if (Vout < 1.5){
      digitalWrite(LED, HIGH);
      delay(1000);
      }
    if(Vout > 1.5){
      digitalWrite(LED, LOW);
      delay(1000);
      }  
  }
  }

void backlightOn()
{
lcd.write(0x7C); //command flag for backlight stuff
lcd.write(157); //light level
delay(10);
}
