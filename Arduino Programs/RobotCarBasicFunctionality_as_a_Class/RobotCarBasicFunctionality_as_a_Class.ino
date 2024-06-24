#include "SR04.h"
SR04 sr04;

class Ultrasonic
{
  int triggerPin;
  int echoPin;
  

  //Constructor
  public:
  //Pass the pin numbers for the two enable wires and 4 motor control wires
  Ultrasonic(int trig, int echo)
  {
    triggerPin = trig;
    echoPin = echo;
    //SR04 sr04;
    SR04 sr04 = SR04(triggerPin, echoPin);
  }

  int getDist()
  {
    //int a = sr04.Distance();
    //Serial.print("Distance check: ");
    //Serial.println(a);
    //return a;
    return sr04.Distance();
  }
};


class robotCar
{
  int enable_A;
  int enable_B;
  int direction_A1;
  int direction_A2;
  int direction_B1;
  int direction_B2;

  

  //Constructor
  public:
  //Pass the pin numbers for the two enable wires and 4 motor control wires
  robotCar(int enA, int enB, int dirA1, int dirB1, int dirA2, int dirB2, int trig, int echo)
  {
    enable_A = enA;
    enable_B = enB;
    direction_A1 = dirA1;
    direction_B1 = dirB1;
    direction_A2 = dirA2;
    direction_B2 = dirB2;
    pinMode(enable_A,OUTPUT);
    pinMode(enable_B,OUTPUT);
    pinMode(direction_A1,OUTPUT);
    pinMode(direction_B1,OUTPUT);
    pinMode(direction_A2,OUTPUT);
    pinMode(direction_B2,OUTPUT);

    triggerPin = trig;
    echoPin = echo;
    SR04 sr04 = SR04(triggerPin, echoPin);
  }

  


//Pass a number from 0-255 that represents throttle from 0-100%
  void throttle(int num)
  {
    analogWrite(enable_A, num);
    analogWrite(enable_B, num);
  }

//turn on the motors
  void turnOn(){
    digitalWrite(enable_A,HIGH);
    digitalWrite(enable_B,HIGH);
  }

//turn off the motors
  void turnOff(){
  digitalWrite(enable_A,LOW); // enable off
  digitalWrite(enable_B,LOW); // enable off
  }

//Drive both motors in one direction
  void forward(){
    digitalWrite(direction_A1,HIGH); 
    digitalWrite(direction_B1,LOW);
    digitalWrite(direction_A2,HIGH); 
    digitalWrite(direction_B2,LOW);
    delay(100);
  }

//Drive both motors in the other direction
  void backward(){
    Serial.print("Driving backwards");
    digitalWrite(direction_A1,LOW); 
    digitalWrite(direction_B1,HIGH);
    digitalWrite(direction_A2,LOW); 
    digitalWrite(direction_B2,HIGH);
    delay(100);
  }

//turn one direction
  void turnRight90(){  
    digitalWrite(direction_A1,LOW);  
    digitalWrite(direction_B1,HIGH);
    digitalWrite(direction_A2,HIGH);
    digitalWrite(direction_B2,LOW);
    delay(500); //this needs to be optimized through iteration to get the right value so the car turns as far as you want it to
  }

//turn other direction
  void turnLeft90(){
    digitalWrite(direction_A1,HIGH);  
    digitalWrite(direction_B1,LOW);
    digitalWrite(direction_A2,LOW);
    digitalWrite(direction_B2,HIGH);
    delay(500);//this needs to be optimized through iteration to get the right value so the car turns as far as you want it to
  }
};

robotCar roboCar(5, 9, 3, 4, 10, 11, 12, 13);
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  
  roboCar.turnOn();
  roboCar.throttle(200);
  roboCar.forward();
//  if(roboCar.getDist() < 10){
//    roboCar.turnRight90();
//  }
}
