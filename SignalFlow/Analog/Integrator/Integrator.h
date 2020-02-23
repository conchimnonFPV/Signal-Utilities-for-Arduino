#ifndef INTEGRATOR_H
#define INTEGRATOR_H

namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
class Integrator
{
private:
    double integral = 0;
    unsigned long previousTime = 0;

public:
    const float lowerSat = -1 * INFINITY;
    const float upperSat = INFINITY;
    const unsigned int dt = 1;

    Integrator(float ls = -1 * INFINITY, float us = INFINITY, unsigned int _dt = 1) : lowerSat(ls), upperSat(us), dt(_dt)
    {
        reset();
    }

    void reset()
    {
        previousTime = millis();
        integral = 0;
    }

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