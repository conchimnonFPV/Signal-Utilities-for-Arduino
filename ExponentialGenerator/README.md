# ExponentialGenerator

Changes value from initial to final in given time in exponential manner.

## Contents
| ExponentialGenerator                                                                                                                                            |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| + start(T, T, unsigned long): void<br/> + stop(): void<br/> + pause(): void</br> + resume(): void</br> + running(): bool<br/> + paused(): bool<br/> + read(): T |

## Usage
#### ExponentialGenerator variable initializer:
```cpp
template<typename T>
ExponentialGenerator;
```
**T:** Type of the generator's output variable.<br/>
***
#### Start generator:
```cpp
void start(T startVal, T stopVal, unsigned long time);
```
+ **startVal:** Start regulation with this value<br/>
+ **stopVal:** End regulation with this value<br/>
+ **time:** Regulation shall take this time (in milliseconds)<br/>
***

#### Stop generator:
```cpp
void stop();
```
Finishes the task the generator is currently doing.<br/>
Doesn't do anything if the generator is not running.<br/>
***

#### Pause generator:
```cpp
void pause();
```
Does not finish the task the generator is currently doing, but pauses it.<br/>
Doesn't do anything if the generator is not running.<br/>
***

#### Resume generator:
```cpp
void resume();
```
Doesn't do anything if the generator is not running.<br/>
<br/>

#### Check whether generator is running:
```cpp
bool running();
```
+ **returns:** true if generator has not finished it's task, even if it's paused.<br/>
***

#### Check whether generator is paused:
```cpp
bool paused();
```
+ **returns:** True if the generator is paused.<br/>
***

#### Get current value from ExponentialGenerator:
```cpp
T read();
```
+ **returns:** New value for running generator. If the generator is not running, returns the last value it computed when it was running or 0 if the generator was never started.
