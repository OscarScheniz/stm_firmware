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

/**
 * @brief Function initiates the pwm signals for controlling the motors
 * @param None
 * @retval None
 */
void motor_control_init(void);

/**
 * @brief Function starts PWM generation on all timers and channels
 * @param None
 * @retval None
 */
void motor_control_start(void);

/**
 * @brief Function sets the PWM signal so the motors stop.
 * @param None
 * @retval None
 */
void motor_control_stop(void);

/**
 * @brief Function sets the motors to turn left
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_turn_left(uint8_t percentage);

/**
 * @brief Function sets the motors to turn right
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_turn_right(uint8_t percentage);

/**
 * @brief Function sets the motors to go backwards
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_backward(uint8_t percentage);

/**
 * @brief Function sets the motors to go forwards
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_forward(uint8_t percentage);




#endif /* __MOTOR_CONTROL_H */