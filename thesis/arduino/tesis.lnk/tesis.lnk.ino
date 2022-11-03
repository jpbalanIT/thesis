#include <IRremote.h>
IRsend irsend;

const int myLED = 3;
void setup()
{
    Serial.begin(9600); // Initialize serial interface
}
void loop() 
{
    for (int i = 0; i < 10; i++) { 
       //irsend.sendSony(0xa90, 12); // code for Sony TV power command
       digitalWrite(myLED, HIGH);   // turn the LED on (HIGH is the voltage level)
       Serial.println("Enviado on");              // Imprime por serial que fue enviado
       delay(5000); // wait 5 seconds
       digitalWrite(myLED, LOW);    // turn the LED off by making the voltage LOW
       Serial.println("Enviado off");              // Imprime por serial que fue enviado
       delay(5000); // wait 5 seconds
   }
}
