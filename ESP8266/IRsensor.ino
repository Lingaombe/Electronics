#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "iPhone"; 
const char* password = "00000000"; 

unsigned long myChannelNumber = 3205264;
const char* myWriteAPIKey = " MUHIIOVWIDFS952P";

#define IR_PIN D1
#define LED_PIN D2

WiFiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
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
  int irVal = digitalRead(IR_PIN);
  if (irVal == HIGH) {
  Serial.println("No Object Detected");
  digitalWrite(LED_PIN, LOW);
  delay(500);
  } else {
  Serial.println("Object Detected");
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  }
  ThingSpeak.setField(6, irVal);
  int response = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.print("ThingSpeak Error Code: ");
  }
  delay(15000);
}