# System Architecture

Source: FYP report, Figure 3.1 ("Complete Project Working Concept") and Figure 3.2 ("Complete Project Circuits Diagrams"), Section 3.3.

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

This mirrors Figure 3.1 in the report, which shows the transmitter chain as **Text/Data -> Arduino UNO -> LASER Driver -> LASER Module**, a **Free Space** gap, and the receiver chain as **Photodiode -> Amplifier (LM358) -> Arduino UNO -> Serial Monitor / LED / Speaker**.

```mermaid
flowchart LR
    A[Text / Data] --> B[Transmitter Arduino Uno]
    B --> C[Laser Driver - NPN transistor stage]
    C --> D[Laser Module - 650 nm, OOK]
    D -.->|Free-Space Optical Channel| E[Photodiode BPW34]
    E --> F[Amplifier LM358]
    F --> G[Receiver Arduino Uno]
    G --> H[Serial Monitor]
```

## Modulation

The report specifies **On-Off Keying (OOK)**, a digital modulation scheme where the laser carrier is switched on for binary '1' and off for binary '0' (Section 3.3.1):

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
