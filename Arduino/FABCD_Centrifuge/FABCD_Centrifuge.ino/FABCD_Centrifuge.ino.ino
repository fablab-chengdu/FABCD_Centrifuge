/*
Coded by Bloomlj @ Fablab Chengdu
*/

#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
//`int count = 0;
int pretime = 0;
int rpm = 0;
Servo firstESC, secondESC; //Create as much as Servo object you want. You can controll 2 or more Servos at the same time

void setup() {
  attachInterrupt(0, counter, CHANGE);    //设置触发，中断号0，即数字2口
  firstESC.attach(9);    // attached to pin 9 I just do this with 1 Servo
  Serial.begin(9600);    // start serial at 9600 baud

  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  //lcd.setCursor(2,0);
  //lcd.print("Hello, world!");
  //lcd.setCursor(1,1);
  //lcd.print("Ywrobot Arduino!");
  
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000,2000 );     // scale it to use it with the servo (value between 0 and 180)
  lcd.setCursor(1,0);
  lcd.print("speed:"); 
  lcd.setCursor(7,0);
  lcd.print(val);
  lcd.setCursor(1,1);
  lcd.print(rpm);
  Serial.println(val);                         
//First connect your ESC WITHOUT Arming. Then Open Serial and follo Instructions
  firstESC.writeMicroseconds(val);
  delay(15);  // waits for the moto to change speed

  //for test,use Serial input
  //if(Serial.available()) 
  //  value = Serial.parseInt();    // Parse an Integer from Serial

}

void counter(){
  Serial.println(micros() -pretime);
  rpm = 60*1000000/(micros() -pretime);
  pretime = micros();
  //count++;
  }
