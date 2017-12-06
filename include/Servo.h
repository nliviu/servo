#pragma once

class Servo
{
public:
    Servo();

    ~Servo()
    {
    }

    /*
     * generates pwm with "on" time
     */
    int doTime(int onTime);

    /*
     * generates pwm with "on" time
     * and stops after timer milliseconds
     */
    int doTimeWithTimer(int onTime, int timer = 750);

    /*
     * generates pwm to move the servo to the specified angle
     */
    int doAngle(int angle);

    /*
     * generates pwm to move the servo to the specified angle
     * and stops after timer milliseconds
     */
    int doAngleWithTimer(int angle, int timer = 750);

private:
    int _pin;
    int _tmin;
    int _tmax;
    
    //Adjust constant according to mos tool version
    static float _factor;

    static void staticStopPwmTimerCB(void * arg);

    template <typename T>
    T minMax(T val, T min, T max)
    {
        return (val < min) ? min : ((val > max) ? max : val);
    }
};
