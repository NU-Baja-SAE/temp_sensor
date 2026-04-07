#include <Arduino.h>

const int thermistorPin = 32;
const float referenceVoltage = 3.3;
const int referenceResistor = 10000;
const int beta = 3950;
const int nominalTemp = 25;
const int nominalResistance = 8300;

void setup() {
  Serial.begin(115200);
  pinMode(thermistorPin, INPUT);
}

void loop() {
  float reading;
  reading = analogRead(thermistorPin);  // Analog Reading

  float resistance = referenceResistor / ((4095 / reading) - 1);  //Convert to Resistance

  float tempK = 1 / (((log(resistance / nominalResistance)) / beta) + (1 / (nominalTemp + 273.15)));  // Convert to Temp
  float tempC = tempK - 273.15;
  float tempF = tempC * 1.8 + 32;

  printf("Reading %.2f\n", reading);
  printf("Resistance %.2f\n", resistance);
  printf("Temperature (*C): %.2f\n", tempC);
  printf("Temperature (*F): %.2f\n", tempF);

  delay(1000);
}







