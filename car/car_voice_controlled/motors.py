'''This is code for H-Bridge Motor Driver in Raspberry Pi using python. First, import GPIO library and set pins to GPIO.BOARD mode. Then, declare GPIO 3 as input 1 and GPIO 5 as input 2. Also, declare GPIO 8 as enable. Set these three pins in output mode. We are running motor only in forward direction, so, set input 1 and enable to High, and input 2 to Low. If you want to run the motor in reverse direction set input 2 to High and input 1 to Low, keeping enable High.'''

import RPi.GPIO as GPIO
from time import sleep
 
GPIO.setmode(GPIO.BOARD)
 
input1 = 3    
input2 = 5    
enable = 8    
 
GPIO.setup(input1,GPIO.OUT)
GPIO.setup(input2,GPIO.OUT)
GPIO.setup(enable,GPIO.OUT)

GPIO.output(input1,GPIO.HIGH)
GPIO.output(input2,GPIO.LOW)
GPIO.output(enable,GPIO.HIGH)
