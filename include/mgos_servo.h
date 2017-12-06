#pragma once

#ifdef __cplusplus
#include "Servo.h"
#else
typedef struct ServoTag Servo;
#endif

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /*
     creates a servo object using the settings defined in mos.yml
     */
    Servo* mgos_servo_create();

    /*
     * deletes the object by calling the destructor
     */
    void mgos_servo_delete(Servo* pThis);

    /*
     * generates pwm with "on" time
     * returns onTime if pThis is not null, -1 otherwise
     */
    int mgos_servo_doTime(Servo* pThis, int onTime);

    /*
     * generates pwm with "on" time
     * and stops after timer milliseconds
     * returns onTime if pThis is not null, -1 otherwise
     */
    int mgos_servo_doTimeWithTimer(Servo* pThis, int onTime, int timer);

    /*
     * generates pwm to move the servo to the specified angle
     * returns angle if pThis is not null, -1 otherwise
     */
    int mgos_servo_doAngle(Servo* pThis, int angle);

    /*
     * generates pwm to move the servo to the specified angle
     * and stops after timer milliseconds
     * returns angle if pThis is not null, -1 otherwise
     */
    int mgos_servo_doAngleWithTimer(Servo* pThis, int angle, int timer);

#ifdef __cplusplus
}
#endif /* __cplusplus */
