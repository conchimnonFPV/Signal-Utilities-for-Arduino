#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <Arduino.h>

namespace SigUtil
{
namespace Controllers
{
namespace Analog
{
/**
 * \brief PID controller with saturation and integral anti windup.
 */
class PIDController
{
private:
    unsigned long previousTime = 0;
    double previousErr = 0;
    double integral = 0;
    double previousControllVal = 0;

    double kp = 0;
    double ki = 0;
    double kd = 0;

public:
    const unsigned int dt = 1; //!< Delta time.
    const double lowerSaturation = INFINITY; //!< Maximum value that integrator may have.
    const double upperSaturation = -1 * INFINITY; //!< Minimum value that integrator may have.

    /**
    * \brief Class constructor.
    * 
    * \param _kp Proportional gain.
    * \param _ki Integral gain.
    * \param _kd Derivative gain.
    * \param ls Lower saturation value.
    * \param us Upper saturation value.
    * \param _dt Delta time in milliseconds.
    */
    PIDController(double _kp, double _ki, double _kd, double ls = -1 * INFINITY, double us = INFINITY, unsigned int _dt = 1) : kp(_kp), ki(_ki), kd(_kd), lowerSaturation(ls), upperSaturation(us), dt(_dt != 0 ? _dt : 1)
    {
        reset();
    }

    /**
     * \brief Reset internal state of the controller.
     */
    void reset();

    /**
     * \brief Receive control signal based on error value
     * 
     * \param err Error value.
     * \return Control value.
     */
    double read(double err);

    void setKp(double newKp) { kp = newKp; }
    void setKi(double newKi) { ki = newKi; }
    void setKd(double newKd) { kd = newKd; }

    double getKp() { return kp; }
    double getKi() { return ki; }
    double getKd() { return kd; }
};

void PIDController::reset()
{
    previousTime = millis();
    previousErr = 0;
    integral = 0;
    previousControllVal = 0;
}

double PIDController::read(double err)
{
    unsigned long currentTime = millis();
    unsigned long diff = currentTime - previousTime;
    if (diff >= dt)
    {
        //basic pid computing
        integral = integral + err * ((double)diff / (double)1000);
        double derivative = (err - previousErr) / ((double)diff / (double)1000);
        double controllVal = kp * err + ki * integral + kd * derivative;

        //saturation and integral clamping
        if (controllVal > upperSaturation)
        {
            //this if statement is experimental
            //apparently this metod (if I implemented it properly) is proven to be the best
            //method of integral clamping
            //but still it needs some testing
            if (err > 0 && controllVal > 0 || err < 0 && controllVal < 0)
                integral = integral - err * ((double)diff / (double)1000); //revert changes to integral made in this iteration

            controllVal = upperSaturation; //saturate output
        }
        else if (controllVal < lowerSaturation)
        {
            //same as above
            if (err > 0 && controllVal > 0 || err < 0 && controllVal < 0)
                integral = integral - err * ((double)diff / (double)1000);

            controllVal = lowerSaturation;
        }

        //save current stuff for next iteration
        previousErr = err;
        previousControllVal = controllVal;
        previousTime = currentTime;

        return controllVal;
    }
    return previousControllVal; //zero order hold
}
} // namespace Analog
} // namespace Controllers
} // namespace SigUtil
#endif
