#include <Wire.h>

int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;


int counter = 0;

byte A = 12;
byte B = 13;
byte C = 14;
byte D = 15;
byte E = 16;

void setup()
{
    Serial.begin(9600);
    
    Wire.begin(); // join i2c bus (address optional for master)
  
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);  
    
}
void loop()
{
    Serial.print(counter);
    Wire.beginTransmission(4); // transmit to device #4 
    delay(1000);
    counter++;
    
     if(counter ==3)
      {
          Wire.write(A);              // sends one byte
          
          digitalWrite(2,1);
          delay(500);
          digitalWrite(2,0);
          delay(500);
      }  
       if(counter==6)
       {
          Wire.write(B);  // sends one byte
          
          digitalWrite(3,1);
          delay(500);
          digitalWrite(3,0);
          delay(500);
       }
       if(counter==9)
      {
        Wire.write(C);              // sends one byte
        
        digitalWrite(4,1);
        delay(500);
        digitalWrite(4,0);
        delay(500);
      }  
       if(counter==12)
       {
         Wire.write(D);
         
         digitalWrite(5,1);
         delay(500);
         digitalWrite(5,0);
         delay(500);
         counter=0;
       }
      
  Wire.endTransmission();    // stop transmitting

  delay(500);
}
    
