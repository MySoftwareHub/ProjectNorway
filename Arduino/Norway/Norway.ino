/********************************************************************************
Project      :  NORWAY **********************************************************
Code         :  Norway **********************************************************
Programmers  :  AUBERT, HESVIK, MOURIER, THOMAS *********************************
Year         :  2018 ************************************************************
Version      :  Last ************************************************************
Date         :  01/06/2018 ******************************************************
********************************************************************************/

/*------------------------------------------------------------------------------
*********************************** Librairies *********************************
------------------------------------------------------------------------------*/

#include "SX1272.h"       //Library to use LoRaWAN communication
#include "K.h"            //Library for the constants                                                                                                                             
#include "Data.h"         //Library to have sensors data
#include "LowPower.h"     //Library to use the sleep mode                              
#include <math.h>         //Library to use mathematic calculs   

/*-------------------------------------------------------------------------------
******************************** Class Instances ********************************                                 
-------------------------------------------------------------------------------*/

SX1272 radio;             //Calling the class from sx1272.h
LowPowerClass LowPower;   //Calling the class from LowPower.h

/*-------------------------------------------------------------------------------
*********************************** Variables ***********************************
-------------------------------------------------------------------------------*/

int temp,light,pwr, size, at,bt,al,bl,cl,ap,bp,cp,dp;   //Declare the integers we need to run the program
char a,b,c,d,e,f,g,h,i,j,k,l;                           //Declare the character we need to run the program

/*-------------------------------------------------------------------------------
************************************** Setup ************************************
-------------------------------------------------------------------------------*/

void setup()                               
{
    pinMode(PIN_PHOTORESISTANCE, INPUT);        //Pin to get the photoresistor data    
    Serial.begin(9600);                         //Declare the speed of data transmit to the serial monitor            
    Wire.begin();                               //Start the I2C communication                
 
    radio.ON();                                 //Turn on the shield
    radio.setMode(1);                           //Spreading Factor 7, Coding Rate = 4/5, Bandwidth = 125 KHz   
    radio.setHeaderON();                        //Informations about the device
    radio.setChannel(CH_18_868);                //Define the frequency (f = 868 MHz)
    radio.setCRC_ON();                          //Start the Cyclic Redundancy Check (CRC)
    radio.setPower('H');                        //Select the output power (L, H, M, x, X) to transmit data
    radio.setNodeAddress(NODE);                 //Define the address of the node
}

/*-------------------------------------------------------------------------------
************************************ Main Loop **********************************
-------------------------------------------------------------------------------*/

void loop()                           
{
  
//--------------------------------- Temperature ---------------------------------

  temp = temperatureReading();          //Acquisition of the thermal sensor
  Serial.print("Temperature :");
  Serial.println(temp);                 //Display the value on the serial monitor

//----------------------------- Positive Temperature ----------------------------

if (temp > 0){  

  size = log10(temp)+1;   //----- Size calcul -----
  
  if (size == 1){   //----- Size = 1 -----
  
    at = temp;      //----- Translation -----
  
//----- at -----

    switch (at){
      
      case 0 : a = '+'; b = '0'; c = '0'; d ='/'; break;
      case 1 : a = '+'; b = '0'; c = '1'; d ='/'; break;
      case 2 : a = '+'; b = '0'; c = '2'; d ='/'; break;
      case 3 : a = '+'; b = '0'; c = '3'; d ='/'; break;
      case 4 : a = '+'; b = '0'; c = '4'; d ='/'; break;
      case 5 : a = '+'; b = '0'; c = '5'; d ='/'; break;
      case 6 : a = '+'; b = '0'; c = '6'; d ='/'; break;
      case 7 : a = '+'; b = '0'; c = '7'; d ='/'; break;
      case 8 : a = '+'; b = '0'; c = '8'; d ='/'; break;
      case 9 : a = '+'; b = '0'; c = '9'; d ='/'; break;
    
    }
  
  }
  
  if (size == 2){   //----- Size = 2 -----
  
    at = temp/10;   //----- Translation -----
    bt = temp%10;   //----- Translation -----
  
//----- at ----- 

    switch (at){
      
      case 0 : a = '+'; b = '0'; d ='/'; break;
      case 1 : a = '+'; b = '1'; d ='/'; break;
      case 2 : a = '+'; b = '2'; d ='/'; break;
      case 3 : a = '+'; b = '3'; d ='/'; break;
      case 4 : a = '+'; b = '4'; d ='/'; break;
      case 5 : a = '+'; b = '5'; d ='/'; break;
      case 6 : a = '+'; b = '6'; d ='/'; break;
      case 7 : a = '+'; b = '7'; d ='/'; break;
      case 8 : a = '+'; b = '8'; d ='/'; break;
      case 9 : a = '+'; b = '9'; d ='/'; break;
    
    }
  
//----- bt -----

    switch (bt){
      
      case 0 : a = '+'; c = '0'; d ='/'; break;
      case 1 : a = '+'; c = '1'; d ='/'; break;
      case 2 : a = '+'; c = '2'; d ='/'; break;
      case 3 : a = '+'; c = '3'; d ='/'; break;
      case 4 : a = '+'; c = '4'; d ='/'; break;
      case 5 : a = '+'; c = '5'; d ='/'; break;
      case 6 : a = '+'; c = '6'; d ='/'; break;
      case 7 : a = '+'; c = '7'; d ='/'; break;
      case 8 : a = '+'; c = '8'; d ='/'; break;
      case 9 : a = '+'; c = '9'; d ='/'; break;
    
    }  
  }
}

//----------------------------- Negative Temperature ----------------------------

if (temp < 0){  

  size = log10(abs(temp))+1;    //----- Size calcul -----
  
  if (size == 1){  //----- Size = 1 -----
  
  at = temp;      //----- Translation -----
  
//----- at -----

    switch (at){
      
      case 0 : a = '-'; b = '0'; c = '0'; d ='/'; break;
      case -1 : a = '-'; b = '0'; c = '1'; d ='/'; break;
      case -2 : a = '-'; b = '0'; c = '2'; d ='/'; break;
      case -3 : a = '-'; b = '0'; c = '3'; d ='/'; break;
      case -4 : a = '-'; b = '0'; c = '4'; d ='/'; break;
      case -5 : a = '-'; b = '0'; c = '5'; d ='/'; break;
      case -6 : a = '-'; b = '0'; c = '6'; d ='/'; break;
      case -7 : a = '-'; b = '0'; c = '7'; d ='/'; break;
      case -8 : a = '-'; b = '0'; c = '8'; d ='/'; break;
      case -9 : a = '-'; b = '0'; c = '9'; d ='/'; break;
    
    }
  
  }
  
  if (size == 2){   //----- Size = 2 -----
  
  at = temp/10;     //----- Translation -----
  bt = temp%10;     //----- Translation -----

//----- at -----

    switch (at){
      
      case 0 : a = '-'; b = '0'; d ='/'; break;
      case -1 : a = '-'; b = '1'; d ='/'; break;
      case -2 : a = '-'; b = '2'; d ='/'; break;
      case -3 : a = '-'; b = '3'; d ='/'; break;
      case -4 : a = '-'; b = '4'; d ='/'; break;
      case -5 : a = '-'; b = '5'; d ='/'; break;
      case -6 : a = '-'; b = '6'; d ='/'; break;
      case -7 : a = '-'; b = '7'; d ='/'; break;
      case -8 : a = '-'; b = '8'; d ='/'; break;
      case -9 : a = '-'; b = '9'; d ='/'; break;
    
    }
  
//----- bt -----

    switch (bt){
      
      case 0 : a = '-'; c = '0'; d ='/'; break;
      case 1 : a = '-'; c = '1'; d ='/'; break;
      case 2 : a = '-'; c = '2'; d ='/'; break;
      case 3 : a = '-'; c = '3'; d ='/'; break;
      case 4 : a = '-'; c = '4'; d ='/'; break;
      case 5 : a = '-'; c = '5'; d ='/'; break;
      case 6 : a = '-'; c = '6'; d ='/'; break;
      case 7 : a = '-'; c = '7'; d ='/'; break;
      case 8 : a = '-'; c = '8'; d ='/'; break;
      case 9 : a = '-'; c = '9'; d ='/'; break;
    
    }
  }
}

//--------------------------------- Luminosity ---------------------------------
  
  light = luminosityReading();          //Acquisition of the light sensor
  Serial.print("Luminosity :");
  Serial.println(light);                //Display the value on the serial monitor

  size = log10(light)+1;                //----- Size calcul -----

  if (size == 1){   //----- Size = 1 -----
  
  al = light;       //----- Translation -----
  
//----- al -----

    switch (al){
      
      case 0 : e = '0'; f = '0'; g = '0'; h ='/'; break;
      case 1 : e = '0'; f = '0'; g = '1'; h ='/'; break;
      case 2 : e = '0'; f = '0'; g = '2'; h ='/'; break;
      case 3 : e = '0'; f = '0'; g = '3'; h ='/'; break;
      case 4 : e = '0'; f = '0'; g = '4'; h ='/'; break;
      case 5 : e = '0'; f = '0'; g = '5'; h ='/'; break;
      case 6 : e = '0'; f = '0'; g = '6'; h ='/'; break;
      case 7 : e = '0'; f = '0'; g = '7'; h ='/'; break;
      case 8 : e = '0'; f = '0'; g = '8'; h ='/'; break;
      case 9 : e = '0'; f = '0'; g = '9'; h ='/'; break;
    
    }
  }
  
  if (size == 2){   //----- Size = 2 -----
  
  al = light/10;    //----- Translation -----
  bl = light%10;    //----- Translation -----
  
//----- al -----

    switch (al){
      
      case 0 : e = '0'; f = '0'; h ='/'; break;
      case 1 : e = '0'; f = '1'; h ='/'; break;
      case 2 : e = '0'; f = '2'; h ='/'; break;
      case 3 : e = '0'; f = '3'; h ='/'; break;
      case 4 : e = '0'; f = '4'; h ='/'; break;
      case 5 : e = '0'; f = '5'; h ='/'; break;
      case 6 : e = '0'; f = '6'; h ='/'; break;
      case 7 : e = '0'; f = '7'; h ='/'; break;
      case 8 : e = '0'; f = '8'; h ='/'; break;
      case 9 : e = '0'; f = '9'; h ='/'; break;
    
    }
  
//----- bl -----

    switch (bl){
      
      case 0 : e = '0'; g = '0'; h ='/'; break;
      case 1 : e = '0'; g = '1'; h ='/'; break;
      case 2 : e = '0'; g = '2'; h ='/'; break;
      case 3 : e = '0'; g = '3'; h ='/'; break;
      case 4 : e = '0'; g = '4'; h ='/'; break;
      case 5 : e = '0'; g = '5'; h ='/'; break;
      case 6 : e = '0'; g = '6'; h ='/'; break;
      case 7 : e = '0'; g = '7'; h ='/'; break;
      case 8 : e = '0'; g = '8'; h ='/'; break;
      case 9 : e = '0'; g = '9'; h ='/'; break;
    
    }
  }

  if (size == 3){     //----- Size = 3 -----
    
    al = light/100;         //----- Translation -----
    bl = (light%100)/10;    //----- Translation -----
    cl = light%10;          //----- Translation -----
    
//----- al -----

      switch (al){
        
        case 0 : e = '0'; h ='/'; break;
        case 1 : e = '1'; h ='/'; break;
        case 2 : e = '2'; h ='/'; break;
        case 3 : e = '3'; h ='/'; break;
        case 4 : e = '4'; h ='/'; break;
        case 5 : e = '5'; h ='/'; break;
        case 6 : e = '6'; h ='/'; break;
        case 7 : e = '7'; h ='/'; break;
        case 8 : e = '8'; h ='/'; break;
        case 9 : e = '9'; h ='/'; break;
      
      }
    
//----- bl -----

      switch (bl){
        
        case 0 : f = '0'; h ='/'; break;
        case 1 : f = '1'; h ='/'; break;
        case 2 : f = '2'; h ='/'; break;
        case 3 : f = '3'; h ='/'; break;
        case 4 : f = '4'; h ='/'; break;
        case 5 : f = '5'; h ='/'; break;
        case 6 : f = '6'; h ='/'; break;
        case 7 : f = '7'; h ='/'; break;
        case 8 : f = '8'; h ='/'; break;
        case 9 : f = '9'; h ='/'; break;
      
      }
  
//----- cl -----

      switch (cl){
        
        case 0 : g = '0'; h ='/'; break;
        case 1 : g = '1'; h ='/'; break;
        case 2 : g = '2'; h ='/'; break;
        case 3 : g = '3'; h ='/'; break;
        case 4 : g = '4'; h ='/'; break;
        case 5 : g = '5'; h ='/'; break;
        case 6 : g = '6'; h ='/'; break;
        case 7 : g = '7'; h ='/'; break;
        case 8 : g = '8'; h ='/'; break;
        case 9 : g = '9'; h ='/'; break;
      
      }
    }

//--------------------------------- Power Supply ---------------------------------

  pwr = PowerSupply();    //Acquisition of the Arduino's power supply
  Serial.print("Power supply :");
  Serial.println(pwr);    //Display the value on the serial monitor

  size = log10(pwr)+1;    //----- Size calcul -----

  if (size == 1){  //----- Size = 1 -----
  
  ap = pwr;       //----- Translation -----
  
//----- ap -----

    switch (ap){
      
      case 0 : i = '0'; j = '0'; k = '0'; l ='0'; break;
      case 1 : i = '0'; j = '0'; k = '0'; l ='1'; break;
      case 2 : i = '0'; j = '0'; k = '0'; l ='2'; break;
      case 3 : i = '0'; j = '0'; k = '0'; l ='3'; break;
      case 4 : i = '0'; j = '0'; k = '0'; l ='4'; break;
      case 5 : i = '0'; j = '0'; k = '0'; l ='5'; break;
      case 6 : i = '0'; j = '0'; k = '0'; l ='6'; break;
      case 7 : i = '0'; j = '0'; k = '0'; l ='7'; break;
      case 8 : i = '0'; j = '0'; k = '0'; l ='8'; break;
      case 9 : i = '0'; j = '0'; k = '0'; l ='9'; break;
    
    }
  }

  if (size == 2){  //----- Size = 2 -----
  
  ap = pwr;               //----- Translation -----
  bp = (pwr%1000)/100;    //----- Translation -----
  
//----- ap -----

    switch (ap){
      
      case 0 : i = '0'; j = '0'; k ='0'; break;
      case 1 : i = '0'; j = '0'; k ='1'; break;
      case 2 : i = '0'; j = '0'; k ='2'; break;
      case 3 : i = '0'; j = '0'; k ='3'; break;
      case 4 : i = '0'; j = '0'; k ='4'; break;
      case 5 : i = '0'; j = '0'; k ='5'; break;
      case 6 : i = '0'; j = '0'; k ='6'; break;
      case 7 : i = '0'; j = '0'; k ='7'; break;
      case 8 : i = '0'; j = '0'; k ='8'; break;
      case 9 : i = '0'; j = '0'; k ='9'; break;
    
    }

//----- bp -----

    switch (bp){
      
      case 0 : i = '0'; j = '0'; l ='0'; break;
      case 1 : i = '0'; j = '0'; l ='1'; break;
      case 2 : i = '0'; j = '0'; l ='2'; break;
      case 3 : i = '0'; j = '0'; l ='3'; break;
      case 4 : i = '0'; j = '0'; l ='4'; break;
      case 5 : i = '0'; j = '0'; l ='5'; break;
      case 6 : i = '0'; j = '0'; l ='6'; break;
      case 7 : i = '0'; j = '0'; l ='7'; break;
      case 8 : i = '0'; j = '0'; l ='8'; break;
      case 9 : i = '0'; j = '0'; l ='9'; break;
    
    }
  }

  if (size == 3){  //----- Size = 3 -----
  
  ap = pwr;               //----- Translation -----
  bp = (pwr%1000)/100;    //----- Translation -----
  cp = (pwr%100)/10;      //----- Translation -----
  
//----- ap -----

    switch (ap){
      
      case 0 : i = '0'; j ='0'; break;
      case 1 : i = '0'; j ='1'; break;
      case 2 : i = '0'; j ='2'; break;
      case 3 : i = '0'; j ='3'; break;
      case 4 : i = '0'; j ='4'; break;
      case 5 : i = '0'; j ='5'; break;
      case 6 : i = '0'; j ='6'; break;
      case 7 : i = '0'; j ='7'; break;
      case 8 : i = '0'; j ='8'; break;
      case 9 : i = '0'; j ='9'; break;
    
    }

//----- bp -----

    switch (bp){
      
      case 0 : i = '0'; k ='0'; break;
      case 1 : i = '0'; k ='1'; break;
      case 2 : i = '0'; k ='2'; break;
      case 3 : i = '0'; k ='3'; break;
      case 4 : i = '0'; k ='4'; break;
      case 5 : i = '0'; k ='5'; break;
      case 6 : i = '0'; k ='6'; break;
      case 7 : i = '0'; k ='7'; break;
      case 8 : i = '0'; k ='8'; break;
      case 9 : i = '0'; k ='9'; break;
    
    }

//----- cp -----

    switch (cp){
      
      case 0 : i = '0'; l ='0'; break;
      case 1 : i = '0'; l ='1'; break;
      case 2 : i = '0'; l ='2'; break;
      case 3 : i = '0'; l ='3'; break;
      case 4 : i = '0'; l ='4'; break;
      case 5 : i = '0'; l ='5'; break;
      case 6 : i = '0'; l ='6'; break;
      case 7 : i = '0'; l ='7'; break;
      case 8 : i = '0'; l ='8'; break;
      case 9 : i = '0'; l ='9'; break;
    
    }
  }

  if (size == 4){  //----- Size = 4 -----
  
  ap = pwr/1000;          //----- Translation -----
  bp = (pwr%1000)/100;    //----- Translation -----
  cp = (pwr%100)/10;      //----- Translation -----
  dp = pwr%10;            //----- Translation -----
  
//----- ap -----

    switch (ap){
      case 0 : i ='0'; break;
      case 1 : i ='1'; break;
      case 2 : i ='2'; break;
      case 3 : i ='3'; break;
      case 4 : i ='4'; break;
      case 5 : i ='5'; break;
      case 6 : i ='6'; break;
      case 7 : i ='7'; break;
      case 8 : i ='8'; break;
      case 9 : i ='9'; break;
    
    }

//----- bp -----

    switch (bp){
      case 0 : j ='0'; break;
      case 1 : j ='1'; break;
      case 2 : j ='2'; break;
      case 3 : j ='3'; break;
      case 4 : j ='4'; break;
      case 5 : j ='5'; break;
      case 6 : j ='6'; break;
      case 7 : j ='7'; break;
      case 8 : j ='8'; break;
      case 9 : j ='9'; break;
    
    }

//----- cp ----- 

    switch (cp){
      case 0 : k ='0'; break;
      case 1 : k ='1'; break;
      case 2 : k ='2'; break;
      case 3 : k ='3'; break;
      case 4 : k ='4'; break;
      case 5 : k ='5'; break;
      case 6 : k ='6'; break;
      case 7 : k ='7'; break;
      case 8 : k ='8'; break;
      case 9 : k ='9'; break;
    
    }

//----- dp -----

    switch (dp){
      case 0 : l ='0'; break;
      case 1 : l ='1'; break;
      case 2 : l ='2'; break;
      case 3 : l ='3'; break;
      case 4 : l ='4'; break;
      case 5 : l ='5'; break;
      case 6 : l ='6'; break;
      case 7 : l ='7'; break;
      case 8 : l ='8'; break;
      case 9 : l ='9'; break;
    
    }
  }  

  char data[]={a,b,c,d,e,f,g,h,i,j,k,l,'\0'};     //Data frame

  if ( EXPO == 1 ){   //EXPO mode = 1, it sends data every seconds
    
    radio.sendPacketTimeout(NODE,data);     //Send data
    delay(1000);                            //Wait 1 s
    
  }

  if ( EXPO == 0 ){   //EXPO mode = 0, it not sends data every seconds
    
    for(int nb_of_send = 0; nb_of_send < 10; nb_of_send++){   //Send 10 data
     
      radio.sendPacketTimeout(NODE,data);     //Send data
      delay(1000);                            //Wait 1 s
        
    }
      
    for(int poweroff = 0; poweroff < 38; poweroff++){     //Sleep mode for 5 min (38 * 8 s = 304 s = 5.06 min)
        
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);     //Sleep mode
      
    }
  }
}

/*Project Norway*/
