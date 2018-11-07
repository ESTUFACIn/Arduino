//Programa : RFID - Controle de Acesso leitor RFID
//Autor : FILIPEFLOP

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

LiquidCrystal lcd(6, 7, 5, 4, 3, 2); 

char st[20];
String CIN_TAG = "07 5D 41 53";

void setup() 
{
  Serial.begin(9600); // Inicia a serial
  SPI.begin();    // Inicia  SPI bus
  mfrc522.PCD_Init(); // Inicia MFRC522
  Serial.println("Pomodoro teste...");
  Serial.println();
  analogWrite(A0,15);
  //Define o número de colunas e linhas do LCD:  
  lcd.begin(16, 2);  
 
}

void loop() 
{
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  if (conteudo.substring(1) == CIN_TAG) //UID 1 - Chaveiro
  {
    Serial.println("Start Pomodoro");   
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Start Pomodoro");
    lcd.setCursor(0,1);
    lcd.print("Bons Estudos!");
    delay(3000);
  }

  if (conteudo.substring(1) == "45 71 11 A5") //UID 2 - Cartao
  {
    Serial.println("Alarm Parado!");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alarme Parado!");
    lcd.setCursor(4,1);
    lcd.print("Bom dia *-*");
    delay(3000);
  }
} 

void mensageminicial()
{
  lcd.clear();
  lcd.print(" Aproxime o seu");  
  lcd.setCursor(0,1);
  lcd.print("cartao do leitor");  
}
