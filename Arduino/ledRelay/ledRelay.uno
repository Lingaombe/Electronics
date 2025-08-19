int relay = 7;
int led = 12;

void setup(){
	pinMode(relay,OUTPUT);
	pinMode(led,OUTPUT);
}
void loop(){
	digitalWrite(relay,HIGH);
	digitalWrite(led,HIGH);
	delay(2000);
	digitalWrite(relay,LOW);
	digitalWrite(led,LOW);
	delay(2000);
}