/*
version 3.6
DENIS KOECH(WINNIPEG)
EDITED FOR HOME RUN BY LARRY
Thanks alot Denis 
elbow
Grab the damn Votes
Addition of storing the critter after picking

*/

#include <Servo.h>

Servo elbow;
Servo gripper;
Servo wrist;
Servo shoulder;

int gripL,gripR,wst,elb,shd,bse;

void setup()
{
  
 Serial.begin(9600);  
 // start serial for output
 gripper.attach(5);
 wrist.attach(6);
 elbow.attach(10);
 shoulder.attach(9);
 
 int pos=10;
 

 //gripper.attach(11);

  
}

void loop()
{
  delay(3000);
  
  home_position();
   //delay(300);
 // pick_cylinder();
  //drop_cuboid();

  //delay(2000);
  //drop();
 // 
// picking();
//store_on_car();
// before_pick_cuboid();
//pick_cuboid();
//carry_cuboid();
//pick_sphere();
//carry_cuboid();
//drop();
//pick_from_store();

  
}

void home_position()
{

  for(int pos=100;pos<130;pos++)
 { 
   int g=map(pos,100,130,100,10);
   int w=map(pos,20,130,10,170);
   int e=map(pos,100,130,10,60);
   int s=map(pos,100,130,50,50); //
   
   gripper.write(g);
   delay(20);
   wrist.write(w); 
   delay(10);
   elbow.write(e);
   delay(10);
   shoulder.write(s);
   delay(10); 
   
 }
 
 
    for(int pos=100;pos<130;pos++)
 {
   
  int g=map(pos,100,130,10,100);
  int w=map(pos,100,130,170,10);
  int e=map(pos,100,130,60,10);
  int s=map(pos,100,130,50,50);
  
  gripper.write(g);
  delay(20);
 
  wrist.write(w); 
   delay(10);
  elbow.write(e);
  delay(10);
  shoulder.write(s);
  delay(10);
   
 
 }
 
}

void pick_cylinder()
{
     for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,10,100);
   int e=map(pos,100,150,10,100);
   int s=map(pos,100,150,50,138);

  Serial.println(s);
  wrist.write(w); 
  delay(10);
    elbow.write(e);
  delay(10);
   shoulder.write(s);
   delay(30);
  
   
 }
 grab();
 //inafa nirudishe vile ilikuwa but dang who cares
      for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,100,10);
   int e=map(pos,100,150,100,10);       
   int s=map(pos,100,150,130,50);
   wrist.write(w); 
   delay(10);
   elbow.write(e);
   delay(10);
   shoulder.write(s);
   delay(30);
  
   
 }
 
}

//drop cuboid at the hive
void drop_cuboid()
{
     for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,10,100);
   int e=map(pos,100,150,10,100);
   int s=map(pos,100,150,50,100);
   int g=map(pos,100,130,100,10);
   Serial.println(s);
   wrist.write(w); 
   delay(10);
   elbow.write(e);
  delay(10);
   shoulder.write(s);
  gripper.write(g);
   delay(30);
   
 }
 grab();
 //hii pia rudisha I mean it dnt forget Larry
      for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,100,10);
   int e=map(pos,100,150,100,10);      
   int s=map(pos,100,150,100,50);
   wrist.write(w); 
   delay(10);
   elbow.write(e);
  delay(10);
   shoulder.write(s);
   delay(30);
   
 }
 
}



void grab()
{
     for(int pos=100;pos<150;pos++)
 {
   int g=map(pos,100,150,100,10);
   gripper.write(g); 
   delay(40);

 }

}


void drop()
{
  
  for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,100,120);
   int e=map(pos,100,150,160,80);
   int s=map(pos,100,150,138,110);
   int g=map(pos,100,150,10,100);
   Serial.println(s);
   wrist.write(w); 
   delay(10);
   elbow.write(e);
   delay(10);
   gripper.write(g);
   delay(50);  
   shoulder.write(s);
   delay(50);  

 }
  
  
}

void picking()
{
  
     for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,10,100);
   int e=map(pos,100,150,10,100);
   int s=map(pos,100,150,50,138);

   Serial.println(s);
   wrist.write(w); 
   delay(10);
   elbow.write(e);
   delay(10);
   shoulder.write(s);
   delay(30);
  
   
 }

grab();  
}

void store_on_car()
{
   
 
    for(int pos=100;pos<150;pos++)
 {
   

  int w=map(pos,100,150,100,30);
  int e=map(pos,100,150,100,157);
  int s=map(pos,100,150,138,67);
  int g=map(pos,100,150,10,100);


 wrist.write(w);
 delay(50);
 elbow.write(e);  delay(50);
 shoulder.write(s);

  delay(50); 
   
 }
 ungrip();
}

 void ungrip()
{
 for(int pos=100;pos<150;pos++)
 {
  int g=map(pos,100,150,10,100);  
  gripper.write(g);
  delay(50);
  
}
}

void before_pick_cuboid()
{
  
 for(int pos=100;pos<150;pos++)
 {
   
  
  int w=map(pos,100,150,30,110);
  int e=map(pos,100,150,157,60);
  int s=map(pos,100,150,67,80);

   
  wrist.write(w);
  delay(30);
  elbow.write(e);
  delay(30);
  shoulder.write(s);
  delay(30);
   
 }
}
 void pick_cuboid()
{
   
  for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,110,100);
   int e=map(pos,100,150,60,100);
   int s=map(pos,100,150,80,138);

   Serial.println(s);
   wrist.write(w); 
   delay(10);
   elbow.write(e);
   delay(10);
   shoulder.write(s);
   delay(30);  
 }
 grab(); 
 
}
void carry_cuboid()
{
   for(int pos=100;pos<150;pos++)
 {
   
  int s=map(pos,100,150,138,138);
  int e=map(pos,100,150,100,160);
  int w=map(pos,100,150,100,100);
   
  
   
  wrist.write(w);
  delay(20);
  elbow.write(e);
  delay(20);
  shoulder.write(s);
  delay(20);
   
   
 }
 
 //drop(); 
}

void pick_sphere()
{
 for(int pos=100;pos<150;pos++)
 {
   int w=map(pos,100,150,10,100);
   int e=map(pos,100,150,10,85);
   int s=map(pos,100,150,50,138);

  
   wrist.write(w); 
   delay(10);
   elbow.write(e);
   delay(10);
   shoulder.write(s);
   delay(30);
  
   
 }

grab();   
  
}

void pick_from_store()
{
  
    for(int pos=100;pos<150;pos++)
 {
   

  int w=map(pos,100,150,120,30);
  int e=map(pos,100,150,80,170);
  int s=map(pos,100,150,110,67);
  int g=map(pos,100,150,100,20);


 wrist.write(w);
 delay(20);
 elbow.write(e);  delay(20);
 shoulder.write(s);

  delay(50); 
   
 } 
  
}
