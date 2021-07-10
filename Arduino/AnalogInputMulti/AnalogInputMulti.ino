/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin01 = A0;    
int sensorPin02 = A1;    
int sensorPin03 = A2;    
int sensorPin04 = A3;    

int sensorValue01,sensorValue02,sensorValue03,sensorValue04 = 0;  // variable to store the value coming from the sensor

void setup() {
  
  Serial.begin(9600);  
}

void loop() {
  // read the value from the sensor:
  sensorValue01 = analogRead(sensorPin01);
  Serial.print(sensorValue01);
  Serial.print("\t");
  sensorValue02 = analogRead(sensorPin02);
  Serial.print(sensorValue02);
  Serial.print("\t");   
  sensorValue03 = analogRead(sensorPin03);
  Serial.print(sensorValue03);
  Serial.print("\t");   
  sensorValue04 = analogRead(sensorPin04);
  Serial.println(sensorValue04);       
 
  delay(10);                  
}
