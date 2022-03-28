"""********************************************************************************
Project      :  NORWAY ************************************************************
Code 	     :	client.py *********************************************************
Programmers  :  AUBERT, HESVIK, MOURIER, THOMAS ***********************************
Year         :  2018 **************************************************************
Version      :  Last **************************************************************
Date         :  01/06/2018 ********************************************************
********************************************************************************"""

import socket       #It is the librairy which permits to send data from a client to a server
import time         #It is the librairy which permits to use delays
import csv          #It is the librairy which permits to use .csv files

#Function that read data from a .csv file and it has for settings: the name of the file, the line of the array and the column of the array
def getElem(file, i, j):
    with open(file, 'r') as f:
        reader = csv.reader(f)
        for line in reader:
            if reader.line_num - 1 == i:
                f.close()
                return line[j]

#Function that decode the encoded data in Hexadecimal to character (with the ASCII Table) from the .csv file
def translate(z):
    chaine = "%s" %z    #Convert the data in a string     
    """Example: The string looks like this before decoding it: "012B32312F3038392F35303438" (it is in Hexadecimal) and after decoding it will looks like this "1+21/089/5,048" (it is in character)
    *************************************************** 0 and 1 ************************************************** Gateway_ID"""
    a, b, c, d, e, f, g, h, i, j, k, l, m = "", "", "", "", "", "", "", "", "", "", "", "", ""

    if chaine[0] == '0' and chaine[1] == '1':
        a = "1"

    if chaine[0] == '0' and chaine[1] == '2':
        a = "2"

    if chaine[0] == '0' and chaine[1] == '3':
            a = "3"

    if chaine[0] == '0' and chaine[1] == '4':
            a = "4"

    if chaine[0] == '0' and chaine[1] == '5':
            a = "5"

    if chaine[0] == '0' and chaine[1] == '6':
            a = "6"

    if chaine[0] == '0' and chaine[1] == '7':
            a = "7"

    if chaine[0] == '0' and chaine[1] == '8':
            a = "8"
    #************************************************** 9 and 10 ************************************************** + and - for the Temperature
    if chaine[9] == '2' and chaine[10] == 'B':
            b = "+"

    if chaine[9] == '2' and chaine[10] == 'D':
            b = "-"
    #************************************************** 11 and 12 ************************************************** Numbers for Temperature (decade)
    if chaine[11] == '3' and chaine[12] == '0':
            c = "0"

    if chaine[11] == '3' and chaine[12] == '1':
            c = "1"

    if chaine[11] == '3' and chaine[12] == '2':
            c = "2"

    if chaine[11] == '3' and chaine[12] == '3':
            c = "3"

    if chaine[11] == '3' and chaine[12] == '4':
            c = "4"

    if chaine[11] == '3' and chaine[12] == '5':
            c = "5"
    #************************************************** 13 and 14 ************************************************** Numbers for Temperature (unity)
    if chaine[13] == '3' and chaine[14] == '0':
            d = "0"

    if chaine[13] == '3' and chaine[14] == '1':
            d = "1"

    if chaine[13] == '3' and chaine[14] == '2':
            d = "2"

    if chaine[13] == '3' and chaine[14] == '3':
            d = "3"

    if chaine[13] == '3' and chaine[14] == '4':
            d = "4"

    if chaine[13] == '3' and chaine[14] == '5':
            d = "5"

    if chaine[13] == '3' and chaine[14] == '6':
            d = "6"

    if chaine[13] == '3' and chaine[14] == '7':
            d = "7"

    if chaine[13] == '3' and chaine[14] == '8':
            d = "8"

    if chaine[13] == '3' and chaine[14] == '9':
            d = "9"
    #************************************************** 15 and 16 ************************************************** Slash
    if chaine[15] == '2' and chaine[16] == 'F':
            e = "/"
    #************************************************** 18 and 19 ************************************************** Numbers for Luminosity (hundred)
    if chaine[18] == '3' and chaine[19] == '0':
            f = "0"

    if chaine[18] == '3' and chaine[19] == '1':
            f = "1"

    if chaine[18] == '3' and chaine[19] == '2':
            f = "2"

    if chaine[18] == '3' and chaine[19] == '3':
            f = "3"

    if chaine[18] == '3' and chaine[19] == '4':
            f = "4"

    if chaine[18] == '3' and chaine[19] == '5':
            f = "5"

    if chaine[18] == '3' and chaine[19] == '6':
            f = "6"

    if chaine[18] == '3' and chaine[19] == '7':
            f = "7"

    if chaine[18] == '3' and chaine[19] == '8':
            f = "8"

    if chaine[18] == '3' and chaine[19] == '9':
            f = "9"
    #************************************************** 20 and 21 ************************************************** Numbers for Luminosity (decade)
    if chaine[20] == '3' and chaine[21] == '0':
            g = "0"

    if chaine[20] == '3' and chaine[21] == '1':
            g = "1"

    if chaine[20] == '3' and chaine[21] == '2':
            g = "2"

    if chaine[20] == '3' and chaine[21] == '3':
            g = "3"

    if chaine[20] == '3' and chaine[21] == '4':
            g = "4"

    if chaine[20] == '3' and chaine[21] == '5':
            g = "5"

    if chaine[20] == '3' and chaine[21] == '6':
            g = "6"

    if chaine[20] == '3' and chaine[21] == '7':
            g = "7"

    if chaine[20] == '3' and chaine[21] == '8':
            g = "8"

    if chaine[20] == '3' and chaine[21] == '9':
            g = "9"
    #************************************************** 22 and 23 ************************************************** Numbers for Luminosity (unity)
    if chaine[22] == '3' and chaine[23] == '0':
            h = "0"

    if chaine[22] == '3' and chaine[23] == '1':
            h = "1"

    if chaine[22] == '3' and chaine[23] == '2':
            h = "2"

    if chaine[22] == '3' and chaine[23] == '3':
            h = "3"

    if chaine[22] == '3' and chaine[23] == '4':
            h = "4"

    if chaine[22] == '3' and chaine[23] == '5':
            h = "5"

    if chaine[22] == '3' and chaine[23] == '6':
            h = "6"

    if chaine[22] == '3' and chaine[23] == '7':
            h = "7"

    if chaine[22] == '3' and chaine[23] == '8':
            h = "8"

    if chaine[22] == '3' and chaine[23] == '9':
            h = "9"
    #************************************************** 24 and 25 ************************************************** Slash
    if chaine[24] == '2' and chaine[25] == 'F':
            i = "/"
    #************************************************** 27 and 28 ************************************************** Numbers for Arduino voltage (thousand)
    if chaine[27] == '3' and chaine[28] == '0':
            j = "0."

    if chaine[27] == '3' and chaine[28] == '1':
            j = "1."

    if chaine[27] == '3' and chaine[28] == '2':
            j = "2."

    if chaine[27] == '3' and chaine[28] == '3':
            j = "3."

    if chaine[27] == '3' and chaine[28] == '4':
            j = "4."

    if chaine[27] == '3' and chaine[28] == '5':
            j = "5."

    if chaine[27] == '3' and chaine[28] == '6':
            j = "6."

    if chaine[27] == '3' and chaine[28] == '7':
            j = "7."

    if chaine[27] == '3' and chaine[28] == '8':
            j = "8."

    if chaine[27] == '3' and chaine[28] == '9':
            j = "9."
    #************************************************** 29 and 30 ************************************************** Numbers for Arduino voltage (hundred)
    if chaine[29] == '3' and chaine[30] == '0':
            k = "0"

    if chaine[29] == '3' and chaine[30] == '1':
            k = "1"

    if chaine[29] == '3' and chaine[30] == '2':
            k = "2"

    if chaine[29] == '3' and chaine[30] == '3':
            k = "3"

    if chaine[29] == '3' and chaine[30] == '4':
            k = "4"

    if chaine[29] == '3' and chaine[30] == '5':
            k = "5"

    if chaine[29] == '3' and chaine[30] == '6':
            k = "6"

    if chaine[29] == '3' and chaine[30] == '7':
            k = "7"

    if chaine[29] == '3' and chaine[30] == '8':
            k = "8"

    if chaine[29] == '3' and chaine[30] == '9':
            k = "9"
    #************************************************** 31 and 32 ************************************************** Numbers for Arduino voltage (decade)
    if chaine[31] == '3' and chaine[32] == '0':
            l = "0"

    if chaine[31] == '3' and chaine[32] == '1':
            l = "1"

    if chaine[31] == '3' and chaine[32] == '2':
            l = "2"

    if chaine[31] == '3' and chaine[32] == '3':
            l = "3"

    if chaine[31] == '3' and chaine[32] == '4':
            l = "4"

    if chaine[31] == '3' and chaine[32] == '5':
            l = "5"

    if chaine[31] == '3' and chaine[32] == '6':
            l = "6"

    if chaine[31] == '3' and chaine[32] == '7':
            l = "7"

    if chaine[31] == '3' and chaine[32] == '8':
            l = "8"

    if chaine[31] == '3' and chaine[32] == '9':
            l = "9"
    #************************************************** 33 and 34 ************************************************** Numbers for Arduino voltage (unity)
    if chaine[33] == '3' and chaine[34] == '0':
            m = "0"

    if chaine[33] == '3' and chaine[34] == '1':
            m = "1"

    if chaine[33] == '3' and chaine[34] == '2':
            m = "2"

    if chaine[33] == '3' and chaine[34] == '3':
            m = "3"

    if chaine[33] == '3' and chaine[34] == '4':
            m = "4"

    if chaine[33] == '3' and chaine[34] == '5':
            m = "5"

    if chaine[33] == '3' and chaine[34] == '6':
            m = "6"

    if chaine[33] == '3' and chaine[34] == '7':
            m = "7"

    if chaine[33] == '3' and chaine[34] == '8':
            m = "8"

    if chaine[33] == '3' and chaine[34] == '9':
            m = "9"

    z = a + b + c + d + e + f + g + h + i + j + k + l + m       #Creation of the decoded string
    #Example: The string looks like this after decoding: "1+21/089/5,048" (it is in character) and it was this before "012B32312F3038392F35303438" (it is in Hexadecimal)

    return z        #Return the string decoded

#This is the main code
hote = "158.39.187.12"      #Define the host
port = 12800                #Define the port

connexion_avec_serveur = socket.socket(socket.AF_INET, socket.SOCK_STREAM)      #Create a socket object
connexion_avec_serveur.connect((hote, port))                                    #Binding the host to the port
print("Data are being sent to the server ...")                                  #Display on the terminal window "Data are sending to the server ..."

n = 0       #Declare n at 0

#This while loop permits to select the data from a column, decode it and send it to the server
while 1:        #Infinite loop

    n = n + 1                           #Basic calcul to increment the lines to permit to the function getElem to read the data line per line
    file = open("LoRaWan.csv","r")      #Open the file called "LoRaWan.csv"
    e = getElem("LoRaWan.csv", n, 15)   #Get the data from the column 15 and the line n (Data)
    f = getElem("LoRaWan.csv", n, 7)    #Get the data from the column 7 and the line n (CRC)
    g = getElem("LoRaWan.csv", n, 11)	#Get the data from the column 11 and the line n (SF)
    file.close()                        #Close the file called "LoRaWan.csv"

    #The If loop permits to send the data to the server if there is data in the line n and in column 7
    if f != None and e != None :
        if len(e) == 35:                                #If the length of the string measure 35 do the things below
            if "CRC_OK" in f:       			        #If in the column it is written "CRC_OK" 
		        if not "ERR" or not "UNDEF" in g:   	#If it is not an error or it is not undefined, do the things below                               
                    r = translate(e)    				            #Decode the data from Hexadecimal to Character
                    msg_a_envoyer = r   				            #Little shortcut
                    print(msg_a_envoyer)				            #Display the message
                    msg_a_envoyer = msg_a_envoyer.encode()         	#Encode the data
                    connexion_avec_serveur.send(msg_a_envoyer)     	#Send the data to the server
                    time.sleep(.5)                                 	#Wait 0.5 s = 500 ms


    if f == None and e == None: #If the column is empty
        n = n - 1               #Basic calcul to decrement the lines to permit to the function getElem to read the data line per line
        time.sleep(.5)          #Wait 0.5 s = 500 ms
            
#Project Norway