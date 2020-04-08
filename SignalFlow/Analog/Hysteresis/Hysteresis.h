#ifndef HYSTERESIS_H
#define HYSTERESIS_H
namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
/**
 * \brief Simple hysteresis object.
 */
class Hysteresis
{
private:
    bool on = false;

public:
    const float offValue = 0;//!< Value returned when hysteresis is in low state.
    const float onValue = 0;//!< Value returned when hysteresis is in high state.
    const float lowSwitchState = 0;//!< Value where hysteresis changes it's state from high to low.
    const float highSwitchState = 0;//!< Value where hysteresis changes it's state from low to high.

    /**
     * \brief Class constructor.
     * 
     * \param _offValue Value returned when hysteresis is in low state.
     * \param _onValue Value returned when hysteresis is in high state.
     * \param _lowSwitchState Value where hysteresis changes it's state from high to low.
     * \param _highSwitchState Value where hysteresis changes it's state from low to high.
     */
    Hysteresis(float _offValue, float _onValue, float _lowSwitchState = 0, float _highSwitchState = 0) : offValue(_offValue), onValue(_onValue), lowSwitchState(_lowSwitchState), highSwitchState(_highSwitchState) {}

    /**
     * \brief Reset internal state (set Hysteresis to low state).
     */
    void reset() { on = false; }

    /**
     * \brief Get value of the Hysteresis object based on given input.
     * 
     * \param val Input for hysteresis.
     * \return Current value of hysteresis.
     */
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