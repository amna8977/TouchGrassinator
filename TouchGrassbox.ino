const int trigPin = 7;  // Trigger pin
const int echoPin = 6; // Echo pin

const int beeperPin = 11;

const int maxDistance = 100;

const int minDistance = 10;

const int minFrequency = 200;   // the further away, the lower the frequency
const int maxFrequency = 2000;  // the closer it is, the higher the frequency
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(beeperPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  int frequency = map(distance, minDistance, maxDistance, minFrequency, maxFrequency);

  distance = constrain(distance, minDistance, maxDistance);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance != 100) {
    tone(beeperPin, frequency); // Send frequency sound signal
    delay(10);                  // Delay for 10ms
    noTone(beeperPin);          // Stop sound
  }

  delay(100); // Wait for 0.1 second before the next measurement
}
