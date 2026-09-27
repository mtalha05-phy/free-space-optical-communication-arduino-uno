# Free Space Optical Communication System Using Laser Diode and Arduino

A low-cost, point-to-point **Free Space Optical (FSO) communication** prototype that transmits text data through a modulated 650 nm laser beam and recovers it on a receiver built around a BPW34 photodiode, an LM358 amplifier, and a second Arduino Uno. Built as a BS Physics Final Year Project at the Department of Physics, Government Graduate College, Sahiwal.

> This repository documents the project exactly as reported in the accompanying FYP report ([docs/project-report.pdf](docs/project-report.pdf)). No specifications, results, or features beyond what the report states are claimed here — see [Implementation Notes / Report Clarifications](#implementation-notes--report-clarifications) for a few places where the report itself is inconsistent.

## Description

This project demonstrates a laser-based wireless link that sends text typed into a Serial Monitor across free space and displays it on a second computer's Serial Monitor, without any wires or radio-frequency hardware in between. The transmitter Arduino modulates a 650 nm laser using On-Off Keying (OOK); the receiver uses a BPW34 photodiode and an LM358 op-amp to recover and amplify the optical signal before a second Arduino decodes and displays it.

## Project Overview

Free Space Optical (FSO) communication uses light instead of radio waves to carry information through open space, offering high bandwidth, immunity to electromagnetic interference, and (due to its narrow, directional beam) a degree of inherent security — advantages the report cites as motivation, alongside noting that the same underlying principle underlies advanced systems such as satellite and deep-space laser links. This prototype demonstrates the basic building blocks of such a link at a small, benchtop scale: an Arduino-driven laser transmitter and a photodiode-based receiver with amplification and decoding. It is intended, per the report, "for educational and prototyping purposes."

For the full write-up (problem statement, objectives, and scope), see [docs/project-overview.md](docs/project-overview.md).

## System Architecture

```text
Computer / Serial Monitor
        |
        v
Transmitter Arduino
        |
        v
Digital Data / On-Off Keying (OOK)
        |
        v
Laser Module (650 nm)
        |
        v
Free-Space Optical Channel
        |
        v
BPW34 Photodiode
        |
        v
LM358 Amplifier
        |
        v
Receiver Arduino
        |
        v
Serial Monitor
```

```mermaid
flowchart LR
    A[Computer / Serial Monitor] --> B[Transmitter Arduino]
    B --> C[OOK Modulation]
    C --> D[Laser Module]
    D --> E[Free-Space Optical Channel]
    E --> F[BPW34 Photodiode]
    F --> G[LM358 Amplifier]
    G --> H[Receiver Arduino]
    H --> I[Serial Monitor]
```

Full detail: [docs/system-architecture.md](docs/system-architecture.md)

## Features

Only features documented in the report are listed here:

- Free-space optical (laser-based) data transmission
- Laser-diode transmitter, driven through an NPN transistor stage
- BPW34 photodiode receiver with LM358 signal amplification
- Arduino-based encoding/decoding on both ends
- On-Off Keying (OOK) digital modulation
- Text output via the Arduino Serial Monitor
- Short-range, point-to-point communication (tested up to ~8 m indoors)
- Low-cost prototype built from readily available components

## Hardware

| Component | Quantity | Purpose |
| --- | ---: | --- |
| Arduino Uno | 2 | Transmitter and receiver processing |
| Laser Module (650 nm) | 1 | Optical transmitter |
| BPW34 Photodiode | 1 | Optical receiver |
| LM358 Op-Amp | 1 | Signal amplification |
| NPN Transistor | 1 | Laser switching/driver (see [transistor naming note](#implementation-notes--report-clarifications)) |
| Resistors | Various | Biasing / current limiting / gain-setting (see [resistor values note](#implementation-notes--report-clarifications)) |
| Breadboard | 1 | Circuit prototyping |
| Jumper Wires | Various | Connections |
| Power Adapter | 1 | ~5 V / 2 A system power |

Full component descriptions: [hardware/components.md](hardware/components.md)

## Software

- **Arduino IDE** — used to write and upload both sketches.
- **C/C++** — the language Arduino sketches are written in.
- **SoftwareSerial library** — used on both the transmitter and receiver to create a second serial channel dedicated to the laser link, separate from the hardware serial connection to each computer's Serial Monitor.

## How It Works

1. A user types a message into the transmitter computer's Serial Monitor.
2. The transmitter Arduino reads each character as it arrives.
3. The Arduino forwards the character over `SoftwareSerial` to the laser driver stage, which switches the laser on and off in the corresponding 8-bit binary / OOK pattern.
4. The laser light propagates across the free-space optical channel.
5. The BPW34 photodiode at the receiver detects the incoming light pulses and converts them to a weak photocurrent.
6. The LM358 op-amp amplifies this signal to a usable level.
7. The receiver Arduino reads the amplified signal over its own `SoftwareSerial` channel and reconstructs each character.
8. The recovered message is printed to the receiver computer's Serial Monitor.

## Arduino Code

**Transmitter:** [`arduino/transmitter/transmitter.ino`](arduino/transmitter/transmitter.ino)
**Receiver:** [`arduino/receiver/receiver.ino`](arduino/receiver/receiver.ino)

Both sketches are reproduced from the report's Program Code section (3.3.4) with explanatory comments added; no functional changes were made to the logic.

## Circuit Connections

- **Transmitter side:** [hardware/transmitter-connections.md](hardware/transmitter-connections.md)
- **Receiver side:** [hardware/receiver-connections.md](hardware/receiver-connections.md)
- **Circuit diagram (as drawn in the report):** [hardware/circuit-diagram/](hardware/circuit-diagram/) (see note below)

> **Note:** the original circuit diagram (report Figure 3.2) exists only as an embedded image inside the PDF report ([docs/project-report.pdf](docs/project-report.pdf), page 18); it has not been re-drawn or extracted as a separate image file here to avoid introducing errors. The `hardware/circuit-diagram/` folder is provided as a placeholder if you'd like to add an extracted or redrawn version.

## Results

Tested indoors under clear line-of-sight conditions:

| Distance | Performance |
| --- | --- |
| 1–2 m | Excellent |
| 2–3 m | Good (stable) |
| 3–7 m | Moderate (some noise) |
| > 7 m | Degraded |

Test messages "HELLO", "12345678", and "Laser" were transmitted and received correctly. Sunlight and artificial light were noted as noise sources, addressed with optical shielding and a filtering capacitor.

Full results and discussion: [docs/results.md](docs/results.md)

## Limitations

As stated in the report:

1. Requires a clear line of sight between transmitter and receiver.
2. Affected by fog, rain, and dust.
3. Speed is limited by Arduino timing delay.
4. Requires precise alignment between transmitter and receiver.

## Applications and Future Work

The report discusses these as potential applications/extensions of the underlying technology (not as capabilities this prototype itself demonstrates): Moon–Earth/Earth–Moon communication, satellite and space communication, military/secure communication, Li-Fi, industrial automation, and medical technology. Details: [docs/results.md](docs/results.md#applications-and-future-expansion-section-52).

## Repository Structure

```text
free-space-optical-communication-arduino/
├── README.md
├── LICENSE
├── .gitignore
│
├── docs/
│   ├── project-report.pdf
│   ├── project-overview.md
│   ├── system-architecture.md
│   └── results.md
│
├── arduino/
│   ├── transmitter/
│   │   └── transmitter.ino
│   └── receiver/
│       └── receiver.ino
│
├── hardware/
│   ├── components.md
│   ├── transmitter-connections.md
│   ├── receiver-connections.md
│   └── circuit-diagram/
│
├── images/
│   ├── project/
│   ├── circuit/
│   ├── hardware/
│   └── results/
│
└── references/
    └── references.md
```

## Implementation Notes / Report Clarifications

The report contains a few internal inconsistencies. Rather than silently resolving them, they are documented here and in the relevant hardware docs, with what the report actually says on each side:

- **Transistor part number:** Table 2.1 and Section 2.1.5 call it a "2N2222 Transistor"; Section 3.3.1 and the circuit diagram (Figure 3.2) call it a "BC547." The report does not state which was actually used, or whether the labels were used loosely. See [hardware/components.md](hardware/components.md#implementation-note--transistor-part-number).
- **Receiver output pin:** the written wiring description (Section 3.2.2) sends the LM358 output to "Arduino Digital pin 2," matching the receiver code's `SoftwareSerial(2, 3)`. The circuit diagram (Figure 3.2) instead labels this connection "Digital Pin 8." See [hardware/receiver-connections.md](hardware/receiver-connections.md#implementation-note--arduino-pin-receiving-the-amplified-signal).
- **Transmitter drive pin:** the written wiring description refers only to "the Arduino data pin," while the circuit diagram labels it "Digital Pin 9"; the transmitter code instead drives the laser stage via `SoftwareSerial` TX on pin 3. See [hardware/transmitter-connections.md](hardware/transmitter-connections.md#implementation-note--arduino-pin-used-to-drive-the-laser).
- **Resistor value list:** the summary component table (Table 2.1) lists only "1 kΩ, 10 kΩ, 220 Ω" resistors, but the detailed wiring in Section 3.2 also calls for a 10–47 Ω emitter resistor and a 100 kΩ feedback resistor. See [hardware/components.md](hardware/components.md#implementation-note--resistor-values).
- **Project title wording:** the report's cover page reads "...Using Laser **Diode** and Arduino," while its certificate page reads "...Using Laser **Module** and Arduino." This repository uses the cover-page title.

None of these are claimed here as experimentally verified beyond what the report itself establishes — they are flagged so anyone reproducing the prototype can check their own hardware against both versions.

## References

See [references/references.md](references/references.md) for the full list as given in the report, including the Arduino, TinkerCAD, and component datasheet references cited.

## Authors

Final Year Project, BS Physics (Session 2021–25), Department of Physics, Government Graduate College, Sahiwal — supervised by Mr. M. Khalid Saleem.

- Arslan Maqsood
- Muhammad Talha
- Muhammad Sajid
- Muhammad Azam Mustafa
- Muhammad Danish
- Sajid Ali

## License

Released under the [MIT License](LICENSE).
