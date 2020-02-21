#ifndef HYSTERESIS_H
#define HYSTERESIS_H
namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
class Hysteresis
{
private:
    bool on = false;

public:
    float offVal = 0;
    float onVal = 0;
    float lowBound = 0;
    float highBound = 0;

    Hysteresis(float _offVal, float _onVal, float _lowBound = 0, float _highBound = 0) :  offVal(_offVal), onVal(_onVal), lowBound(_lowBound), highBound(_highBound) {}

    float read(float val)
    {
        if (val >= highBound)
            on = true;
        else if (val <= lowBound)
            on = false;

        if (on)
            return onVal;
        else
            return offVal;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil
#endif