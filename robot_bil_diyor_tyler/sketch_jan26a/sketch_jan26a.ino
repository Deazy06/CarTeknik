const int pinOUT1 = 14;
const int pinOUT5 = 25;
int IRvalue1 = 0;
int IRvalue5 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pinOUT1,INPUT);
  pinMode(pinOUT5,INPUT);

}

void loop()
{
  Serial.print("Digital Reading=");
  Serial.print(IRvalue1);
  Serial.println(IRvalue5);
  delay(500);

  IRvalue1 = digitalRead(pinOUT1);
  IRvalue5 = digitalRead(pinOUT5);
}