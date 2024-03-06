// Feb 25, 2024
// Shilpa Rao 
// raoshilpa@g.ucla.edu 
// Driver + force sensor integrated control file for one teensy

#include <DualG2HighPowerMotorShield.h>
#include <Wire.h>
#include "MS5837.h"
#include "TCA9548.h"

#define TCAADDR 0x70
DualG2HighPowerMotorShield18v18 md;

// for each device make a difference sensor instance 
MS5837 sensor0;
MS5837 sensor1;
MS5837 sensor2;
MS5837 sensor3;

// for switching between the TCA9548A channels
void tcaselect(uint8_t channel) {
  if (channel > 3) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();  
}

void stopIfFault()
{
  // if (md.getM2Fault())
  // {
  //   md.disableDrivers();
	// delay(1);
  //   Serial.println("M2 fault");
  //   while (1);
  // }

  if (md.getM1Fault())
  {
    md.disableDrivers();
	delay(1);
    Serial.println("M1 fault");
    while (1);
  }
}

void forceLoop(MS5837 sensor0, MS5837 sensor1, MS5837 sensor2, MS5837 sensor3) {

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

  Serial.println("NEW PACKET:");
  Serial.println(pres0);
  Serial.println(pres1);
  Serial.println(pres2);
  Serial.println(pres3);

  // delay(1);

}

void mdLoop(DualG2HighPowerMotorShield18v18 md) {
  
  md.enableDrivers();
  // delay(1);  // The drivers require a maximum of 1ms to elapse when brought out of sleep mode.

  for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      // Serial.print("M1 current: ");
      // Serial.println(md.getM1CurrentMilliamps());
	}
    delay(2);
  }

  for (int i = 400; i >= -400; i--)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      // Serial.print("M1 current: ");
      // Serial.println(md.getM1CurrentMilliamps());
	}
    delay(2);
  }

  for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      // Serial.print("M1 current: ");
      // Serial.println(md.getM1CurrentMilliamps());
	}
    delay(2);
  }

  for (int i = 0; i <= 400; i++)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      // Serial.print("M2 current: ");
      // Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }

  for (int i = 400; i >= -400; i--)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      // Serial.print("M2 current: ");
      // Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }

  for (int i = -400; i <= 0; i++)
  {
    md.setM2Speed(i);
    stopIfFault();
    if (i%200 == 100)
    {
      // Serial.print("M2 current: ");
      // Serial.println(md.getM2CurrentMilliamps());
    }
    delay(2);
  }

  md.disableDrivers(); // Put the MOSFET drivers into sleep mode.
  // delay(500);
}

void setup()
{

  ////////////////////////////////
        // Force Sensor Setup

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

  ////////////////////////////////
        // Motor Driver Setup
  Serial.println("Dual G2 High Power Motor Shield");
  md.init();
  md.calibrateCurrentOffsets();

  delay(10); // driver needs 10 ms to start up

  // Uncomment to flip a motor's direction:
  // md.flipM1(true);

}

bool firstStart = true;
void loop()
{

  if (firstStart == true) {
    delay(1); // driver needs 1 ms to warm up
    firstStart = false;
  }
  // Multiplexor/force sensor loop
  forceLoop(sensor0, sensor1, sensor2, sensor3);

  // Motor Driver Loop
  mdLoop(md);

  delay(10);

}

