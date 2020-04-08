#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>

namespace SigUtil
{
namespace Functions
{
namespace Analog
{
/**
 * \brief Suppress signal when it's in given range.
 * 
 * \param val Value to be passed through deadband.
 * \param lowBound Output signal is 0 when signal is above this value.
 * \param highBund Output signal is 0 when signal is below this value.
 * \return Filtered value.
 */
float deadband(float val, float lowBound, float highBound)
{
    if (val >= highBound || val <= lowBound)
        return val;

    return 0;
}

/**
 * \brief Saturate given input.
 * 
 * \param val Input to be saturated.
 * \param minv Min output value.
 * \param maxv Max output value.
 * \return Saturated input.
 */
float saturation(float val, float minv = 0, float maxv = 255)
{
    if (val > maxv)
        val = maxv;
    else if (val < minv)
        val = minv;
    return val;
}

/**
 * \brief Invert given signal
 * 
 * i.e change 255 to 0 and vice versa.
 * 
 * \param val Input signal.
 * \param minv Min value of the signal.
 * \param maxv Max value of the signal
 * \return Inverted signal.
 */
float inverse(float val, float minv = 0, float maxv = 255)
{
    return maxv - val + minv;
}

/**
 * \brief Translate linear signal into exponential signal.
 * 
 * \param val Value to be translated.
 * \param minv Lower boundary of the signal.
 * \param maxv Upper boundary of the signal.
 * \return Translated signal.
 */
float exponential(float val, float minv, float maxv)
{
    if (val == minv)
        return minv;
    else if (val == maxv)
        return maxv;
    else if (minv < 0 || maxv < 0)
        return 0;

    double expMin = log(minv + 1);
    double expMax = log(maxv + 1);
    double a = (expMax - expMin) / (maxv - minv);
    double b = expMin;

    double expVal = a * val + b;
    return exp(expVal) - 1;
}
} // namespace Analog
} // namespace Functions
} // namespace SigUtil

#endif