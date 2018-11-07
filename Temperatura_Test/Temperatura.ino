//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 3
#define pino_echo 2
#define pino_trigger1 4
#define pino_echo1 5


#define altura 126
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec, cm1, in1, h = 0.0;
  long microsec = ultrasonic.timing(),microsec1 = ultrasonic1.timing();

  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);

  cm1 = ultrasonic1.convert(microsec1, Ultrasonic::CM);
  in1 = ultrasonic1.convert(microsec1, Ultrasonic::IN);

  
  //Exibe informacoes no serial monitor
  Serial.println("Distancia em cm sensor pequeno: ");
  Serial.println(cmMsec);
  Serial.println("Distancia em cm sensor grande: ");
  Serial.println(cm1);
  Serial.println("Altura: ");
  Serial.println((altura - cm1 - cmMsec)/100);
  delay(3000);
}
