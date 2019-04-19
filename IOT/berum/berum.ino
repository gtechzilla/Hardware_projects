
#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include <Hx711.h>
Hx711 scale1(A2, A3);
Hx711 scale2(A4, A5);
#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celcius=0;

//SSID of your network
char ssid[] = "Tibim"; //SSID of your Wi-Fi router
char pass[] = "maria@123"; //Password of your Wi-Fi router

void setup()
{
  Serial.begin(115200);
  delay(10);

  Serial.begin(9600);
  sensors.begin();

  // Connect to Wi-Fi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to...");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wi-Fi connected successfully");
}

void loop () {  
  
  Serial.print("Scale 1 : \t");
  Serial.print(scale1.getGram(), 1);
  Serial.println(" g");
  Serial.print("Scale 2 : \t");
  Serial.print(scale2.getGram(), 1);
  Serial.println(" g");
  delay(200)

  
    
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
 
  Serial.print(" C  ");
  Serial.print(Celcius);

  delay(1000);
  }
