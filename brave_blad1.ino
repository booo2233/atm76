const int redLED = 2;
const int greenLED = 3;
const int orangeLED = 4;
const int whiteLED = 5;
const int blueLED = 6;

void setup() {
  // Initialize LED pins as outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  // Turn on the red LED
  digitalWrite(redLED, HIGH);
  delay(100);  // Wait for 1 second
  
  // Turn off the red LED and turn on the green LED
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(100);  // Wait for 1 second
  
  // Turn off the green LED and turn on the orange LED
  digitalWrite(greenLED, LOW);
  digitalWrite(orangeLED, HIGH);
  delay(100);  // Wait for 1 second
  
  // Turn off the orange LED and turn on the blue LED
  digitalWrite(orangeLED, LOW);
  digitalWrite(blueLED, HIGH);
  delay(100);  // Wait for 1 second
  
  // Blink all LEDs two times
  for (int i = 0; i < 2; i++) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(orangeLED, HIGH);
    digitalWrite(whiteLED, HIGH);
    digitalWrite(blueLED, HIGH);
    delay(500);  // Wait for 0.5 second
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(orangeLED, LOW);
    digitalWrite(whiteLED, LOW);
    digitalWrite(blueLED, LOW);
    delay(500);  // Wait for 0.5 second
  }
}
