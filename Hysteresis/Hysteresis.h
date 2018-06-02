#ifndef HYSTERESIS_H
#define HYSTERESIS_H
namespace SigUtil
{
template <typename inType, typename outType>
class Hysteresis
{
  private:
    bool on = 0;
    outType offVal;
    outType onVal;
    inType lowBound;
    inType highBound;

  public:
    Hysteresis(inType lowbound, inType highbound, outType offval, outType onval);
    outType read(inType val);
};

template <typename inType, typename outType>
Hysteresis<inType, outType>::Hysteresis(inType lowbound, inType highbound, outType offval, outType onval) : lowBound(lowbound), highBound(highbound), offVal(offval), onVal(onval) {}

template <typename inType, typename outType>
outType Hysteresis<inType, outType>::read(inType val)
{
    if (val >= highBound)
        on = 1;
    else if (val <= lowBound)
        on = 0;
    if (on)
        return onVal;
    else
        return offVal;
}
}
#endif