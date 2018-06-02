## Functions

Trim values out of lowerBound/upperBound bounds:
```cpp
//returns some type and expects three parameters of the same type
SigUtil::saturate(value, lowerBound, upperBound); 
```

Inverse value i.e for reverse logic, where 1 is swapped with 0 for digital and 255 is swapped with 0 for analog
```cpp
//returns some type and expects three parameters of the same type
SigUtil::inverse(value, lowerBound, upperBound); 
```
