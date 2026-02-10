#include <ESP8266WiFi.h> 
WiFiServer server(80); 
const char* ssid = "NodeMCU"; 
const char* password = "12345678"; 
int led1 = D1; 
int led2 = D2; 
void setup() { 
  Serial.begin(9600); 
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW); 
 
  WiFi.softAP(ssid, password); 
  Serial.println("Soft AP Started"); 
  Serial.print("IP Address: "); 
  Serial.println(WiFi.softAPIP()); 
 
  server.begin(); 
} 
 
void loop() { 
  WiFiClient client = server.available(); 
  if (!client) return; 
 
  String request = client.readStringUntil('\r'); 
  client.flush(); 
 
  if (request.indexOf("/LED1ON") != -1) 
    digitalWrite(led1, HIGH); 
 
  if (request.indexOf("/LED1OFF") != -1) 
    digitalWrite(led1, LOW); 
 
  if (request.indexOf("/LED2ON") != -1) 
    digitalWrite(led2, HIGH); 
 
  if (request.indexOf("/LED2OFF") != -1) 
    digitalWrite(led2, LOW); 
 
  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html"); 
  client.println(); 
  client.println("<html><body>"); 
  client.println("<h2>ESP8266 Two LED Control</h2>"); 
  client.println("<p>LED 1</p>"); 
  client.println("<a href=\"/LED1ON\"><button>ON</button></a>"); 
  client.println("<a href=\"/LED1OFF\"><button>OFF</button></a>"); 
  client.println("<p>LED 2</p>"); 
  client.println("<a href=\"/LED2ON\"><button>ON</button></a>"); 
  client.println("<a href=\"/LED2OFF\"><button>OFF</button></a>"); 
  client.println("</body></html>"); 
 
  delay(1); 
} 
