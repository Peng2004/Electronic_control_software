/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENCODERA_Pin GPIO_PIN_0
#define ENCODERA_GPIO_Port GPIOA
#define ENCODERB_Pin GPIO_PIN_1
#define ENCODERB_GPIO_Port GPIOA
#define ENCODERC_Pin GPIO_PIN_6
#define ENCODERC_GPIO_Port GPIOA
#define ENCODERD_Pin GPIO_PIN_7
#define ENCODERD_GPIO_Port GPIOA
#define ENA_Pin GPIO_PIN_10
#define ENA_GPIO_Port GPIOB
#define DIR_Pin GPIO_PIN_11
#define DIR_GPIO_Port GPIOB
#define DATA_Pin GPIO_PIN_12
#define DATA_GPIO_Port GPIOB
#define CMD_Pin GPIO_PIN_13
#define CMD_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_14
#define CS_GPIO_Port GPIOB
#define CLK_Pin GPIO_PIN_15
#define CLK_GPIO_Port GPIOB
#define MOTOR1_Pin GPIO_PIN_8
#define MOTOR1_GPIO_Port GPIOC
#define MOTOR2_Pin GPIO_PIN_9
#define MOTOR2_GPIO_Port GPIOC
#define ENGINE_Pin GPIO_PIN_11
#define ENGINE_GPIO_Port GPIOA
#define STEPPER_Pin GPIO_PIN_3
#define STEPPER_GPIO_Port GPIOB
#define INT1_Pin GPIO_PIN_4
#define INT1_GPIO_Port GPIOB
#define INT2_Pin GPIO_PIN_5
#define INT2_GPIO_Port GPIOB
#define INT3_Pin GPIO_PIN_6
#define INT3_GPIO_Port GPIOB
#define INT4_Pin GPIO_PIN_7
#define INT4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
