# Circuit Design

This directory contains the circuit designs, Tinkercad simulations, wiring documentation, and circuit diagrams developed throughout the project.

Circuit development will progress alongside the hardware implementation, with each major version documented and tested.

## Temperature and Simulated Humidity Test

### Objective
To test the Arduino's ability to read two independent analog inputs: temperature from a TMP36 sensor and a simulated humidity value from a potentiometer.

### Components
- Arduino Uno
- TMP36 temperature sensor
- 10 kΩ potentiometer
- Jumper wires

### Pin Connections

| Component | Arduino Pin |
|--|---|
| TMP36 output | A0 |
| TMP36 power | 5V |
| TMP36 ground | GND |
| Potentiometer wiper | A1 |
| Potentiometer outer pins | 5V and GND |

### Method
The TMP36 provides an analog voltage that is converted into a temperature reading in degrees Celsius.

The potentiometer provides a variable analog input. Its ADC reading is mapped to a 0–100% scale to simulate humidity changes.

### Observations
- Temperature readings were displayed through the Serial Monitor.
- The simulated humidity value changed when the potentiometer was adjusted.
- A simulated humidity reading of approximately 53.96% was observed during testing.

### Limitations
The potentiometer does not measure actual relative humidity. The percentage is a simulated input used to test analog data acquisition and processing.

Actual humidity measurement will require a dedicated humidity sensor in the physical prototype.

### Test Status
Temperature and simulated humidity input testing completed successfully in Tinkercad.
