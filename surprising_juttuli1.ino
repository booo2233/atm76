const int trigPin = 9;  // Trigger pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor
const int greenLED = 7; // Green LED pin
const int redLED = 8;   // Red LED pin

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  // Initialize Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pulse duration in microseconds
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in centimeters
  float distance_cm = duration / 29.1 / 2;
  
  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  // Check if an object is in range (adjust the threshold as needed)
  if (distance_cm <= 20) { // Change 20 to your desired range in centimeters
    digitalWrite(greenLED, HIGH); // Turn on the green LED
    digitalWrite(redLED, LOW);   // Turn off the red LED
  } else {
    digitalWrite(greenLED, LOW);  // Turn off the green LED
    digitalWrite(redLED, HIGH);   // Turn on the red LED
  }
  
  delay(1000); // Delay for stability, adjust as needed
}

