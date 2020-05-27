#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); /*rs,en,d4,d5,d6,d7*/
int bootlimit = 1;
int lock_frequency = 0;
char password[5] = {'A', '0', 'B', '1'};
char temp_password[5];
int pass_check = 0;


void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}


void booting()
{
  if (bootlimit == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   ASTRA R.O.S");
    lcd.setCursor(0, 1);
    lcd.print("status : Booting");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   ASTRA R.O.S");
    lcd.setCursor(0, 1);
    lcd.print("status : Ready");
    delay(2000);
    lcd.clear();
  }
  bootlimit--;
}


void loop() {
  booting();
  int x = analogRead(A0);
  //Serial.println(x);
  Serial.println(lock_frequency);
  lcd.setCursor(0, 0);
  lcd.print("Tuning :");
  lcd.setCursor(9, 0);
  lcd.print(x);
  lcd.setCursor(13, 0);
  lcd.print("MHz");
  if (x == 40 or x == 41 or x == 42 or x == 43)
  {

    lcd.setCursor(0, 1);
    lcd.print("station: Mil SAR");
    lock_frequency = 0;
  }

  else if (x == 138 or x == 139 or x == 140 or x == 141)
  {

    lcd.setCursor(0, 1);
    lcd.print("station: AF SAR");
    lock_frequency = 0;
  }
  else if (x == 160 or x == 161 or x == 162 or x == 163 or x == 164)
  {
    lcd.setCursor(0, 1);
    lcd.print("station: UGV SAR");
    lock_frequency = 1;
  }
  else
  {

    lcd.setCursor(0, 1);
    lcd.print("station: ?");
    lock_frequency = 0;
  }
  delay(200);
  lcd.clear();
}
