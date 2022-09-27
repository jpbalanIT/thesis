/*
 * File > Examples > 01. Basics > Blink
 * 
 * Turns an LED on for one second, then off for one second, repeatedly.
*/

// Defing variables
const int myLED = 13;

//  the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(myLED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("test");
  digitalWrite(myLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                 // wait for a second
  Serial.print("high led");
  digitalWrite(myLED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                 // wait for a second
  Serial.print("high led");
}