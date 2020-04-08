#ifndef INTEGRATOR_H
#define INTEGRATOR_H

namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
/**
 * \brief Integrator with saturation.
 */
class Integrator
{
private:
    double integral = 0;
    unsigned long previousTime = 0;

public:
    const float lowerSat = -1 * INFINITY;//!< Lower saturation value.
    const float upperSat = INFINITY;//!< Upper saturation value.
    const unsigned int dt = 1;//!< Sampling time.

    /**
     * \brief Class constructor.
     * 
     * \param ls Lower saturation value.
     * \param us Upper saturation value.
     * \param _dt Sampling time.
     */
    Integrator(float ls = -1 * INFINITY, float us = INFINITY, unsigned int _dt = 1) : lowerSat(ls), upperSat(us), dt(_dt)
    {
        reset();
    }

    /**
     * \brief Reset internal state of Integrator.
     */
    void reset()
    {
        previousTime = millis();
        integral = 0;
    }

    /**
     * \brief Get current value from integrator
     * 
     * \param signal Input signal for integrator.
     * \return Current value of the integrator.
     */
    float read(float signal)
    {
        unsigned long currentTime = millis();
        unsigned long diff = currentTime - previousTime;
        if (diff >= dt)
        {
            integral = integral + signal * ((float)diff / (float)1000);

            //saturate integral
            if (integral > upperSat)
            {
                integral = upperSat;
            }
            else if (integral < lowerSat)
            {
                integral = lowerSat;
            }
        }
        return integral;
    }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil

#endif