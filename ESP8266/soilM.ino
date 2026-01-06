#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "VCK";
const char* password = "ugc@3981";

unsigned long myChannelNumber = 3211873; 
const char * myWriteAPIKey = "I79YZ1WOILMEQNWJ"; 
const int sensor_pin = A0;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("\nConnecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  ThingSpeak.begin(client); 
}
void loop() {
  const int sensorValue = analogRead(sensor_pin);
  float moisture_percentage;
  moisture_percentage = 100.00 - ((sensorValue / 1023.00) * 100.00);
  Serial.print("Soil Moisture (in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  int statusCode = ThingSpeak.writeField(myChannelNumber, 3, moisture_percentage, myWriteAPIKey);
  if (statusCode == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.print("Problem updating channel. HTTP error code ");
    Serial.println(statusCode);
  }
  delay(15000);
}