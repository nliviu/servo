#include <stdbool.h>

#include <mgos_pwm.h>

bool mgos_servo_init(void) {
    return mgos_pwm_init();
}
