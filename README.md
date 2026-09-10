# Morgan's Metronome v1.0

Arduino-based digital metronome developed from a breadboard prototype into a custom KiCad PCB shield. (First Project)
I built this project to learn how to use Arduino hardware and software and to create a working metronome instead of having to purchase one to practice my sax.

## Features

- 100 mm × 90 mm size shield
- Adjustable 40–180 BPM
- 5 BPM increments using a 10k potentiometer
- Start/Stop button
- 2–7 beat pattern selection
- Accented first beat
- 16x2 LCD display
- LED beat indicator
- Passive buzzer
- Custom 2-layer Arduino Uno shield PCB

## Development

The project started as a simple buzzer and LED metronome.

I originally used `delay()` for timing, but testing against a reference metronome showed that the BPM was inaccurate. I replaced this with `millis()`-based timing so the beat interval could be tracked more reliably.

I also replaced button-based BPM control with a potentiometer. Since the analog input was too sensitive, I rounded the BPM to 5 BPM increments.

After finishing the breadboard prototype
- I recreated the circuit in KiCad
- Ran ERC/DRC checks
- Selected and measured component footprints
- Routed the PCB, added a bottom GND plane
- Generated Gerber files 

## Hardware

- Arduino Uno
- 16x2 LCD
- 10k potentiometer
- Passive buzzer
- 5mm LED
- 220Ω resistor
- 2 pushbuttons

## Future Improvements
Tap tempo
More rhythm modes
Standalone PCB without the Arduino Uno
Enclosure
Improved buzzer volume control

## Repository

```text
firmware/   Arduino code
hardware/   KiCad schematic and PCB
gerbers/    Manufacturing files
images/     Project screenshots

Version

Morgan's Metronome v1.0
