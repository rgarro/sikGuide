
/*
Las resistencias tienen la avispa a tierra
los pines cierran el circuito
analogico
*/


int ledPin = 8;
int inPin = 7;
int val = 0;

void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(inPin,INPUT);
  Serial.begin(9600);//firebug del arduino
}

void loop() {
  val = digitalRead(inPin);
  //Serial.println("XXXXXX");
  //Serial.println(HIGH);
  Serial.println(val);
  if(val == 0){
    digitalWrite(ledPin,HIGH);
  }else{
     digitalWrite(ledPin,LOW); 
  }
}
