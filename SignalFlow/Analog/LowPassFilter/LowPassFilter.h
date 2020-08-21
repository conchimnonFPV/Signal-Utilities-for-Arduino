#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

namespace SigUtil
{
namespace SignalFlow
{
namespace Analog
{
/**
 * \brief First order low pass filter.
 */
class LowPassFilter
{
private:
  float previousOutput = 0;

public:
  const double smoothingFactor = 1;//!< Smoothing factor. 1: everything passes through, 0: nothing passes through.

  /**
   * \brief Class constructor
   * 
   * \param _sf Smoothing factor. 1: everything passes through, 0: nothing passes through.
   */
  LowPassFilter(double _sf = 1) : smoothingFactor(_sf){};

  /**
   * \brief Reset internal state of the filter.
   */
  void reset(){
    previousOutput = 0;
  }

  /**
   * \brief Pass input signal through the filter.
   * 
   * \param input Input to the filter.
   * \return Filtered input.
   */
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
