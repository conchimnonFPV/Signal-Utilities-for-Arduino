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
    const float offValue = 0; //!< Output when error is below bottomSwitchBoundary.
    const float onValue = 0;  //!< Output when error is above topSwitchBoundary.
    const float bottomSwitchBoundary = 0;//!< Error value below which regulator switches to off value.
    const float topSwitchBoundary = 0;//!< Error value above which regulator switches to on value.

    /**
     * \brief Class constructor.
     * 
     * \param _offValue Output when regulator is in disabled state.
     * \param _onValue Output when regulator is in enabled state.
     * \param bottomSwitchBoundary Value when regulator switches to low state.
     * \param topSwitchBoundary Value when regulator switches to high state.
     */
    TwoStateController(float _offValue, float _onValue, float _bottomSwitchBoundary, float _topSwitchBoundary) : offValue(_offValue), onValue(_onValue), bottomSwitchBoundary(_bottomSwitchBoundary), topSwitchBoundary(_topSwitchBoundary) {}

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
        if (err >= topSwitchBoundary)
            on = true;
        else if (err <= bottomSwitchBoundary)
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
