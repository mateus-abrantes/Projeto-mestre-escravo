# -*- coding: iso-8859-1 -*-
 
import time
import serial
 
# Iniciando conexao serial
comport = serial.Serial('COM3', 9600)
#comport = serial.Serial('/dev/ttyUSB0', 9600, timeout=1) # Setando timeout 1s para a conexao
def serial_ard_py():
    while True :
        #VALUE_SERIAL=comport.readline()
        #VALUE_SERIAL=comport.read()
        VALUE_SERIAL=comport.readline(10)

        print("nRetorno da serial:", VALUE_SERIAL)
 
# Fechando conexao serial
serial_ard_py()
comport.close()