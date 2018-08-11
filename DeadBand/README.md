# DeadBand

Sets output to 0 when given value is between lowBound and highBound and doesn't change it if otherwise.

## Contents

| DeadBand                                                     |
|--------------------------------------------------------------|
| + lowBound: T <br /> + highBound: T                          |
| + begin(T, T): void <br /> + end(): void <br /> + read(T): T |

## Usage
#### DeadBand variable initializer:
```cpp
template<typename T>
DeadBand;
```
**T:** type of your input/output variable<br/>
***

#### Set lowBound and highBound to given values:
```cpp
void begin(T lowBound, T highBound);
```
***

#### Set lowBound and highBound to 0:
```cpp
void end();
```
***

#### Process given value through DeadBand:
```cpp
T read(T input);
```
+ **input:** your input value<br/>


+ **returns:** result of proccessing your input through DeadBand
