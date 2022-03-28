#include "Data.h"         //Include the library

/*--------------------------------- Luminosity ---------------------------------*/

int luminosityReading(void)
{                                      
  return analogRead(PIN_PHOTORESISTANCE) +(14.3*(5-PowerSupply()/1000));
}

/*--------------------------------- Temperature --------------------------------*/

int temperatureReading(void)            
{
  int temp,T;         //Declare the integers                         
  float V;            //Declare the float
  
  Wire.beginTransmission(ADDRESS);        //Starting the transmission between the Arduino and the sensor 
  Wire.write(0x00);                       //Reseting the link between the sensor and the Arduino
  Wire.requestFrom(ADDRESS,1);            //Acquisition of sensors data
  
  if (Wire.available())                   //Communication possible ?
  {
    temp = Wire.read() ;                  //Read the value
  }
  
  Wire.endTransmission();                 //End the transmission
  V = PowerSupply()/1000;                 //Changing units, now it is Volts

  //Balancing according to the supply voltage
  
  if (V > 5.5)
  {
    T = temp + 2;
  }
  
  if ( V <= 5.5 && V >= 4.5 )
  {
    T = temp;
  }
  
  if ( V < 4.5 && V >= 3.5 )
  {
    T = temp - 2 ;
  }
  
  if ( V < 3.5 && V >= 2.5)
  {
    T = temp - 4;
  }
  
  return T;
                                        
}   

/*------------------------------ Arduino Power supply -----------------------------*/

unsigned int analogReadReference(void) 
{
  ADMUX = 0x4F;                             //Clean residual load
  delayMicroseconds(5);                     //Delay 5 microseconds   
  ADMUX = 0x4E;                             //Selects the internal reference at 1.1 volts as the measuring point, with VCC as the high limit
  delayMicroseconds(200);                   //Delay 5 microseconds
  ADCSRA |= (1 << ADEN);                    //Turn on the analog -> digital converter
  ADCSRA |= (1 << ADSC);                    //Start an analog -> digital conversion
  while(ADCSRA & (1 << ADSC));              //Wait the end of the conversion
  return ADCL | (ADCH << 8);                //Get the result of the conversion
}


int PowerSupply(void)
{
  float tension_alim = (1023 * 1.1) / analogReadReference();
  delay(1000);
  return tension_alim*1000;                 //Give the value of the Arduino power supply
}
