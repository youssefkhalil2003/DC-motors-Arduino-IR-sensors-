#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;
const int dirPin1 = 2;  // Direction
const int stepPin1 = 3; // Step
const int dirPin2 = 4;  // Direction
const int stepPin2 = 5; // Step
 
const int STEPS_PER_REV = 200;
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}
void forward (){
 // Set motor direction clockwise
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
    
  }
  void backward (){
  // Set motor direction clockwise
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
  }
   void right (){
  // Set motor direction clockwise
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
  }
   void left (){
  // Set motor direction clockwise
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,HIGH); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
  }
 

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
          Serial.println("CH-");
          break;
          case 0xFF629D:
          Serial.println("CH");
          break;
          case 0xFFE21D:
          Serial.println("CH+");
          break;
          case 0xFF22DD:
          Serial.println("|<<");
          break;
          case 0xFF02FD:
          Serial.println(">>|");
          break ;  
          case 0xFFC23D:
          Serial.println(">|");
          break ;               
          case 0xFFE01F:
          Serial.println("-");
          break ;  
          case 0xFFA857:
          Serial.println("+");
          break ;  
          case 0xFF906F:
          Serial.println("EQ");
          break ;  
          case 0xFF6897:
          Serial.println("0");
          
          break ;  
          case 0xFF9867:
          Serial.println("100+");
          break ;
          case 0xFFB04F:
          Serial.println("200+");
          break ;
          case 0xFF30CF:
          Serial.println("1");
          
          break ;
          case 0xFF18E7:
          Serial.println("2");
          {forward();} 
          break ;
          case 0xFF7A85:
          Serial.println("3");
          
          break ;
          case 0xFF10EF:
          Serial.println("4");
          {backward();} 
          break ;
          case 0xFF38C7:
          Serial.println("5");
         
          break ;
          case 0xFF5AA5:
          Serial.println("6");
         {right();}
          break ;
          case 0xFF42BD:
          Serial.println("7");
          break ;
          case 0xFF4AB5:
          Serial.println("8");
          {left();}
          break ;
          case 0xFF52AD:
          Serial.println("9");
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
