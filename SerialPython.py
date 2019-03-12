import serial
import matplotlib.pyplot as plt
from drawnow import *

values = []

plt.ion()
cnt=0

serialArduino = serial.Serial('/dev/tty.SLAB_USBtoUART', 115200)

def plotValues():
    plt.title('Valor enviado via Serial')
    plt.grid(True)
    plt.ylabel('Potenciometro')
    plt.plot(values, 'rx-', label='valores')
    plt.legend(loc='upper left')


for i in range(0,50):
    values.append(0)
    
while True:
    while (serialArduino.inWaiting()==0):
        pass
    valueRead = serialArduino.readline()

    
    try:
        valueInInt = int(valueRead)
        print(valueInInt)

        if valueInInt <= 255:
            if valueInInt >= 0:
                values.append(valueInInt)
                values.pop(0)
                drawnow(plotValues)


    except ValueError:
        print "Numero Invalido!"