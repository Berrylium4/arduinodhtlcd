#include <LiquidCrystal.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <SimpleDHT.h>

int DHTpin = 3;
SimpleDHT11 dht11;

LiquidCrystal lcd(7,8,9,10,11,12);
char buff[10];

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.clear();
}

void loop() {
  byte temp = 0;
  byte humidity = 0;
  byte rawdata[40];
  float fahr;
  memset(rawdata, 0, 40);

  if (dht11.read(DHTpin, &temp, &humidity, rawdata)){
    Serial.println("Read DHT11 failed");
    return;
  }

  fahr = ((int)temp * 1.8) + 32;

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  //itoa((int)temp, buff, 10);
  //lcd.print(buff);
  //lcd.print(" C ");
  lcd.print(fahr);
  lcd.print(" F");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  itoa((int)humidity, buff, 10);
  lcd.print(buff);
  lcd.print("%");
  
  Serial.print((int)temp);
  Serial.print("C, ");
  Serial.print((int)humidity);
  Serial.println("%");

  delay(1500);
  /*
  if (Serial.available()){
    delay(100);
    lcd.clear();
    memset(buff, 0, sizebuf); // clears buffer
    index = 0;
    while (Serial.available() > 0){
      char inputchar = Serial.read();
      //Serial.print(inputchar);
      if (inputchar != '\n')
      {
        buff[index] = inputchar;
        ++index;
      }
    }

    lcd.print(buff);
    if (evaluate(buff)) // success
    {
      lcd.setCursor(0,1);
      lcd.print(buff);
      lcd.setCursor(0,0);
    }
    else
    {
      if (clrs) // clear screen
      {
        lcd.clear();
      }
    }
  }
  */

} // void loop
