# Receiver-Side Connections

## Components used

1. Arduino Uno
2. Photodiode (BPW34)
3. Op-Amp LM358
4. Resistors (10 kΩ, 100 kΩ)
5. Breadboard
6. Jumper wires
7. Display screen

## Wiring

- **Photodiode (BPW34):** Connect the **Cathode** to **5 V**. Connect the **Anode** to one end of a **10 kΩ resistor**. Connect the other end of that resistor to **GND**.
- **Op-Amp input:** Connect a jumper wire from the junction between the photodiode anode and the 10 kΩ resistor to **LM358 pin 3 (non-inverting input, +)**.
- **Gain feedback:** Place a **100 kΩ resistor** between **LM358 pin 1 (Output)** and **pin 2 (inverting input, −)**.
- **Gain grounding:** Place a **1 kΩ resistor** between **LM358 pin 2 (−)** and **GND**.
- **Decoupling:** Place a **0.1 µF capacitor** directly between **LM358 pin 8 (5 V supply)** and **pin 4 (GND)**.
- **To Arduino:** Connect **LM358 pin 1 (Output)** to **Arduino Digital pin 2** (the report notes this uses "a digital reading with a software serial implementation for robust edge detection").

## How the receiver works

The BPW34 photodiode receives the modulated optical pulses from the laser. When light falls on it, electron-hole pairs are generated; under reverse bias the resulting photoelectric current is very weak, so it is amplified by the LM358 op-amp (chosen because it can operate from a single, low-voltage supply).

Once amplified, the signal is read by the Arduino, which decodes the incoming bit sequence back into 8-bit binary characters and reconstructs the original message for display on the Serial Monitor.

## Implementation Note — Arduino pin receiving the amplified signal

The written description above states the LM358 output connects to **"Arduino Digital pin 2."** The report's own circuit diagram (**Figure 3.2**), however, labels this same connection **"Digital Pin 8."** The receiver Arduino sketch in this repository (`arduino/receiver/receiver.ino`) uses `SoftwareSerial(2, 3)` with **pin 2** as RX, matching the written description rather than the diagram. This discrepancy between the report's own text and its diagram is preserved here rather than silently corrected — see also the equivalent note in [transmitter-connections.md](transmitter-connections.md).
