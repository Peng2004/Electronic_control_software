#include "ps2.h"


uint16_t Handkey;
uint8_t  Comd[2]={0x01,0x42};
uint8_t  Data[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint16_t MASK[]=
{
    PSB_SELECT,
    PSB_L3,
    PSB_R3 ,
    PSB_START,
    PSB_PAD_UP,
    PSB_PAD_RIGHT,
    PSB_PAD_DOWN,
    PSB_PAD_LEFT,
    PSB_L2,
    PSB_R2,
    PSB_L1,
    PSB_R1 ,
    PSB_GREEN,
    PSB_RED,
    PSB_BLUE,
    PSB_PINK
};

/* ���ֱ��������� */
void PS2_Cmd(uint8_t CMD)
{
    volatile uint16_t ref=0x01;
    Data[1] = 0;
    for(ref=0x01;ref<0x0100;ref<<=1)
    {
        if(ref&CMD)
        {
            DO_H;
        }
        else DO_L;
        CLK_H;
        Delay_us(50);
        CLK_L;
        Delay_us(50);
        CLK_H;
        if(DI)
            Data[1] = ref|Data[1];
    }
}
/* �жϿ���ģʽ */
uint8_t PS2_RedLight(void)
{
    CS_L;
    PS2_Cmd(Comd[0]);  //��ʼ����
    PS2_Cmd(Comd[1]);  //��������
    CS_H;
    if( Data[1] == 0X73)
        return 0 ;
    else 
        return 1;
}
/* ��ȡ�ֱ����� */
void PS2_ReadData(void)
{
    volatile uint8_t byte=0;
    volatile uint16_t ref=0x01;
    CS_L;
    PS2_Cmd(Comd[0]);  //��ʼ����
    PS2_Cmd(Comd[1]);  //��������
    for(byte=2;byte<9;byte++)          //��ʼ��������
    {
        for(ref=0x01;ref<0x100;ref<<=1)
        {
            CLK_H;
            CLK_L;
            Delay_us(50);
            CLK_H;
            if(DI)
            Data[byte] = ref|Data[byte];
        }
        Delay_us(50);
    }
    CS_H;
}
/* �ֱ����ݴ��� */
uint8_t PS2_DataKey()
{
    uint8_t index;

    PS2_ClearData();
    PS2_ReadData();

    Handkey=(Data[4]<<8)|Data[3];
    for(index=0;index<16;index++)
    {    
        if((Handkey&(1<<(MASK[index]-1)))==0)
        return index+1;
    }
    return 0;
}
/* ҡ��ģ������ȡ */
uint8_t PS2_AnologData(uint8_t button)
{
    return Data[button];
}
/* ������ݻ����� */
void PS2_ClearData()
{
    uint8_t a;
    for(a=0;a<9;a++)
        Data[a]=0x00;
}
/* �ֱ����� */
void PS2_Control(void)
{
    int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;
    PS2_LX = PS2_AnologData(PSS_LX);
    PS2_LY = PS2_AnologData(PSS_LY);
    PS2_RX = PS2_AnologData(PSS_RX);
    PS2_RY = PS2_AnologData(PSS_RY);
    PS2_KEY = PS2_DataKey();
    
    int up,down,left,right,colck,anticolck,stop;
    stop = 0;
    up = 1;
    down = 3;
    left = 2;
    right = 4;
    colck = 5;
    anticolck =6;
    
    Delay_ms(80);
    
    //���ģʽ�������Ƶ���
    if( Data[1] == 0X73)
    {
        printf("���ģʽ\n");
        printf("PS2_LX=%d    ",PS2_LX);
        printf("PS2_LY=%d    ",PS2_LY);
        printf("PS2_RX=%d    ",PS2_RX);
        printf("PS2_RY=%d    ",PS2_RY);
        printf("PS2_KEY=%d    \r\n",PS2_KEY);
        
        switch(PS2_LX)
        {
            //����
            case 0:
                Usart_SendString(&huart3,(uint8_t *)left);
            break;
            //����
            case 255:
                Usart_SendString(&huart3,(uint8_t *)right);
            break;
        }
        switch(PS2_LY)
        {
            //ǰ��
            case 0:
                Usart_SendString(&huart3,(uint8_t *)up);
            break;
            //����
            case 255:
                Usart_SendString(&huart3,(uint8_t *)down);
            break;
        }
        switch(PS2_KEY)
        {
            //ʧ�ܣ���ֹʧ�أ�
            case 0:
                Usart_SendString(&huart3,(uint8_t *)stop);
            break;
            //˳ʱ����ת
            case 2:
                Usart_SendString(&huart3,(uint8_t *)colck);
            break;
            //��ʱ����ת
            case 3:
                Usart_SendString(&huart3,(uint8_t *)anticolck);
            break;
        }
    }
    //�̵�ģʽ���������ϲ�
    else if(Data[1] == 0X41)
    {
        printf("�̵�ģʽ\n");
        printf("PS2_KEY=%d    \r\n",PS2_KEY);
        
        switch(PS2_KEY)
        {
            //ʧ�ܣ���ֹʧ�أ�
            case 0:
            Stepper_Disable();
            break;
            //�����������
            case 5:
            Stepper_UP();
            break;
            //���λ�����ֵ
            case 6:
            Engine_MAX();
            break;
            //�����������
            case 7:
            Stepper_DOWN();
            break;
            //���λ����Сֵ
            case 8:
            Engine_MIN();
            break;
            //����벽���������
            case 13:
            Stepper_UP();
            Engine_UP();
            break;
            //�ſ�
            case 14:
            Motor_AntiExtraction(180);
            break;
            //����벽���������
            case 15:
            Stepper_DOWN();
            Engine_DOWN();
            break;
            //ȡ��
            case 16:
            Motor_Extraction(180);
            break;
        }
    }
}
