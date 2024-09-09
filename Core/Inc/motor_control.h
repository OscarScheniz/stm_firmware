#ifndef __MOTOR_CONTROL_H
#define __MOTOR_CONTROL_H

#include <stdint.h>
#include "stm32f3xx_hal.h"

typedef enum 
{
    Motor_0,
    Motor_1,
    Motor_2,
    Motor_3
}MOTOR;

void motor_control_init(void);


#endif /* __MOTOR_CONTROL_H */