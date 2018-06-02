#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include <Arduino.h>
namespace SigUtil
{
template <typename valType>
class LowPassFilter
{
private:
  bool intervalCheck = 1;
  double sf;
  unsigned int dt;

public:
  LowPassFilter(double _sf, unsigned int _dt);

  void disableIntervalCheck();
  void enableIntervalCheck();

  void setSmoothingFactor(double _sf);

  bool intervalCheckEnabled();
  double getSmoothingFactor();

  valType read(valType input);
};

template <typename valType>
LowPassFilter<valType>::LowPassFilter(double _sf, unsigned int _dt)
    : sf(_sf), dt(_dt) {}

template <typename valType>
void LowPassFilter<valType>::disableIntervalCheck()
{
  intervalCheck = 0;
}

template <typename valType>
void LowPassFilter<valType>::enableIntervalCheck()
{
  intervalCheck = 1;
}

template <typename valType>
void LowPassFilter<valType>::setSmoothingFactor(double _sf)
{
  sf = _sf;
}

template <typename valType>
bool LowPassFilter<valType>::intervalCheckEnabled()
{
  return intervalCheck;
}

template <typename valType>
double LowPassFilter<valType>::getSmoothingFactor()
{
  return sf;
}

template <typename valType>
valType LowPassFilter<valType>::read(valType input)
{
  static unsigned long previousTime = 0;
  static valType previousOutput = 0;

  unsigned long currentTime = millis();
  if ((unsigned long)(currentTime - previousTime) >= dt || !intervalCheck)
  {
    int n = (currentTime-previousTime) / dt;
    double output;
    for(int i = 0; i < n; i++)
    {
      output = previousOutput + sf * (input - previousOutput);
      previousOutput = output;
    }
    previousTime = currentTime;
    return output;
  }
  return previousOutput;
}
}
#endif