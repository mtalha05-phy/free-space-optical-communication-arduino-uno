/*
  Free Space Optical Communication System - RECEIVER
  ---------------------------------------------------------------
  Project : Free Space Optical Communication System Using Laser
            Diode and Arduino (BS Physics FYP, Govt. Graduate
            College, Sahiwal)

#include <SoftwareSerial.h>

// pin 2 is RX (connect to LM358 pin 1), pin 3 is TX (unused here)
SoftwareSerial laserSerial(2, 3);

void setup() {
  Serial.begin(9600);       // Hardware serial for Computer
  laserSerial.begin(1200);  // Must match the transmitter's baud rate
  Serial.println("Laser Receiver Ready. Waiting for signal...");
}

void loop() {
  if (laserSerial.available() > 0) {
    char outChar = laserSerial.read();
    Serial.print(outChar); // Display received character on monitor
  }
}
