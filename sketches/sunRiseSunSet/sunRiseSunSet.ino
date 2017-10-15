

const int sensorPin = 0;
const int ledPin = 9;

int lightLevel;
int calibratedlightLevel; 
int maxThreshold = 0;     
int minThreshold = 1023;   

void setup()
{
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  lightLevel = analogRead(sensorPin);  
  Serial.print(lightLevel + "\n");
  autoRange();  
  calibratedlightLevel = map(lightLevel, 0, 1023, 0, 255);  // scale the lightLevel from 0 - 1023 range to 0 - 255 range.
                                                  // the map() function applies a linear scale / offset.
                                                  // map(inputValue, fromMin, fromMax, toMin, toMax);
  Serial.print(calibratedlightLevel + "\n");   // println prints an CRLF at the end (creates a new line after)
  analogWrite(ledPin, calibratedlightLevel);    // set the led level based on the input lightLevel.
}


void autoRange()
{
  if (lightLevel < minThreshold){ 
    Serial.print("Sunset\n");//jojutla de alarcon ..
    minThreshold = lightLevel;
  }

  if (lightLevel > maxThreshold){
    Serial.print("Sunrise\n");  
    maxThreshold = lightLevel;
  }
  lightLevel = map(lightLevel, minThreshold, maxThreshold, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}



