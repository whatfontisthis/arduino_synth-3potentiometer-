// pin
const int buzzerPin = 13;
const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;

int tone1;
int tone2;
int tempo;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  tone1 = map(analogRead(potPin1), 0, 1023, 100, 3000);
  tone2 = map(analogRead(potPin2), 0, 1023, 100, 3000);
  tempo = map(analogRead(potPin3), 0, 1023, 10, 1000);

  if (analogRead(potPin1) < 20 && analogRead(potPin2)  < 20 && analogRead(potPin3) < 20) {
    Serial.println("special tune1");
    soundFX(1000, 1000);
  }
  else if (analogRead(potPin1) < 20 && analogRead(potPin2)  < 20 && analogRead(potPin3) > 1000) {
    Serial.println("special tune1");
    soundFX1(1500, 800);
  }
  else {
    tone(buzzerPin, tone1);
    delay(tempo);
    noTone(buzzerPin);
    delay(tempo);

    tone(buzzerPin, tone2);
    delay(tempo);
    noTone(buzzerPin);
    delay(tempo);
  }

  Serial.print(analogRead(potPin1));
  Serial.print(",");
  Serial.print(analogRead(potPin2));
  Serial.print(",");
  Serial.println(analogRead(potPin3));


}

void soundFX(float num, float period) {
  int fxdelay = num + num * tan(millis() / period);
  for (int i = 0; i < 7; i++) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(fxdelay);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(fxdelay);
  }
}

void soundFX1(float num, float period) {
  int fxdelay = num + num * sin(millis() / period);
  for (int i = 0; i < 5; i++) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(fxdelay);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(fxdelay);
  }
}
