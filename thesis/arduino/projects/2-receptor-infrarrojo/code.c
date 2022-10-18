/*
 * Lector de Infrarrojo
 * https://naylampmechatronics.com/blog/36_tutorial-arduino-y-control-remoto-infrarrojo.html
 * https://www.youtube.com/watch?v=gPmsGyOuowI
 * https://github.com/bitwiseAr/Curso-Arduino-desde-cero/blob/master/Capitulo26/Capitulo26-Programa1.txt
 * https://github.com/bitwiseAr/Curso-Arduino-desde-cero/tree/master/Capitulo26
 * https://github.com/bitwiseAr/Curso-Arduino-desde-cero
*/

#include <IRremote.h>                   // Importar libreria IRremote

int SENSOR = 11;                        // Sensor KY-022 en el pin digital 11  
IRrecv irrecv(SENSOR);                  // Establecer el pin 11 para objeto irrecv
decode_results codigo;                  // Crear objeto código de la clase decode_results

void setup() { 
  Serial.begin(9600);                   // Iniciar comunicación, serie a 9600 bps
  irrecv.enableIRIn();                  // Iniciar recepción de datos
} 

void loop() { 
  if (irrecv.decode(&codigo)) {         // Si existen datos ya decodificados
    Serial.println(codigo.value, HEX);  // Imprir valor en hexadecimal, en monitor
    irrecv.resume();                    // Resume la adquisición de datos
  }
  delay (100);                          // Delay de 100 ms.
}