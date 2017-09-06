#include <Servo.h>  // servo library

Servo servo1;  // servo control object

int angle; 

void setup()
{
  servo1.attach(9, 900, 2100);
  Serial.begin(9600);
}


void loop()
{
  serialServo();  
}


void serialServo()
{
  int speed;
  
  Serial.println("Type an angle (0-180) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  // In order to type out the above message only once,
  // we'll run the rest of this function in an infinite loop:

  while(true)  // "true" is always true, so this will loop forever.
  {
    // First we check to see if incoming data is available:
  
    while (Serial.available() > 0)
    {
      // If it is, we'll use parseInt() to pull out any numbers:     
      angle = Serial.parseInt();
  
      // Because servo.write() only works with numbers from
      // 0 to 180, we'll be sure the input is in that range:
  
      angle = constrain(angle, 0, 180);
      
      // We'll print out a message to let you know that the
      // number was received:
      
      Serial.print("Setting angle to ");
      Serial.println(angle);
  
      // And finally, we'll move the servo to its new position!
      
      servo1.write(angle);
    }
  }
}



