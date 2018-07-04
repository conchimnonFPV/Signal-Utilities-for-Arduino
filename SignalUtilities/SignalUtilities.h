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

template <typename T>
T toExponential(T val, T min, T max)
{
    if(val == min)
        return min;
    else if(val == max)
        return max;
        
    double expMin = log(min + 1);
    double expMax = log(max + 1);
    double a = (expMax-expMin) / (max - min);
    double b = expMin;
    //Serial.println(a);
    //Serial.println(b);
    double expVal = a*val+b;
    return exp(expVal)-1;
}
};