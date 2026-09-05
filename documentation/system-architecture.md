# System Architecture

## 1. System Overview

The Intelligent Air Filtration & Pollution Monitoring System is a modular environmental monitoring and adaptive air-filtration prototype.

The system is designed to continuously monitor environmental conditions, interpret sensor measurements, classify the detected pollution level, and adjust filtration activity accordingly.

The overall system follows the pipeline:

**SENSE → ANALYZE → RESPOND → DISPLAY → LOG → ANALYZE**

Environmental measurements are acquired through multiple sensors and processed by an Arduino Uno. Based on the interpreted measurements, the control system determines an appropriate filtration response. Environmental readings, system classifications, and filtration activity are subsequently recorded for analysis.

The project is designed as a progressive engineering prototype. Initial development will use Tinkercad Circuits for circuit simulation and Arduino-compatible components, while later development may transition to physical hardware and calibrated environmental sensors.

The system is intended to demonstrate the integration of:

- Embedded systems
- Environmental sensing
- Signal processing
- Rule-based control
- Adaptive filtration
- Data logging
- Data analysis
- Engineering validation

Advanced computational methods, including machine learning, may be investigated during later development only if they provide a measurable improvement over the baseline control system.

## 2. Design Objectives

The primary objectives of the project are:

1. Develop a system capable of acquiring multiple environmental measurements.
2. Establish a reproducible method for processing and interpreting sensor data.
3. Develop a documented pollution-classification methodology.
4. Implement adaptive filtration control rather than simple binary fan operation.
5. Provide users with clear information about current environmental conditions and system status.
6. Record environmental measurements and system responses in a structured format.
7. Analyze collected data using Python to identify trends, relationships, and system performance.
8. Evaluate the reliability and limitations of the sensing and control approach.
9. Maintain a reproducible engineering record of circuit designs, software, experiments, testing, and revisions.
10. Investigate advanced prediction or optimization techniques only where they provide meaningful technical benefits.
    ## 3. System Architecture

The system is organized into interconnected functional layers. Each layer has a defined responsibility, allowing individual components to be tested and improved without redesigning the entire system.

### 3.1 Environmental Sensing Layer

The sensing layer acquires measurements representing the surrounding environmental conditions.

The planned measurements include:

- PM2.5
- PM10
- Gas or air-quality indicators
- Temperature
- Relative humidity

During simulation, some measurements may be represented using controlled analog inputs rather than physically accurate environmental sensors. These simulated inputs will be explicitly identified and will not be treated as calibrated real-world measurements.

### 3.2 Processing and Classification Layer

The Arduino Uno acts as the primary embedded processing unit.

It will:

1. Acquire sensor measurements.
2. Convert raw electrical signals into usable values where appropriate.
3. Apply basic signal processing or validation.
4. Evaluate measurements against documented classification criteria.
5. Determine the current pollution condition.
6. Generate a control command for the filtration system.

The classification system will initially use a transparent rule-based approach. Thresholds and assumptions will be documented and justified rather than selected arbitrarily.

### 3.3 Filtration Control Layer

The control layer translates the pollution classification into a filtration response.

Rather than using a simple ON/OFF system, the prototype will investigate multiple operating states, such as:

- Idle
- Low
- Medium
- High

The exact control strategy will be determined during development and testing.

The filtration actuator will be electrically isolated from the Arduino's GPIO pins using an appropriate driver circuit. The Arduino will provide a control signal rather than directly powering the motor.

### 3.4 User Interface Layer

A local display will provide information about the current state of the system.

The interface is intended to communicate:

- Relevant environmental measurements
- Pollution classification
- Fan operating state
- System status

The interface will be designed to prioritize useful information rather than displaying every available variable simultaneously.

### 3.5 Data Logging Layer

Environmental measurements and system responses will be recorded in a structured format.

A data record may contain:

- Timestamp
- Temperature
- Humidity
- PM2.5
- PM10
- Gas measurement
- Pollution classification
- Fan state or control level

The data structure will be kept consistent so that measurements can later be analyzed using Python.

### 3.6 Analysis Layer

Python will be used as the primary analysis environment for collected data.

Analysis may include:

- Descriptive statistics
- Time-series visualization
- Pollution-level distributions
- Relationships between environmental variables
- Sensor-response analysis
- Filtration activity analysis
- System performance evaluation

Python analysis will operate primarily on recorded data rather than being responsible for real-time safety-critical control.

### 3.7 Advanced Intelligence Layer

After the baseline rule-based system has been developed and evaluated, advanced algorithms may be investigated.

Potential applications include:

- Pollution-level prediction
- Short-term trend forecasting
- Anomaly detection
- Control optimization

Any machine-learning approach will be compared against the baseline rule-based system.

Machine learning will only be retained if testing demonstrates a meaningful improvement in a clearly defined performance measure.
## 4. Data Flow

The system processes environmental information through a sequential data flow from sensing to analysis.

### 4.1 Sensor Acquisition

Environmental sensors produce electrical signals corresponding to measured environmental conditions.

The Arduino periodically reads these signals through its available input interfaces.

The initial prototype will use a defined sampling interval so that measurements are collected at consistent time intervals.

### 4.2 Signal Conversion

Raw sensor signals are converted into usable numerical values.

Depending on the sensor, this may involve:

- Analog-to-digital conversion
- Voltage calculation
- Sensor-specific conversion equations
- Unit conversion
- Range checking

Sensor-specific conversion methods will be documented separately to avoid treating different sensor outputs as interchangeable.

### 4.3 Data Validation

Before measurements are used by the control system, basic validation may be applied.

Possible checks include:

- Detecting values outside the expected range
- Identifying missing or invalid readings
- Detecting sudden unrealistic changes
- Checking whether a sensor is responding

Invalid measurements should not automatically trigger an extreme filtration response.

Instead, the system should distinguish between genuine environmental changes and potential sensor errors where possible.

### 4.4 Pollution Classification

Validated measurements are passed to the classification layer.

The initial system will use a transparent rule-based methodology based on documented thresholds and, where appropriate, combinations of multiple measurements.

The classification output will represent the current environmental condition rather than claiming to provide a medical or regulatory assessment of air quality.

### 4.5 Control Decision

The pollution classification is passed to the filtration-control system.

The controller determines an appropriate fan operating level.

The initial control strategy will use multiple discrete operating states rather than a binary ON/OFF response.

Control behavior will be evaluated during testing to determine whether the system responds appropriately to changes in environmental conditions.

### 4.6 Display

The current measurements, pollution classification, and filtration state may be presented through a local display.

The display will use human-readable units and labels wherever the underlying measurement supports a valid unit.

Simulated or proxy measurements will be clearly identified during the simulation phase.

### 4.7 Data Logging

Measurements and system decisions are recorded as structured data.

A typical record may follow the structure:

`timestamp, temperature, humidity, PM2.5, PM10, gas, pollution_level, fan_state`

The logging format will remain consistent throughout experiments so that different test runs can be compared.

### 4.8 Offline Analysis

Collected data will be transferred to the Python analysis environment.

Python will be used to:

- Clean and organize measurements
- Calculate descriptive statistics
- Visualize environmental trends
- Evaluate pollution classifications
- Analyze filtration behavior
- Investigate relationships between variables
- Evaluate system performance

Results from this analysis may be used to improve subsequent versions of the embedded system.

### 4.9 Development Feedback Loop

The project will use an iterative development process.

Analysis of experimental data may reveal weaknesses in:

- Sensor selection
- Thresholds
- Classification logic
- Control behavior
- Sampling frequency
- Data quality

These findings will inform later revisions of the hardware and software.

The system therefore follows an iterative cycle:

**Measure → Process → Classify → Respond → Record → Analyze → Improve**

## 5. Hardware Architecture

The hardware architecture consists of sensing, processing, control, user-interface, and filtration subsystems.

### 5.1 Processing Unit

The primary embedded controller will be an Arduino Uno.

The Arduino will be responsible for:

- Reading sensor inputs
- Performing basic signal conversion
- Validating sensor measurements
- Executing the pollution-classification logic
- Generating filtration-control signals
- Updating the local user interface
- Preparing measurements for data logging

The Arduino Uno is selected for the initial prototype because it is accessible, well documented, and suitable for demonstrating the embedded control architecture.

Its limitations, including processing capability, memory, number of I/O pins, and lack of built-in wireless connectivity, will be considered during later development.

### 5.2 Environmental Sensors

The planned sensing system will monitor several environmental variables.

#### Particulate Matter

PM2.5 and PM10 measurements are intended to provide information about airborne particulate pollution.

A real implementation will require a particulate-matter sensor capable of producing measurements appropriate for these quantities.

During Tinkercad development, accurate PM2.5 and PM10 sensing may not be physically represented. Simulated analog inputs may therefore be used to develop and test the software architecture.

These simulated values will not be presented as calibrated particulate concentrations.

#### Gas / Air-Quality Measurement

A gas or air-quality sensor may be used to provide an additional indicator of gaseous pollutants or changes in air composition.

The specific sensor and its measurable gases will need to be considered before assigning physical units or interpreting its output as a standardized air-quality index.

#### Temperature

Temperature will be measured using an appropriate temperature sensor.

For the initial Tinkercad prototype, a TMP36 may be used because its analog output can be read directly by the Arduino Uno.

#### Relative Humidity

Relative humidity will be measured using an appropriate humidity sensor in the physical implementation.

If humidity is represented by a potentiometer during simulation, the resulting value will be treated as a simulated input rather than a physical humidity measurement.

### 5.3 Actuator and Motor Control

The filtration subsystem will use a fan or other airflow-producing actuator.

The Arduino will not directly power the motor.

Instead, a suitable switching or driver circuit will be used between the Arduino and the actuator.

Depending on the selected fan and power requirements, the driver may use a transistor or MOSFET with appropriate protection components.

The control signal generated by the Arduino will determine the operating state or speed of the fan.

### 5.4 User Interface

A display may be incorporated to provide real-time system information.

Possible displayed information includes:

- Temperature
- Relative humidity
- PM2.5
- PM10
- Gas measurement
- Pollution classification
- Fan operating level

The final display technology will be selected based on available Arduino pins, power requirements, readability, and ease of integration.

### 5.5 Power Architecture

The power requirements of the controller, sensors, display, and filtration actuator will be considered separately.

The Arduino's GPIO pins will only be used for control and signal communication within their electrical specifications.

Higher-current components such as motors or fans will use an appropriate power path rather than drawing motor current directly through an Arduino GPIO pin.

Common electrical reference points will be maintained where required by the circuit design.

### 5.6 Hardware Modularity

The system will be developed as modular subsystems:

**Sensing → Processing → Control → Filtration → Interface → Logging**

Each subsystem should be testable independently where practical.

This modular approach will make it possible to replace simulated sensors with physical sensors, or replace individual components, without redesigning the entire system.

### 5.7 Simulation-to-Hardware Transition

Tinkercad will be used during early development to test circuit logic and Arduino software.

The simulation will not be treated as equivalent to a physical environmental monitoring system.

Differences may include:

- Sensor behavior
- Sensor calibration
- Electrical noise
- Measurement accuracy
- Response time
- Motor characteristics
- Airflow
- Filter efficiency
- Environmental variability

Physical testing will therefore be required before making claims about real-world sensing or filtration performance.

## 6. Software Architecture

The software will be developed as a modular embedded control system. Each major function will be separated into a logical component so that individual parts can be tested, modified, and validated independently.

### 6.1 Software Pipeline

The primary Arduino software pipeline is:

**Acquire → Convert → Validate → Classify → Control → Display → Log**

Each stage receives defined inputs and produces defined outputs.

### 6.2 Sensor Acquisition

The sensor-acquisition layer is responsible for reading raw values from connected sensors.

The software will maintain separate variables for each measured quantity rather than combining sensor readings prematurely.

Examples include:

- Temperature
- Relative humidity
- PM2.5
- PM10
- Gas measurement

The sampling interval will be explicitly defined so that measurements are collected at predictable intervals.

### 6.3 Signal Conversion

Raw sensor readings will be converted into meaningful quantities where a valid conversion method exists.

For example, an analog voltage from a temperature sensor may be converted into degrees Celsius using the sensor's documented transfer function.

Sensor-specific conversion functions should remain separate from pollution-classification logic.

This prevents assumptions about one sensor from affecting unrelated measurements.

### 6.4 Data Validation

The software will perform basic validation before using measurements for classification or control.

Validation may include:

- Minimum and maximum expected values
- Detection of invalid readings
- Detection of sensor disconnection where technically possible
- Detection of implausible sudden changes
- Sensor-status flags

Validated data will be distinguishable from raw sensor data.

### 6.5 Pollution Classification

The classification layer will convert validated environmental measurements into a defined pollution state.

The initial implementation will use a transparent rule-based approach.

For example, the system may produce states such as:

- LOW
- MODERATE
- HIGH
- CRITICAL

The exact thresholds will be established separately using documented criteria.

Thresholds will not be selected solely to make the simulation produce visually interesting results.

### 6.6 Control Logic

The control layer converts the pollution state into an actuator command.

The system will support multiple filtration states rather than a simple binary response.

A conceptual mapping is:

| Pollution state | Filtration response |
|---|---|
| LOW | Idle / Low |
| MODERATE | Low / Medium |
| HIGH | High |
| CRITICAL | Maximum |

The final control mapping will be determined through testing.

Hysteresis, smoothing, or minimum operating times may be introduced later if testing shows that rapid fluctuations cause undesirable switching between fan states.

### 6.7 User Interface Logic

The display layer will present selected system information to the user.

The software will separate the underlying sensor and control calculations from display formatting.

This allows the display hardware to be changed without redesigning the core sensing and control logic.

### 6.8 Data Logging

The logging layer will prepare measurements in a consistent structured format.

A typical record may contain:

`timestamp, temperature, humidity, pm25, pm10, gas, pollution_level, fan_state`

The logging implementation will depend on the available hardware.

During early development, Serial output may be used to produce machine-readable records before dedicated storage hardware is introduced.

### 6.9 Timing Architecture

The software will avoid unnecessary blocking delays as the project becomes more complex.

Early prototypes may use simple timing methods, but the final system should preferably use non-blocking timing based on Arduino's timing functions.

This will allow sensor acquisition, display updates, control decisions, and logging to operate at different appropriate intervals.

### 6.10 Error Handling

The software should respond predictably when measurements are unavailable or invalid.

Potential error states include:

- Sensor reading outside expected range
- Missing sensor response
- Invalid data
- Communication failure
- Unsupported measurement

The system should avoid interpreting an invalid measurement as a confirmed extreme pollution event.

Where appropriate, the system may enter a defined fallback state and report the problem to the user.

### 6.11 Software Modularity

The code will be organized around functions with clearly defined responsibilities.

A conceptual structure is:

```text
setup()
│
├── initializeSensors()
├── initializeDisplay()
├── initializeLogging()
└── initializeControl()

loop()
│
├── readSensors()
├── convertMeasurements()
├── validateMeasurements()
├── classifyPollution()
├── updateFiltration()
├── updateDisplay()
└── logMeasurements()

## 7. Design Constraints and Assumptions

The system is being developed as an engineering prototype. Its design and interpretation are therefore subject to technical constraints and explicit assumptions.

### 7.1 Simulation Constraints

Tinkercad Circuits will be used to develop and test the early circuit and software architecture.

However, the simulation environment does not reproduce all characteristics of a real atmospheric environment.

In particular, the simulation may not accurately represent:

- Real PM2.5 concentrations
- Real PM10 concentrations
- Complex gas mixtures
- Sensor calibration behavior
- Atmospheric particle distributions
- Airflow through a filter
- Filter efficiency
- Real fan performance
- Environmental interference

Therefore, simulated sensor inputs will be treated as controlled test signals rather than direct evidence of real-world air-quality measurements.

### 7.2 Sensor Assumptions

Each physical sensor will have its own:

- Measurement range
- Accuracy
- Resolution
- Response time
- Calibration requirements
- Environmental limitations

Sensor-specific documentation will be consulted before assigning physical units or interpreting measurements.

A sensor output will not automatically be treated as a standardized pollution measurement simply because it changes in response to an environmental condition.

### 7.3 Particulate-Matter Measurement

PM2.5 and PM10 require appropriate particulate-matter sensing hardware for meaningful physical measurements.

During the simulation phase, these variables may be represented using controlled proxy inputs.

Proxy values will be clearly identified in experimental records and will not be reported as calibrated particulate concentrations.

### 7.4 Pollution Classification Assumptions

The initial pollution-classification system will be rule-based.

Classification thresholds will be documented before evaluating system performance.

Where standardized environmental or regulatory thresholds are used, their source and applicable measurement conditions will be recorded.

Where experimental thresholds are required because of simulation limitations, they will be explicitly identified as prototype assumptions.

The classification system is intended for engineering experimentation and is not a substitute for certified environmental monitoring or health guidance.

### 7.5 Filtration Assumptions

The system can control the operation of an airflow-producing actuator, but actuator operation alone does not demonstrate effective pollutant removal.

Actual filtration performance depends on factors including:

- Filter material
- Filter area
- Particle size
- Airflow rate
- Fan characteristics
- Air leakage
- Enclosure design
- Filter loading
- Environmental conditions

Therefore, fan activity will initially be evaluated as a control response rather than automatically interpreted as proof of a specific pollutant-removal efficiency.

### 7.6 Electrical Constraints

The Arduino Uno has limited:

- GPIO pins
- Analog inputs
- Program memory
- RAM
- Processing capability
- Electrical output current

The system architecture must therefore remain within the electrical and computational limitations of the controller.

High-current loads will use appropriate driver circuitry and power paths rather than being powered directly from Arduino GPIO pins.

### 7.7 Measurement Uncertainty

Environmental measurements are subject to uncertainty.

Sources of uncertainty may include:

- Sensor accuracy
- Calibration error
- Electrical noise
- Environmental variation
- Sampling frequency
- Sensor placement
- Sensor response time
- Data-processing assumptions

Experimental results will therefore be reported with appropriate consideration of measurement uncertainty rather than presenting every measurement as exact.

### 7.8 Data Assumptions

Recorded data will be treated as experimental observations rather than automatically assumed to be error-free.

Data analysis may require:

- Missing-value handling
- Invalid-reading detection
- Outlier investigation
- Unit verification
- Timestamp validation
- Sensor-status checking

Data should not be removed solely because it produces an unexpected result. Potential anomalies will first be investigated to determine whether they represent measurement errors or genuine environmental changes.

### 7.9 Prototype Scope

The initial prototype focuses on demonstrating the complete engineering pipeline:

**Sensing → Processing → Classification → Control → Display → Logging → Analysis**

The project is not initially intended to provide certified air-quality measurements or guarantee a specific filtration performance.

These capabilities may be investigated during later physical development and validation.

### 7.10 Reproducibility

Major design decisions, circuit versions, software changes, datasets, experiments, and analysis methods will be documented in the GitHub repository.

Where practical, experiments will specify:

- Hardware configuration
- Software version
- Input conditions
- Sampling interval
- Number of observations
- Classification criteria
- Control settings
- Analysis method

This will allow results to be reproduced and compared across different versions of the system.

### 7.11 Engineering Assumption Policy

Assumptions will be explicitly labeled throughout the project.

The project will distinguish between:

**Measured** — directly obtained from a sensor or experiment.

**Calculated** — derived mathematically from measured data.

**Simulated** — produced within the simulation environment.

**Assumed** — selected as a design or experimental assumption.

**Referenced** — obtained from an external technical or scientific source.

This distinction will prevent simulated or assumed values from being presented as experimentally measured real-world data.

## 8. Control Strategy

The filtration system will use a rule-based control strategy during the initial development phase.

The purpose of the control strategy is to translate validated environmental measurements into an appropriate filtration response while avoiding unnecessary actuator switching.

### 8.1 Control Inputs

The primary control inputs will be the validated environmental measurements produced by the sensing layer.

Potential inputs include:

- PM2.5
- PM10
- Gas or air-quality measurement
- Temperature
- Relative humidity

Not every measurement will necessarily be used directly in the final control decision.

Measurements will only influence the control system when their relationship to the intended control objective is technically justified.

### 8.2 Pollution State

The controller will classify the current environmental condition into discrete states.

The initial states are:

- LOW
- MODERATE
- HIGH
- CRITICAL

The classification will be determined using documented thresholds.

Where multiple measurements are available, the control system may consider more than one variable rather than relying on a single sensor.

### 8.3 Fan Operating States

The filtration actuator will have multiple operating states.

The initial control levels are:

| Pollution state | Fan state |
|---|---|
| LOW | IDLE / LOW |
| MODERATE | LOW / MEDIUM |
| HIGH | MEDIUM / HIGH |
| CRITICAL | HIGH / MAXIMUM |

The exact mapping will be established experimentally.

The final design may use fewer or more operating states depending on the capabilities of the selected actuator and the results of testing.

### 8.4 Decision Logic

The conceptual control sequence is:

```text
Read sensors
      ↓
Validate measurements
      ↓
Classify environmental condition
      ↓
Determine required filtration level
      ↓
Compare with current fan state
      ↓
Update fan if required
## 9. Testing and Validation Architecture

Testing will be performed progressively throughout development rather than only after the complete system has been assembled.

Each subsystem will first be tested independently before integration testing is performed.

The testing process will evaluate both successful behavior and failure conditions.

### 9.1 Testing Philosophy

The project will follow a staged validation process:

**Component Testing → Subsystem Testing → Integration Testing → System Testing → Performance Evaluation**

Each stage will have defined inputs, expected outputs, and acceptance criteria where appropriate.

### 9.2 Component Testing

Individual components will be tested before integration.

Examples include:

- Arduino analog inputs
- Temperature sensor
- Humidity sensor
- Gas or air-quality sensor
- Display
- Motor-control circuit
- Fan or actuator
- Data-logging interface

The purpose of component testing is to identify hardware or software problems before they propagate into the complete system.

### 9.3 Sensor Testing

Sensor tests will examine whether measurements behave as expected within the intended operating range.

Testing may include:

- Stable-input testing
- Minimum and maximum input testing
- Gradual input changes
- Repeated measurements
- Response to simulated environmental changes
- Invalid-input testing

For physical sensors, measurements may also be compared against an appropriate reference instrument where available.

### 9.4 Classification Testing

The pollution-classification algorithm will be tested using predefined input conditions.

Example test cases include:

| Test condition | Expected classification |
|---|---|
| Low input | LOW |
| Moderate input | MODERATE |
| High input | HIGH |
| Critical input | CRITICAL |
| Boundary value | Defined by threshold |
| Invalid input | Error / fallback state |

Boundary conditions are particularly important because classification errors are most likely to occur near threshold values.

### 9.5 Control Testing

The filtration-control system will be tested independently of environmental sensors when possible.

Controlled inputs will be used to verify that each pollution state produces the intended fan command.

Tests will include:

- Fan activation
- Fan deactivation
- Low-speed operation
- Medium-speed operation
- High-speed operation
- State transitions
- Repeated transitions
- Invalid-input behavior

### 9.6 Hysteresis and Stability Testing

If hysteresis or temporal smoothing is implemented, additional tests will evaluate whether these mechanisms reduce unnecessary state changes.

A controlled signal will be moved repeatedly around a classification boundary.

The system will be evaluated for:

- Number of state transitions
- Response delay
- Stability
- Correct response to sustained changes

The objective is to reduce unnecessary switching without making the controller excessively slow.

### 9.7 Display Testing

The user interface will be tested to confirm that:

- Values are displayed correctly
- Units are correctly identified
- Pollution classification is correct
- Fan state matches the control system
- Invalid measurements are identified appropriately
- Display updates occur at the intended interval

### 9.8 Data-Logging Testing

The logging system will be tested to verify that each record contains the expected fields.

A typical record structure is:

`timestamp, temperature, humidity, pm25, pm10, gas, pollution_level, fan_state`

Tests will check for:

- Missing fields
- Incorrect values
- Incorrect timestamps
- Formatting errors
- Duplicate records
- Invalid sensor data
- Inconsistent units

### 9.9 Integration Testing

After individual subsystems have been validated, they will be combined.

Integration testing will verify the complete information path:

**Sensor → Arduino → Classification → Control → Fan → Display → Data Log**

A change in the simulated or physical environmental input should propagate through the system and produce the expected classification, control response, display update, and logged record.

### 9.10 System-Level Test Scenarios

The complete system will be tested using controlled scenarios.

Potential scenarios include:

1. Normal low-pollution conditions
2. Gradually increasing pollution
3. Gradually decreasing pollution
4. Rapid change in pollution input
5. Sensor fluctuation near a threshold
6. Invalid sensor reading
7. Sensor recovery
8. Extended operation
9. Repeated state transitions
10. Data-logging interruption

Each scenario will have a predefined expected behavior.

### 9.11 Performance Evaluation

System performance may be evaluated using measurable criteria such as:

- Sensor response time
- Classification accuracy against predefined test cases
- Control response time
- State-transition frequency
- Data-record completeness
- Percentage of valid readings
- System uptime during testing

The selected metrics will depend on the subsystem being evaluated.

### 9.12 Failure-Case Testing

The system will deliberately be tested under abnormal conditions.

Examples include:

- Out-of-range sensor values
- Missing sensor data
- Rapidly changing inputs
- Communication failures
- Power interruption
- Invalid control states
- Data-logging errors

The purpose is to determine whether the system fails predictably rather than simply testing ideal conditions.

### 9.13 Repeated Trials

Important experiments will be repeated where practical.

Repeated measurements can help determine whether observed behavior is consistent or whether it may be caused by random variation.

The number of repetitions will be recorded for each relevant experiment.

### 9.14 Test Records

Each major experiment should record:

- Test ID
- Date
- Hardware configuration
- Software version
- Input conditions
- Expected behavior
- Observed behavior
- Result
- Notes
- Identified problems

A structured testing record will make it possible to compare different versions of the system.

### 9.15 Acceptance Criteria

Before a subsystem is considered complete, it should satisfy predefined acceptance criteria.

Examples include:

- Correct response to defined test inputs
- No unexpected actuator behavior
- Valid data records
- Correct display information
- Predictable handling of invalid inputs
- Reproducible results across repeated trials

Acceptance criteria may be refined as the physical implementation develops.

### 9.16 Validation Limitations

Successful operation in Tinkercad will demonstrate that the circuit and software logic operate under the simulated conditions.

It will not, by itself, validate:

- Real-world PM2.5 measurement accuracy
- Real-world PM10 measurement accuracy
- Gas concentration accuracy
- Filter efficiency
- Air-cleaning performance
- Long-term sensor reliability
- Real-world energy consumption

Physical testing will therefore be necessary before making claims about real-world environmental or filtration performance.

## 10. Development Roadmap

The system will be developed incrementally. Each stage will establish and validate a specific capability before additional complexity is introduced.

This approach reduces debugging complexity and allows design decisions to be supported by experimental evidence.

### 10.1 Phase 1 — Arduino and Development Environment

The first phase will establish the basic Arduino development workflow.

Objectives:

- Configure the Arduino Uno environment
- Upload and execute a basic program
- Verify Serial Monitor communication
- Establish the initial GitHub code structure
- Confirm the Tinkercad simulation workflow

The purpose of this phase is to verify the development environment before introducing environmental sensors.

### 10.2 Phase 2 — Environmental Sensor Integration

Individual environmental inputs will be introduced and tested separately.

Planned measurements include:

- Temperature
- Relative humidity
- Gas or air-quality indicators
- Simulated particulate measurements during the Tinkercad stage

Each sensor will first be tested independently before being integrated into the complete system.

### 10.3 Phase 3 — Signal Processing and Validation

Raw sensor inputs will be converted into usable values where appropriate.

The software will then implement:

- Range validation
- Invalid-reading detection
- Basic signal processing
- Sensor-status handling
- Consistent sampling intervals

The objective is to establish reliable inputs before implementing pollution classification.

### 10.4 Phase 4 — Pollution Classification

A transparent rule-based classification system will be implemented.

The system will:

1. Receive validated measurements.
2. Compare them against documented criteria.
3. Determine the current pollution state.
4. Output the classification through Serial communication.

Initial states will include:

- LOW
- MODERATE
- HIGH
- CRITICAL

The classification methodology will be documented and tested using predefined inputs.

### 10.5 Phase 5 — Filtration Control

The filtration actuator will then be integrated.

Development will include:

- Motor-driver circuit
- Fan control
- Multiple operating states
- Control-state transitions
- Invalid-input behavior
- Optional hysteresis or smoothing

The fan will not be connected directly to an Arduino GPIO pin.

### 10.6 Phase 6 — User Interface

A local display will be integrated after the sensing and control logic has been validated.

The interface may display:

- Environmental measurements
- Pollution classification
- Fan state
- System status

Display development will remain separate from the core control logic.

### 10.7 Phase 7 — Data Logging

Once the system can reliably sense, classify, and respond, structured data logging will be introduced.

The dataset will contain relevant environmental measurements and system decisions.

The initial logging workflow may use Serial output before dedicated storage hardware is introduced.

### 10.8 Phase 8 — Physical Prototype

After the simulated architecture has been validated, the project may transition to physical hardware.

This phase will investigate:

- Physical environmental sensors
- Fan and motor characteristics
- Filter integration
- Electrical behavior
- Sensor placement
- Enclosure or airflow design

Physical measurements will be distinguished from simulation data.

### 10.9 Phase 9 — Experimental Data Collection

Controlled experiments will be performed using the physical prototype where appropriate.

Experiments may investigate:

- Sensor behavior
- Environmental response
- Control response
- Fan operation
- System stability
- Data consistency
- Filtration behavior

Experimental conditions and results will be recorded systematically.

### 10.10 Phase 10 — Python Data Analysis

Collected datasets will be analyzed using Python.

Analysis may include:

- Data cleaning
- Descriptive statistics
- Time-series analysis
- Environmental trends
- Pollution-state distributions
- Sensor relationships
- Fan activity
- System response times
- Experimental comparisons

Visualizations and statistical results will be stored in the repository where appropriate.

### 10.11 Phase 11 — System Evaluation

The complete system will be evaluated against predefined testing criteria.

Evaluation may consider:

- Measurement consistency
- Classification behavior
- Control response
- State stability
- Data completeness
- Failure handling
- Repeatability
- Physical-system limitations

The results will be compared with the original design objectives.

### 10.12 Phase 12 — Advanced Analysis

Only after sufficient experimental data has been collected will advanced computational methods be considered.

Potential investigations include:

- Pollution forecasting
- Anomaly detection
- Predictive control
- Classification models
- Optimization

Any advanced method will be compared against the rule-based baseline.

A model will not be described as an improvement unless experimental evidence supports that conclusion.

### 10.13 Phase 13 — Final Documentation

The final project documentation will consolidate the complete development process.

It will include:

- Problem definition
- Motivation
- System architecture
- Hardware design
- Circuit diagrams
- Software architecture
- Control methodology
- Testing methodology
- Experimental data
- Data analysis
- Results
- Limitations
- Failure cases
- Environmental considerations
- Future improvements
- References

The final documentation will distinguish clearly between simulation results, calculated values, assumptions, and physical experimental measurements.

### 10.14 Development Principle

Each phase will follow the cycle:

**Build → Test → Record → Analyze → Improve**

A later phase will only be introduced after the preceding functionality has reached a sufficiently stable state for meaningful integration.
This incremental approach is intended to make the development process reproducible, reduce unnecessary complexity, and ensure that system improvements are supported by evidence.
