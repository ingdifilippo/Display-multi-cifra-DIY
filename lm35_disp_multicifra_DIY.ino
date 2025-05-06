#include <Arduino.h>

const int A = 5;
const int B = 4;
const int C = 3;
const int D = 2;

const int D4 = 6;
const int D3 = 7;
const int D2 = 8;
const int D1 = 9;

void displayDigit(int d, int n) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(9-i, (i == d? LOW : HIGH));     
  }
  digitalWrite(5, (n & B00000001));
  digitalWrite(4, (n & B00000010));
  digitalWrite(3, (n & B00000100));
  digitalWrite(2, (n & B00001000));    
}

void setup() {
  Serial.begin(9600);

  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);  
  }
  
 

  digitalWrite(D1, LOW); 
  digitalWrite(D2, HIGH); 
  digitalWrite(D3, HIGH); 
  digitalWrite(D4, HIGH);
  delay(1000);
    
  digitalWrite(D, LOW); 
  digitalWrite(C, LOW); 
  digitalWrite(B, LOW); 
  digitalWrite(A, LOW);
  delay(1000);

}

int x = 0;
int t = 0 ;
unsigned long dt, t1;


void loop() {
  displayDigit(0, (t %10));
  delay(4);
  displayDigit(1, ((t/10)%10));
  delay(4);
  displayDigit(2, ((t/100)%10));
  delay(4);
  displayDigit(3, ((t/1000)%10));
  delay(4);
  
  dt = millis() - t1;
  if (dt >= 1000) 
   {
    x=analogRead(0);
    t = (x/1023.0)*150;
    t1 = millis();
   }  
  /* digitalWrite(D1, LOW); 
  delay(1000);
  digitalWrite(D1, HIGH); 
  delay(1000); */

}



