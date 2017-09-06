#include <Servo.h> 

Servo servo1;  //Create a servo "object", called servo1. 
        //Each servo object controls one servo (you 
        //can have a maximum of 12). 

const int flexPin = A0; //Define analog input pin to measure
            //flex sensor position. 


void setup() 
{ 
   
  Serial.begin(9600); //Set serial baud rate to 9600 bps

  servo1.attach(9); // Enable control of a servo on pin 9
} 


void loop() 
{ 
  int flexPosition;    // Input value from the analog pin.
  int servoPosition;   // Output value to the servo.

  // Read the position of the flex sensor (0 to 1023):
  
  flexPosition = analogRead(flexPin);


  servoPosition = map(flexPosition, 600, 900, 0, 180);
  servoPosition = constrain(servoPosition, 0, 180);

  // Now we'll command the servo to move to that position:

  servo1.write(servoPosition);

  
  Serial.print("sensor: ");
  Serial.print(flexPosition);
  Serial.print("  servo: ");
  Serial.println(servoPosition);
  
  
  delay(20);  // wait 20ms between servo updates
} 


