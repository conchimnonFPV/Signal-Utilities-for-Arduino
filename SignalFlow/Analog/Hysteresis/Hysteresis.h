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
    const float offValue = 0;
    const float onValue = 0;
    const float lowSwitchState = 0;
    const float highSwitchState = 0;

    Hysteresis(float _offValue, float _onValue, float _lowSwitchState = 0, float _highSwitchState = 0) : offValue(_offValue), onValue(_onValue), lowSwitchState(_lowSwitchState), highSwitchState(_highSwitchState) {}

    void reset() { on = false; }

    float read(float val)
    {
        if (val >= highSwitchState)
            on = true;
        else if (val <= lowSwitchState)
            on = false;

        if (on)
            return onValue;
        return offValue;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil
#endif