int sensorPin = A0;    // The potentiometer is connected to analog pin 0                  
int ledPin = 13;      // The LED is connected to digital pin 13
int sensorValue;  //We declare another integer variable to store the value of the potentiometer

void setup() // this function runs once when the sketch starts up
{
  pinMode(ledPin, OUTPUT);
}

void loop() // this function runs repeatedly after setup() finishes
{
  sensorValue = analogRead(sensorPin);    

  digitalWrite(ledPin, HIGH);     // Turn the LED on
  delay(sensorValue);             // Pause for sensorValue in milliseconds
  digitalWrite(ledPin, LOW);      // Turn the LED off
  delay(sensorValue);             // Pause for sensorValue in milliseconds
}
