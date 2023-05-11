#ifndef __PSTWO_H
#define __PSTWO_H
#include "usart.h"
#include "tim.h"
#include "delay.h"
#include "motor.h"
#include "engine.h"
#include "stepper.h"

//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+12)   //0x4001080C
#define GPIOB_ODR_Addr    (GPIOB_BASE+12)   //0x40010C0C
#define GPIOC_ODR_Addr    (GPIOC_BASE+12)   //0x4001100C
#define GPIOD_ODR_Addr    (GPIOD_BASE+12)   //0x4001140C
#define GPIOE_ODR_Addr    (GPIOE_BASE+12)   //0x4001180C
#define GPIOF_ODR_Addr    (GPIOF_BASE+12)   //0x40011A0C
#define GPIOG_ODR_Addr    (GPIOG_BASE+12)   //0x40011E0C
#define GPIOA_IDR_Addr    (GPIOA_BASE+8)    //0x40010808
#define GPIOB_IDR_Addr    (GPIOB_BASE+8)    //0x40010C08
#define GPIOC_IDR_Addr    (GPIOC_BASE+8)    //0x40011008
#define GPIOD_IDR_Addr    (GPIOD_BASE+8)    //0x40011408
#define GPIOE_IDR_Addr    (GPIOE_BASE+8)    //0x40011808
#define GPIOF_IDR_Addr    (GPIOF_BASE+8)    //0x40011A08
#define GPIOG_IDR_Addr    (GPIOG_BASE+8)    //0x40011E08
//IO口操作
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)
#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)
#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)
#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)
#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)
#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)
#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)
//IO模式配置
#define DI      PBin(12)            //PB12输入
#define DO_H    PBout(13)=1         //命令位高
#define DO_L    PBout(13)=0         //命令位低
#define CS_H    PBout(14)=1         //CS拉高
#define CS_L    PBout(14)=0         //CS拉低
#define CLK_H   PBout(15)=1         //时钟拉高
#define CLK_L   PBout(15)=0         //时钟拉低
//按键设置
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2          9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      26
//摇杆设置
#define PSS_RX 5
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

extern uint8_t Data[9];
extern uint16_t MASK[16];
extern uint16_t Handkey;

uint8_t PS2_RedLight(void);
void    PS2_ReadData(void);
void    PS2_Cmd(uint8_t CMD);
uint8_t PS2_DataKey(void);
uint8_t PS2_AnologData(uint8_t button);
void    PS2_ClearData(void);
void    PS2_Control(void);

#endif
