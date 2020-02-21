#ifndef INVERSE_H
#define INVERSE_H

namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
class Inverse
{
public:
    const float minVal = 0;
    const float maxVal = 255;

    Inverse(float _minVal = 0, float _maxVal = 255) : minVal(_minVal), maxVal(_maxVal) {}

    float read(float val) const
    {
        return val = (maxVal - minVal) - val;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil

#endif