#include <DHT11.h>
#include <LiquidCrystal.h>

DHT11 dht11(4);

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int temperature;
int humidity;


void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
}

void loop() {

  dht11.readTemperatureHumidity(temperature, humidity);

  lcd.setCursor(13, 0);
  lcd.print(String(temperature) + "C");
  lcd.setCursor(13, 1);
  lcd.print(String(humidity) + "%");

  delay(2000);
}