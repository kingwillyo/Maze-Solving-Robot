# Maze-Solving-Robot
 An Arduino-based maze-solving robot using 3 ultrasonic sensors, an L293D motor driver, and 2 DC motors. The robot detects obstacles, makes navigation decisions, and autonomously traverses mazes. Includes Proteus simulation and Arduino code for easy implementation.


Project Overview

This project showcases an autonomous maze-solving robot built using an Arduino Uno, three ultrasonic sensors, an L293D motor driver, and two simple DC motors. The robot navigates a maze by detecting obstacles, making real-time decisions, and turning left or right based on sensor data. It highlights key concepts in robotics, obstacle avoidance, and microcontroller programming.


Features

Autonomous Navigation: The robot traverses a maze without human intervention.

Real-time Obstacle Detection: Ultrasonic sensors measure distances to detect obstacles and guide navigation.

Dynamic Turning Logic: Continuously evaluates sensor data to make mid-turn decisions.

Modular Code Design: Easy to modify or extend functionality.

Simulation Ready: Compatible with Proteus for virtual testing.


Components


Hardware:

Arduino Uno: The main microcontroller for decision-making.

Ultrasonic Sensors (HC-SR04):

Front Sensor: Detects obstacles directly ahead.

Left Sensor: Monitors obstacles on the left side.

Right Sensor: Monitors obstacles on the right side.

L293D Motor Driver: Controls the two DC motors.

DC Motors (2): Represent the robot’s left and right wheels.

Power Supply: Provides power to the motors and Arduino.


Software:

Arduino IDE: Used for writing, compiling, and uploading the code to the Arduino Uno.

Proteus: For simulation and testing the robot’s behavior virtually.

Circuit Design

Sensor Connections:

Front Sensor:

TRIG: Pin 7

ECHO: Pin 6

Left Sensor:

TRIG: Pin 8

ECHO: Pin 9

Right Sensor:

TRIG: Pin 10

ECHO: Pin A0

L293D Motor Driver Connections:

Power Pins:

VCC1 (Pin 16): Connect to 5V.

VCC2 (Pin 8): Connect to a higher voltage (e.g., 9V or 12V).

GND (Pins 4, 5, 12, 13): Connect all to GND.

Motor Outputs:

OUT1 and OUT2: Connect to the left motor terminals.

OUT3 and OUT4: Connect to the right motor terminals.

Control Pins:

IN1 (Pin 2): Connect to Arduino Pin 3 (Left motor forward).

IN2 (Pin 7): Connect to Arduino Pin A1 (or GND if not used).

IN3 (Pin 10): Connect to Arduino Pin 5 (Right motor forward).

IN4 (Pin 15): Connect to Arduino Pin A2 (or GND if not used).

Enable Pins:

ENA (Pin 1): Connect to Arduino Pin 4.

ENB (Pin 9): Connect to Arduino Pin 12.

Software Implementation

Key Code Functions:

readDistance(trigPin, echoPin):

Sends an ultrasonic pulse and measures the time for the echo to return.

Converts the time into a distance in centimeters.

Movement Functions:

moveForward(): Moves the robot forward.

turnLeft(): Turns the robot left by stopping the left motor and running the right motor forward.

turnRight(): Turns the robot right by stopping the right motor and running the left motor forward.

stopMotors(): Stops all motor activity.

Dynamic Decision-Making:

Continuously checks sensor readings during movement and turning to dynamically adjust the robot’s behavior.

How to Run the Project

Simulation (Proteus):

Assemble the circuit in Proteus based on the connections described above.

Load the compiled Arduino code (.hex file) into the Arduino Uno component.

Run the simulation and place virtual obstacles in the maze to observe the robot’s behavior.

Physical Build:

Assemble the hardware following the circuit design.

Upload the Arduino code to the Arduino Uno using the Arduino IDE.

Place the robot in a maze environment.

Power on the system and observe how the robot navigates the maze.

Adjustments

Sensor Thresholds:

Modify distance thresholds (e.g., distanceFront < 15) to match the maze’s dimensions.

Turning Delays:

Adjust delay(500) in turnLeft() and turnRight() for sharper or wider turns.

Dynamic Logic:

Fine-tune the turning logic in the while loops within turnLeft() and turnRight() for smoother behavior.

Troubleshooting

Motors Not Responding:

Check the L293D connections and ensure sufficient power is supplied to VCC2.

Verify that enable pins (ENA and ENB) are correctly controlled.

Sensors Not Detecting Obstacles:

Ensure TRIG and ECHO pins are correctly connected.

Use the Serial Monitor to debug sensor readings.

Erratic Robot Behavior:

Test each motor and sensor individually to isolate issues.

Adjust delays and thresholds for optimal performance.

Future Improvements

Implement advanced maze-solving algorithms like flood-fill or A*.

Add more sensors (e.g., IR sensors) for enhanced obstacle detection.

Integrate wireless monitoring and control using Bluetooth or Wi-Fi.

Optimize motor control using PID (Proportional-Integral-Derivative) algorithms.

Acknowledgments

This project was inspired by fundamental robotics concepts and microcontroller programming. Special thanks to the open-source Arduino and Proteus communities for their tools and resources.

