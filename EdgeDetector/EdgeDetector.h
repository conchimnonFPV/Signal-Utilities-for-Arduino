#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <Arduino.h>
#define BOTH 2
namespace SigUtil
{
class EdgeDetector
{
  private:
    bool previousState = 0;

  public:
    uint8_t edgeType = LOW;
    void begin(uint8_t etype){edgeType = etype;};
    void reset(){previousState = 0;};
    void end(){reset();edgeType=LOW;};
    bool read(bool input);
};

bool EdgeDetector::read(bool input)
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
} // namespace SigUtil
#endif