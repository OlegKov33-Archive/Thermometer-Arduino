#include <DHT11.h>
#include <LiquidCrystal.h>

DHT11 dht11(4);

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int redPin = 7;
int greenPin = 6;
int bluePin = 5;
int temperature;
int humidity;


void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");

  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {

  dht11.readTemperatureHumidity(temperature, humidity);

  lcd.setCursor(13, 0);
  lcd.print(String(temperature) + "C");
  lcd.setCursor(13, 1);
  lcd.print(String(humidity) + "%");

  if((temperature > 20 && temperature < 25) &&
    (humidity >= 30 && humidity <= 50)){

      setColor(0, 255, 0);
  }
  
  else if(temperature > 24){
    setColor(255, 0, 0);
  }
  else if(temperature < 20){
    setColor(0, 0, 255);
  }

  else if(humidity > 50){
    setColor(255, 150, 0);
  }
  else if(humidity < 30){
    setColor(255, 0, 150);
  }
  else{
    setColor(255, 255, 255);
  }
  delay(2000);
}

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);
}
