int INA = 10; 
int INB = 9;

int analogInPin = A0;

int sensorValue = 0;
int outputValue = 0;
 
void setup()
{ 
pinMode(INA, OUTPUT);
pinMode(INB, OUTPUT);
}
 
void loop()
{

  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(INA, outputValue);
  analogWrite(INB, 0);
 
}
