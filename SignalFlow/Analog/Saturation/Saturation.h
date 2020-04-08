#ifndef SATURATION_H
#define SATURATION_H
namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
/**
 * \brief Simple saturation class.
 */
class Saturation
{
    public:
    const float minVal = -1 * INFINITY;//!< Min output value.
    const float maxVal = INFINITY;//!< Max output value.

    /**
     * \brief Class constructor.
     * 
     * \param _minVal Min output value.
     * \param _maxVal Max output value.
     */
    Saturation(float _minVal = -1 * INFINITY, float _maxVal = INFINITY) : minVal(_minVal), maxVal(_maxVal) {}

    /**
     * \brief Get saturated value.
     * 
     * \param input Input to be saturated.
     * \return Saturated input.
     */
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