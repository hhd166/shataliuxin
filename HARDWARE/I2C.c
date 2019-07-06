#include	"I2C.h"


//I2C��ʼ������
//ʹ��STM32��I2C1
void I2C_INIT(void)
{
	 
	I2C_InitTypeDef I2C_InitStructure;
	 
	I2C_INIT_GPIO();
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);											//����I2C1��ʱ��

	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;																//����ģʽΪI2Cģʽ
 	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;                       //����I2Cռ�ձ�
 	I2C_InitStructure.I2C_OwnAddress1 = I2C1_SLAVE_ADDRESS7;									//���ñ���I2C�ĵ�ַ
 	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;															//����I2C��Ӧ����
 	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; //����I2CӦ���ַΪ7λ
 	I2C_InitStructure.I2C_ClockSpeed = 20000;                                  //����I2C����ʱ��Ƶ��
	 
	I2C_Init(I2C1, &I2C_InitStructure);																					//��I2C1���г�ʼ��
	I2C_Cmd(I2C1, ENABLE);   																									//ʹI2C1
}


//ʹ��PB6��PB7��ΪI2C�ӿ�
void I2C_INIT_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);  //����GPIOB��AFIO����ʱ��
		
	/* Configure IO connected to IIC*********************/
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;                	//��I2C1��Ӧ��IO�ڽ��г�ʼ��
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;                          //ע����Ϊ���ÿ�©���
 	 GPIO_Init(GPIOB, &GPIO_InitStructure);
}



/**********************************************************************/
/*IICдһ���ֽ�	         				                              */
/*																	  */
/**********************************************************************/
void I2C_WriteByte(unsigned char id,unsigned char write_address,unsigned char byte)
{	
	I2C_GenerateSTART(I2C1,ENABLE);
	//������ʼ����
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	//�ȴ�ACK����������Ƿ���I2C����
	I2C_Send7bitAddress(I2C1,id,I2C_Direction_Transmitter);
	//��I2C�����ϵĴ��豸����׼��ͨ�ŵ��豸��ַ������ʾҪд����
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	//�ȴ�ACK���ȴ��Ƿ��иõ�ַ��I2C�豸��Ӧ
	I2C_SendData(I2C1, write_address);
	//�Ĵ�����ַ������Ӧ������׼��д�����ݵļĴ����ĵ�ַ
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	//�ȴ�ACK���ȴ����豸��Ӧ
	I2C_SendData(I2C1, byte);
	//�������ݣ�����׼��д��Ĵ���������
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	//������ɣ��ȴ����豸��Ӧ���������ͳɹ�
	I2C_GenerateSTOP(I2C1, ENABLE);
	//���������ź�
}
/**********************************************************************/
/*IIC������	         				                              	  */
/*																	  */
/**********************************************************************/
unsigned char I2C_ReadByte(unsigned char  id, unsigned char read_address)
{
	unsigned char temp; 	
  while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));//�ȴ�I2C���ȴ�I2C���߻ص�����
	
	I2C_GenerateSTART(I2C1, ENABLE);//������ʼ�ź�
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));//EV5���ȴ�ACK
	
	I2C_Send7bitAddress(I2C1, id, I2C_Direction_Transmitter);//����׼��ͨ�ŵĴ��豸��ַ������ʾҪд����
 	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));//EV6���ȴ�ACK
	
 	I2C_Cmd(I2C1, ENABLE);//�������ÿ������EV6
 	I2C_SendData(I2C1, read_address);  //����׼����ȡ�ļĴ����ĵ�ַ
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));//EV8 ���ȴ�ACK
	
	I2C_GenerateSTART(I2C1, ENABLE);//���²�����ʼ�źţ�׼��������
 	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));//EV5
	
 	I2C_Send7bitAddress(I2C1, id, I2C_Direction_Receiver);//����׼����ȡ���豸�ĵ�ַ
 	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));//EV6 
	
  I2C_AcknowledgeConfig(I2C1, DISABLE);//�ر�Ӧ���ֹͣ��������
  while(!(I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED)));//�ȴ����յ�����
	
  temp = I2C_ReceiveData(I2C1);//��ȡ���ܵ�������	
	I2C_GenerateSTOP(I2C1, ENABLE);//������������
	I2C_AcknowledgeConfig(I2C1, ENABLE);//���¿���Ӧ��
	
	return temp;
}
