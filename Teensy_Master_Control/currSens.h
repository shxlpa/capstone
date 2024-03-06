// Setup & loop functions for custom designed current sensor PCB with the following integrated circuits:
  // Texas Instr. INA240 –4-V to 80-V, Bidirectional, Ultra-Precise Current Sense Amplifier With Enhanced PWM Rejection
  // Texas Instr. ADS117L11 400-kSPS Wide-Bandwidth, 16-Bit Delta-Sigma ADC
  // Texas Instr. REF4132 Low-Drift, Low-Power, Small-Footprint Series Voltage Reference

// SPI pin setup
#include <SPI.h>

// NOT USING FOR NOW.
// Initialize pins - might want to do our own cs because spi.transfer might not give us the cs signal we want
const int cs = 10;

// ADS117 dictionary
// Define the register addresses (p. 48) 
// FIRST TASK: READ DEV_ID
const int DEV_ID = 0x0;
const int REV_ID = 0x1;
const int STATUS = 0x2;
const int CONTROL = 0x3;
const int MUX = 0x4;
const int CONFIG1 = 0x5;
const int CONFIG2 = 0x6;
const int CONFIG3 = 0x7;
const int CONFIG4 = 0x8;
const int OFFSET2 = 0x9;
const int OFFSET1 = 0xA;
const int OFFSET0 = 0xB; 
const int GAIN2 = 0xC;
const int GAIN1 = 0xD;
const int GAIN0 = 0xE;
const int CRC = 0xF;

void stop() {
  // Function to run for testing
  Serial.println("Stopping read protocol");
}

// Main function to read SPI transfer from board
void readReg() {
  // create buffer of bytes to store the packet you will write
  uint8_t buf[32];

  // Fill buf with the packet you want to send
  buf[0] = 0x00;
  buf[1] = 0x40 + CONTROL;
  buf[2] = 0x00;

  // Serial.print("buf[0] = ");
  // Serial.print(buf[0]);
  // Serial.print(", buf[1] = ");
  // Serial.print(buf[1]);
  // Serial.print(", buf[2] = ");
  // Serial.print(buf[2], DEC);
  // Serial.println();

  // Serial.print("Current: ");
  // Serial.println(buf[1] + buf[2], DEC);
  // buf[1] = 0x40 + DEV_ID + 0x40

  int numBytes = 3; // number of bytes in the packet

  // SPI.transfer using a buffer and number of bytes overwrites the data in buf with the received values
  //  the variable 'buf' is actually a reference to the first element of the array,
  //   so 'buf' is equivalent to '&buf[0]'. You may see me use the latter notation in later code.
  digitalWrite(cs, LOW); // "the comm frame is started by taking CS low and ended by taking CS high"
  //SPI.transfer(0);
  SPI.transfer(buf, numBytes); // overwrites buf
  delay(10);
  digitalWrite(cs, HIGH);
  // Serial.println("Buffer overwritten");

  // Print out the elements of buf
  // Serial.print("buf[0] = ");
  // Serial.print(buf[0]);
  // Serial.print(", buf[1] = ");
  // Serial.print(buf[1]);
  // Serial.print(", buf[2] = ");
  // Serial.println(buf[2]);
  // Serial.println("Ending read protocol");
  // Serial.println();

  
  // Serial.print("Current: ");
  // Serial.println(buf[1] + buf[2], DEC);

}

void start() {
  // Function to run for testing
  // Serial.println("Initiating read protocol");
  readReg();
}

void currSetup() {

  // SPI communication setup
  // SPI configuration and SPI.begin stuff
  SPI.begin();
  SPI.beginTransaction(SPISettings(400000, MSBFIRST, SPI_MODE1)); // MSB or LSB first? 
  pinMode(cs, OUTPUT);
  digitalWrite(cs, HIGH);
  // start Serial over usb to computer
  Serial.begin(115200);
  while (!Serial)
  {
    // wait until the serial port is opened
  }

  delay(100); // give the sensor time to set up. 5/9/23: unsure whether I actually need this

}

void currLoop() {

  // Serial.println("Loop started");
  // start();

  // Don't print reading from buf unles prompted by user. 
    // This will be useful for eventually implementing the reading inside our master control loop.
  // if(Serial.available()) {
    // read something in
    char in = Serial.read(); // in must be one of the ID's above
    // Serial.println("Serial is available");
    start();
    // Make a bunch of cases that you want to test
    // switch(in) {
    //   case 'start':
    //     start(in);
    //     break;
    //   case 'stop':
    //     stop();
    //     break;
    //   default:
    //     Serial.println("Unknown command");
    // }

  // }

}