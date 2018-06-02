# LowPassFilter for Arduino
This library gives you the ability to filter out unwanted, fast changes from your sensor's readings i.e filter out noise from ultrasonic sensor.

## Usage
Firstly, you need to declare LowPassFilter object:
```cpp
SigUtil::LowPassFilter<int> filter(0.2, 20); //where <int> is the variable type expected and returned by the filter
                                             //0.2 is the smoothig factor (double)
                                             //20 is the interval time in milliseconds (unsigned int)
```
Then you should use
```cpp
filteredVal = filter.read(someVal); //(<int>) expects (<int>)
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

You can change smoothing factor while program is running by using:
```cpp
filter.setSmoothingFactor(someSmoothingFactor); //(void) expects (double)
filter.getSmoothingFactor(); //(double) expects nothing
```

## Example
```cpp
#include <LowPassFilter.h>

int potpin = A0;
SigUtil::LowPassFilter<int> filter(0.2, 20);

void setup()
{
  pinMode(potpin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(potpin);
  int filteredVal = filter.read(val);
  
  //use plotter to compare both sinals
  Serial.print(val);
  Serial.print(" ");
  Serial.println(filteredVal);
}
```
