#include <Wire.h>

#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"

#include "EmonLib.h"                   // Include Emon Library
 
#define FONA_RX 9
#define FONA_TX 8
#define FONA_RST 7
 
SoftwareSerial SIM800ss = SoftwareSerial(FONA_TX, FONA_RX);
Adafruit_FONA SIM800 = Adafruit_FONA(FONA_RST);
EnergyMonitor emon1;                   // Create an instance
 
 
int LED = 13;
 
char http_cmd[80];
char url_string[] = "api.thingspeak.com/update?api_key=PIH0M6IT6YTDWY0A&field1";
char current_string[20];
double current_reading;
int net_status;
 
uint16_t statuscode;
int16_t length;
String response = "";
char buffer[512];
 
boolean gprs_on = false;
boolean tcp_on = false;

void setup() {
  pinMode(LED, OUTPUT);
  while (!Serial);
 
  Serial.begin(115200);
  
  Serial.println("Current Data to ThingSpeak");
  Serial.println("Initializing SIM800L....");
 
  SIM800ss.begin(4800); // if you're using software serial
 
  if (! SIM800.begin(SIM800ss)) {            
    Serial.println("Couldn't find SIM800L");
    while (1);
  }
  
  Serial.println("SIM800L is OK"); 
  delay(1000);

  
  Serial.println("Waiting to be registered to network...");
  net_status = SIM800.getNetworkStatus();
  while(net_status != 1){
     net_status = SIM800.getNetworkStatus();
     delay(2000);
  }
  Serial.println("Registered to home network!");
  Serial.print("Turning on GPRS... ");
  delay(2000); 
  while(!gprs_on){
    if (!SIM800.enableGPRS(true)){  
        Serial.println("Failed to turn on GPRS");
        Serial.println("Trying again...");
        delay(2000);
        gprs_on = false;
    }else{
        Serial.println("GPRS now turned on");
        delay(2000);
        gprs_on = true;   
    } 
  }
}

void loop() {    
    digitalWrite(LED, LOW);
    current_reading = emon1.calcIrms(1480);
    dtostrf(current_reading, 5, 0, current_string);
    sprintf(http_cmd,"%s=%s",url_string,current_string);
    delay(2000);
    while(!tcp_on){
      if (!SIM800.HTTP_GET_start(http_cmd, &statuscode, (uint16_t *)&length)) {
           Serial.println("Failed!");
           Serial.println("Trying again...");
           tcp_on = false;
      }else{
        tcp_on = true;
        digitalWrite(LED, HIGH);
        while (length > 0) {
           while (SIM800.available()) {
             char c = SIM800.read();
             response += c;
             length--;
           }
        }
        Serial.println(response);
        if(statuscode == 200){
          Serial.println("Success!");
          tcp_on = false;
        }
        digitalWrite(LED, LOW);
      }
      delay(2000);
    }
    delay(2000);
}
