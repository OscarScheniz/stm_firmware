#ifndef __MOTOR_CONTROL_H
#define __MOTOR_CONTROL_H

#include <stdint.h>
#include "stm32f3xx_hal.h"

typedef enum 
{
    FRONT_LEFT,
    FRONT_RIGHT,
    REAR_LEFT,
    REAR_RIGHT
}MOTOR;

void motor_control_init(void);
void motor_control_start(void);


#endif /* __MOTOR_CONTROL_H */