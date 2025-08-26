#include <dht.h>
#define outPin 8

dht DHT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int readData = DHT.read11(outPin);

  float temp = DHT.temperature;
  float humi = DHT.humidity;

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("C | ");
  Serial.print((temp*9)/5+32.0);
  Serial.println("F");
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.println("%");
  Serial.println(" ");

  delay(2000);
}
