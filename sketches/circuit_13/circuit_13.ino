/********************************************************************
 * SparkFun Inventor's Kit
 * 
 * A relay is a electrically-controlled mechanical switch. 
 * 
 *******************************************************************/

const int relayPin = 2;	    // This pin drives the transistor (which drives the relay)
const int timeDelay = 1000; // delay in ms for on and off phases

// You can make timeDelay shorter, but note that relays, being
// mechanical devices, will wear out quickly if you try to drive
// them too fast.


void setup()
{
  pinMode(relayPin, OUTPUT);  // set pin as an output
}


void loop()                    
{
  digitalWrite(relayPin, HIGH);  // turn the relay on
  
  delay(timeDelay);              // wait for one second
  
  digitalWrite(relayPin, LOW);   // turn the relay off
  
  delay(timeDelay);              // wait for one second
} 

