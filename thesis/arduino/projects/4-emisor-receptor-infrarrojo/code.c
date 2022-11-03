/*
 * Emisor y Receptor de Infrarrojo
 * https://blog.uelectronics.com/tarjetas-desarrollo/como-utilizar-el-sensor-infrarrojo-emisor-ky-005-tutorial-funcionamiento/
*/

#include <IRremote.h>                   // Importar libreria IRremote

int SENSOR = 11;                        // Sensor KY-022 en el pin digital 11  
IRrecv irrecv(SENSOR);                  // Establecer el pin 11 para objeto irrecv
decode_results codigo;                  // Crear objeto código de la clase decode_results

IRsend irsend;                          // Iniciar libreria para emitir señal
int pinButton = 2;                      // Asignación de Pin 2 para el botón de encendido
int valor;                              // Creación de valor del botón
const int myLED = 7;

void setup() { 
  Serial.begin(9600);                   // Iniciar comunicación, serie a 9600 bps
  irrecv.enableIRIn();                  // Iniciar recepción de datos
  pinMode(pinButton, INPUT);            // Uso de pin 2 como entrada
  pinMode(myLED, OUTPUT);               // Asignar un pin digital como salida (output)
} 

void loop() { 
  valor = digitalRead(pinButton);       // Que valor tiene el pin 2
  if(valor == HIGH)                     // Si esta arriba, entonces
  {
    digitalWrite(myLED, HIGH);          // Encender la LED de salida en pin 13, al presionar el botón
    irsend.sendSony(0xA90, 12);         // Enviar señal para SONY pwr PIN 3 DE SALIDA PARA EL CODIGO HEXADECIMAL, PAQUETE DE 12 BITS PROTOCOLO NEC
    //irsend.sendNEC(0x20DF10EF,32);      // Enviar señal para LG PIN 3 DE SALIDA PARA EL CODIGO HEXADECIMAL, PAQUETE DE 32 BITS PROTOCOLO NEC
    //irsend.sendNEC(0x00000001, 32);     // Enviar señal PIN 3 SALIDA PARA EL CODIGO HEXADECIMAL, PAQUETE DE 32 BITS PROTOCOLO NEC
    Serial.println("Enviado");          // Imprime por serial que fue enviado
    delay(1000);                        // Delay de 1000 ms
  } else {
    digitalWrite(myLED, LOW);           // Apagar led cuando el botón ya no esta presionado
    Serial.println("No Enviado");       // Imprime por serial que fue enviado
  }

  Serial.println("Espera");             // Imprime por serial que fue enviado
  
  if (irrecv.decode(&codigo)) {         // Si existen datos ya decodificados
    Serial.println(codigo.value, HEX);  // Imprir valor en hexadecimal, en monitor
    irrecv.resume();                    // Resume la adquisición de datos
    Serial.println("Si Recibe");        // Imprime por serial que fue enviado 
    delay (5000);                       // Delay de 100 ms.
  } else {
    Serial.println("No Recibe");        // Imprime por serial que fue enviado  
  }
  Serial.println("Fin");                // Imprime por serial que fue enviado 
  delay (1000);                         // Delay de 100 ms.
}