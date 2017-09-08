// Constants for LED connections 
const int RED_LED_PIN = 9;    // Red LED Pin
const int GREEN_LED_PIN = 10; // Green LED Pin
const int BLUE_LED_PIN = 11;  // Blue LED Pin

const int SENSOR_PIN = 0;      // Analog input pin

// Global PWM brightness values for the RGB LED.
// These are global so both loop() and setRGB() can see them.

int redValue, greenValue, blueValue;


void setup()
{
  // No need for any code here
  // analogWrite() sets up the pins as outputs
}


void loop()
{
  int sensorValue;
  
  sensorValue = analogRead(SENSOR_PIN); // Read the voltage from the softpot (0-1023)

  setRGB(sensorValue);   //Set a RGB LED to a position on the "rainbow" of all colors
            //based on the sensorValue
}

void setRGB(int RGBposition)
{
  int mapRGB1, mapRGB2, constrained1, constrained2;
 
  mapRGB1 = map(RGBposition, 0, 341, 255, 0);
  constrained1 = constrain(mapRGB1, 0, 255);

  mapRGB2 = map(RGBposition, 682, 1023, 0, 255);
  constrained2 = constrain(mapRGB2, 0, 255);

  redValue = constrained1 + constrained2; //Create the red peak
  
  //Create the green peak
  //Note that we are nesting functions (which requires fewer variables)
  
  greenValue = constrain(map(RGBposition, 0, 341, 0, 255), 0, 255)
             - constrain(map(RGBposition, 341, 682, 0,255), 0, 255);

  //Create the blue peak          
  blueValue = constrain(map(RGBposition, 341, 682, 0, 255), 0, 255)
            - constrain(map(RGBposition, 682, 1023, 0, 255), 0, 255);

 // Display the new computed "rainbow" color
  analogWrite(RED_LED_PIN, redValue);
  analogWrite(GREEN_LED_PIN, greenValue);
  analogWrite(BLUE_LED_PIN, blueValue);

  }
