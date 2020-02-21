#ifndef EXPONENTIAL_GENERATOR_H
#define EXPONENTIAL_GENERATOR_H

#include <Arduino.h>
#include "../AbstractAnalogGenerator.h"

namespace SigUtil
{
namespace Generators
{
namespace Analog
{
class SigUtil::Generators::Analog::AbstractAnalogGenerator : ExponentialGenerator
{
private:
    double a, b;

public:
    void start(float startval, float endval, unsigned long timeval);
    float read();
};

void ExponentialGenerator::start(float startVal, float _endVal, unsigned long _endTime)
{
    if (startVal < 0 || _endVal < 0 || _endTime == 0)
    {
        if (_endTime == 0 && _endVal >= 0)
            currentVal = _endVal;
        return;
    }

    endVal = _endVal;
    endTime = _endTime;
    currentVal = startVal;

    double expStartVal = log(startVal + 1);
    double expEndVal = log(endVal + 1);

    a = (expEndVal - expStartVal) / (double)endTime;
    b = expStartVal;

    if (a < 0)
        goingDown = true;
    else
        goingDown = false;

    startTimestamp = millis();

    isRunning = true;
    isPaused = false;
}

float ExponentialGenerator::read()
{
    if (!isRunning || isPaused)
        return currentVal;

    unsigned long currentTime = (unsigned long)(millis() - startTimestamp); //get current time
    double expCurrentVal = a * currentTime + b;                             //compute linear function
    currentVal = exp(expCurrentVal) - 1;

    if (goingDown && currentVal < endVal || !goingDown && currentVal > endVal) //saturate output
        currentVal = endVal;

    if (currentTime >= endTime) //finished timewise so set result to end value and stop the GENERATOR
    {
        currentVal = endVal;
        isRunning = false;
    }

    return currentVal;
}
} // namespace Analog
} // namespace Generators
} // namespace SigUtil
#endif
