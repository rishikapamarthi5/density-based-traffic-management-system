# Working Principle

## Overview

The system is an Arduino-based traffic management system designed for a four-road intersection.

Four ultrasonic sensors are used, with one sensor positioned at the back of each road. Each sensor measures the distance between the sensor and the nearest vehicle or object in that road.

The measured vehicle distance is used as an indication of traffic density.

## Basic Principle

**Smaller Distance → Vehicle is closer to the sensor → Higher detected traffic density**

**Larger Distance → Vehicle is farther from the sensor → Lower detected traffic density**

## System Operation

The Arduino continuously performs the following operations:

1. Trigger each ultrasonic sensor.
2. Measure the echo time returned by the sensor.
3. Calculate the corresponding distance in centimeters.
4. Store the distance measured for each of the four roads.
5. Compare the four measured distances.
6. Identify the road with the minimum measured distance.
7. Select that road as the active road.
8. Turn the yellow signal ON for the selected road for 3 seconds.
9. Turn the green signal ON for the selected road.
10. Keep the other roads at red.
11. Continue monitoring the sensor readings.
12. Change the active road when another road has a smaller measured distance.

## Distance Measurement

The ultrasonic sensor measures the time taken for the transmitted ultrasonic pulse to travel to the vehicle/object and return to the sensor.

The Arduino code calculates the distance using:

**Distance = Echo Time × 0.034 / 2**

Where:

- **Distance** is the measured distance in centimeters.
- **Echo Time** is the time taken for the ultrasonic echo in microseconds.
- **0.034 cm/µs** is the approximate speed of sound used in the calculation.
- **2** accounts for the outgoing and returning path of the ultrasonic pulse.

## Traffic Signal Control

When a road is selected as the active road, the signal changes through the following sequence:

**Red OFF → Yellow ON for 3 seconds → Yellow OFF → Green ON**

The other roads remain at red.

## Decision Logic

The Arduino compares the distance values from all four roads.

For example:

| Road | Measured Distance |
|---|---:|
| Road 1 | 80 cm |
| Road 2 | 35 cm |
| Road 3 | 65 cm |
| Road 4 | 100 cm |

The minimum distance is **35 cm**, which belongs to Road 2.

Therefore, Road 2 is selected as the active road because the vehicle is closest to the sensor on that road.

## Continuous Monitoring

After the signal is updated, the Arduino continues reading the ultrasonic sensors.

If another road later has a smaller measured distance than the current active road, the Arduino changes the active road accordingly.

## Important Note

This project uses vehicle distance as an indication of traffic density. It does not directly count the number of vehicles in each road.

The current implementation determines the active road by comparing the minimum measured distance among the four ultrasonic sensors.
