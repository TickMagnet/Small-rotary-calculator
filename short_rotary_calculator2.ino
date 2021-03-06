#include <LiquidCrystal_I2C.h>
  const int analogInPin1 = A1;
  const int analogInPin2 = A2;
  const int analogInPin3 = A0;
  float sensorValue1 = 0;
  float sensorValue2 = 0;
  int sensorValue3 = 0;
  float outputValue1 = 0;
  float outputValue2 = 0;
  int outputValue3 = 0;
LiquidCrystal_I2C lcd(0x27,16,2);
  void setup()
{
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("Spin Calculator!");
  delay (3500);
}
  void loop()
{
  int analogValue = analogRead(analogInPin3);
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 100);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 100); 
    if (analogValue < 250) { 
  lcd.setCursor(0, 0);
  lcd.print(outputValue1,0);
  lcd.print(" + ");
  lcd.print(outputValue2,0);
  lcd.print("               ");
  lcd.setCursor(0, 1);
  lcd.print("= ");
  lcd.print(outputValue1 + outputValue2,0);
  lcd.print("               ");
  } 
    else if (analogValue > 251 && analogValue < 500){
  lcd.setCursor(0, 0);
  lcd.print(outputValue1,0);
  lcd.print(" - ");
  lcd.print(outputValue2,0);
  lcd.print("               ");
  lcd.setCursor(0, 1);
  lcd.print("= ");
  lcd.print(outputValue1 - outputValue2,0);
  lcd.print("               ");   
  }  
    else if (analogValue > 501 && analogValue < 750){
  lcd.setCursor(0, 0);
  lcd.print(outputValue1,0);
  lcd.print(" X ");
  lcd.print(outputValue2,0);
  lcd.print("               ");
  lcd.setCursor(0, 1);
  lcd.print("= ");
  lcd.print(outputValue1 * outputValue2,0);
  lcd.print("               ");  
  }  
    else { 
  lcd.setCursor(0, 0);
  lcd.print(outputValue1);
  lcd.print(" / ");
  lcd.print(outputValue2);
  lcd.print("               ");
  lcd.setCursor(0, 1);
  lcd.print("= ");
  lcd.print(outputValue1 / outputValue2,12);
  lcd.print("               "); 
  }
  }
