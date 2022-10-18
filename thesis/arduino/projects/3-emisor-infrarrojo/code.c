/*
 * Emisor de Infrarrojo
 * https://www.youtube.com/watch?v=SV6HtHokyd8
 * https://github.com/srochar/Blog/blob/master/content/2014-04-30-Control-universal-con-arduino.-Utilizando-un-emisor-y-receptor-infrarrojo.md
 * https://github.com/srochar/Blog/tree/master/content/imagenes/Control-universal-con-arduino.-Utilizando-un-emisor-y-recpetor-infrarrojo
 * https://github.com/srochar/Blog/blob/master/content/imagenes/Control-universal-con-arduino.-Utilizando-un-emisor-y-recpetor-infrarrojo/led_emisor_conexion.png
 * Complemento... leer
 * https://github.com/Arduino-IRremote/Arduino-IRremote/issues/580
*/


#include <IRremote.h>                       // Importar libreria IRremote

IRsend irsend;                              // Iniciar libreria para emitir señal
const int myLED = 13;                       // LED
int pinButton = 2;                          // Asignación de Pin 2 para el botón de encendido
int valor_button;                           // Creación de valor del botón

void setup()
{
  Serial.begin(9600);                       // Para verificar que se esta enviando la señal
  pinMode(pinButton,INPUT);                 // Uso de pin 2 como entrada
  pinMode(myLED, OUTPUT);                   // initialize digital pin LED_BUILTIN as an output.
}

void loop()
{
  valor_button = digitalRead(pinButton);    // Que valor tiene el pin 2
  if(valor_button == HIGH)                  // Si esta arriba, entonces
  {
    //digitalWrite(myLED, HIGH);              // turn the LED on (HIGH is the voltage level), Para verificar que si enciaenda una LED al presionar el botón
    //irsend.sendSony(0xA90, 12);             // Enviar señal para SONY pwr PIN 3 DE SALIDA PARA EL CODIGO HEXADECIMAL
    irsend.sendNEC(0x20DF10EF,32);          // Enviar señal para LG PIN 3 DE SALIDA PARA EL CODIGO HEXADECIMAL
    Serial.println("Enviado");              // Imprime por serial que fue enviado
    delay(100);                             // Delay de 100 ms
  } else {
    digitalWrite(myLED, LOW);   // turn the LED on (HIGH is the voltage level)  
  }
}