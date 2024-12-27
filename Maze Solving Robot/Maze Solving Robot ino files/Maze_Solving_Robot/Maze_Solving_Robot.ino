// Pin Definitions
#define trigFront 7
#define echoFront 6
#define trigLeft 8
#define echoLeft 9
#define trigRight 10
#define echoRight A0
#define motorLeftForward 3
#define motorLeftBackward A1
#define motorRightForward 5
#define motorRightBackward A2
#define motorEnableLeft 4
#define motorEnableRight 12


void setup() {
    pinMode(trigFront, OUTPUT);
    pinMode(echoFront, INPUT);
    pinMode(trigLeft, OUTPUT);
    pinMode(echoLeft, INPUT);
    pinMode(trigRight, OUTPUT);
    pinMode(echoRight, INPUT);

    pinMode(motorLeftForward, OUTPUT);
    pinMode(motorLeftBackward, OUTPUT);
    pinMode(motorRightForward, OUTPUT);
    pinMode(motorRightBackward, OUTPUT);

    pinMode(motorEnableLeft, OUTPUT);
    pinMode(motorEnableRight, OUTPUT);

    analogWrite(motorEnableLeft, 255); // Full speed
    analogWrite(motorEnableRight, 255); // Full speed

    Serial.begin(9600);
}

long readDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000); // Timeout after 30ms
    if (duration == 0) return 500; // Return large value if no echo is received
    return duration * 0.034 / 2; // Convert to cm
}


void moveForward() {
    digitalWrite(motorLeftForward, HIGH);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, HIGH);
    digitalWrite(motorRightBackward, LOW);
}

void turnRight() {
    digitalWrite(motorLeftForward, HIGH);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, LOW);
    digitalWrite(motorRightBackward, HIGH);
    delay(500); // Adjust turning duration
    stopMotors();
}

void turnLeft() {
    digitalWrite(motorLeftForward, LOW);
    digitalWrite(motorLeftBackward, HIGH);
    digitalWrite(motorRightForward, HIGH);
    digitalWrite(motorRightBackward, LOW);
    delay(500); // Adjust turning duration
    stopMotors();
}

void stopMotors() {
    digitalWrite(motorLeftForward, LOW);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, LOW);
    digitalWrite(motorRightBackward, LOW);
}


void loop() {
    long distanceFront = readDistance(trigFront, echoFront);
    long distanceLeft = readDistance(trigLeft, echoLeft);
    long distanceRight = readDistance(trigRight, echoRight);

    Serial.print("Front: "); Serial.print(distanceFront);
    Serial.print(" | Left: "); Serial.print(distanceLeft);
    Serial.print(" | Right: "); Serial.println(distanceRight);

    if (distanceFront < 15) { // Obstacle ahead
        if (distanceRight > 15) {
            turnRight();
        } else if (distanceLeft > 15) {
            turnLeft();
        } else {
            stopMotors(); // No clear path
        }
    } else {
        moveForward(); // No obstacle ahead
    }
}
