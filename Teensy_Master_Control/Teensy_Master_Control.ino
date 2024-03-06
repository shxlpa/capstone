// Feb 25, 2024
// Shilpa Rao 
// raoshilpa@g.ucla.edu 
// Driver + force sensor + current sensor integrated control file for one teensy
  // still to-do: integrate OpenCV feedback at the highest level of control (it'll be slower than everything else!)

#include <DualG2HighPowerMotorShield.h>
#include <Wire.h>
#include "MS5837.h"
#include "TCA9548.h"

// Control files
#include "currSens.h"
#include "forceSens.h"
#include "md.h"

DualG2HighPowerMotorShield18v18 md;


void setup()
{

  ////////////////////////////////
        // Force Sensor Setup
  forceSetup();
  ////////////////////////////////
        // Motor Driver Setup
  mdSetup(md);
  ////////////////////////////////
        // Current Sensor Setup
  // currSetup();

}

int i = 0;
void loop()
{

  if (i == 0) {
    delay(1); // driver needs 1 ms to warm up
    i++;
  }

  // Motor Driver FORCE TEST 3/6/24 (must run fastest)
    // observation: the motor driver NEEDS the delay to operate.
  mdLoopForceTest(md); // MD loop calls force loop so that we can map a force reading to the pwm

  // Multiplexor/force sensor loop
  // if (i%1 == 0) { // run 50% of the time
  //   forceLoop();
  // }

  // if (i%4 == 0) {
  //   // currLoop(); // run 25% of the time
  // }

  i++;

  delay(10);

}

