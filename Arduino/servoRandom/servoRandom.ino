
#include <Servo.h>
 
Servo myservo01,myservo02,myservo03;  // create servo object to control a servo  
int interval01,interval02,interval03 = 1000;
int previousMillis01,previousMillis02,previousMillis03 = 0; 
 
void setup() 
{ 
  myservo01.attach(20);  // attaches the servo on pin 20 
  myservo02.attach(21);  // attaches the servo on pin 21 
  myservo03.attach(22);  // attaches the servo on pin 22 
} 
 
 
void loop() 
{ 
  unsigned long currentMillis = millis();

  //Servo 01
  if(currentMillis - previousMillis01 > interval01) {
    previousMillis01 = currentMillis;
    interval01 = random(1000,4000);
    int angle01 = random(10,180);
     myservo01.write(angle01);
   }   

   //Servo 02
  if(currentMillis - previousMillis02 > interval02) {
    previousMillis02 = currentMillis;
    interval02 = random(1000,4000);
    int angle02 = random(10,180);
     myservo02.write(angle02);
   }   

   //Servo 03
  if(currentMillis - previousMillis03 > interval03) {
    previousMillis03 = currentMillis;
    interval03 = random(1000,4000);
    int angle03 = random(10,180);
     myservo03.write(angle03);
   }   
  
  
} 
