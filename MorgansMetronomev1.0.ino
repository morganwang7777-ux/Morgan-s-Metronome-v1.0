#include <LiquidCrystal.h>

LiquidCrystal lcd(10, 11, 12, 13, A0, A1);

bool running = false;

int bpm = 40;
int patternOptions[] = {4, 5, 6, 7, 2, 3};
int patternIndex = 0;
int patternLength = 4;

int currentBeat = 0;

unsigned long lastBeat = 0;
unsigned long beatInterval = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("METRONOME");

  lcd.setCursor(0, 1);
  lcd.print("BPM: 40  4 BP");

  beatInterval = 60000UL / bpm;

  Serial.println("Ready!");
}

void loop() {
  int potValue = analogRead(A5);

  int newBpm = map(potValue, 0, 1023, 40, 180);

  newBpm = ((newBpm + 2) / 5) * 5;

  if (newBpm != bpm) {
    bpm = newBpm;

    beatInterval = 60000UL / bpm;

    lcd.setCursor(0, 1);
    lcd.print("BPM: ");
    lcd.print(bpm);
    lcd.print("  ");
    lcd.print(patternLength);
    lcd.print(" BP ");

    Serial.print("BPM: ");
    Serial.println(bpm);
  }

  if (digitalRead(3) == LOW) {
    patternIndex++;

    if (patternIndex >= 6) {
      patternIndex = 0;
    }

    patternLength = patternOptions[patternIndex];

    currentBeat = 0;

    lcd.setCursor(0, 1);
    lcd.print("BPM: ");
    lcd.print(bpm);
    lcd.print("  ");
    lcd.print(patternLength);
    lcd.print(" BP ");

    Serial.print("Pattern: ");
    Serial.print(patternLength);
    Serial.println(" beats");

    while (digitalRead(3) == LOW) {
      delay(10);
    }
  }

  if (digitalRead(7) == LOW) {
    running = !running;

    if (running) {
      Serial.println("STARTED");

      lcd.setCursor(0, 0);
      lcd.print("RUNNING         ");

      currentBeat = 0;

      lastBeat = millis();

      digitalWrite(8, HIGH);

      tone(9, 400);
    }
    else {
      Serial.println("STOPPED");

      lcd.setCursor(0, 0);
      lcd.print("METRONOME       ");

      digitalWrite(8, LOW);
      noTone(9);
    }

    while (digitalRead(7) == LOW) {
      delay(10);
    }
  }

  if (running) {
    unsigned long currentTime = millis();

    if (currentTime - lastBeat >= beatInterval) {
      lastBeat += beatInterval;

      currentBeat++;

      if (currentBeat >= patternLength) {
        currentBeat = 0;
      }

      digitalWrite(8, HIGH);

      if (currentBeat == 0) {
        tone(9, 400);
      }
      else {
        tone(9, 200);
      }

      delay(60);

      digitalWrite(8, LOW);
      noTone(9);
    }
  }
}