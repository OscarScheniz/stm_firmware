/**
  ******************************************************************************
  * @file           : timers.c
  * @brief          : Timer functionality
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "timers.h"

/**
* Initializes the Global MSP.
*/
void timers_MspInit(void)
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();
}

/**
* @brief TIM_PWM MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void timers_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
    if(htim_pwm->Instance==TIM2)
    {
        /* Peripheral clock enable */
        __HAL_RCC_TIM2_CLK_ENABLE();
    }
    else if(htim_pwm->Instance==TIM3)
    {
        /* Peripheral clock enable */
        __HAL_RCC_TIM3_CLK_ENABLE();
    }
}

/**
* @brief TIM_Base MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
void timers_Base_MspInit(TIM_HandleTypeDef* htim_base)
{
    if(htim_base->Instance==TIM17)
    {
        /* Peripheral clock enable */
        __HAL_RCC_TIM17_CLK_ENABLE();
    }
}

void timers_MspPostInit(TIM_HandleTypeDef* htim)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if(htim->Instance==TIM2)
    {
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**TIM2 GPIO Configuration
        PA0     ------> TIM2_CH1
        PA1     ------> TIM2_CH2
        */
        GPIO_InitStruct.Pin = PWM0_Pin|PWM1_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    }
    else if(htim->Instance==TIM3)
    {
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**TIM3 GPIO Configuration
        PA4     ------> TIM3_CH2
        */
        GPIO_InitStruct.Pin = PWM2_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
        HAL_GPIO_Init(PWM2_GPIO_Port, &GPIO_InitStruct);

    }
    else if(htim->Instance==TIM17)
    {
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**TIM17 GPIO Configuration
        PA7     ------> TIM17_CH1
        */
        GPIO_InitStruct.Pin = PWM3_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF1_TIM17;
        HAL_GPIO_Init(PWM3_GPIO_Port, &GPIO_InitStruct);

    }
}

/**
* @brief TIM_PWM MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void timers_pwm_MspDeInit(TIM_HandleTypeDef* htim_pwm)
{
    if(htim_pwm->Instance==TIM2)
    {
        /* Peripheral clock disable */
        __HAL_RCC_TIM2_CLK_DISABLE();
    }
    else if(htim_pwm->Instance==TIM3)
    {
        /* Peripheral clock disable */
        __HAL_RCC_TIM3_CLK_DISABLE();
    }
}

/**
* @brief TIM_Base MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
void timer_base_MspDeInit(TIM_HandleTypeDef* htim_base)
{
    if(htim_base->Instance==TIM17)
    {
        /* Peripheral clock disable */
        __HAL_RCC_TIM17_CLK_DISABLE();
    }
}