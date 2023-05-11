#include "delay.h"

void Delay_us( uint32_t cnt)
{
    uint32_t temp;
    SysTick->LOAD = 9* cnt;
    SysTick->VAL=0X00;
    SysTick->CTRL=0X01;
    do
    {
        temp=SysTick->CTRL;
    }while((temp&0x01)&&(!(temp&(1<<16))));
    SysTick->CTRL=0x00; 
    SysTick->VAL =0X00; 
}

void Delay_ms( uint32_t cnt)
{
    uint32_t i=0; 
    for(i=0;i<cnt;i++)
    Delay_us(1000);
}
