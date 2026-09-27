/*
  Free Space Optical Communication System - RECEIVER
  ---------------------------------------------------------------
  Project : Free Space Optical Communication System Using Laser
            Diode and Arduino (BS Physics FYP, Govt. Graduate
            College, Sahiwal)

  Role in system:
    Reads the recovered digital signal coming out of the LM358
    amplifier stage (fed from the BPW34 photodiode) on a software
    serial RX pin, and prints each decoded character to the
    Serial Monitor on the receiver-side computer.

  Hardware this sketch expects (see hardware/receiver-connections.md):
    - Arduino Uno
    - BPW34 photodiode -> LM358 amplifier -> this Arduino
    - SoftwareSerial pins 2 (RX, connected to LM358 output) and
      3 (TX, unused here)

  NOTE (Implementation Note - see README "Implementation Notes /
  Report Clarifications"): the report's written connection
  description (Section 3.2.2) states the LM358 output goes to
  "Arduino Digital pin 2", matching this code's use of pin 2 for
  SoftwareSerial RX. The report's circuit diagram (Figure 3.2),
  however, labels this same connection "Digital Pin 8". This
  code follows the report's written description and its own
  SoftwareSerial(2, 3) declaration, i.e. pin 2.

  Source: code reproduced from the FYP report, Section 3.3.4
  "Program Code - Receiver Code", with added comments.
*/

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
