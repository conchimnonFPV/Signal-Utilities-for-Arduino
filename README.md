# Signal-Utilities-for-Arduino

This is a collection of libraries that provide some useful functionality for signal processing. The libraries are organised in the following manner:
* **Controllers** - Generate control signal based on given variables.
    * **Analog**
        * **PIDController** - PID controller with saturation and integral anti-windup
* **Detectors** - Generate single boolean pulse when some change in signal is detected, i.e when change from binary 0 to 1 is detected.
    * **Binary**
        * **EdgeDetector** - Detects change in digital signal
* **Generators** - Generate some signal over time, i.e ramp signal.
    * **Analog**
        * **LinearGenerator** - Generate linear signal over time.
        * **ExponentialGenerator** - Generate exponential signal over time.
* **Signal shapers** - Change shape of input signal and return new signal, i.e filters or non linear blocks such as hysteresis.
    * **Analog**
        * **DeadBand** - Set signal to 0 if it's in given region.
        * **Hysteresis** - Filters signal so it reacts less rapidly. Output value can be either on or off value.
        * **Saturation** - Saturates signal if it exceeded given region.
        * **LowPassFilter** - Throttles high frequency signals.
        * **Inverse** - Inverses given signal, i.e 255 becomes 0 and 0 becomes 255.
    * **Functions** - functional alternative for stateless classes in **Signal shapers**
        * **saturation()** - See **Analog/Saturation**
        * **deadband()** - See **Analog/DeadBand**
        * **inverse()** - See **Analog/Inverse**
        * **exponential()** - See **Analog/Exponential**

Libraries are written in following way:
* For classes, constant members can be accessed directly and non-constant via getters and setters.
* Every class has a read function that is used to retreive new signal value.
* Classes that are time sensitive work on difference between current time and previous update time so missing update deadline shouldn't do too much harm.
* Classes that are time sensitive have update ratio which is set to 1ms by default and can be changed during construction of the object.
* Classes that have some internal state such as PID or filters have a reset() function to reset said state.
* Stateless signal flow classes have corresponding function in "SigUtil/SignalFlow/Functions.h", i.e Saturation class have saturate() function.
* Classes that have some integration functionality are saturated. By default saturation region is set to infinity and -infinity.