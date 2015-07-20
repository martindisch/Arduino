import serial
import time

def receiving(ser):
    global last_received
    buffer_string = ''
    while True:
        buffer_string = buffer_string + ser.read(ser.inWaiting())
        if '\n' in buffer_string:
            lines = buffer_string.split('\n') # Guaranteed to have at least 2 entries
            last_received = lines[-2]
            #If the Arduino sends lots of empty lines, you'll lose the
            #last filled line, so you could make the above statement conditional
            #like so: if lines[-2]: last_received = lines[-2]
            buffer_string = lines[-1]
            return last_received

ser = serial.Serial('COM3', 9600, timeout=0)
# Don't write immediately, the Arduino is restarting
time.sleep(1.5)

command = raw_input("Enter command: ")
ser.write(command)

while 1:
    print receiving(ser)