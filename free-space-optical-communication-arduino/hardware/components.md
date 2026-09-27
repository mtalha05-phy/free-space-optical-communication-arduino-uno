# Hardware Components

## Summary table

| # | Component | Quantity | Description (as given in report) |
|---|---|---:|---|
| 1 | Arduino Uno | 2 | Microcontroller board for TX and RX |
| 2 | Laser Diode Module | 1 | 650 nm red laser transmitter |
| 3 | Photodiode BPW34 | 1 | For light detection |
| 4 | Op-Amp LM358 | 1 | For signal amplification |
| 5 | NPN Transistor | 1 | NPN transistor for laser switching |
| 6 | Resistors | Various | 1 kΩ, 10 kΩ, 220 Ω resistors |
| 7 | Breadboard | 1 | Circuit prototyping board |
| 8 | Jumper Wires | Various | Connecting wires |
| 9 | Power Adapter | 1 | Power supply, ~5 V / 2 A |

## Component notes

- **Arduino Uno** — ATmega328-based board, 14 digital I/O pins (6 PWM-capable), 6 analog input pins, 16 MHz clock, programmed via the Arduino IDE.
- **Laser Module** — 5 V laser diode module with a built-in driver circuit; three terminals (VCC, GND, Signal); lasing wavelength 655–670 nm; used as the transmitter element.
- **Photodiode (BPW34)** — Silicon PIN photodiode used as the receiver element; peak sensitivity wavelength ~900 nm; two terminals (Anode, Cathode).
- **LM358 Operational Amplifier** — Dual op-amp used to amplify the weak photocurrent signal from the BPW34 before it is processed by the receiver Arduino.
- **NPN Transistor** — Used as a driver/switch for the laser module, since the Arduino's own output current is too limited to drive the laser directly.
- **Resistors** — Used for current limiting, biasing, and gain-setting in both the transmitter driver stage and the receiver amplifier stage.
- **Breadboard** — Used to assemble and interconnect all components without soldering.
- **Jumper Wires** — Used to make breadboard connections.
- **Power Adapter** — ~5 V, 2 A supply powering the Arduino Uno and the rest of the circuit.

## Implementation Note — transistor part number

The report is not fully consistent about the exact NPN transistor part number used:

- **Table 2.1** and **Section 2.1.5** describe it generically as an "NPN Transistor" and, in the summary table, as a **"2N2222 Transistor."**
- **Section 3.3.1 ("Components Use")** and **Figure 3.2 (circuit diagram)** both label it a **"PN Transistor (BC547)."**

Both are common small-signal NPN transistors usable as a low-side/high-side switch driver, but the report does not clarify which one was actually used in the prototype, or whether both were tried. This documentation preserves both names as they appear in the report rather than picking one.

## Implementation Note — resistor values

Table 2.1 lists the resistor values used in the project as **"1 kΩ, 10 kΩ, 220 Ω."** However, the detailed wiring description in Section 3.2 ("Connections") specifies additional values that do not appear in that summary line:

- A low-value resistor of **10 Ω – 47 Ω** (exact value dependent on the laser's current rating) at the transistor emitter (transmitter side).
- A **100 kΩ** feedback resistor between the LM358 output and its inverting input (receiver side, gain-setting).
- A second **10 kΩ** resistor used at the photodiode (receiver side).

See [transmitter-connections.md](transmitter-connections.md) and [receiver-connections.md](receiver-connections.md) for the full, as-documented wiring, including these additional resistor values.
