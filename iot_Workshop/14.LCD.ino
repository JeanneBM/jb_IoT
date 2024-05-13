#include <LCD_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11 

LCD_I2C lcd(0x27, 16, 2); 
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    lcd.begin(); 
    lcd.backlight();
    dht.begin();
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Temp: "); 
    lcd.print(dht.readTemperature(), 1);
    lcd.print(char(223));
    lcd.print("C");
    lcd.setCursor(0, 1); 
    lcd.print("Hum: ");
    lcd.print(dht.readHumidity(), 0);
    lcd.print("%");
    delay(500);
}
