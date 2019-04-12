const int ap1 = A5; 
const int ap2 = A4;
const int ap3 = A3;

float sv1 = 0;        
float ov1 = 0;    
float sv2 = 0;      
float ov2= 0;      
float sv3 = 0;       
float ov3= 0;      

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogReference(EXTERNAL);    //connect 3.3v to AREF
  sv1 = analogRead(ap1);            
  // map it to the range of the analog out:
  ov1 = map(sv1, 0, 1023, 0, 255);  
  delay(2);                     
  sv2 = analogRead(ap2);            
  ov2 = map(sv2, 0, 1023, 0, 255); 
  delay(2);                 
  sv3 = analogRead(ap3);            
  ov3 = map(sv3, 0, 1023, 0, 255);
  ov1 = (-1)*(ov1-127);
  ov1 = map(ov1,-27,27,-10,10); 
  ov2 = (-1)*(ov2-127);
  ov2 = map(ov2,-27,27,-10,10); 
  ov3 = (-1)*(ov3-127);
  ov3 = map(ov3,-27,27,-10,10);  
  Serial.print("Xsensor1 = " );                       
  Serial.print(sv1);      
  Serial.print("\t output1 = ");      
  Serial.println(ov1);  
  Serial.print("Ysensor2 = " );                       
  Serial.print(sv2);      
  Serial.print("\t output2 = ");      
  Serial.println(ov2);   
  Serial.print("Zsensor3 = " );                       
  Serial.print(sv3);      
  Serial.print("\t output3 = ");      
  Serial.println(ov3);
  Serial.println();   

  delay(1000);                     
  
}
