int IRsensor = 2;
int led1=4;
int led2=5;
const int trigPin = 7;
const int echoPin = 9;
int buzzer = 6;
long duration;
int distance;
const int DIS_THRESHOLD=50;
void setup() {
  // put your setup code here, to run once:
// Initialize Pin Modes

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(IRsensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); // Corrected echoPin to INPUT for pulseIn() function
  
  // Initialize Serial Communication
  Serial.begin(9600);
}


void loop() {
    // Ultrasonic Sensor Measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculate Distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print Distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Read IR Sensor Status
  int status_IR = digitalRead(IRsensor);

  // Control Buzzer Based on IR Sensor Status
  if (status_IR == HIGH || distance > DIS_THRESHOLD) {
    digitalWrite(buzzer, LOW);// IR sensor detects object, buzzer OFF
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  } else {
    digitalWrite(buzzer, HIGH); // IR sensor clear, buzzer ON
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  }

  delay(500); // Small delay for readability
}
 // put your main code here, to run repeatedly:
