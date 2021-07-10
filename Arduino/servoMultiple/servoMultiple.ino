// Sweep
// by BARRAGAN <http://barraganstudio.com> 



#include <Servo.h>
 
Servo myservo01,myservo02,myservo03;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos01= 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo01.attach(20);  // attaches the servo on pin 20 
  myservo02.attach(21);  // attaches the servo on pin 21 
  myservo03.attach(22);  // attaches the servo on pin 22 
} 
 
 
void loop() 
{ 
  for(pos01 = 10; pos01 < 170; pos01 += 1)  // goes from 10 degrees to 170 degrees 
  {                                  // in steps of 1 degree 
    myservo01.write(pos01);
    myservo02.write(pos01);
    myservo03.write(pos01);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos01 = 180; pos01>=1; pos01-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo01.write(pos01);
    myservo02.write(pos01);
    myservo03.write(pos01);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 
