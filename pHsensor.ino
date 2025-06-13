unsigned long previousMillis = 0;
const long interval = 500; // 500ms delay between readings

const int pH_Pin = A0; // pH sensor connected to analog pin

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int rawValue = analogRead(pH_Pin);
    float voltage = rawValue * (3.3 / 1023.0); // Convert to voltage for ESP32/ESP8266
    float pH = 7.0 + ((2.5 - voltage) / 0.18); // Approximate conversion

    Serial.print("Raw: ");
    Serial.print(rawValue);
    Serial.print(" | Voltage: ");
    Serial.print(voltage, 2);
    Serial.print(" V | pH: ");
    Serial.println(pH, 2);
  }
}
