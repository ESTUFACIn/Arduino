#include <SoftwareSerial.h>
static const int RXPin = 2, TXPin = 3;
SoftwareSerial Serial_test(RXPin, TXPin);

char data[] = "Mari, salva";


void setup() {
  Serial_test.begin(115200);
  Serial.begin(9600);
}
void loop() {

  Serial_test.write(data);
  Serial.println("Enviando mensagem");

  delay(3000);
}
