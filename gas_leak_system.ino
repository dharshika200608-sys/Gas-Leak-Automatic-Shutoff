// Gas Detection, Alert & Automatic Shut-Off System
// Controller : NodeMCU 1.0 (ESP-12E Module) - ESP8266
// Sensor     : MQ-2
// Outputs    : LED, Buzzer, Relay

int gassensor = A0;   // MQ-2 analog output

int led = D3;         // GPIO0
int buzzer = D2;      // GPIO4
int relay = D1;       // GPIO5

int threshold = 460;  // Adjust after testing

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);

  digitalWrite(relay, HIGH);  // Normal supply ON
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

void loop() {
  int gasvalue = analogRead(gassensor);
  Serial.println(gasvalue);

  if (gasvalue >= threshold) {
    // Gas leakage detected
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(relay, LOW);   // Shut-off / deactivate relay

    Serial.println("GAS LEAK DETECTED - SHUT OFF");
  }
  else {
    // Normal condition
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, HIGH);  // Normal supply ON

    Serial.println("NORMAL");
  }

  delay(500);
}
