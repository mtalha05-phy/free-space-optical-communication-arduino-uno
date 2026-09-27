/*
  Free Space Optical Communication System - TRANSMITTER
  ---------------------------------------------------------------
  Project : Free Space Optical Communication System Using Laser
            Diode and Arduino (BS Physics FYP, Govt. Graduate
            College, Sahiwal)


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
