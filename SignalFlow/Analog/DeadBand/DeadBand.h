#ifndef DEADBAND_H
#define DEADBAND_H
namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
/**
 * \brief Suppress signal when it's in given range.
 */
class DeadBand
{
public:
    const float lowSuppressValue = 0;//!< Output signal is 0 when signal is above this value.
    const float highSuppressValue = 0;//!< Output signal is 0 when signal is below this value.

    /**
     * \brief Class constructor.
     * 
     * \param _lowSuppressValue Output signal is 0 when signal is above this value.
     * \param _highSuppressValue Output signal is 0 when signal is below this value.
     */
    DeadBand(float _lowSuppressValue = 0, float _highSuppressValue = 0) : lowSuppressValue(_lowSuppressValue), highSuppressValue(_highSuppressValue) {}

    /**
     * \brief Pass value through DeadBand object
     * 
     * \param val Value to be passed through.
     */
    float read(float val) const
    {
        if (val >= highSuppressValue || val <= lowSuppressValue)
            return val;

        return 0;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil
#endif