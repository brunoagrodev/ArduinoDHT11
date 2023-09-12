#include <DHT.h>
#include <DHT_U.h>

#define Tipo DHT11
int pinoDHT = 2;
DHT HT(pinoDHT, Tipo);
float tempC;
float umidade;

int pinoLED = 7; 
bool sensorAtivado = false;

void setup() {
  Serial.begin(9600);
  HT.begin();
  pinMode(pinoLED, OUTPUT); 
}

void loop() {
  tempC = HT.readTemperature();
  umidade = HT.readHumidity();
  
  Serial.println();
  Serial.print("A temperatura é: ");
  Serial.print(tempC);
  Serial.print("ºC ");
  Serial.println();
  Serial.println();
  
  Serial.println();
  Serial.print("A umidade é: ");
  Serial.print(umidade);
  Serial.print("% ");
  
  if (!sensorAtivado && !isnan(tempC) && !isnan(umidade)) {
    sensorAtivado = true;
    digitalWrite(pinoLED, HIGH); 
  } else if (sensorAtivado && (isnan(tempC) || isnan(umidade))) {
    sensorAtivado = false;
    digitalWrite(pinoLED, LOW); 
  }

  delay(1000); 
}
