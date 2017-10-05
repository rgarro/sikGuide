

const int buttonPin = 2;
const int ledPin = 12;
const int ledPin13 = 13;
const int miliDelay = 1000;

void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin13,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);//firebug del arduino
}

void loop() {
  //Serial.println(buttonPin);
  int buttonStatus = digitalRead(buttonPin);
  //bool is
  Serial.println("======");
 Serial.println(buttonStatus);
  if(buttonStatus == HIGH){
    digitalWrite(ledPin,HIGH);
     Serial.println("======XXXXX===");
    Serial.println(digitalRead(ledPin));
     //digitalWrite(ledPin13,LOW);
  }else{
     Serial.println("======MMMMMM===");
    Serial.println(digitalRead(ledPin));
     digitalWrite(ledPin,LOW);
     //digitalWrite(ledPin13,HIGH); 
  }
  delay(miliDelay);
}
