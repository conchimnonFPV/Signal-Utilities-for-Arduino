#ifndef LINEAR_GENERATOR_H
#define LINEAR_GENERATOR_H

#include <Arduino.h>
#include "../AbstractAnalogGenerator.h"

namespace SigUtil
{
namespace Generators
{
namespace Analog
{
class SigUtil::Generators::Analog::AbstractAnalogGenerator : LinearGenerator
{
private:
    double a, b;
public:
    void start(float startval, float endval, unsigned long timeval);
    float read();
};

void LinearGenerator::start(float startVal, float _endVal, unsigned long _endTime)
{
    if (_endTime == 0)
    {
        currentVal = _endVal;
        return;
    }
    endVal = _endVal;
    endTime = _endTime;
    currentVal = startVal;

    a = (double)(endVal - startVal) / (double)endTime;
    b = (double)startVal;

    if (a < 0)
        goingDown = true;
    else
        goingDown = false;

    startTimestamp = millis();

    isRunning = true;
    isPaused = false;
}

float LinearGenerator::read()
{
    if (!isRunning || isPaused)
        return currentVal;

    unsigned long currentTime = (unsigned long)(millis() - startTimestamp); //get current time
    currentVal = a * currentTime + b;                                       //compute linear function

    if (goingDown && currentVal < endVal || !goingDown && currentVal > endVal) //saturate output
        currentVal = endVal;

    if (currentTime >= endTime) //finished timewise so set result to end value and stop the generator
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