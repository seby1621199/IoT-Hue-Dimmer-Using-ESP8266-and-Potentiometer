const int potPin = A0;
const int ledPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);

  int pwmValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, pwmValue);

  delay(200);
}
