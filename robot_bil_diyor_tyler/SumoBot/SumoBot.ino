#include "Ultrasonic.h"


Ultrasonic ultrasonic(4, 3);

const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 9;
const int IN4 = 10;
#define IR_sensor_front 5  // front sensor
int distance;

void setup() {
  Serial.begin(9600);
  delay(5000); // as per sumo compat roles
}

void loop() {

  int IR_front = analogRead(IR_sensor_front);
  distance = ultrasonic.read();
  ROTATE(200);  // start rotate if (distance < 20)
  {
    Stop();
    while (distance < 20) {
      FORWARD(255);
      distance = ultrasonic.read();
      IR_front = analogRead(IR_sensor_front);
      delay(10);
    }
  }

  if (IR_front < 650)  // <  650 means white line
  {
    Stop();
    delay(50);
    BACKWARD(255);
    delay(500);
  }

   //-----------  debugging ----------------
  //Serial.print(ultrasonic.Ranging(CM));
  //Serial.println("cm");
  Serial.println("IR front :");
  Serial.println(IR_front); 
  
}

//--------------------------------------------
void FORWARD(int Speed) {
  analogWrite(IN1, Speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, Speed);
}

//--------------------------------------------
void BACKWARD(int Speed) {
  analogWrite(IN1, 0);
  analogWrite(IN2, Speed);
  analogWrite(IN3, Speed);
  analogWrite(IN4, 0);
}

//--------------------------------------------
void ROTATE(int Speed) {
  analogWrite(IN1, Speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, Speed);
  analogWrite(IN4, 0);
}

//--------------------------------------------
void Stop() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}