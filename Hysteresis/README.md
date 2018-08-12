# Hysteresis

Two state regulator with variable space around switching point. </br>
Space is set in lowBound and highBound variables. <br/>
States are set in offVal and onVal variables. <br/>
When input is above highBound - regulator returns onVal,
when input is below lowBound - regulator returns offVal,
otherwise regulator returns previous state.
## Contents
| Hysteresis                                                                                                                                                             |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| + offVal: outType<br/> + onVal: outType<br/> + lowBound: inType<br/> + highBound: inType<br/>                                                                          |
| + begin(inType,inType,outType,outType): void <br/> + reset(): void<br/> + end(): void<br/> + forceOn(): void<br/> + forceOff(): void<br/> + read(inType): outType<br/> |

## Usage
#### Hysteresis variable initializer:
```cpp
template<typename inType, typename outType>
Hysteresis;
```
**inType:** Type of the hysteresis input variable.<br/>
**outType:** Type of the hysteresis output variable.<br/>
***

#### Clear internal state of hysteresis and set every parameter:
```cpp
void begin(inType _lowBound, inType _highBound, outType _offVal, outType _onVal);
```
+ **_lowBound:** Below this bound hysteresis goes off
+ **_highBound:** Above this bound hysteresis goes on
+ **offVal:** Value that is returned when hysteresis is off
+ **onVal:** Value that is returned when hysteresis is on

***
#### Clear internal state of hysteresis:
```cpp
void reset();
```

***

#### Clear internal state of hysteresis and set every parameter to 0:
```cpp
void end();
```
Sets lowBound, highBound, offVal, onVal to 0.
***

#### Set interlan state of hysteresis:
```cpp
void forceOn();
```

***

#### Clear internal state of hysteresis:
```cpp
void forceOff();
```

***

#### Process given value through hysteresis:
```cpp
outType read(inType val);
```
+ **val:** Value to be processed
<br />

+ **returns:** Result of hysteresis

