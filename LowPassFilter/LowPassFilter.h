#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include <Arduino.h>
namespace SigUtil
{
template <typename valType>
class LowPassFilter
{
private:
  bool intervalCheck = true;
  bool enabled = false;

  unsigned long previousTime = 0;
  valType previousOutput = 0;

  void update(double _sf, unsigned int _dt);

public:
  double smoothingFactor;
  unsigned int dt;

  void begin(double _sf, unsigned int _dt);
  void reset();
  void end();

  void disableIntervalCheck();
  void enableIntervalCheck();
  bool intervalCheckEnabled();

  valType read(valType input);
};

template <typename valType>
void LowPassFilter<valType>::update(double _sf, unsigned int _dt)
{
  smoothingFactor = _sf;
  dt = _dt;
}

template <typename valType>
void LowPassFilter<valType>::begin(double _sf, unsigned int _dt)
{
  reset();
  update(_sf, _dt);
  enabled = true;
}

template <typename valType>
void LowPassFilter<valType>::reset()
{
  previousOutput = 0;
  previousTime = 0;
}

template <typename valType>
void LowPassFilter<valType>::end()
{
  reset();
  update(0, 0);
  enabled = false;
}

template <typename valType>
void LowPassFilter<valType>::disableIntervalCheck()
{
  intervalCheck = false;
}

template <typename valType>
void LowPassFilter<valType>::enableIntervalCheck()
{
  intervalCheck = true;
}

template <typename valType>
bool LowPassFilter<valType>::intervalCheckEnabled()
{
  return intervalCheck;
}

template <typename valType>
valType LowPassFilter<valType>::read(valType input)
{
  if(!enabled)
    return 0;

  unsigned long currentTime = millis();
  if ((unsigned long)(currentTime - previousTime) >= dt || !intervalCheck)
  {
    double output = previousOutput + smoothingFactor * (input - previousOutput);
    previousOutput = output;
    previousTime = currentTime;
    return output;
  }
  return previousOutput;//zero hold order
}
}
#endif