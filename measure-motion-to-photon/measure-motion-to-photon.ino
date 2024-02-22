

// Pin configurations
const int probePin = A4;
const int startProbePin = A3;
const short buttonPin = 7;
const short ledPin = LED_BUILTIN;

const short threshold = 300;
const short startThreshold = 20;

int probeValue;
int startProbeValue;

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
  Serial.println("Hey MMP");
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
    if (analogRead(startProbePin) > startThreshold) {
      testing = true;
      start = millis();
    } else {
      testing false;
    }
  }
}
