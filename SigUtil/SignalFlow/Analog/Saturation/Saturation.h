#ifndef SATURATION_H
#define SATURATION_H
namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
class Saturation
{
    public:
    const float minVal = -1 * INFINITY;
    const float maxVal = INFINITY;

    Saturation(float _minVal = -1 * INFINITY, float _maxVal = INFINITY) : minVal(_minVal), maxVal(_maxVal) {}

    float read(float input) const
    {
        if (input > maxVal)
            input = maxVal;
        else if (input < minVal)
            input = minVal;
        return input;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil
#endif