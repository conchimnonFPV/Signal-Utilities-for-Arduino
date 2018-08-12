# EdgeDetector
Read returns true only if desired change in signal has been detected.

## Contents
| EdgeDetector                                     |
|--------------------------------------------------|
| + edgeType: uint8_t                              |
| + begin(bool): void<br/> + reset(): void<br/> + end(): void<br/> + read(bool): bool<br/> |

## Usage
#### Set edgeType to given value:
```cpp
void begin(bool edgeType);
```
+ **edgeType:** Edge to look for (HIGH/LOW/BOTH)<br/>
***
#### Set internal state of the detector to 0:
```cpp
void reset();
```
***
#### Set edgeType to LOW and set internal state of the detector to 0:
```cpp
void end(bool input);
```
***
#### Check whether desired change in the signal happened:
```cpp
bool read(bool input);
```
+ **input:** Signal's value to be processed.

+ **returns:** True if given edge has been detected.
