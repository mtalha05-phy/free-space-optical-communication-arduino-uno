/*
  Free Space Optical Communication System - TRANSMITTER
  ---------------------------------------------------------------
  Project : Free Space Optical Communication System Using Laser
            Diode and Arduino (BS Physics FYP, Govt. Graduate
            College, Sahiwal)

  Role in system:
    Reads characters typed into the Serial Monitor on the
    transmitter-side computer and forwards them, one character
    at a time, over a second (software) serial channel that is
    wired to the laser driver circuit. The laser is switched
    ON/OFF in the pattern of the outgoing bits, i.e. On-Off
    Keying (OOK): binary '1' -> laser ON, binary '0' -> laser OFF.

  Hardware this sketch expects (see hardware/transmitter-connections.md):
    - Arduino Uno
    - 5V laser module, driven through an NPN transistor stage
    - SoftwareSerial pins 2 (RX, unused) and 3 (TX, drives the laser stage)

  Source: code reproduced from the FYP report, Section 3.3.4
  "Program Code - Transmitter Code", with added comments.
*/

#include <SoftwareSerial.h>

// pin 3 is TX (connect to laser), pin 2 is RX (unused here)
SoftwareSerial laserSerial(2, 3);

void setup() {
  Serial.begin(9600);       // Hardware serial for Computer
  laserSerial.begin(1200);  // Low baud rate for higher reliability over the air
  Serial.println("Laser Transmitter Ready. Type your message below:");
}

void loop() {
  if (Serial.available() > 0) {
    char inChar = Serial.read();
    laserSerial.write(inChar); // Send character via laser
    Serial.print(inChar);      // Echo back to local monitor
  }
}
