#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(23, 22, 21, 19, 18, 17);

const int heartPin = 35;

int beats = 0;
int bpm = 0;

unsigned long lastCalc = 0;
unsigned long lastDisplay = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(heartPin, INPUT);

  sensors.begin();

  lcd.begin(16,2);
  lcd.print("Health Monitor");

  delay(2000);
  lcd.clear();

  lastCalc = millis();
}

void loop()
{
  // Count pulse
  if(digitalRead(heartPin) == HIGH)
  {
    beats++;
    delay(250);   // Prevent counting the same beat multiple times
  }

  // Calculate BPM every 5 seconds
  if(millis() - lastCalc >= 5000)
  {
    bpm = beats * 12;

    beats = 0;
    lastCalc = millis();
  }

  // Update display every second
  if(millis() - lastDisplay >= 5000)
  {
    lastDisplay = millis();

    sensors.requestTemperatures();
    float temp = sensors.getTempCByIndex(0);

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" C   ");

    Serial.print("Heart Rate: ");
    Serial.print(bpm);
    Serial.println(" BPM");

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Temp:");
    lcd.print(temp,1);
    lcd.print((char)223);
    lcd.print("C");

    lcd.setCursor(0,1);
    lcd.print("HR:");
    lcd.print(bpm);
    lcd.print(" BPM");
  }
}