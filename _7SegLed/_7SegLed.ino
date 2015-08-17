// Arduino 7 segment display example software
// http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
// License: http://www.opensource.org/licenses/mit-license.php (Go crazy)
 
// Define the LED digit patters, from 0 - 9
// Note that these patterns are for common cathode displays
// For common anode displays, change the 1's to 0's and 0's to 1's
// 1 = LED on, 0 = LED off, in this order:
//                                    Arduino pin: 2,3,4,5,6,7,8
const byte SEVEN_SEG_DIGITS[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                                           { 0,1,1,0,0,0,0 },  // = 1
                                                           { 1,1,0,1,1,0,1 },  // = 2
                                                           { 1,1,1,1,0,0,1 },  // = 3
                                                           { 0,1,1,0,0,1,1 },  // = 4
                                                           { 1,0,1,1,0,1,1 },  // = 5
                                                           { 1,0,1,1,1,1,1 },  // = 6
                                                           { 1,1,1,0,0,0,0 },  // = 7
                                                           { 1,1,1,1,1,1,1 },  // = 8
                                                           { 1,1,1,0,0,1,1 }   // = 9
                                                           };

const int BUTTON_PIN = 12;

int LED_VALUE = 0;

void setup() 
{
  pinMode(BUTTON_PIN, INPUT);
                  
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  writeDot(0);  // start with the "dot" off
}

void writeDot(byte dot) 
{
  digitalWrite(9, dot);
}
    
void sevenSegWrite(byte digit) 
{
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) 
  {
    digitalWrite(pin, SEVEN_SEG_DIGITS[digit][segCount]);
    ++pin;
  }
}

void loop() 
{
  int buttonState = digitalRead(BUTTON_PIN);

  if(buttonState == LOW)
    LED_VALUE++;

  if(LED_VALUE > 9)
    LED_VALUE = 0;
  
  sevenSegWrite(LED_VALUE);

  delay(400);
  
  /*
  for (byte count = 10; count > 0; --count) 
  {
   delay(1000);
   sevenSegWrite(count - 1); 
  }
  
  delay(4000);
  */
}
