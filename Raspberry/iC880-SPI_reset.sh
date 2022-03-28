#!/bin/bash		

#********************************************************************************
#Project      :  NORWAY *********************************************************
#Code 	      :	 iC880-SPI_reset.sh *********************************************
#Programmers  :  AUBERT, HESVIK, MOURIER, THOMAS ********************************
#Year         :  2018 ***********************************************************
#Version      :  Last ***********************************************************
#Date         :  01/06/2018 *****************************************************
#********************************************************************************

echo "17" > /sys/class/gpio/export					#Select GPIO pin 17		
echo "out" > /sys/class/gpio/gpio17/direction		#Put it in Output	
echo "1" > /sys/class/gpio/gpio17/value				#Put it at 1	
sleep 5												#Wait 5 s	
echo "0" > /sys/class/gpio/gpio17/value				#Put it at 0	
sleep 1												#Wait 1 s	
echo "0" > /sys/class/gpio/gpio17/value				#Put it at 0

#Project Norway	