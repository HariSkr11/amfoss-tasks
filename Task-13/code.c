#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
 lcd.begin(16, 2);
  pinMode(8,INPUT);
  Serial.begin(9600);
}
int count=0;
void loop()
{
  if (digitalRead(6) == HIGH){
    count = 0;
  lcd.setCursor(0,0);          
  lcd.print("CROWD COUNT: "); 
  lcd.setCursor(1,1);           
  lcd.print(count);
  } 
  Serial.println(digitalRead(8));
  if (digitalRead(8)==HIGH){
    count++;
  lcd.setCursor(0,0);          
  lcd.print("CROWD COUNT: "); 
  lcd.setCursor(1,1);           
  lcd.print(count); 
  delay(1500);
  }
  else{
  lcd.setCursor(0,0);          
  lcd.print("CROWD COUNT: "); 
  lcd.setCursor(1,1);           
  lcd.print(count); 
  }
  }
