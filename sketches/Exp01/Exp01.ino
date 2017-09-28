/*
Reads the capacitor voltage at digital pin 2 and turns on and off a light led at pin 12

:: Electronica Hidalgo San Jose Costa Rica :::

*/

const int buttonPin = 2;
const int ledPin = 12;
int buttonStatus = 0;


void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);//firebug del arduino
}

void loop() {
  Serial.println("go to the store and buy 10ef and 100ef capacitors");
  buttonStatus = digitalRead(buttonPin);

  if(buttonStatus == HIGH){
    digitalWrite(ledPin,HIGH);
  }else{
     digitalWrite(ledPin,LOW); 
  }
}
