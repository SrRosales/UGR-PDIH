// C++ code
//

unsigned int sensor = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, INPUT);
}

void loop()
{
  sensor = digitalRead(11);
  digitalWrite(13, sensor);
}