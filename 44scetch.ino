Код:
#include <TinyGPS.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(2, 3);

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

TinyGPS gps;

void getgps(TinyGPS &gps);

void setup()
{
  gpsSerial.begin(9600);
  lcd.begin(16, 2);
}

void getgps(TinyGPS &gps)
{
  float latitude, longitude;
  gps.f_get_position(&latitude, &longitude);
  
  lcd.setCursor(0, 0);
  lcd.print("Lat:");
  lcd.print(latitude, 5);
  lcd.print(" ");
  
  lcd.setCursor(0, 1);
  lcd.print("Long:");
  lcd.print(longitude, 5);
  lcd.print(" ");
  
  delay(3000);
  lcd.clear();
}

void loop()
{
  while (gpsSerial.available() > 0)
  {
    byte a = gpsSerial.read();
    if (gps.encode(a))
    {
      getgps(gps);
    }
  }
}
