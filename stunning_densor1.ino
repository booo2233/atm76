// Define the pins for the RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // Set the LED pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  rainbowCycle(20); // Change the delay time to adjust the speed of the rainbow effect
}

void rainbowCycle(int speed) {
  int totalColors = 256; // Total number of colors in the rainbow
  int deltaHue = totalColors / 30; // Change this value to adjust the color spread

  for (int j = 0; j < totalColors; j += deltaHue) {
    for (int i = 0; i < 30; i++) {
      setRGBWheel((i + j) % totalColors);
      delay(speed);
    }
  }
}

void setRGBWheel(int wheelPos) {
  wheelPos = 255 - wheelPos; // Reverse the order for a more intuitive rainbow

  if (wheelPos < 85) {
    analogWrite(redPin, 255 - wheelPos * 3);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, wheelPos * 3);
  } else if (wheelPos < 170) {
    wheelPos -= 85;
    analogWrite(redPin, 0);
    analogWrite(greenPin, wheelPos * 3);
    analogWrite(bluePin, 255 - wheelPos * 3);
  } else {
    wheelPos -= 170;
    analogWrite(redPin, wheelPos * 3);
    analogWrite(greenPin, 255 - wheelPos * 3);
    analogWrite(bluePin, 0);
  }
}
