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
    const float maxVal = 1;
    const float offset = 0;
    Inverse(float _minVal = 1, float _maxVal = 1) : 
     maxVal(_maxVal-_minVal),
     offset(2*_minVal) {}

    float read(float val) const
    {
        return maxVal - val + offset;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil

#endif