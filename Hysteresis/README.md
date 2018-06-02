# Hysteresis for Arduino
This library allows you to add some space around switching point of some signal to prevent it from changing rapidly in short time intervals which is useful i.e for water pumps where switching should happen rarely to not destroy the pump.<br /> 
## Usage
Firstly, you need to declare Hysteresis object:
```cpp
SigUtil::Hysteresis<int, bool> hysteresis(0.04, 0.06, 0, 1); 
//where <int,bool> is the input and output variable type
//0.04 is the off trigger (<int>)
//0.06 is the on trigger (<int>)
//0 is the off value (<bool>)
//1 is the on value (<bool>)
```
Then you should use
```cpp
boolVal = hysteresis.read(intVal); //(<bool>) expects (<int>)
```

## Example
```cpp
#include <Hysteresis.h>
int led = 13;
int pot = A0;
SigUtil::Hysteresis<int,bool> hysteresis(256, 512, 0, 1);//on led when pot above 512
                                                         //off led when below 256
                                                         //do not change state when between.

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
}
void loop()
{
  int potVal = analogRead(pot);
  bool ledVal = hysteresis.read(potVal);
  digitalWrite(led, ledVal);
}
```
