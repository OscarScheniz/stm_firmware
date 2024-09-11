/**
  ******************************************************************************
  * @file           : motor_control.c
  * @brief          : Motor controller
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

#include "motor_control.h"
#include "timers.h"
#include "error_handling.h"
#include "SEGGER_RTT.h"

#define PWM_PULSE_MIN     1050 //Full reverse
#define PWM_PULSE_NEUTRAL 1500 //Neutral
#define PWM_PULSE_MAX     1950 //Full forward
#define PWM_PRESCALER			7
#define PWM_PERIOD				20000

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim17;

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void pwm_tim2_init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = PWM_PRESCALER;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = PWM_PERIOD;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = PWM_PULSE_NEUTRAL;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_TIM_MspPostInit(&htim2);
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void pwm_tim3_init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = PWM_PRESCALER;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = PWM_PERIOD;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = PWM_PULSE_NEUTRAL;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_TIM_MspPostInit(&htim3);
}

/**
  * @brief TIM17 Initialization Function
  * @param None
  * @retval None
  */
static void pwm_tim17_init(void)
{
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  htim17.Instance = TIM17;
  htim17.Init.Prescaler = PWM_PRESCALER;
  htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim17.Init.Period = PWM_PERIOD;
  htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim17.Init.RepetitionCounter = 0;
  htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim17) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim17) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = PWM_PULSE_NEUTRAL;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim17, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim17, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_TIM_MspPostInit(&htim17);
}

/**
 * @brief Function takes in desired motor to control and percentage of motor speed.
 * @param MOTOR motor - motor to apply speed to
 * @param int8_t percentage - Percentage of speed: -100 (full reverse) 100 (full forward)
 * @retval None
 */
static void motor_control_set(MOTOR motor, int8_t percentage)
{
  if (percentage < -100)
  {
      percentage = -100;
  }
  else if (percentage > 100)
  {
    percentage = 100;
  }
  
  uint32_t pwm_value = PWM_PULSE_MIN + ((percentage + 100) * (PWM_PULSE_MAX - PWM_PULSE_MIN)) / 200;
	//SEGGER_RTT_printf(0, "PWM:%d\n", pwm_value);

  switch(motor)
  {
    case FRONT_LEFT:
    	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pwm_value);
    break;

    case FRONT_RIGHT:
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pwm_value);
    break;

    case REAR_LEFT:
      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pwm_value);
    break;

    case REAR_RIGHT:
      __HAL_TIM_SET_COMPARE(&htim17, TIM_CHANNEL_1, pwm_value);
    break;
  }
}

/**
 * @brief Function sets the motors to go forwards
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_forward(uint8_t percentage)
{
  motor_control_set(FRONT_RIGHT, percentage);
  motor_control_set(FRONT_LEFT, percentage);
  motor_control_set(REAR_RIGHT, percentage);
  motor_control_set(REAR_LEFT, percentage);
}

/**
 * @brief Function sets the motors to go backwards
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_backward(uint8_t percentage)
{
  int8_t converted_percent = percentage * -1;

  motor_control_set(FRONT_RIGHT, converted_percent);
  motor_control_set(FRONT_LEFT, converted_percent);
  motor_control_set(REAR_RIGHT, converted_percent);
  motor_control_set(REAR_LEFT, converted_percent);
}

/**
 * @brief Function sets the motors to turn right
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_turn_right(uint8_t percentage)
{
  motor_control_set(FRONT_RIGHT, percentage * 0.5);
  motor_control_set(FRONT_LEFT, percentage);
  motor_control_set(REAR_RIGHT, percentage * 0.5);
  motor_control_set(REAR_LEFT, percentage);
}

/**
 * @brief Function sets the motors to turn left
 * @param int8_t percentage - Speed of the motors (0-100)
 * @retval None
 */
void motor_control_turn_left(uint8_t percentage)
{
  motor_control_set(FRONT_RIGHT, percentage);
  motor_control_set(FRONT_LEFT, percentage * 0.5);
  motor_control_set(REAR_RIGHT, percentage);
  motor_control_set(REAR_LEFT, percentage * 0.5 );
}

/**
 * @brief Function sets the PWM signal so the motors stop.
 * @param None
 * @retval None
 */
void motor_control_stop(void)
{
  motor_control_set(FRONT_LEFT, 0);
  motor_control_set(FRONT_RIGHT, 0);
  motor_control_set(REAR_LEFT, 0);
  motor_control_set(REAR_RIGHT, 0);
	log_info("PWM Signals Stopped\n");
}

/**
 * @brief Function starts PWM generation on all timers and channels
 * @param None
 * @retval None
 */
void motor_control_start(void)
{
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
	log_info("PWM Signals Started\n");
}

/**
 * @brief Function initiates the pwm signals for controlling the motors
 * @param None
 * @retval None
 */
void motor_control_init(void)
{
  pwm_tim2_init();
  pwm_tim3_init();
  pwm_tim17_init();
	log_info("PWM Signals Initiated\n");
}
