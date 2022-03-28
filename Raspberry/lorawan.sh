#!/bin/bash

#********************************************************************************
#Project      :  NORWAY *********************************************************
#Code 	      :	 lorawan.sh *****************************************************
#Programmers  :  AUBERT, HESVIK, MOURIER, THOMAS ********************************
#Year         :  2018 ***********************************************************
#Version      :  Last ***********************************************************
#Date         :  01/06/2018 *****************************************************
#********************************************************************************

#Execute the first program which permit to reset pins for the node
sudo sh /home/pi/LoRa/lora_gateway/lora_gateway/util_pkt_logger/iC880-SPI_reset.sh	#Go in the repertory and run the program
echo "Pins have been reseted"			#Display on the terminal window							

sleep 1			#Wait 1 s

#Execute the second program which permit to read all the data coming from the node SX1272 and put it all in a csv file
echo "Data are sending to a .csv file"							#Display on the terminal window
cd /home/pi/LoRa/lora_gateway/lora_gateway/util_pkt_logger		#Goes in the repertory
./util_pkt_logger&												#Run the program

sleep 30		#Wait 30 s

#Execute the third program which permit to send the data from the csv file to the server and stock them in a database
echo "Data are sending to the server"	#Display on the terminal window							
sudo python /home/pi/LoRa/lora_gateway/lora_gateway/util_pkt_logger/client.py&		#Go in the repertory and run the program

#Project Norway