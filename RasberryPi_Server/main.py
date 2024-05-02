import serial
from threading import Thread
from time import sleep
from data_connect import sql_data

stm_num=1
temp=0
humid=0
bright=0
curtain=0
cnt=0
set_temp = 25

ports = ['/dev/rfcomm0', '/dev/ttyAMA2', '/dev/ttyAMA3']  
serial_ports = dict()
serial_func = dict()

def remote_ctrl(signal):
    global set_temp
    global curtain
    # 0 is closed 1 is opened
    if 'C' in signal:
        
        if curtain==0 :
            print("\ncurtain opened")
            serial_ports[ports[1]].write(('0').encode('utf-8'))
            curtain=1
            return

        elif curtain==1 :
            print("\ncurtain closed")
            serial_ports[ports[1]].write(('1').encode('utf-8'))
            curtain=0
            return
        
    elif signal == "0\r":
        print(f"\nset temp : {set_temp}")
        set_temp+=1
    
    elif signal == "1\r":
        print(f"\nset temp : {set_temp}")
        set_temp-=1
           
def refresh(received_data):
    global temp
    global humid
    global bright
    global curtain
    global cnt    
    cnt=cnt+1
    if cnt ==10:
        sql_data(1, temp, humid, bright)
        cnt=0
    temp, humid, bright = received_data.split(' ')
    
    serial_ports[ports[0]].write((str(temp) + ' ').encode('utf-8'))
    
    if int(bright)<40 and curtain==0:
        serial_ports[ports[1]].write(('0').encode('utf-8'))
        curtain = 1
    elif int(bright)>40 and curtain ==1:
        serial_ports[ports[1]].write(('1').encode('utf-8'))
        curtain = 0
    
    File = open("test.txt", "w")
    if(temp!='\0'):
        File.write(f"{temp} {humid}")
    File.close()
    print(f"\ntemp : {temp} humid : {humid} bright : {bright}")
    
    
def trash(received_data):
    print('trash')
    return
            
def serial_reader(ser):
    global serial_func
    while True:
        try:
            received_data = ser.readline().decode('utf-8')
            if received_data:
                #print(f"\nReceived from {ser.port}: {received_data}")
                serial_func[ser](received_data)
 
        except KeyboardInterrupt:
            print(f"\nExiting reader thread for port {ser.port}.")
            break

def main():
    global ports
    global serial_ports
    baudrate = 9600
    parity = serial.PARITY_NONE
    stopbits = serial.STOPBITS_ONE
    bytesize = serial.EIGHTBITS
    timeout = 1
    
    
    threads = []
    for port in ports:
        ser = serial.Serial(
            port=port,
            baudrate=baudrate,
            parity=parity,
            stopbits=stopbits,
            bytesize=bytesize,
            timeout=timeout
        )
        serial_ports[port] = ser
        
        reader_thread = Thread(target=serial_reader, args=(ser,))
        reader_thread.daemon = True
        reader_thread.start()
        threads.append(reader_thread)
    
    serial_func[serial_ports[ports[0]]]=remote_ctrl
    serial_func[serial_ports[ports[1]]]=trash
    serial_func[serial_ports[ports[2]]]=refresh
    
    try:
        while True:
            sleep(1)
           
    except KeyboardInterrupt:
        print("Program stopped by user.")
        

    finally:
        for ser in serial_ports.values():
            ser.close() 
        for thread in threads:
            thread.join()  

if __name__ == "__main__":
    main()
