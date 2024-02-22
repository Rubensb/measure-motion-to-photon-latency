#include "Keyboard.h"
#include "Mouse.h"

// Pin configurations
const int probePin = A4;
const short buttonPin = 7;
const short ledPin = LED_BUILTIN;

const short threshold = 300;

int probeValue;

bool testing = false;

short buttonState = LOW;
short sceneState = 0;  // 0 == dark

unsigned long start;
unsigned long measurement = 0;

void setup() {
  // Pin mode configurations
  pinMode(probePin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Initial LED state
  digitalWrite(ledPin, LOW);

  // Serial port initialization
  Serial.begin(9600);
  while (!Serial)
    ;  // Wait for the serial port to connect. Needed for native USB
  Serial.println("Hey");
  Keyboard.begin();
}

void loop() {
  if (testing) {
    // Measurement logic when testing
    probeValue = analogRead(probePin);
    if (probeValue > threshold) {
      measurement = millis() - start;
      testing = false;
      digitalWrite(ledPin, LOW);
      Serial.println(measurement);
    }
  } else {
    // Rising edge detection for button press
    if (digitalRead(buttonPin) == HIGH) {
      if (buttonState == LOW) {
        // Button pressed, start testing
        Serial.println("yo");
        digitalWrite(ledPin, HIGH);
        testing = true;
        Keyboard.write('d');
        start = millis();
      }
      buttonState = HIGH;
    } else {
      buttonState = LOW;
    }
  }
}
