import RPi.GPIO as GPIO
import time
import smtplib
import os

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
GPIO.setup(11, GPIO.IN)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(13, GPIO.IN)
#Read output from PIR motion sensor
#GPIO.setup(3, GPIO.OUT)         #LED output pin

while True:
    i=GPIO.input(11)
    z=GPIO.input(13)
    sensors=[i,z]
    if sensors[0] ==1:
            print("Intruder detected at cam 1")
            os.system("fswebcam -r 1280x720 --no-banner img1.jpg")
            part = MIMEBase('application', 'octet-stream')
            attachment = open("img.jpg", "rb")
            part.set_payload((attachment).read())
            encoders.encode_base64(part)
            filename = "img.jpg"
            
            part.add_header('Content-Disposition', "attachment; filename= {}".format(filename))
            msg.attach(part)

            server = smtplib.SMTP('smtp.gmail.com', 587)
            server.starttls()
            server.login(fromaddr, "89201992")
            text = msg.as_string()
            server.sendmail(fromaddr, toaddr, text)
            server.quit()
            #GPIO.output(3, 1)  #Turn ON LED
            sensors[0] =0
            time.sleep(0.5)
            
    if sensors[1] ==1:
            print("Intruder detected at cam 2")
            os.system("fswebcam -r 1280x720 --no-banner img2.jpg")
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
            sensors[1] =0
            time.sleep(0.5)




    
