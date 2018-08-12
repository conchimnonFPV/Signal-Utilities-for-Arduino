#ifndef EXPONENTIAL_GENERATOR_H
#define EXPONENTIAL_GENERATOR_H

#include <Arduino.h>
namespace SigUtil
{
template <typename T>
class ExponentialGenerator
{
  private:
    bool isRunning = false;
    bool isPaused = false;
    bool goingDown = false;

    double a, b;
    unsigned long startTimestamp;
    unsigned long endTime;
    T currentVal = 0;
    T endVal;

  public:
    void start(T startval, T endval, unsigned long timeval);
    void stop();
    void pause();
    void resume();
    bool running();
    bool paused();
    T read();
};

template <typename T>
void ExponentialGenerator<T>::start(T startVal, T _endVal, unsigned long _endTime)
{
    if(startVal < 0 || _endVal < 0 || _endTime == 0)
    {
        if(_endTime == 0 && _endVal >= 0)
            currentVal = _endVal;
        return;
    }

    endVal = _endVal;
    endTime = _endTime;
    currentVal = startVal;

    double expStartVal = log(startVal + 1);
    double expEndVal = log(endVal + 1);

    a = (expEndVal - expStartVal) / endTime;
    b = expStartVal;

    if (a < 0)
        goingDown = true;
    else
        goingDown = false;

    startTimestamp = millis();

    isRunning = true;
    isPaused = false;
}

template <typename T>
void ExponentialGenerator<T>::stop()
{
    isPaused = false;
    isRunning = false;
}

template <typename T>
void ExponentialGenerator<T>::pause()
{
    if (!isRunning) //you can't pause a GENERATOR that is not running
        return;

    //save remaining time
    //so if GENERATOR was set to 1000ms and paused at 800
    //it will take remaining 200ms to finish regulation after resume
    unsigned long currentTime = (unsigned long)(millis() - startTimestamp);
    endTime = (unsigned long)(endTime - currentTime);

    isPaused = true;
}

template <typename T>
void ExponentialGenerator<T>::resume()
{
    if (!isRunning) //you can't resume a GENERATOR that is not running
        return;

    //resume timer from current position
    //with remaining time computed in pause() function
    //start() clears isPaused flag
    start(currentVal, endVal, endTime);
}

template <typename T>
T ExponentialGenerator<T>::read()
{
    if (!isRunning || isPaused)
        return currentVal;

    unsigned long currentTime = (unsigned long)(millis() - startTimestamp); //get current time
    double expCurrentVal = a * currentTime + b;                                    //compute linear function
    currentVal = exp(expCurrentVal) - 1;

    if (goingDown && currentVal < endVal || !goingDown && currentVal > endVal) //saturate output
        currentVal = endVal;

    if (currentTime >= endTime) //finished timewise so set result to end value and stop the GENERATOR
    {
        currentVal = endVal;
        isRunning = false;
    }

    return currentVal;
}

template <typename T>
bool ExponentialGenerator<T>::running()
{
    return isRunning;
}

template <typename T>
bool ExponentialGenerator<T>::paused()
{
    return isPaused;
}
};
#endif
