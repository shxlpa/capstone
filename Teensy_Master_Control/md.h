// Setup & loop functions for Pololu 2515 Dual G2 High-Power Motor Driver 18v18 Shield for Arduino

#include <DualG2HighPowerMotorShield.h>

// Fault function
void stopIfFault(DualG2HighPowerMotorShield18v18 md)
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

void mdLoopForceTest(DualG2HighPowerMotorShield18v18 md) {
  
  md.enableDrivers();
  delay(1);  // The drivers require a maximum of 1ms to elapse when brought out of sleep mode.

  for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    stopIfFault(md);
    // if (i%200 == 100)
    // {
    //   // Serial.print("M1 current: ");
    //   // Serial.println(md.getM1CurrentMilliamps());
	  // }
    // delay(1); // give capsule time to reach esophagus wall before we record it

    if (i%4 == 0) { // speed it up 4x by only recording force every pwm change of n*4
      Serial.print(i);
      Serial.print(",");
      forceLoop();
    }

  }

  delay(1000);

  // for (int i = 400; i <= -400; i++)
  // {
  //   md.setM1Speed(i);
  //   stopIfFault(md);
  //   if (i%200 == 100)
  //   {
  //     // Serial.print("M1 current: ");
  //     // Serial.println(md.getM1CurrentMilliamps());
	//   }
  //   delay(2);
  // }

  md.disableDrivers(); // Put the MOSFET drivers into sleep mode.
  // delay(500);
}

void mdSetup(DualG2HighPowerMotorShield18v18 md) {
  Serial.println("Dual G2 High Power Motor Shield");
  md.init();
  md.calibrateCurrentOffsets();

  delay(10); // driver needs 10 ms to start up
  // Uncomment to flip a motor's direction:
  // md.flipM1(true);
}