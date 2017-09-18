/* Tracking Sensor Module Obstacle Avoidance (KY-033) [S026] : http://rdiot.tistory.com/168 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int T = 2; // INPUT PIN
int count = 0;
String dot = ".";

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(T, INPUT);
  delay(1000);

  lcd.clear();
}

void loop()
{
  if(count >= 20)
  {
    dot = "";
    lcd.clear();
    count = 0;
  }
 
  lcd.setCursor(0,0);
  lcd.print("S026:KY-033 Tracking");

  if (LOW == digitalRead(T))
  {
    dot += "Detected";

    lcd.setCursor(0,1);
    lcd.print(dot);
    count = count+8;
  }
  else
  {
    dot += ".";
    lcd.setCursor(0,1);
    lcd.print(dot);
    count++;
  }
  delay(100);
}
