#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <Arduino.h>
#define BOTH 2

namespace SigUtil
{
namespace Detectors
{
namespace Digital
{
class EdgeDetector
{
private:
  bool previousState = 0;

public:
  const uint8_t edgeType = LOW;

  EdgeDetector(uint8_t etype) : edgeType(etype) {}

  bool read(bool input)
  {
    bool r = 0;
    if (!previousState && input && (edgeType == HIGH || edgeType == BOTH))
    {
      r = 1;
    }
    else if (previousState && !input && (edgeType == LOW || edgeType == BOTH))
    {
      r = 1;
    }
    previousState = input;
    return r;
  }
};
} // namespace Binary
} // namespace Detectors
} // namespace SigUtil
#endif