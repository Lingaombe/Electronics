const int trigPin = 2; // Trigger pin connected to digital pin 9
const int echoPin = 3; // Echo pin connected to digital pin 10
const int ledPin = 13; // LED connected to digital pin 13
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
void loop()
}
{
long duration;
int distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
if (distance < 10) { // If object is closer than 10 cm
digitalWrite(ledPin, HIGH); // Turn ON LED
}
else {
digitalWrite(ledPin, LOW); // Turn OFF LED
}
delay(500);