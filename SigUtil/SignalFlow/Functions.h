#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>

namespace SigUtil
{
namespace Functions
{
namespace Analog
{
float deadband(float val, float lowBound, float highBound)
{
    if (val >= highBound || val <= lowBound)
        return val;

    return 0;
}

float saturation(float val, float min = 0, float max = 255)
{
    if (val > max)
        val = max;
    else if (val < min)
        val = min;
    return val;
}

float inverse(float val, float min = 0, float max = 255)
{
    return val = (max - min) - val;
}

namespace Experimental
{
float toExponential(float val, float min, float max)
{
    if (val == min)
        return min;
    else if (val == max)
        return max;
    else if (min < 0 || max < 0)
        return 0;

    double expMin = log(min + 1);
    double expMax = log(max + 1);
    double a = (expMax - expMin) / (max - min);
    double b = expMin;

    double expVal = a * val + b;
    return exp(expVal) - 1;
}
} // namespace Experimental
} // namespace Analog
} // namespace Functions
} // namespace SigUtil

#endif