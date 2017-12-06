#include <stdint.h>
#include "mgos_servo.h"

Servo* mgos_servo_create()
{
    return new Servo();
}

void mgos_servo_delete(Servo* pThis)
{
    delete pThis;
}

int mgos_servo_doTime(Servo* pThis, int onTime)
{
    return (nullptr != pThis) ? pThis->doTime(onTime) : -1;
}

int mgos_servo_doTimeWithTimer(Servo* pThis, int onTime, int timer)
{
    return (nullptr != pThis) ? pThis->doTimeWithTimer(onTime, timer) : -1;
}

int mgos_servo_doAngle(Servo* pThis, int angle)
{
    return (nullptr != pThis) ? pThis->doAngle(angle) : -1;
}

int mgos_servo_doAngleWithTimer(Servo* pThis, int angle, int timer)
{
    return (nullptr != pThis) ? pThis->doAngleWithTimer(angle, timer) : -1;
}
