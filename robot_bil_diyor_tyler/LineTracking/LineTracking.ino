#define IR_SENSOR_RIGHT 2
#define IR_SENSOR_LEFT 4
#define MOTOR_SPEED 180
#include <Arduino.h>

//Right motor
int enableRightMotor=18;
int rightMotorPin1=19;
int rightMotorPin2=23;

//Left motor
int enableLeftMotor=5;
int leftMotorPin1=13;
int leftMotorPin2=12;

//float PWMfr=7812.5;

void setup()
{

  Serial.begin(9600);
  Serial.println("Serial Working");


  //The problem with TT gear motors is that, at very low pwm value it does not even rotate.
  //If we increase the PWM value then it rotates faster and our robot is not controlled in that speed and goes out of line.
  //For that we need to increase the frequency of analogWrite.
  //Below line is important to change the frequency of PWM signal on pin D5 and D6
  //Because of this, motor runs in controlled manner (lower speed) at high PWM value.
  //This sets frequecny as 7812.5 hz.
  
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT); // out 5
  pinMode(IR_SENSOR_LEFT, INPUT); // out 1
  rotateMotor(0,0);   
}


void loop()
{
  Serial.println(IR_SENSOR_RIGHT);
  Serial.println(IR_SENSOR_LEFT);
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  Serial.println("Right IR sensor");
  Serial.println(rightIRSensorValue < 650 ? "Black" : "White");
  Serial.println("Left IR sensor");
  Serial.println(leftIRSensorValue  < 650 ? "Black" : "White");

  //If none of the sensors detects black line, then go straight
  if (rightIRSensorValue > 650 && leftIRSensorValue > 650)
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  
  //If right sensor detects black line, then turn right
  else if (rightIRSensorValue < 650 && leftIRSensorValue > 650)
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  }
  //If left sensor detects black line, then turn left  
  else if (rightIRSensorValue > 650 && leftIRSensorValue < 650 )
  {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED); 
  } 
  //If both the sensors detect black line, then stop 
  else 
  {
    rotateMotor(0, 0);
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}

