#ifndef __TIMERS_H
#define __TIMERS_H

#include "stm32f3xx_hal.h"

#define PWM0_Pin GPIO_PIN_0
#define PWM0_GPIO_Port GPIOA
#define PWM1_Pin GPIO_PIN_1
#define PWM1_GPIO_Port GPIOA
#define PWM2_Pin GPIO_PIN_4
#define PWM2_GPIO_Port GPIOA
#define PWM3_Pin GPIO_PIN_7
#define PWM3_GPIO_Port GPIOA

/** 
* Initializes the Global MSP. 
*/
void HAL_TIM_MspInit(void);

/**
* @brief TIM_PWM MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm);

/**
* @brief TIM_Base MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
void HAL_TIM_BASE_MspInit(TIM_HandleTypeDef* htim_base);


void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);

/**
* @brief TIM_PWM MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_BASE_MspDeInit(TIM_HandleTypeDef* htim_pwm);

/**
* @brief TIM_Base MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
void HAL_TIM_BASE_MspDeInit(TIM_HandleTypeDef* htim_base);

#endif /* __TIMERS_H */