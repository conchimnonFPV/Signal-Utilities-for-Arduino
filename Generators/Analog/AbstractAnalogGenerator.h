#ifndef ABSTRACT_ANALOG_GENERATOR_H
#define ABSTRACT_ANALOG_GENERATOR_H

#include <Arduino.h>

namespace SigUtil
{
namespace Generators
{
namespace Analog
{
/**
* \brief Abstract generator.
*/
class AbstractAnalogGenerator
{
protected:
    bool isRunning = false;
    bool isPaused = false;
    bool goingDown = false;
    unsigned long startTimestamp;
    unsigned long endTime;
    float currentVal = 0;
    float endVal;

public:
    /**
     * \brief Start the generator.
     *
     * \param startval Value the generator will start from.
     * \param endval Value the generator will finish on.
     * \param timeval Time in milliseconds to generate some signal from startval to endval
     */ 
    virtual void start(float startval, float endval, unsigned long timeval) = 0;

    /**
     * \brief Stop the generator.
     */
    void stop();

    /**
     * \brief Pause the generator.
     */
    void pause();

    /**
     * \brief Resume the generator.
     */
    void resume();

    /**
     * \brief Check if generator is still running.
     * 
     * \return True if generator is still running.
     */
    bool running() const {return isRunning;}

    /**
     * \brief Check if generator is paused.
     * 
     * \return True if generator is paused.
     */
    bool paused() const {return isPaused;}

    /**
     * \brief Get current value from the generator.
     * 
     * When generator is not working (either stopped, paused or finished) then value doesn't change.
     */
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

} // namespace Analog
} // namespace Generators
} // namespace SigUtil
#endif