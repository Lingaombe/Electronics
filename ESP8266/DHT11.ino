#include <ESP8266WiFi.h> 
#include <DHT.h> 
#include <ThingSpeak.h> 

const char* ssid = "VCK"; 
const char* password = "ugc@3981"; 

unsigned long myChannelNumber = 3211873; 
const char * myWriteAPIKey = "I79YZ1WOILMEQNWJ";
#define DHTPIN D3      
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE); 
WiFiClient client; 
void setup() { 
Serial.begin(9600); 
delay(10); 
dht.begin(); 
Serial.println(); 
Serial.print("Connecting to "); 
Serial.println(ssid); 
WiFi.mode(WIFI_STA); 
WiFi.begin(ssid, password); 
while (WiFi.status() != WL_CONNECTED) { 
delay(500); 
Serial.print("."); 
} 
Serial.println(""); 
Serial.println("WiFi connected"); 
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP()); 
  ThingSpeak.begin(client); 
} 
 
void loop() { 
  
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
 
  
  if (isnan(h) || isnan(t)) { 
    Serial.println("Failed to read from DHT sensor!"); 
    return; 
  } 
 
  
  ThingSpeak.setField(1, t); 
  ThingSpeak.setField(2, h); 
 
  int code = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); 
 
  if (code == 200) { 
    Serial.println("Channel update successful."); 
    Serial.print("Temperature = "); 
      Serial.print(t); 
      Serial.print("°C | "); 
      Serial.print("Humidity = "); 
      Serial.print(h); 
      Serial.println("% "); 
      Serial.println(""); 
 
  } else { 
    //Serial.println("Problem updat\ ing channel. HTTP error code " + 
//String(code)); 
  } 
  delay(10000); 

}
