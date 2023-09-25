// Define the pins for the servo motor, ultrasonic sensor, and LED
const int servoPin = 9;
const int trigPin = 7;
const int echoPin = 8;
const int ledPin = 13;

// Define the maximum distance (in centimeters) for the ultrasonic sensor
const int maxDistance = 10; // Adjust this value as needed

// Create variables to store distance and a flag to track the state
int distance;
boolean objectDetected = false;

// Create a servo object
Servo servo;

void setup() {
  // Initialize the servo motor
  servo.attach(servoPin);

  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  distance = getDistance();

  if (distance <= maxDistance) {
    // Object detected
    if (!objectDetected) {
      // If an object is detected for the first time, turn off the LED and move the servo
      digitalWrite(ledPin, LOW);
      servo.write(90); // Move servo to 90 degrees

      // Set the flag to indicate that an object is detected
      objectDetected = true;
    }
  } else {
    // No object detected
    if (objectDetected) {
      // If no object is detected after an object was detected, turn on the LED
      digitalWrite(ledPin, HIGH);
      
      // Reset the flag
      objectDetected = false;
    }
  }
}

// Function to measure distance with the ultrasonic sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  return pulseIn(echoPin, HIGH) / 58; // Calculate distance in centimeters
}
