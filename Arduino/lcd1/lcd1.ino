#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(3,0);
  lcd.print("VIVEKANAND");
  lcd.setCursor(5,1);
  lcd.print("COLLEGE");
}
