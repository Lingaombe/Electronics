const int trigPin = 2; 
const int echoPin = 3; 
const int ledPin = 13; 

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  long duration;
  int distance;

  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  duration = pulseIn(echoPin, 1);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) digitalWrite(ledPin, 1); 
  else  digitalWrite(ledPin, 0); 
  delay(500);
}