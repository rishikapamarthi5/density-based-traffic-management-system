# Pin Configuration

The project uses four ultrasonic sensors and three traffic-signal LEDs for each of the four roads.

| Component | Road 1 | Road 2 | Road 3 | Road 4 |
|---|---:|---:|---:|---:|
| Ultrasonic Trigger | 2 | 4 | 6 | 8 |
| Ultrasonic Echo | 3 | 5 | 7 | 9 |
| Red LED | 22 | 24 | 26 | 28 |
| Green LED | 23 | 25 | 27 | 29 |
| Yellow LED | 30 | 32 | 34 | 36 |

## Components

- Arduino board
- 4 × Ultrasonic sensors
- 4 × Red LEDs
- 4 × Yellow LEDs
- 4 × Green LEDs

## Sensor Placement

The ultrasonic sensors are positioned at the back of the respective lanes. A smaller measured distance indicates that a vehicle is closer to the sensor and is used as an indication of higher traffic density.

## Traffic Signal Logic

The Arduino compares the measured distances from all four roads and selects the road with the minimum distance as the active road.

- Selected road → Yellow for 3 seconds → Green
- Other roads → Red
