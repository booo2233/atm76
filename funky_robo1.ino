#include <Servo.h>

const int trigPin = 9;   // Trigger pin of the ultrasonic sensor
const int echoPin = 10;  // Echo pin of the ultrasonic sensor
const int ledPin = 13;   // LED pin

Servo myservo;            // Create a servo object
int servoPosition = 90;   // Initial servo position (centered)

void setup() {
  myservo.attach(8);     // Attaches the servo on pin 8
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pulse duration
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = (duration / 2) / 29.1;

  // Check if an object is in the detection range
  if (distance < 20) {  // Adjust the threshold as needed
    // Object detected, turn the servo 90 degrees
    myservo.write(0);  // Change 0 to 90 if you want it to turn right
    digitalWrite(ledPin, LOW); // Turn off the LED
  } else {
    // No object detected, display a red LED
    myservo.write(90);  // Reset the servo to its initial position
    digitalWrite(ledPin, HIGH); // Turn on the LED
  }
  
  delay(1000);  // Delay to prevent rapid servo movement and LED flashing
}
