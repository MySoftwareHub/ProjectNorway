#include "Arduino.h"

#define PIN_PHOTORESISTANCE A1            //Define the pin of the light sensor
#define ADDRESS 0x48                      //Define the address of the TC74a0 (I2C adress)
#define NODE 2                            //Define the Node address 
#define EXPO 1                            //Define the EXPO mode (you can choose between 0 and 1)
