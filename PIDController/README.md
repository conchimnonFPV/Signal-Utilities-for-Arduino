# PIDController


## Contents
| PIDController                                                                                                                                                                                                                                                      |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| + kp: double<br/> + ki: double<br/> + kd: double<br/> + dt: unsigned int<br/> + lowerSaturation: returnType<br/> + upperSaturation: returnType<br/> + setPoint: inputType<br/>                                                                                     |
| + begin(double, double, double, returnType, returnType, unsigned int): void <br/> + reset(): void<br/> + end(): void<br/> + disableIntervalCheck(): void<br/> + enableIntervalCheck(): void<br/> + intervalCheckEnabled(): bool<br/> + read(inputType): returnType |

## Usage
#### PIDController variable initializer:
```cpp
template<typename inputType, typename returnType>
PIDController;
```
+ **inputType:** Type of pid's process value
+ **returnType:** Type of pid's output value
***
#### Set pid's parameters and reset internal state of the controller:
```cpp
void begin(double kp, double ki, double kd, returnType ls, returnType us, unsigned int dt);
```
+ **kp:** Proportional coefficient
+ **ki:** Integral coefficient
+ **kd:** Derivative coefficient
+ **ls:** Lower saturation value
+ **us:** Upper saturation value
+ **dt:** Sampling rate

Sets setpoint to 0.
***
#### Set internal state of the controller to 0:
```cpp
void reset();
```
***
#### Set parameters to 0 and set internal state of the controller to 0:
```cpp
void end();
```
Sets setpoint to 0.
***
#### Disable interval check:
```cpp
void disableIntervalCheck();
```
Calculations still will be performed on given dt.<br/>
Useful for calls from timer ISR.
***
#### Enable interval check:
```cpp
void enableIntervalCheck();
```
***
#### Check whether interval check is enabled:
```cpp
bool intervalCheckEnabled();
```
+ **returns:** True if interval check is enabled

Interval check is enabled by default.
***
#### Calculate new pid's output:
```cpp
returnType read(inputType pv);
```
+ **pv:** Process value from the system

+ **returns:** PID's output
***

