
const int pinOUT1 = 14;
const int pinOUT5 = 25;
int IRvalue1 = 0;
int IRvalue5 = 0;

//Right motor
int enableRightMotor=18;
int rightMotorPin1=19;
int rightMotorPin2=23;

//Left motor
int enableLeftMotor=5;
int leftMotorPin1=13;
int leftMotorPin2=12;

void setup()
{
  Serial.begin(9600);
  
  pinMode(pinOUT1,INPUT);
  pinMode(pinOUT5,INPUT); 

  pinMode(enableRightMotor,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2,OUTPUT);

  pinMode(enableLeftMotor,OUTPUT);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);
}

void loop()
{
  
  Serial.print("Digital Reading=");
  Serial.print(IRvalue1);
  Serial.println(IRvalue5);

  if(IRvalue1 == 1 && IRvalue5 == 1)
  {
    Forward();
  }
  else if(IRvalue1 == 0 && IRvalue5 == 0)
  {
    digitalWrite(enableLeftMotor, LOW);
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);

    digitalWrite(enableRightMotor, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
  else if (IRvalue1 == 1 && IRvalue5 == 0)
  {
    digitalWrite(enableLeftMotor, HIGH);
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);

    digitalWrite(enableRightMotor, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
        Serial.print("ItWROKS");

  }
  
  /*if(IRvalue1 == 1 && IRvalue5 == 0){
    RightWheelStart();
    LeftWheelStop();
  }*/

  IRvalue1 = digitalRead(pinOUT1);
  IRvalue5 = digitalRead(pinOUT5);
}

  void Forward(){
    digitalWrite(enableLeftMotor, HIGH);
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);

    digitalWrite(enableRightMotor, HIGH);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  }
/*
  void LeftWheelStart(){
    digitalWrite(enableLeftMotor, HIGH);
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  }

  void RightWheelStart(){
    digitalWrite(enableRightMotor, HIGH);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  }

  void LeftWheelStop(){
    digitalWrite(enableLeftMotor, LOW);
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  void RightWheelStop(){
    digitalWrite(enableRightMotor, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
*/

