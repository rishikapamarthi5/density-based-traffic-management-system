// Pin assignments
const int trigPins[] = {2, 4, 6, 8};   // Trigger pins for the four ultrasonic sensors
const int echoPins[] = {3, 5, 7, 9};   // Echo pins for the four ultrasonic sensors
const int redLEDPins[] = {22, 24, 26, 28};    // Red LED pins for each road
const int greenLEDPins[] = {23, 25, 27, 29};  // Green LED pins for each road
const int yellowLEDPins[] = {30, 32, 34, 36}; // Yellow LED pins for each road

long duration;
int distance[4];  // Array to store distances measured by each sensor
int activeRoad = -1; // Variable to keep track of which road has green LED

// Function to get distance from a specific sensor
int getDistance(int trigPin, int echoPin) {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time it takes for the echo
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in cm
  int distance = duration * 0.034 / 2;
  return distance;
}

// Function to control the LEDs
void controlLEDs(int activeRoad) {
  // Yellow transition period of 3 seconds before green LED turns on
  for (int i = 0; i < 4; i++) {
    if (i == activeRoad) {
      // Turn off red, glow yellow for 3 seconds, then glow green
      digitalWrite(redLEDPins[i], LOW);   // Turn off red LED
      digitalWrite(yellowLEDPins[i], HIGH); // Turn on yellow LED
      delay(3000); // Wait for 3 seconds
      digitalWrite(yellowLEDPins[i], LOW);  // Turn off yellow LED
      digitalWrite(greenLEDPins[i], HIGH);  // Turn on green LED
    } else {
      // Glow red on all other sides
      digitalWrite(redLEDPins[i], HIGH);  // Turn on red LED
      digitalWrite(greenLEDPins[i], LOW); // Turn off green LED
      digitalWrite(yellowLEDPins[i], LOW); // Make sure yellow LED is off
    }
  }
}

void setup() {
  // Initialize pins for ultrasonic sensors
  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
    
    // Initialize LED pins
    pinMode(redLEDPins[i], OUTPUT);
    pinMode(greenLEDPins[i], OUTPUT);
    pinMode(yellowLEDPins[i], OUTPUT);
  }
  
  // Initialize all LEDs to red at the start
  controlLEDs(-1);
}

void loop() {
  int minDistance = 1000; // Start with a large distance
  int newActiveRoad = activeRoad;
  
  // Measure distances from all sensors
  for (int i = 0; i < 4; i++) {
    distance[i] = getDistance(trigPins[i], echoPins[i]);
    
    // Update the road with the least distance
    if (distance[i] < minDistance) {
      minDistance = distance[i];
      newActiveRoad = i;
    }
  }
  
  // If the active road changes, update the LEDs
  if (newActiveRoad != activeRoad) {
    activeRoad = newActiveRoad;
    controlLEDs(activeRoad);
  }
  
  delay(500); // Delay for stability in sensor reading
}
