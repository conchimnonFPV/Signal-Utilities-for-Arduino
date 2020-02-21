#ifndef ABSTRACT_ANALOG_GENERATOR_H
#define ABSTRACT_ANALOG_GENERATOR_H

#include <Arduino.h>

namespace SigUtil
{
namespace Generators
{
namespace Analog
{
class AbstractAnalogGenerator
{
private:
    bool isRunning = false;
    bool isPaused = false;
    bool goingDown = false;

    unsigned long startTimestamp;
    unsigned long endTime;
    float currentVal = 0;
    float endVal;

public:
    virtual void start(float startval, float endval, unsigned long timeval) = 0;
    void stop();
    void pause();
    void resume();
    bool running() const;
    bool paused() const;
    virtual float read() = 0;
};

void AbstractAnalogGenerator::stop()
{
    isPaused = false;
    isRunning = false;
}

void AbstractAnalogGenerator::pause()
{
    if (!isRunning) //you can't pause a generator that is not running
        return;

    //save remaining time
    //so if generator was set to 1000ms and paused at 800
    //it will take remaining 200ms to finish regulation after resume
    unsigned long currentTime = (unsigned long)(millis() - startTimestamp);
    endTime = (unsigned long)(endTime - currentTime);

    isPaused = true;
}

void AbstractAnalogGenerator::resume()
{
    if (!isRunning) //you can't resume a generator that is not running
        return;

    //resume timer from current position
    //with remaining time computed in pause() function
    //start() clears isPaused flag
    start(currentVal, endVal, endTime);
}

bool AbstractAnalogGenerator::running()
{
    return isRunning;
}

bool AbstractAnalogGenerator::paused()
{
    return isPaused;
}
} // namespace Analog
} // namespace Generators
} // namespace SigUtil
#endif