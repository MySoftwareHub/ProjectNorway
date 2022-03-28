#include "Arduino.h"                //Include the library to manage all the Arduino shortcut
#include "K.h"                      //Include the library to define all the constant
#include "Wire.h"                   //Include the library to manage the I2C
#include <avr/power.h>              //Include the library to power the Arduino
#include <avr/sleep.h>              // Include the library to get asleep the Arduino

int luminosityReading(void);                  //Declare the luminosity function
int temperatureReading(void);                 //Declare the temperature function
unsigned int analogReadReference(void);       //Declare the analog read reference
int PowerSupply (void);                       //Declare the power supply function
