#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11
int dhtPin = 2;
DHT HT(dhtPin, Type);
float tempC;
float humidity;
int dt (10000);
void setup() {
  Serial.begin(9600);
  HT.begin();

}

void loop() {
  tempC = HT.readTemperature();
  Serial.println();
  Serial.print("The temperature is: ");
  Serial.print(tempC);
  Serial.print("ºC ");
  delay(dt);
  Serial.println();
  Serial.println();
  
  humidity = HT.readHumidity();
  Serial.println();
  Serial.print("The humidity is: ");
  Serial.print(humidity);
  Serial.print("% ");
}
