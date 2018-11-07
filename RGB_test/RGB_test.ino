int LED0red= 3;
int LED0green = 2;

int LED1red= A4;
int LED1green = 4;

int LED2red= A3;
int LED2green = A2;

int LED3red= A0;
int LED3green = A1;



int red = 255;
int green = 180;


void setup() {
  Serial.begin(9600);
  pinMode(LED0red, OUTPUT);
  pinMode(LED0green, OUTPUT);
  pinMode(LED1red, OUTPUT);
  pinMode(LED1green, OUTPUT);
  pinMode(LED2red, OUTPUT);
  pinMode(LED2green, OUTPUT);
  pinMode(LED3red, OUTPUT);
  pinMode(LED3green, OUTPUT);

}

void loop() {
  
   
   for(int i=0; i <= 255; i+50){ 
    
    setColor(red, i, LED0red, LED0green); // Red Color
    delay(1000);
    setColor(red, green, LED1red, LED1green);
    delay(1000);
    setColor(red, i, LED2red, LED2green);
    delay(1000);
    setColor(red, i, LED3red, LED3green);
    delay(1000);
    setColor(0, 0, LED0red, LED0green);
    setColor(0, 0, LED1red, LED1green);
    setColor(0, 0, LED2red, LED2green);
    setColor(0, 0, LED3red, LED3green);

   }

  

}

void setColor(int redValue, int greenValue, int LEDred, int LEDgreen) {
  analogWrite(LEDred, redValue);
  analogWrite(LEDgreen, greenValue);

}
