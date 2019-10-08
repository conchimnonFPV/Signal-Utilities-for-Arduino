#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <Arduino.h>

namespace SigUtil
{
template <typename inputType, typename returnType>
class PIDController
{
  private:
    bool intervalCheck = true;

    unsigned long previousTime = 0;
    inputType previousErr = 0;
    inputType integral = 0;
    returnType previousControllVal = 0;

    void update(double _kp, double _ki, double _kd, returnType ls, returnType us, unsigned int _dt);

  public:
    double kp = 0;
    double ki = 0;
    double kd = 0;
    unsigned int dt;
    returnType lowerSaturation = 0;
    returnType upperSaturation = 0;
    inputType setpoint = 0;

    void begin(double _kp, double _ki, double _kd, returnType ls, returnType us, unsigned int _dt);
    void reset();
    void end();

    void disableIntervalCheck();
    void enableIntervalCheck();
    bool intervalCheckEnabled();

    returnType read(inputType pv);
};

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::update(double _kp, double _ki, double _kd, returnType ls, returnType us, unsigned int _dt)
{
    kp = _kp;
    ki = _ki;
    kd = _kd;
    lowerSaturation = ls;
    upperSaturation = us;
    dt = _dt;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::begin(double _kp, double _ki, double _kd, returnType ls, returnType us, unsigned int _dt)
{
    reset();
    update(_kp, _ki, _kd, ls, us, _dt);
    setpoint = 0;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::end()
{
    reset();
    update(0, 0, 0, 0, 0, 0);
    setpoint = 0;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::reset()
{
    previousTime = 0;
    previousErr = 0;
    integral = 0;
    previousControllVal = 0;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::disableIntervalCheck()
{
    intervalCheck = false;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::enableIntervalCheck()
{
    intervalCheck = true;
}

template <typename inputType, typename returnType>
bool PIDController<inputType, returnType>::intervalCheckEnabled()
{
    return intervalCheck;
}

template <typename inputType, typename returnType>
returnType PIDController<inputType, returnType>::read(inputType pv)
{       
    unsigned long currentTime = millis();
    if ((unsigned long)(currentTime - previousTime) >= dt || !intervalCheck)
    {
        //basic pid computing
        inputType err = setpoint - pv;
        integral = integral + err * (inputType)dt;
        inputType derivative = (err - previousErr) / (inputType)dt;
        returnType controllVal = kp * err + ki * integral + kd * derivative;

        //saturation and integral clamping
        if (controllVal > upperSaturation)
        {
            //this if statement is experimental
            //apparently this metod (if I implemented it properly) is proven to be the best
            //method of integral clamping
            //but still it needs some testing
            if(err > 0 && controllVal > 0 || err < 0 && controllVal < 0)
                integral = integral - err*(inputType)dt;//revert changes to integral made in this iteration
          
            controllVal = upperSaturation;//saturate output
        }
        else if (controllVal < lowerSaturation)
        {
            //same as above
            if(err > 0 && controllVal > 0 || err < 0 && controllVal < 0)
                integral = integral - err*(inputType)dt;
          
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
}
#endif
