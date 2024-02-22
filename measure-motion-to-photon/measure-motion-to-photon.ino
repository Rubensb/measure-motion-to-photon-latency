// Pin configurations
const int probePin = A4;
const int startProbePin = A2;
const int ledPin = LED_BUILTIN;

const short threshold = 300;
const short startThreshold = 50;

bool testing = false;
bool done = false;

unsigned long start;
unsigned long measurement = 0;

void setup() {
  // Pin mode configurations
  pinMode(startProbePin, INPUT);
  pinMode(probePin, INPUT);
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

  // Serial.print("sp: ");
  // Serial.print(analogRead(startProbePin));
  // Serial.print("\tpp: ");
  // Serial.println(analogRead(probePin));
  // delay(200);
  if (testing) {
    // Measurement logic when testing
    if (analogRead(probePin) > threshold) {
      measurement = millis() - start;
      testing = false;
      done = true;
      digitalWrite(ledPin, LOW);
      Serial.println(measurement);
    }
  } else {
    if (done) {
      delay(500);
      return;
    }
    if (analogRead(startProbePin) > startThreshold) {
      testing = true;
      Serial.println("Starting measurement ...");
      start = millis();
    }
  }
}
