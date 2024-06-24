#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define ENABLE_2 9
#define DIRA_2 10
#define DIRB_2 11

#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(ENABLE_2,OUTPUT);
  pinMode(DIRA_2,OUTPUT);
  pinMode(DIRB_2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  turnOn();
  throttle(200);
  forward();
  if(getDist() < 10){
    turnRight90();
  }
  
}

int getDist(){
  int a = sr04.Distance();
  Serial.print("Distance check: ");
  Serial.println(a);
  return a;
}

//Pass a number from 0-255 that represents throttle from 0-100%
void throttle(int num){
  analogWrite(ENABLE, num);
  analogWrite(ENABLE_2, num);
}

void turnOn(){
  //turn on the motors
  digitalWrite(ENABLE,HIGH); // enable on
  digitalWrite(ENABLE_2,HIGH); // enable on
}

void turnOff(){
  //turn on the motors
  digitalWrite(ENABLE,LOW); // enable off
  digitalWrite(ENABLE_2,LOW); // enable off
}

void backward(){
  //Drive both motors in the other direction
  Serial.print("Driving forward");
  digitalWrite(DIRA,LOW);  
  digitalWrite(DIRB,HIGH);
  digitalWrite(DIRA_2,LOW);
  digitalWrite(DIRB_2,HIGH);
  delay(100);
}

void forward(){
  //Drive both motors in one direction
  digitalWrite(DIRA,HIGH); 
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRA_2,HIGH); 
  digitalWrite(DIRB_2,LOW);
  delay(100);
}

void turnRight90(){
  //turn one direction
  digitalWrite(DIRA,LOW);  
  digitalWrite(DIRB,HIGH);
  digitalWrite(DIRA_2,HIGH);
  digitalWrite(DIRB_2,LOW);
  delay(500); //this needs to be optimized through iteration to get the right value so the car turns as far as you want it to
}

void turnLeft90(){
  //turn other direction
  digitalWrite(DIRA,HIGH);  
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRA_2,LOW);
  digitalWrite(DIRB_2,HIGH);
  delay(500);//this needs to be optimized through iteration to get the right value so the car turns as far as you want it to
}
   
