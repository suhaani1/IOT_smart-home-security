const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PIN = 3;
const int TRIG_PIN2 = 11;
const int ECHO_PIN2 = 12;
const int LED_PIN2 = 4;
const int LED_PIN3 = 6;
const int LED_PIN4 = 7;

const int DIS_THRESHOLD = 50; // Distance threshold in cm
float duration_us1, duration_us2;
float distance_cm1, distance_cm2;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
}

void loop() {
  // Clear both TRIG pins
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  
  // Send a pulse to the first TRIG_PIN
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Measure the duration of the echo for the first sensor
  duration_us1 = pulseIn(ECHO_PIN, HIGH);
  distance_cm1 = duration_us1 * 0.034 / 2; // Calculate distance
  
  // Send a pulse to the second TRIG_PIN
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  
  // Measure the duration of the echo for the second sensor
  duration_us2 = pulseIn(ECHO_PIN2, HIGH);
  distance_cm2 = duration_us2 * 0.034 / 2; // Calculate distance

  // Check if the distance is below the threshold for both sensors
  if (distance_cm1 < DIS_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN3, HIGH);// Turn on LED for first sensor
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN3, LOW);// Turn off LED for first sensor
  }
  
  if (distance_cm2 < DIS_THRESHOLD) {
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN4, HIGH);// Turn on LED for second sensor
  } else {
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN4, LOW);// Turn off LED for second sensor
  }
  
  // Print the distances
  Serial.print("Distance 1: ");
  Serial.print(distance_cm1);
  Serial.print(" cm, Distance 2: ");
  Serial.print(distance_cm2);
  Serial.println(" cm");
  delay(500);
}
