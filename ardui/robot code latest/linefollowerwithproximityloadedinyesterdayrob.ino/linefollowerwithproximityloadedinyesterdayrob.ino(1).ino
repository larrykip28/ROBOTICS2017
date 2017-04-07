#include <Wire.h>

//driver pins
int in1=10;
int in2=11;
int in3=12;
int in4=13;
  
int pwm1=5;

int pwm2=6;

 
float maxValue = 200;

//line follower declearation
int lineFollower1 = A0; //right
int lineFollower2 = A1;//center
int lineFollower3 = A2;//left
float left;
float right;
float center;

int currentbit =0;
int memorybit1 =0;
int memorybit2 =0;
int memorybit3 =0;

int countval =0; // number of lines counted

int sensorPin = A3;    // select the input pin for the sensor
int sensorValue = 0;  // variable to store the value coming from the sensor

int Threshhold = 590; 
// This is the threshhold above which the sensor is judged to be on the white line
boolean counted=false;

#define echoPin1 9
#define trigPin1 8


long duration, distance, Sensor1,dist;
int minValue = 8;

boolean startDone=false;


byte A = 10;
byte B = 11;
byte C = 12;
byte D = 13;
byte E = 14;
void setup() {
    // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
   
pinMode(pwm1, OUTPUT);
pinMode(pwm2, OUTPUT);
      

 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);

   Wire.begin();

}

void loop() {
  
  dist=SonarSensor(trigPin1,echoPin1);
  // put your  main code here, to run repeatedly:
  left = analogRead(lineFollower3);
  right = analogRead(lineFollower1);
  center= analogRead(lineFollower2);
  //if(dist<=28&&dist>=29){
    if(dist<29){
    stopp(0);
    Wire.beginTransmission(4); 
    delay(1000);
  
    Wire.write(A);
    Wire.endTransmission();    // stop transmitting

     delay(500);
  }
   else if(dist<28)
  {
    // reverse(255);
     delay(2);
  }
 else
 {
 lineTracking();
 }
// Serial.print(left);
//  Serial.println("left");
//  
//   Serial.print(center);
//  Serial.println("center");
//  
//     Serial.print(right);
//  Serial.println("right");

}

void lineTracking()
{
  //001
 if((left>maxValue) &&(center>maxValue) &&(right<maxValue)) 
 {
   left_to_right_diff(200);
 }
 //010
 else if((left>maxValue)  &&(center<maxValue) &&(right>maxValue)) 
 {
   forward(200);
   
 }
 //011
  else if((left>maxValue)  &&(center<maxValue) &&(right<maxValue)) 
 {
   left_to_right_diff(220); 
 }
 //100
   else if((left<maxValue)&&(center>maxValue) &&(right>maxValue)) 
 {
   right_to_left_diff(220); 
 }
  //110
   else if((left<maxValue)&&(center<maxValue) &&(right>maxValue)) 
 {
   right_to_left_diff(220);   
 }
 //111
    else if((left<maxValue)&&(center<maxValue) &&(right<maxValue)) 
 {
       if((left<maxValue)&&(center<maxValue) &&(right<maxValue) &&(memorybit2>maxValue)) 
       {
         countval++;
         delay(30);
         
       }
        else if(countval==3)
         {
        
         delay(1000);
         }else{
           
           forward(255);
           
         }
 
                
        memorybit1=left;
       memorybit2=center;
       memorybit3=right;
    
  Serial.println(countval);
  
  
}
}
void stopp( int spd)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(pwm1, spd);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, spd); 
  
}

void forward(int spd) {
 
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, spd);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, spd); 
   delay(30);

}
void reverse(int spd) {
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm1, spd);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(pwm2, spd); 

}

void left_to_right(int spd) {
  
  int spd2 = spd - 255;
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, spd2);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, spd); 
   
}

void right_to_left(int spd) {
  int spd2 = spd - 255;
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, spd);

  digitalWrite(in3, HIGH);   
  digitalWrite(in4, LOW);
  analogWrite(pwm2, spd2); 

}

void left_to_right_diff(int spd) {
 
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm1, spd);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, spd); 
   
}

void right_to_left_diff(int spd) {
 
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, spd);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(pwm2, spd); 

}

void right_to_left_sharp(int spd) {
  int spd2 = spd - 240;
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, spd);

  digitalWrite(in3, HIGH);   
  digitalWrite(in4, LOW);
  analogWrite(pwm2, spd2); 

}
void left_to_right_sharp(int spd) {
  
  int spd2 = spd - 255;
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, spd2);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, spd); 
   
}

long SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
return distance;

}
