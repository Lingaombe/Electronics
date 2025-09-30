#include <SoftwareSerial.h>

const int btnPin = A0;
int val = 0;
SoftwareSerial hc05(2,3);

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  hc05.begin(9600);
}

void loop() {
  val = analogRead(btnPin);

  if(val < 200){
    hc05.print("\n Vivekanand College, Kolhapur ");
    delay(500);
    hc05.print("\n Department of Electronics \n\n");
  }
}
