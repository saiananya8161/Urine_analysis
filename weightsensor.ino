#include <HX711.h>

// Define the pins for the HX711
#define DOUT_PIN  7
#define CLK_PIN   6

// Define calibration factors
float calibration_factor = 10000.0; // Adjust as needed based on your specific load sensor

// Initialize the HX711 library
HX711 scale;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println("HX711 calibration");

  // Initialize the load cell
  scale.begin(DOUT_PIN, CLK_PIN);
  scale.set_scale(calibration_factor); // Set the calibration factor
  scale.tare(); // Reset the scale to zero
}

void loop() {
  // Read the weight
  float weight = scale.get_units(10); // Read the weight 10 times and take the average

  // Display the weight
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" units");

  delay(1000); // Wait for a short time before taking another reading
}   
