namespace SigUtil
{
template <typename T>
T saturate(T val, T min, T max)
{
    if (val > max)
        val = max;
    else if (val < min)
        val = min;
    return val;
}

template <typename T>
T inverse(T val, T min, T max)
{
    return val = (max - min) - val;
}
};