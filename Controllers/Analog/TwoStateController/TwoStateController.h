#ifndef TWO_STATE_CONTROLLER
#define TWO_STATE_CONTROLLER

namespace SigUtil
{
namespace Controllers
{
namespace Analog
{
/**
 * \brief Simple two state controller
 */
class TwoStateController
{
private:
    float setpoint = 0;
    float on = false;

public:
    const float offValue = 0; //!< Output when regulator is in disabled state.
    const float onValue = 0;  //!< Output when regulator is in enabled state.
    const float lowSwitchState = 0;//!< Value when regulator switches to low state.
    const float highSwitchState = 0;//!< Value when regulator switches to high state.

    /**
     * \brief Class constructor.
     * 
     * \param _offValue Output when regulator is in disabled state.
     * \param _onValue Output when regulator is in enabled state.
     * \param _lowSwitchState Value when regulator switches to low state.
     * \param _highSwitchState Value when regulator switches to high state.
     */
    TwoStateController(float _offValue, float _onValue, float _lowSwitchState, float _highSwitchState) : offValue(_offValue), onValue(_onValue), lowSwitchState(_lowSwitchState), highSwitchState(_highSwitchState) {}

    /**
     * \brief Reset internal state of the controller.
     */
    void reset() { on = false; }

    /**
     * \brief Receive control signal based on setpoint and process value
     * 
     * \param pv Process value.
     * \return Control value.
     */
    float read(float pv)
    {
        float err = setpoint - pv;
        if (err >= highSwitchState)
            on = true;
        else if (err <= lowSwitchState)
            on = false;

        if (on)
            return onValue;
        return offValue;
    }

    void setSetpoint(float newSp) { setpoint = newSp; }
};
} // namespace Analog
} // namespace Controllers
} // namespace SigUtil

#endif