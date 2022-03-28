"""********************************************************************************
Project      :  NORWAY ************************************************************
Code 	     :	server.py *********************************************************
Programmers  :  AUBERT, HESVIK, MOURIER, THOMAS ***********************************
Year         :  2018 **************************************************************
Version      :  Last **************************************************************
Date         :  01/06/2018 ********************************************************
********************************************************************************"""

import socket 		#It is the librairy which permits to send data from a client to a server
import sqlite3 		#It is the librairy which permits to use Sqlite's Database

#Creation of a table in a Sqlite's Database called Data_Arduino, this function creates 6 columns called ID, Station, Temperature, Luminosity, Battery_Loading and Internal_Temperature
def create_table():
    cursor.execute("CREATE TABLE IF NOT EXISTS Data_Arduino(ID INTEGER PRIMARY KEY AUTOINCREMENT, Station TEXT DEFAULT NULL, Temperature TEXT DEFAULT NULL, Luminosity INTEGER DEFAULT NULL, Battery_Loading TEXT DEFAULT NULL, Internal_Temperature TEXT DEFAULT NULL)")

#Function that allocates for each data a column
def insert_data(A,B,C,D,E):
    cursor.execute("INSERT INTO Data_Arduino(Station, Temperature, Luminosity, Battery_Loading, Internal_Temperature) VALUES(?, ?, ?, ?, ?)",(A, B, C, D, E))

#This is the main code
hote = '' 	#Define the host
port = 12800	#Define the port

connexion_principale = socket.socket(socket.AF_INET, socket.SOCK_STREAM)	#Create a socket object
connexion_principale.bind((hote, port))						#Binding the host to the port
connexion_principale.listen(5)							#Now wait for the client connection 
print("The server is listening on the port {}".format(port))			#Display on the terminal window "The server is listening on the port 12800"

connexion_avec_client, infos_connexion = connexion_principale.accept()		#Establish connection with the client

msg_recu = b""		#Message received

print("Data are being sent to the database ...")	#Display on the terminal window "Data are sending to the database ..."

#The while loop permits to get data and send them into the Database in the right columns when there is a message from the client
while 1:		#Infinite loop
 
    conn = sqlite3.connect('Database.db')	#Connection to the Database called Database.db
    cursor = conn.cursor()			#Permit to write data in the Database

    create_table() 	#Creation of the table 

    msg_recu = connexion_avec_client.recv(1024)		#Define the length of the message which is 1024 bytes

    a = (msg_recu.decode())		#Decode the message sent
    print(a)				#Display on the terminal window the data from the gateway

    chaine = "%s" %a 			#Convert the message in a string
    length = len(chaine)		#Measure the length of the string

    #The If loop permits to store in the right column the data
    if length == 14:				#If the length of the message measure 13

        A = chaine[0:1]				#Store the first element of the string
        B = chaine[1:4]				#Store the elements 1 to 3 of the string
        C = chaine[5:8]				#Store the elements 5 to 7 of the string
        D = chaine[9:len(chaine)]		#Store the 4 lastest elements of the string
        E = 30					#Store the temperature of the Arduino microcontroller

        insert_data(A,B,C,D,E)			#Insert the elements above in the right columns

    conn.commit()		#Confirm all the changes you make in the database
    cursor.close()		#Close the Database
    conn.close()		#Close the database

#Project Norway
