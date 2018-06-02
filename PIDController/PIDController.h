#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <Arduino.h>
namespace SigUtil
{
template <typename inputType, typename returnType>
class PIDController
{
  private:
    bool intervalCheck = 1;
    unsigned int dt;

    inputType setpoint = 0;

    double kp;
    double ki;
    double kd;

    returnType lowerSaturation;
    returnType upperSaturation;

  public:
    PIDController(double _kp, double _ki, double _kd, returnType ls, returnType hs, unsigned int _dt);

    void disableIntervalCheck();
    void enableIntervalCheck();

    void setKp(double _kp);
    void setKi(double _ki);
    void setKd(double _kd);
    void setSetpoint(inputType _sp);

    bool intervalCheckEnabled();
    double getKp();
    double getKi();
    double getKd();
    inputType getSetpoint();

    returnType read(inputType pv);
};

template <typename inputType, typename returnType>
PIDController<inputType, returnType>::PIDController(double _kp, double _ki, double _kd, returnType ls, returnType hs, unsigned int _dt)
    : kp(_kp), ki(_ki), kd(_kd), lowerSaturation(ls), upperSaturation(hs), dt(_dt) {}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::disableIntervalCheck()
{
    intervalCheck = 0;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::enableIntervalCheck()
{
    intervalCheck = 1;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::setKp(double _kp)
{
    kp = _kp;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::setKi(double _ki)
{
    ki = _ki;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::setKd(double _kd)
{
    kd = _kd;
}

template <typename inputType, typename returnType>
void PIDController<inputType, returnType>::setSetpoint(inputType _sp)
{
    setpoint = _sp;
}

template <typename inputType, typename returnType>
bool PIDController<inputType, returnType>::intervalCheckEnabled()
{
    return intervalCheck;
}

template <typename inputType, typename returnType>
double PIDController<inputType, returnType>::getKp()
{
    return kp;
}

template <typename inputType, typename returnType>
double PIDController<inputType, returnType>::getKi()
{
    return ki;
}

template <typename inputType, typename returnType>
double PIDController<inputType, returnType>::getKd()
{
    return kd;
}

template <typename inputType, typename returnType>
inputType PIDController<inputType, returnType>::getSetpoint()
{
    return setpoint;
}

template <typename inputType, typename returnType>
returnType PIDController<inputType, returnType>::read(inputType pv)
{
    static unsigned long previousTime = 0;
    static inputType previousErr = 0;
    static inputType integral = 0;
    static returnType previousControllVal = 0;

    unsigned long currentTime = millis();
    if ((unsigned long)(currentTime - previousTime) >= dt || !intervalCheck)
    {
        inputType err = setpoint - pv;
        integral = integral + err * (inputType)dt;
        inputType derivative = (err - previousErr) / (inputType)dt;
        returnType controllVal = kp * err + ki * integral + kd * derivative;

        if (controllVal > upperSaturation)
            controllVal = upperSaturation;
        else if (controllVal < lowerSaturation)
            controllVal = lowerSaturation;

        previousErr = err;
        previousControllVal = controllVal;
        previousTime = currentTime;
        return controllVal;
    }
    return previousControllVal;
}
}
#endif