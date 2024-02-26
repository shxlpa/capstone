#include <Wire.h>
#include "MS5837.h"

MS5837 sensor;
// MS5837 sensor1;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  Serial.println("Starting");
  
  Wire.begin();
  Wire.setSDA(18);
  Wire.setSCL(19);

  while (!sensor.init()) {
    Serial.println("Init failed!");
    Serial.println("Are SDA/SCL connected correctly?");
    Serial.println("Blue Robotics Bar30: White=SDA, Green=SCL");
    Serial.println("\n\n\n");
    delay(5000);
  }

  sensor.setModel(MS5837::MS5837_02BA);
  sensor.setFluidDensity(1.2); // kg/m^3 (freshwater, 1029 for seawater)

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.read();

  Serial.println(sensor.pressure()); 
  // Serial.println("new line!");

  delay(1);
}