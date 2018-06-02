## Usage

```cpp
#include <LowPassFilter.h>

int potpin = A0;
SigUtil::LowPassFilter<int> filter(0.2, 20);

void setup()
{
  pinMode(potpin, INPUT);
}

void loop()
{
  int val = analogRead(potpin);
  int filteredVal = filter.read(val);
  Serial.print(val);
  Serial.print(" ");
  Serial.println(filteredVal);
}
```
