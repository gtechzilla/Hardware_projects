import RPi.GPIO as GPIO
import time
import smtplib
import os
import urllib.request
import cv2
import numpy as np

from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders


import subprocess


fromaddr = "benedictgakono@gmail.com"
toaddr = "benedictraspberry@gmail.com"

msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "Test Alert"
body = 'This is an extended email test'
msg.attach(MIMEText(body, 'plain'))






GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(13, GPIO.IN)
#Read output from PIR motion sensor
#GPIO.setup(3, GPIO.OUT)         #LED output pin

while True:
    z=GPIO.input(13)
    if z ==1:
        print("Intruder detected at cam 2")
        # Replace the URL with your own IPwebcam shot.jpg IP:port
        url='http://192.168.0.115:8080/shot.jpg'
        while True:
            # Use urllib to get the image from the IP camera
            imgResponse = urllib.request.urlopen(url)

            # Numpy to convert into a array
            imgNp = np.array(bytearray(imgResponse.read()),dtype=np.uint8)

            # Decode the array to OpenCV usable format
            img = cv2.imdecode(imgNp,-1)


            # put the image on screen
            cv2.imshow('IPWebcam',img)
            # Program closes if q is pressed
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        
        '''
        part = MIMEBase('application', 'octet-stream')
        attachment = open("img2.jpg", "rb")
        part.set_payload((attachment).read())
        encoders.encode_base64(part)
        filename = "img2.jpg"
        
        part.add_header('Content-Disposition', "attachment; filename= {}".format(filename))
        msg.attach(part)

        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login(fromaddr, "89201992")
        text = msg.as_string()
        server.sendmail(fromaddr, toaddr, text)
        server.quit()
        #GPIO.output(3, 1)  #Turn ON LED
        '''
        z =0
        time.sleep(0.5)






