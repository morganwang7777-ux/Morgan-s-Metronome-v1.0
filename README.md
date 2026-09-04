# Morgans-Metronome-v1.0
Arduino-based digital metronome with adjustable BPM, beat patterns, LCD feedback, and a custom KiCad PCB shield.

## Features

- Adjustable tempo from 40–180 BPM
- BPM changes in 5 BPM increments
- 10k potentiometer for tempo control
- Start/Stop pushbutton
- Beat pattern selection:
  - 2 beats
  - 3 beats
  - 4 beats
  - 5 beats
  - 6 beats
  - 7 beats
- Accented first beat of each pattern
- 16x2 LCD displaying BPM and beat pattern
- LED flashes on each beat
- Passive buzzer provides audio output
- Arduino Uno-based control
- Custom 2-layer PCB shield designed in KiCad

## Project Development

The project started as a basic Arduino circuit using a passive buzzer and an LED. The buzzer generated the metronome beat while the LED flashed at the same time to provide a visual indication.

### BPM Control

My original plan was to use buttons to increase and decrease BPM, but I did not have enough buttons available for all of the controls I wanted.

I replaced the BPM buttons with a 10k potentiometer connected to an analog input.

The Arduino reads the potentiometer as a value between 0 and 1023 and maps that value to a range of 40–180 BPM.

One problem with this approach was that small changes in the potentiometer caused the BPM value to change too easily. To make the control more stable and easier to use, I rounded the BPM to the nearest 5 BPM.

## Timing Accuracy

One of the biggest problems I encountered was inaccurate beat timing.

My first implementation used `delay()` to control the time between beats. The metronome sounded approximately correct, but after comparing it against the Google Metronome, I noticed that the timing was not consistently accurate.

I changed the timing system to use `millis()` and calculated the beat interval using:

```cpp
beatInterval = 60000UL / bpm;
