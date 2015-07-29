import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
while 1:
    asd = raw_input('New command: ')
    ser.write(asd)
    print 'Command sent'
