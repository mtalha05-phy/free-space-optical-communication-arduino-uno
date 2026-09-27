# System Architecture

## Signal path

```text
Text/Data (typed on transmitter computer)
        |
        v
Transmitter Arduino Uno
        |
        v
Laser Driver (NPN transistor stage)
        |
        v
Laser Module (650 nm, On-Off Keying)
        |
        v
Free-Space Optical Channel
        |
        v
Photodiode (BPW34)
        |
        v
Amplifier (LM358)
        |
        v
Receiver Arduino Uno
        |
        v
Serial Monitor (message displayed)
```

## Modulation

The report specifies **On-Off Keying (OOK)**, a digital modulation scheme where the laser carrier is switched on for binary '1' and off for binary '0' :

```
s(t) = A·cos(2πft)   for binary 1
s(t) = 0              for binary 0
```

## Transmitter and receiver roles

- **Transmitter Arduino:** reads characters from the Serial Monitor, converts each into an 8-bit binary pattern, and drives the laser (via the NPN transistor stage) accordingly.
- **Laser module:** the optical transmitter; converts the electrical drive signal into a modulated light beam.
- **BPW34 photodiode:** the optical receiver; converts the incoming light pulses back into a weak electrical (photocurrent) signal.
- **LM358 amplifier:** boosts the weak photodiode signal to a usable digital-logic level.
- **Receiver Arduino:** reads the amplified signal, reconstructs the original 8-bit characters, and prints the decoded message to its Serial Monitor.

For the exact, as-documented wiring behind each stage (including two pin-numbering inconsistencies between the report's text and its own circuit diagram), see [hardware/transmitter-connections.md](../hardware/transmitter-connections.md) and [hardware/receiver-connections.md](../hardware/receiver-connections.md).
