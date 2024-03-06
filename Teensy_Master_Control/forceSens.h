// Setup & loop functions for 4 bluerobotics MS5837 force sensors + TCA9548 multiplexer

#include "TCA9548.h"
#include "MS5837.h"
#include <Wire.h>
#define TCAADDR 0x70

// for each device make a difference sensor instance 
MS5837 sensor0;
MS5837 sensor1;
MS5837 sensor2;
MS5837 sensor3;

// for switching between the multiplexer TCA9548A channels 
void tcaselect(uint8_t channel) {
  if (channel > 3) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();  
}

// Read force sensor values
// MS5837 sensor0, MS5837 sensor1, MS5837 sensor2, MS5837 sensor3
void forceLoop() {

  float pres0, pres1, pres2, pres3;
  float temp0, temp1, temp2, temp3;

  tcaselect(0);
  sensor0.read();
  pres0 = sensor0.pressure();
  temp0 = sensor0.temperature();

  tcaselect(0);
  sensor1.read();
  pres1 = sensor1.pressure();
  temp1 = sensor1.temperature();

  tcaselect(0);
  sensor2.read();
  pres2 = sensor2.pressure();
  temp2 = sensor2.temperature();

  tcaselect(7);
  sensor3.read();
  pres3 = sensor3.pressure();
  temp3 = sensor3.pressure();

  // Serial.println("Forces ");
  // Serial.print("1: ");
  // Serial.print(pres0);
  // Serial.print(", ");
  // Serial.print("2: ");
  // Serial.print(pres1);
  // Serial.print(", ");
  // Serial.print("3: ");
  // Serial.print(pres2);
  // Serial.print(", ");
  // Serial.print("4: ");
  // Serial.print(pres3);
  // Serial.println(", ");

  Serial.print(pres0);
  Serial.print(",");
  Serial.print(pres1);
  Serial.print(",");
  Serial.print(pres2);
  Serial.print(",");
  Serial.println(pres3);


}

void forceSetup() {
  Serial.begin(115200);
  Serial.println("Starting");
  
  // MUX to Teensy communicates over 1 I2C line. Only declaring 1 wire type since we only have 1 MUX.
  Wire.begin();
  Wire.setSDA(18);
  Wire.setSCL(19);

  tcaselect(0); // SD0, SC0 address on MUX
  sensor0.init(); 
  sensor0.setModel(MS5837::MS5837_02BA);
  sensor0.setFluidDensity(1.2);

  tcaselect(1); // SD1, SC1 address on MUX
  sensor1.init();
  sensor1.setModel(MS5837::MS5837_02BA);
  sensor1.setFluidDensity(1.2);

  tcaselect(2); // SD2, SC2 address on MUX
  sensor2.init();
  sensor2.setModel(MS5837::MS5837_02BA);
  sensor2.setFluidDensity(1.2);

  tcaselect(3); // SD3, SC3 address on MUX
  sensor3.init();
  sensor3.setModel(MS5837::MS5837_02BA);
  sensor3.setFluidDensity(1.2);
}