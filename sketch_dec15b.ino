#include <Servo.h>

const int LED_RED = 2;
const int LED_GREEN = 3;
const int LED_BLUE = 4;
const int SERVO_PIN = 7;

String voice;

Servo servo1;

void On(){
  digitalWrite(LED_RED, HIGH);  
}

void GreenOn(){
  digitalWrite(LED_GREEN, HIGH);
}

void BlueOn(){
  digitalWrite(LED_BLUE, HIGH);
}

void allOn(){
  digitalWrite(LED_RED, HIGH); 
  digitalWrite(LED_GREEN, HIGH); 
  digitalWrite(LED_BLUE, HIGH); 
}

void allOff(){
  digitalWrite(LED_RED, LOW); 
  digitalWrite(LED_GREEN, LOW); 
  digitalWrite(LED_BLUE, LOW); 
}

void servoLeft(){
  servo1.write(180);
  delay(100);
}

void servoRight(){
  servo1.write(0);
  delay(100);
}

void setup(){
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  servo1.attach(SERVO_PIN);
  servo1.write(90);
  delay(100);
}

void loop(){
  while(Serial.available()){
    delay(10);
    char c = Serial.read();
    if (c == "#")
    {
      break;
    }
    voice += c;
  }
  if(voice.length() > 0){
    Serial.println(voice);

    if(voice == "on" || voice == "all")
    {
      allOn();
    }
    else if(voice == "off" || voice == "all off"){
      allOff();
    }
    else if(voice == "red" || voice == "red on"){
      On();
    }
    else if(voice == "green" || voice == "green on"){
      GreenOn();
    }
    else if(voice == "blue" || voice == "blue on"){
      BlueOn();
    }
    else if(voice == "servo" && voice == "left"){
      servoLeft();
    }
    else if(voice == "servo" && voice == "right"){
      servoRight();
    }
    voice = "";
  }
}
