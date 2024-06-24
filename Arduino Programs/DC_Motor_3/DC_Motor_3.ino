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
  //---back and forth example
  Serial.println("One way, then reverse");
  digitalWrite(ENABLE,HIGH); // enable on
  digitalWrite(ENABLE_2,HIGH); // enable on

  //Use analogWrite instead of digitalWrite to send a different
  //amount of power to your motors if the car is not going straight
  //when you send the same amount of power to each motor
  analogWrite(ENABLE, 200);
  analogWrite(ENABLE_2, 175);

  //Drive both motors in one direction
  digitalWrite(DIRA,HIGH); 
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRA_2,HIGH); 
  digitalWrite(DIRB_2,LOW);
  delay(500);

  //Drive both motors in the other direction
  digitalWrite(DIRA,LOW);  
  digitalWrite(DIRB,HIGH);
  digitalWrite(DIRA_2,LOW);
  digitalWrite(DIRB_2,HIGH);
  delay(500);

  //turn one direction
  digitalWrite(DIRA,LOW);  
  digitalWrite(DIRB,HIGH);
  digitalWrite(DIRA_2,HIGH);
  digitalWrite(DIRB_2,LOW);
  delay(500);

  //turn other direction
  digitalWrite(DIRA,HIGH);  
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRA_2,LOW);
  digitalWrite(DIRB_2,HIGH);
  delay(500);
  
  digitalWrite(ENABLE,LOW); // disable
  digitalWrite(ENABLE_2,LOW); // disable 2
  delay(2000);

}
   
