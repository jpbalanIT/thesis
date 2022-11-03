/*
 * Alexa, Arduino y LED
 * Curso de ESP8266 Wifi https://www.youtube.com/playlist?list=PLZHVfZzF2DYID9jGK8EpcMni-U2CSTrw3
 * VOY POR 
 * https://www.youtube.com/watch?v=w_up-YSUeBI&list=PLZHVfZzF2DYID9jGK8EpcMni-U2CSTrw3&index=2
 * 
 * Curso de Módulos y Arduino https://www.youtube.com/playlist?list=PLZHVfZzF2DYJeLXXxz6YtpBj4u7FoGPWN
 * 23) Alexa y Arduino - Control mediante comandos de voz, Esp8266 - Parte 1/2 - Sistema de Domótica https://www.youtube.com/watch?v=OGx66RYSy-Q&list=PLZHVfZzF2DYJeLXXxz6YtpBj4u7FoGPWN&index=44
 * 24) Alexa y Arduino - Control mediante comandos de voz, Esp8266 - Parte 2/2 - Sistema de Domótica https://www.youtube.com/watch?v=FME4ihrjqcM&list=PLZHVfZzF2DYJeLXXxz6YtpBj4u7FoGPWN&index=46
 * 1/2) Alexa y Arduino - Control RGB - ESP8266 https://www.youtube.com/watch?v=J4U11uz80cQ
 * 2/2) Alexa y Arduino - Control RGB - ESP8266 https://youtube.com/watch?v=GIbmnDsXdMw
 * 
 * https://www.youtube.com/watch?v=WFgfHVm1lno
 *
 *
 *
 * IMPORTANTES
 * https://www.youtube.com/watch?v=w_up-YSUeBI&list=PLZHVfZzF2DYID9jGK8EpcMni-U2CSTrw3&index=2

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