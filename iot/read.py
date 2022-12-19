import serial
import requests

arduino = serial.Serial(port='COM2', baudrate=9600, timeout=1)

while True:
    
    a = arduino.readline().decode("utf-8").strip('\n').strip('\r')
    # print("asda"+a)
    if(a!=''):
        temp = a.split('-')
        data = {'suhu':str(temp[1]),
                'ph':str(temp[0])}
       
        res = requests.get('http://192.168.1.4/iot/insertdata.php?ph='+data['ph']+'&suhu='+data['suhu'])
        
        print(data)