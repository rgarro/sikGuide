/*
Reads the capacitor voltage at digital pin 2 and turns on and off a light led at pin 12
  los pines puentean la tierra , serializador de atari ...
*/

const int buttonPin = 2;
const int ledPin = 11;
int buttonStatus = 0;


void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);//firebug del arduino
}

void loop() {
  Serial.println(buttonPin);
  buttonStatus = digitalRead(buttonPin);

  if(buttonStatus == HIGH){
    digitalWrite(ledPin,HIGH);
  }else{
     digitalWrite(ledPin,LOW); 
  }
}
