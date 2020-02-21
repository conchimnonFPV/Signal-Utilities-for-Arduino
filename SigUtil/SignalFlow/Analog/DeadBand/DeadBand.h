#ifndef DEADBAND_H
#define DEADBAND_H
namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
class DeadBand
{
public:
    const float lowBound = 0;
    const float highBound = 0;

    DeadBand(float _lowBound = 0, float _highBound = 0) : lowBound(_lowBound), highBound(_highBound) {}

    float read(float val) const
    {
        if (val >= highBound || val <= lowBound)
            return val;

        return 0;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil
#endif