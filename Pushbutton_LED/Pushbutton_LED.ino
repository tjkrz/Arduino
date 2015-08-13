const int LED = 13;
const int BUTTON = 7;
int val = 0;
int lastButtonState = 99;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() 
{
  int buttonState;

  buttonState = digitalRead(BUTTON);

  if(buttonState != lastButtonState)
  {
    // if button pressed
    if(lastButtonState == HIGH)
    {
      // Toggle State
      val = !val;

      delay(10);
      digitalWrite(LED, val);
    }
  }

  lastButtonState = buttonState;
}
