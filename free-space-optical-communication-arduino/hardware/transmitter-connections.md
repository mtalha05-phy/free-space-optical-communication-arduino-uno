# Transmitter-Side Connections

## Components used

1. Arduino Uno
2. Laser module (5 V)
3. NPN Transistor (report labels this **BC547** here; see [Implementation Note](components.md#implementation-note--transistor-part-number) on the transistor naming inconsistency)
4. 1 kΩ Resistor
5. Breadboard
6. Jumper wires

## Wiring

### 1. The laser module

- Connect the **Positive (VCC)** wire of the 5 V laser module directly to the **5 V power rail**.
- Connect the **Negative (GND/Signal)** wire of the laser module to the **Collector (pin 1)** of the transistor.

### 2. The base control (voltage divider)

- Connect a **10 kΩ resistor** from the Arduino data pin to the **Base (pin 2)** of the transistor.
- Connect a **1 kΩ resistor** from the **Base (pin 2)** to **GND**. This ensures that when the Arduino outputs 5 V, the voltage at the base is tightly regulated.

### 3. The current setter (emitter side)

- Connect a low-value resistor (typically **10 Ω to 47 Ω**, depending on the laser's current rating) from the **Emitter (pin 3)** to **GND**.

## How the transmitter works

The laser module is attached to the Arduino Uno, which is in turn connected to a computer via the Serial Monitor. When a message is typed and sent to the Arduino, the Arduino converts each character into an 8-bit binary code and flashes the laser according to that pattern: binary **'1'** switches the laser **ON**, binary **'0'** switches it **OFF**. This is On-Off Keying (OOK) modulation.

The NPN transistor and base resistor protect the Arduino's output pin, limit the current into the transistor base, and keep the transistor in saturation while switching.

## Implementation Note — Arduino pin used to drive the laser

The written description above (Section 3.2.1) refers only to "the Arduino data pin" without naming a specific pin number. The report's own circuit diagram labels this connection **"Digital Pin 9."** The transmitter Arduino sketch in this repository (`arduino/transmitter/transmitter.ino`), however, sends the laser data over a `SoftwareSerial` object declared on **pins 2 and 3** (TX on pin 3), as given verbatim in the report's Program Code section. The report does not reconcile the "Digital Pin 9" label in the diagram with the pin 3 used in the code — this is preserved here as an unresolved inconsistency in the source report rather than silently corrected.

## Modulation reference

On-Off Keying is expressed in the report as:

```
s(t) = A·cos(2πft)   for binary 1
s(t) = 0              for binary 0
```

where A is amplitude, f is frequency, t is time, and s(t) is the transmitted signal.
