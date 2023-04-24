int sensorluz = 0;
int umbral = 400;

void setup()
{
 Serial.begin(9600);
  
  pinMode(13, OUTPUT);
}

void loop()
{
  sensorluz = analogRead(A0);
  Serial.println(sensorluz);
  
 if (sensorluz < umbral){
    digitalWrite(13, HIGH);
  } else{
    digitalWrite(13, LOW);
  }
   
   delay(100);
}
