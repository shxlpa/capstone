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
  currSetup();

}

bool firstStart = true;
void loop()
{

  if (firstStart == true) {
    delay(1); // driver needs 1 ms to warm up
    firstStart = false;
  }
  // Multiplexor/force sensor loop
  forceLoop();

  // Motor Driver Loop
    // observation: the motor driver NEEDS the delay to operate.
  mdLoop(md);

  currLoop();

  delay(10);

}

