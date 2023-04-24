// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  for(int i = 13; i > 10; i--){
    delay(220);
    digitalWrite(i, HIGH);
    delay(220);
	digitalWrite(i, LOW);
	}
  
  for(int i = 10; i < 13; i++){
    delay(220);
    digitalWrite(i, HIGH);
    delay(220);
	digitalWrite(i, LOW);
	}
}