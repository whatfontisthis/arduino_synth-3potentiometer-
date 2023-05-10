const int buzzerPin = 13;
const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;

int tone1;
int tone2;
int tempo;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tempo = map(analogRead(potPin1), 0, 1023, 10, 1000);
  tone1 = map(analogRead(potPin2), 0, 1023, 50, 2000);
  tone2 = map(analogRead(potPin3), 0, 1023, 50, 2000);
  
  tone(buzzerPin, tone1);
  delay(tempo);
  noTone(buzzerPin);
  delay(tempo);
  
  tone(buzzerPin, tone2);
  delay(tempo);
  noTone(buzzerPin);
  delay(tempo);
}
