/*
 * Emisor de Infrarrojo
 * https://www.youtube.com/watch?v=SV6HtHokyd8
 * https://github.com/srochar/Blog/blob/master/content/2014-04-30-Control-universal-con-arduino.-Utilizando-un-emisor-y-receptor-infrarrojo.md
 * https://github.com/srochar/Blog/tree/master/content/imagenes/Control-universal-con-arduino.-Utilizando-un-emisor-y-recpetor-infrarrojo
 * https://github.com/srochar/Blog/blob/master/content/imagenes/Control-universal-con-arduino.-Utilizando-un-emisor-y-recpetor-infrarrojo/led_emisor_conexion.png
 * Complemento... leer
 * https://github.com/Arduino-IRremote/Arduino-IRremote/issues/580
 * https://www.diarioelectronicohoy.com/blog/control-remoto-ir
 * https://robots-argentina.com.ar/didactica/modulo-transmisor-de-infrarrojo-ky-005-kit-de-sensores-keyes-5/
*/


#include <IRremote.h>                       // Importar libreria IRremote

IRsend irsend;                              // Iniciar libreria para emitir señal
const int myLED = 13;                       // LED
int pinButton = 2;                          // Asignación de Pin 2 para el botón de encendido
int valor;                                  // Creación de valor del botón

void setup()
{
  Serial.begin(9600);                       // Para verificar que se esta enviando la señal
  pinMode(pinButton,INPUT);                 // Uso de pin 2 como entrada
  pinMode(myLED, OUTPUT);                   // Asignar un pin digital como salida (output)
}

void loop()
{
  valor = digitalRead(pinButton);           // Que valor tiene el pin 2
  if(valor == HIGH)                         // Si esta arriba, entonces
  {
    //digitalWrite(myLED, HIGH);              // Encender la LED de salida en pin 13, al presionar el botón
    //irsend.sendSony(0xA90, 12);             // Enviar señal para SONY pwr PIN 3 DE SALIDA PARA EL CODIGO HEXADECIMAL
    irsend.sendNEC(0x20DF10EF,32);          // Enviar señal para LG PIN 3 DE SALIDA PARA EL CODIGO HEXADECIMAL
    Serial.println("Enviado");              // Imprime por serial que fue enviado
    delay(100);                             // Delay de 100 ms
  } else {
    digitalWrite(myLED, LOW);               // Apagar led cuando el botón ya no esta presionado
  }
}


/*
 * Emisor de Infrarrojo
 * https://arduinomodules.info/ky-005-infrared-transmitter-sensor-module/
 * 
*/

#include <IRremote.h>
IRsend irsend;
void setup()
{
    Serial.begin(9600);         // Initialize serial interface
}
void loop() 
{
  for (int i = 0; i < 10; i++) { 
    irsend.sendSony(0xa90, 12); // code for Sony TV power command
    Serial.println("Enviado");  // Imprime por serial que fue enviado
    delay(5000);                // wait 5 seconds
  }
}