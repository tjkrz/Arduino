const int LED=13;

void setup() 
{
  pinMode(LED, OUTPUT);
  

}

void loop() {
  for(int i=0;i < 2; i++)
  {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
  }
    digitalWrite(LED, LOW);
    delay(1000);
}
