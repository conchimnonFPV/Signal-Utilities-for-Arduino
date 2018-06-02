# PIDController for Arduino
This library implements basic PID controller.
## Usage
Firstly, you should declare PIDController object:
```cpp
SigUtil::PIDController<double, int> pid(696.6527, 1/0.956, 0.239, 0, 255, 20);
//where <int, int> is the input and output type for the controller
//696.6527 is the Kp (double)
//1/0.956 is the Ki (double)
//0.239 is the Kd (double)
//0 is the bottom saturation for output (<int>)
//255 is the upper saturation for output (<int>)
//20 is the interval time in milliseconds (unsigned int)
```
then you should your setpoint:
```cpp
pid.setSetpoint(0.03); //(void) expects (<double>)
```
then get your value:
```cpp
controll = pid.read(measured); //(<int>) expects (<double>)
```
You should use read() as often as you can as this library is designed to be used in non-stopping manner.

### Additional functions: <br />
You can disable internal interval check i.e if you want to use read() inside timer's interrupt routine
```cpp
filter.disableIntervalCheck(); //(void) expects nothing
filter.enableIntervalCheck(); //(void) expects nothins
filter.intervalCheckEnabled(); //(bool) expects nothing
```
Interval check is enabled by default. <br />

you can change your settings while program is running: 
```cpp
pid.setKp(someKp); //(void) expects double
pid.setKi(someKi); //(void) expects double
pid.setKd(someKd); //(void) expects double
pid.setSetpoint(someSP); //(void) expects (<double>)
pid.getKp(); //(double) expects nothing
pid.getKi(); //(double) expects nothing
pid.getKd(); //(double) expects nothing
pid.getSetpoint(); //(<double>) expects nothing
```

## Example
```cpp
#include <PIDController.h>

int pumppin = 6;
int distancepin = A0;
SigUtil::PIDController<int, int> pid(696.6527, 1/0.956, 0.239, 0, 255, 20);

void setup()
{
  pinMode(pumppin, OUTPUT);
  pinMode(distancepin, INPUT);
  pid.setSetpoint(256);
}

void loop()
{
  int distance = analogRead(distancepin);
  int pump = pid.read(distance);
  analogWrite(pumppin,pump);
}
```
