#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include <Arduino.h>

namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
class LowPassFilter
{
private:
  float previousOutput = 0;

public:
  const double smoothingFactor = 1;

  LowPassFilter(double _sf = 1) : smoothingFactor(_sf){};

  void reset(){
    previousOutput = 0;
  }

  float read(float input)
  {
    double output = previousOutput + smoothingFactor * (input - previousOutput);
    previousOutput = output;
    return output;
  }
};
} // namespace Analog
} // namespace SignalFlow
} // namespace SigUtil
#endif