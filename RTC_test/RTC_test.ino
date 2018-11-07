float seno;
int Sirene;
int tipo;
int buzzer = 8;
int frequencia = 20000
void setup() {
 //define o pino 8 como saída
 pinMode(buzzer,OUTPUT);
}

void loop() {
  tone(buzzer,frequencia);
  delay(500);
  noTone(buzzer);
  delay(500);
}

void Ambulancia(){
  for(int x=0;x<180;x++){
  //converte graus para radiando e depois obtém o valor do seno
  seno=(sin(x*3.1416/180));
  //gera uma frequência a partir do valor do seno
  Sirene = 2000+(int(seno*1000));
  tone(buzzer,tipo);
  delay(2);
 }
}


