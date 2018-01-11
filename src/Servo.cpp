#include <mgos.h>
#include <mgos_pwm.h>

#include "Servo.h"

const float _factor = 20000.0;

Servo::Servo()
: _pin(mgos_sys_config_get_Servo_pin())
, _tmin(mgos_sys_config_get_Servo_tmin())
, _tmax(mgos_sys_config_get_Servo_tmax())
{
}

Servo::Servo(int pin, int tmin, int tmax)
: _pin(pin)
, _tmin(tmin)
, _tmax(tmax)
{
}

int Servo::doTime(int onTime)
{
    onTime = minMax(onTime, _tmin, _tmax);
    float duty = onTime / _factor;
    LOG(LL_INFO, ("duty=%f, onTime=%d us", duty, onTime));
    mgos_pwm_set(_pin, 50, duty);
    return onTime;
}

int Servo::doTimeWithTimer(int onTime, int timer)
{
    int ret = doTime(onTime);
    mgos_set_timer(timer, false, staticStopPwmTimerCB, (void*) _pin);
    return ret;
}

int Servo::doAngle(int angle)
{
    angle = minMax(angle, (int) 0, (int) 180);
    float duty = (_tmin + angle * (_tmax - _tmin) / 180.0) / _factor;
    float onTime = duty * _factor;
    const char* fmt = "angle=%d, duty=%f, onTime=%f us";
    LOG(LL_INFO, (fmt, angle, duty, onTime));
    mgos_pwm_set(_pin, 50, duty);
    return angle;
}

int Servo::doAngleWithTimer(int angle, int timer)
{
    int ret = doAngle(angle);
    mgos_set_timer(timer, false, staticStopPwmTimerCB, (void*) _pin);
    return ret;
}

void Servo::staticStopPwmTimerCB(void * arg)
{
    //Servo* pThis = reinterpret_cast<Servo*> (arg);
    mgos_pwm_set((int) arg, 0, 0);
}
