const int sensorPin = 7;  

const int ledPin = 13;    

void setup() {

   pinMode(sensorPin, INPUT); 

   pinMode(ledPin, OUTPUT);   

}

void loop() {

   int sensorValue = digitalRead(sensorPin); 

   if (sensorValue == LOW) {  

       digitalWrite(ledPin, HIGH); 

   } else {

       digitalWrite(ledPin, LOW);   

   }

}
