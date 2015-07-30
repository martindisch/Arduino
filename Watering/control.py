import serial, time

def receiving(ser):
    global last_received
    buffer_string = ''
    while True:
        buffer_string = buffer_string + ser.read(ser.inWaiting())
        if '\n' in buffer_string:
            lines = buffer_string.split('\n') # Guaranteed to have at least 2 entries
            last_received = lines[-2]
            buffer_string = lines[-1]
            return last_received

def dateTime():
    return time.strftime("%Y/%m/%d %H:%M:%S  ")

ser = serial.Serial('/dev/ttyACM0', 9600)

# Don't write immediately, the Arduino is restarting
time.sleep(1.5)

print dateTime() + receiving(ser)

while 1:
    asd = raw_input(dateTime() + "New command: ")
    ser.write(asd)
    print dateTime() + receiving(ser)