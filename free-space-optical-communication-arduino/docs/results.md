# Results and Discussion

Source: FYP report, Chapter 4 ("Results and Discussion") and Chapter 5 ("Conclusion and Future Expansion").

## Graphical analysis (Section 4.1)

The report presents two theoretical/graphical relationships (plotted, not raw experimental data tables):

- **Distance vs. signal strength:** the report states signal strength *I* is inversely proportional to the square of distance *d* (an inverse-square relationship, *I ∝ 1/d²*), and shows a graph of relative signal strength dropping sharply from 1 m to about 8 m.
- **Light intensity vs. photodiode output:** the report gives the relationship *I_photo = R · P_light* (photocurrent proportional to incident light power) and shows a graph of photodiode output voltage rising with light intensity (mW/cm²) before leveling off toward saturation around 8-10 mW/cm².

## Transmission distance analysis (Section 4.2)

The report states these results "were obtained experimentally under indoor laboratory conditions using a 650 nm laser module":

| Distance | Performance |
|---|---|
| 1–2 m | Excellent |
| 2–3 m | Good (stable) |
| 3–7 m | Moderate (some noise) |
| > 7 m | Degraded |

## Effect of noise (Section 4.3)

Sunlight and artificial light are reported to introduce noise that can distort the signal and disturb reliable communication. The report states optical shielding and a filtering capacitor were used to reduce this noise effect.

## End-to-end communication results (Section 4.4)

The report states that several test messages — **"HELLO"**, **"12345678"**, and **"Laser"** — were transmitted and that all were received correctly according to the transmitter program. No further quantitative detail (e.g., bit error rate, number of trials) is given in the report for these tests.

## Conclusion (Section 5.1)

The report concludes that the project successfully demonstrated free-space optical communication using a laser module and Arduino, offering an alternative to wired and radio-wave communication that is medium-independent, fast, highly directional, and secure — noting particular relevance to defense and satellite communication, with potential for further development.

## Applications and Future Expansion (Section 5.2)

The report lists these as **applications and future directions for the underlying technology**, not as capabilities already demonstrated by this prototype:

1. **Moon-to-Earth / Earth-to-Moon communication** — cited as an example of ongoing (e.g. NASA) deep-space laser communication research.
2. **Satellite and space communication** — laser links instead of RF for higher data rates and less interference.
3. **Military and secure communication** — narrow beam width makes interception/hacking difficult.
4. **Li-Fi technology** — using light instead of Wi-Fi for faster data transfer.
5. **Industrial automation** — machine-to-machine communication and error detection via laser signals.
6. **Medical technology** — optical signals in imaging, diagnosis, and data transmission between devices.

## Limitations (Section 5.3)

As stated in the report:

1. Laser communication requires a clear line of sight.
2. It is affected by fog, rain, and dust.
3. Its speed is limited by Arduino timing delay.
4. It requires precise alignment between transmitter and receiver.
