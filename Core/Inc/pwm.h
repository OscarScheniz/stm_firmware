#ifndef __PWM_H
#define __PWM_H

#include <stdint.h>
#include "stm32f3xx_hal.h"

typedef enum 
{
    PWM0, //Motor 0
    PWM1, //Motor 1
    PWM2, //Motor 2
    PWM3, //Motor3
}PWM_PIN;

void pwm_tim2_init(void);
void pwm_tim3_init(void);
void pwm_tim17_init(void);


#endif /* __PWM_H */