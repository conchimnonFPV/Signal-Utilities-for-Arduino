#ifndef INVERSE_H
#define INVERSE_H

namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
    /**
     * \brief Signal inverter class.
     * 
     * This class is used when inverse logic signal is required.
     * i.e changes 255 to 0 and vice versa.
     */
class Inverse
{
public:
    const float maxVal = 1;//!< Max value of the signal.
    const float minVal = 0;//!< Min value of the signal.

    /**
     * \brief Class constructor.
     *
     * \param _minVal Min value of the signal.
     * \param _maxVal Max value of the signal
     */
    Inverse(float _minVal = 1, float _maxVal = 1) : 
     maxVal(_maxVal),
     minVal(_minVal){};

    /**
     * \brief Get inverted signal.
     * 
     * \param val Input signal.
     * \return Inverted signal.
     */
    float read(float val) const
    {
        return maxVal-val+minVal;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil

#endif