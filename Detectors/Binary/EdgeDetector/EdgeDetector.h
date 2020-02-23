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
  /**
   * \brief Detects whether given boolean signal changed it's value.
   */
class EdgeDetector
{
private:
  bool previousState = 0;

public:
  const uint8_t edgeType = LOW; //!< Edge on which detector should react. Use LOW, HIGH or BOTH here.

  /**
   * \brief Class constructor.
   * 
   * \param etype Edge type on which detector should react. Use LOW, HIGH or BOTH.
   */
  EdgeDetector(uint8_t etype) : edgeType(etype) {}

  /**
   * \brief Reset internal state of the detector.
   */
  void reset(){previousState = 0;}

  /**
   * \brief Check whether input since last check.
   * 
   * \param input Given input.
   * \return True only if input changed since last check.
   */
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