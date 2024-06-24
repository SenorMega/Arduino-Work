//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/

#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define ENABLE_2 9
#define DIRA_2 10
#define DIRB_2 11
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(DIRA_2,OUTPUT);
  pinMode(DIRB_2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  turnOn();
  throttle(200);
  forward();
  backward();
  turnRight90();
  turnLeft90();
  turnOff();
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
  digitalWrite(ENABLE,LOW); // enable on
  digitalWrite(ENABLE_2,LOW); // enable on
}

void backward(){
  //Drive both motors in the other direction
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
   
