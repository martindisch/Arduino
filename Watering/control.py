import serial, time

dataInterval = 10
waterInterval = 20
counter = waterInterval
motorTime = 3

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

def getOut():
    print dateTime() + receiving(ser)

ser = serial.Serial('/dev/ttyACM0', 9600)

# Don't write immediately, the Arduino is restarting
time.sleep(3)

while 1:
    ser.write('2')
    getOut()
    ser.write('3')
    getOut()
    if (counter >= waterInterval):
        ser.write('1')
        getOut()
        time.sleep(motorTime)
        ser.write('0')
        getOut()
        counter = 0
    counter += dataInterval
    time.sleep(dataInterval)
