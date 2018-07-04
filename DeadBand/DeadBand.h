#ifndef DEADBAND_H
#define DEADBAND_H
namespace SigUtil
{
template <typename T>
class DeadBand
{
  private:
    void update(T _lowBound, T _highBound);

  public:
    T lowBound = 0;
    T highBound = 0;

    void begin(T _lowBound, T _highBound);
    void end();

    T read(T val);
};

template <typename T>
void DeadBand<T>::update(T _lowBound, T _highBound)
{
    lowBound = _lowBound;
    highBound = _highBound;
}

template <typename T>
void DeadBand<T>::begin(T _lowBound, T _highBound)
{
    update(_lowBound, _highBound);
}

template <typename T>
void DeadBand<T>::end()
{
    update(0,0);
}

template <typename T>
T DeadBand<T>::read(T val)
{
    if(val >= highBound || val <= lowBound)
        return val;

    return 0;
}
}
#endif