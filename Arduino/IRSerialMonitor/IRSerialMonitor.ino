const int sensorPin = 7;  

void setup() {

   pinMode(sensorPin, INPUT);  

   Serial.begin(9600); 

}

 

void loop() {

   int sensorValue = digitalRead(sensorPin);  

   if (sensorValue == LOW) {

       Serial.println("Object Detected");  

   } else {

       Serial.println("No Object");

   }

   delay(500);  

}