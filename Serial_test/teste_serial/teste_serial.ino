void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  String data = "1";
  Serial.println(data);
  delay(200);
}
