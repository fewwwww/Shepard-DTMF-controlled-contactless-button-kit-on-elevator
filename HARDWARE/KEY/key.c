#include "key.h"
#include "delay.h"

 	    
//������ʼ������ 
//PB5��PB6 ���ó�����
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTBʱ��

	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;//PB12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB5
	

	
} 
//������������
//���ذ���ֵ

u8 KEY_Scan()
{	 
 
	if(KEY0==0)
	{
		//delay_ms(10);//ȥ���� 
		Delay_ms(10);

		if(KEY0==0)
		while(KEY0==0);
		return KEY0_PRES;
	}     
	return 0;// �ް�������
}