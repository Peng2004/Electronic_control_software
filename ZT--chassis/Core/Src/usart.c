/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
uint8_t Rx_String[100];
uint8_t Rx_Flag=0;
uint8_t Rx_buff;
uint8_t LEN=0;
/* USER CODE END 0 */

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/* 串口初始化 */
void Usart_init(void)
{
  /* 使能串口接收断 */
  __HAL_UART_ENABLE_IT(&huart2,UART_IT_RXNE);
  __HAL_UART_ENABLE_IT(&huart3,UART_IT_RXNE);
}
/* 重定向printf */
int fputc(int ch, FILE *f)
{
  /* 发送一个字节数据到串口2、3 */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 1000);
  HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 1000);
  return (ch);
}
/* 重定向scanf */
int fgetc(FILE *f)
{
  int ch;
  HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, 1000);
  HAL_UART_Receive(&huart3, (uint8_t *)&ch, 1, 1000);
  return (ch);
}
/* 发送字符串 */
void Usart_SendString(UART_HandleTypeDef *huart,uint8_t *str)
{
  unsigned int k=0;
  do 
  {
      HAL_UART_Transmit(&huart2,(uint8_t *)(str + k) ,1,1000);
      k++;
  } while(*(str + k)!='\0');
  do 
  {
      HAL_UART_Transmit(&huart3,(uint8_t *)(str + k) ,1,1000);
      k++;
  } while(*(str + k)!='\0');
}
/* 串口数据回显 */
void Usart_DataShow(UART_HandleTypeDef *huart)
{
  uint8_t ch=0; 
  if(__HAL_UART_GET_FLAG( &huart2, UART_FLAG_RXNE ) != RESET)
  {
    ch=( uint16_t)READ_REG(huart2.Instance->DR);
    Rx_String[LEN] = ch;
    LEN++;
    WRITE_REG(huart2.Instance->DR,ch); 
  }
  if(__HAL_UART_GET_FLAG( &huart3, UART_FLAG_RXNE ) != RESET)
  {
    ch=( uint16_t)READ_REG(huart3.Instance->DR);
    Rx_String[LEN] = ch;
    LEN++;
    WRITE_REG(huart3.Instance->DR,ch); 
  }
}
/* 串口数据接收 */
int USART_DataReceive(UART_HandleTypeDef *huart)
{
  if(huart == &huart2)
  {
     //接收字符
     Rx_String[Rx_Flag++] = Rx_buff;
     //判断是否接收结束
     if(Rx_String[Rx_Flag-1] == 0x0A)
     {
       //字符串发送
       HAL_UART_Transmit(&huart2, (uint8_t *)&Rx_String, Rx_Flag,0xFFFF);
       //判断发送是否完毕
       while(HAL_UART_GetState(&huart2) == HAL_UART_STATE_BUSY_TX);
       //清空接收字符串
       memset(Rx_String,0x00,sizeof(Rx_buff));
       //清空计数器
       Rx_Flag = 0;
     }
     //再开启接收中断
     HAL_UART_Receive_IT(&huart2, (uint8_t *)&Rx_buff, 1);
  }
  if(huart == &huart3)
  {
     //接收字符
     Rx_String[Rx_Flag++] = Rx_buff;
     //判断是否接收结束
     if(Rx_String[Rx_Flag-1] == 0x0A)
     {
       //字符串发送
       HAL_UART_Transmit(&huart3, (uint8_t *)&Rx_String, Rx_Flag,0xFFFF);
       //判断发送是否完毕
       while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);
       //清空接收字符串
       memset(Rx_String,0x00,sizeof(Rx_buff));
       //清空计数器
       Rx_Flag = 0;
     }
     //再开启接收中断
     HAL_UART_Receive_IT(&huart3, (uint8_t *)&Rx_buff, 1);
  }
  
  return cmd;
}
/* USER CODE END 1 */
