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
#define INA3_Pin GPIO_PIN_12
#define INA3_GPIO_Port GPIOB
#define INB3_Pin GPIO_PIN_13
#define INB3_GPIO_Port GPIOB
#define INA4_Pin GPIO_PIN_14
#define INA4_GPIO_Port GPIOB
#define INB4_Pin GPIO_PIN_15
#define INB4_GPIO_Port GPIOB
#define INA1_Pin GPIO_PIN_6
#define INA1_GPIO_Port GPIOC
#define INB1_Pin GPIO_PIN_7
#define INB1_GPIO_Port GPIOC
#define INA2_Pin GPIO_PIN_8
#define INA2_GPIO_Port GPIOC
#define INB2_Pin GPIO_PIN_9
#define INB2_GPIO_Port GPIOC
#define MPTOR1_Pin GPIO_PIN_8
#define MPTOR1_GPIO_Port GPIOA
#define MOTOR2_Pin GPIO_PIN_9
#define MOTOR2_GPIO_Port GPIOA
#define MOTOR3_Pin GPIO_PIN_10
#define MOTOR3_GPIO_Port GPIOA
#define MOTOR4_Pin GPIO_PIN_11
#define MOTOR4_GPIO_Port GPIOA
#define ENCODERE_Pin GPIO_PIN_15
#define ENCODERE_GPIO_Port GPIOA
#define ENCODERF_Pin GPIO_PIN_3
#define ENCODERF_GPIO_Port GPIOB
#define ENCODERG_Pin GPIO_PIN_6
#define ENCODERG_GPIO_Port GPIOB
#define ENCODERH_Pin GPIO_PIN_7
#define ENCODERH_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
