#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int i = 0;
  int pos = 0;
  lcd.setCursor(3,0);
  lcd.print("VIVEKANAND");
  lcd.setCursor(5,1);
  lcd.print("COLLEGE");
  delay(5000);

  for(i=0;i<5;i++){
    lcd.setCursor(3,0);
    lcd.print("VIVEKANAND");
    lcd.setCursor(5,1);
    lcd.print("COLLEGE");
    delay(500);
    lcd.clear();
    delay(500);
  }
  for(i=0;i<14;i++){
    lcd.setCursor(3,0);
    lcd.print("VIVEKANAND");
    lcd.setCursor(5,1);
    lcd.print("COLLEGE");
    for(pos=0;pos<1;pos++){
      lcd.scrollDisplayLeft();
    }
    delay(500);
  }
  lcd.clear();
}