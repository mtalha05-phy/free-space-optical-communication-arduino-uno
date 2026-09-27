# Project Overview

Source: FYP report, Abstract and Chapter 1 ("Introduction").

## Abstract

Free Space Optical (FSO) communication is described in the report as an emerging wireless communication technology that uses light instead of radio waves to transmit information through free space, offering high bandwidth and immunity to electromagnetic interference, and used by satellites, military systems, and industrial automation. The objective of this project was to design and develop a low-cost FSO communication system using a laser diode, a BPW34 photodiode, an LM358 operational amplifier, and Arduino Uno microcontrollers.

## Problem Statement 

The report identifies the following limitations of traditional (RF) wireless systems as motivation for the project:

- **Electromagnetic interference** — unwanted signal from other electronic devices.
- **Limited bandwidth** — limited amount of spectrum.
- **Spectrum licensing** — government permission required to use certain RF bands.
- **Security vulnerabilities** — weaknesses in communication security.

The project's stated aim is to develop a free-space optical communication system using laser light to reduce these limitations for specific applications.

## Project Overview

The project of a laser based wireless communication system built from readily available components, using two Arduino Uno boards as the transmitter and receiver processing units. It notes that the same underlying principle is used in advanced space optical communication systems, citing communication links between the Moon and Earth as an example of the broader technology (this is presented in the report as context/motivation, not as something the prototype itself achieves — see [Limitations](results.md#limitations)).

## Objectives

The primary objectives were to:

- Design and implement a laser-based wireless communication system using Arduino Uno.
- Develop transmitter and receiver circuits for data transmission.
- Learn and implement Arduino programming using the Arduino IDE.
- Evaluate the system's performance.
- Demonstrate practical applications of wireless communication in low cost.

## Working Principle

The report summarizes the system's operating principle as:

1. The Arduino transmitter sends digital signals.
2. The laser module converts digital signals into light pulses.
3. The photodiode detects light pulses via the photoelectric effect.
4. The Arduino receiver processes and decodes the signals.
5. The decoded message is displayed on a computer screen via the Arduino Serial Monitor.

## Scope note

This repository documents the prototype exactly as reported: a short-range, point-to-point optical link tested indoors under laboratory conditions (see [results.md](results.md)). References in the report to satellite links, Moon–Earth communication, Li-Fi, and other applications are the report's own discussion of the broader field and potential future directions — not capabilities demonstrated by this prototype. See [Applications and Future Expansion](results.md#applications-and-future-expansion-section-52).
