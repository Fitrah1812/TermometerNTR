#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float value;
int tmp = A1;

int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;

void setup()
{
    pinMode(A0, INPUT);
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop()
{
    baselineTemp = 40;

    celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

    fahrenheit = ((celsius * 9) / 5 + 32);
    Serial.print(celsius);
    Serial.print(" C, ");
    Serial.print(fahrenheit);
    Serial.println(" F");
    value = analogRead(tmp)*0.004882814;
    value = (value - 0.5) * 100.0;

    if (celsius < baselineTemp && celsius > 27) {
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
    }
    else if (celsius >= baselineTemp) {
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
    }
    lcd.setCursor(0,1);
    lcd.print("Tmp:");
    lcd.print(value);
    delay(1000);
    lcd.clear();
}
