#ifndef HYSTERESIS_H
#define HYSTERESIS_H
namespace SigUtil
{
template <typename inType, typename outType>
class Hysteresis
{
  private:
    bool on = false;

    void update(inType _lowBound, inType _highBound, outType _offVal, outType _onVal);

  public:
    outType offVal = 0;
    outType onVal = 0;
    inType lowBound = 0;
    inType highBound = 0;

    void begin(inType _lowBound, inType _highBound, outType _offVal, outType _onVal);
    void reset();
    void end();
    void forceOn();
    void forceOff();
    outType read(inType val);
};

template <typename inType, typename outType>
void Hysteresis<inType, outType>::update(inType _lowBound, inType _highBound, outType _offVal, outType _onVal)
{
    lowBound = _lowBound;
    highBound = _highBound;
    offVal = _offVal;
    onVal = _onVal;
}

template <typename inType, typename outType>
void Hysteresis<inType, outType>::begin(inType _lowBound, inType _highBound, outType _offVal, outType _onVal)
{
    reset();
    update(_lowBound, _highBound, _offVal, _onVal);
}

template <typename inType, typename outType>
void Hysteresis<inType, outType>::reset()
{
    on = false;
}

template <typename inType, typename outType>
void Hysteresis<inType, outType>::end()
{
    reset();
    update(0,0,0,0);
}
template <typename inType, typename outType>
void Hysteresis<inType, outType>::forceOn()
{
    on = true;
}

template <typename inType, typename outType>
void Hysteresis<inType, outType>::forceOff()
{
    on = false;
}

template <typename inType, typename outType>
outType Hysteresis<inType, outType>::read(inType val)
{
    if (val >= highBound)
        on = true;
    else if (val <= lowBound)
        on = false;

    if (on)
        return onVal;
    else
        return offVal;
}
}
#endif