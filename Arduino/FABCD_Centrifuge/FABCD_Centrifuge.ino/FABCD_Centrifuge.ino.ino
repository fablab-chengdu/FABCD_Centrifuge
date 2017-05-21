/*
Coded by Bloomlj @ Fablab Chengdu
*/

#include <Servo.h>

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

Servo firstESC, secondESC; //Create as much as Servo object you want. You can controll 2 or more Servos at the same time

void setup() {

  firstESC.attach(9);    // attached to pin 9 I just do this with 1 Servo
  Serial.begin(9600);    // start serial at 9600 baud
}

void loop() {

   
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000,2000 );     // scale it to use it with the servo (value between 0 and 180)
  Serial.println(val);                         
//First connect your ESC WITHOUT Arming. Then Open Serial and follo Instructions
  firstESC.writeMicroseconds(val);
  delay(15);  // waits for the moto to change speed

  //for test,use Serial input
  //if(Serial.available()) 
  //  value = Serial.parseInt();    // Parse an Integer from Serial

}
