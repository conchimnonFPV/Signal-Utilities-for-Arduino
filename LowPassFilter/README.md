# LowPassFilter


## Contents
| LowPassFilter                                                                                                                                                                                                         |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| + smoothingFactor: double<br/> + dt: unsigned int                                                                                                                                                                     |
| + begin(double, unsigned int): void <br/> + reset(): void<br/> + end(): void<br/> + disableIntervalCheck(): void<br/> + enableIntervalCheck(): void<br/> + intervalCheckEnabled(): bool<br/> + read(valType): valType |

## Usage
#### ExponentialRegulator variable initializer:
```cpp
template<typename valType>
LowPassFilter;
```
+ **valType:** type on which filter is working on.<br/>
***
#### Set parameters to given values and set internal state of the filter to 0:
```cpp
void begin(double sf, unsigned int dt);
```
+ **sf:** Smoothing factor
+ **dt:** Sampling rate
***
#### Set internal state of the filter to 0:
```cpp
void reset();
```
***
#### Set dt, Smoothing factor and internal state of the filter to 0:
```cpp
void end();
```
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
**returns:** True if interval check is enabled
***
#### ExponentialRegulator variable initializer:
```cpp
valType read(valtype input);
```
+ **input:** Value to filter

+ **returns:** Filtered input
***





