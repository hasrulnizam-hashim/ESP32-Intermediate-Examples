#include <LiquidCrystal.h>
// Creates an LCD object. Parameters: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);
void setup() {
  lcd.begin(16, 2);
  lcd.print("Blinking text");
}
void loop() {
  lcd.display();
  delay(2000);
  lcd.noDisplay();
  delay(2000);
}
