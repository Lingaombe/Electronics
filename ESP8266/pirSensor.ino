#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "VCK"; 
const char* password = "ugc@3981"; 

unsigned long myChannelNumber = 3205264;
const char* myWriteAPIKey = " mwa0000039934776";

#define PIR_PIN D1
#define LED_PIN D4

WiFiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("PIR Sensor Initializing...");
  delay(5000); 
  Serial.println("Ready");
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
  ThingSpeak.begin(client);
}
void loop() {
  int motion = digitalRead(PIR_PIN);
  if (motion == HIGH) {
  Serial.println("Motion Detected");
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  } else {
  Serial.println("No Motion");
  digitalWrite(LED_PIN, LOW);
  delay(500);
  }
  ThingSpeak.setField(4, motion);
  int response = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.print("ThingSpeak Error Code: ");
  }
  delay(15000);
}