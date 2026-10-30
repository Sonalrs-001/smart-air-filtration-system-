
const int tempPin = A0;
const int humidityPin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read temperature from TMP36
  int tempRaw = analogRead(tempPin);

  float voltage = tempRaw * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  // Read simulated humidity from potentiometer
  int humidityRaw = analogRead(humidityPin);

  float simulatedHumidity =
    (humidityRaw / 1023.0) * 100.0;

  // Display temperature
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Display simulated humidity
  Serial.print("Simulated Humidity: ");
  Serial.print(simulatedHumidity);
  Serial.println(" %");

  Serial.println("--------------------");

  delay(1000);
}
