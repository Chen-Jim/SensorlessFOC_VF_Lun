#ifndef __USER_UPLOADER_H__
#define __USER_UPLOADER_H__

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------CONSTANT DATA START ----------------- */
#define  CONSTANT_PI 													  (3.1415926f)
#define  CONSTANT_2_PI 													(6.2831853f)
#define  CONSTANT_PI_DIV3 											(1.0471975f)
#define  CONSTANT_2_PI_DIV3 										(2.0943951f)

//����������ã����裬��У�������
#define RS_PARAMETER     0.59f           //����
#define LS_PARAMETER     0.001f          //���
#define FLUX_PARAMETER   0.01150f        //����
	

#define	 PHASE_SHIFT_ANGLE_60								  	((float)(CONSTANT_PI_DIV3)) //������
#define	 PHASE_SHIFT_ANGLE_120									((float)(CONSTANT_2_PI_DIV3))
	
#define  PWM_TIM_FREQ      										  (10000)//HZ
#define  CONSTANT_Ts   												  (1.0f/PWM_TIM_FREQ)
#define  CONSTANT_Tpwm   												(8000-1) //�붨ʱ���������ֵ��ͬ


/*-----------------CONSTANT DATA End ----------------- */

/*-----------------USER DATA START ----------------- */
//�����˲����Ľ�ֹƵ��	
#define  DEF_USER_FILTER_Fc 										 (100.0f)
#define  DEF_ADC_COUNT 													 (10)
/*-----------------USER DATA End ----------------- */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "rtwtypes.h" 
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
	
  real32_T ia_last;                         /* '<Root>/ia' */
  real32_T ib_last;                         /* '<Root>/ib' */
  real32_T ic_last;                         /* '<Root>/ic' */
	
	
  real32_T Speed_ref;                  /* '<Root>/Speed_ref' */
  real32_T MotorOnOff;                 /* '<Root>/MotorOnOff' */
  real32_T VDC;                        /* '<Root>/VDC' */
} Struct_ExtU;

typedef struct {
	uint16_T adc_value;
  uint16_T offset;
	float gain;
} Struct_OPAMP;

typedef struct
{
	//HALL_Type(0) 0:120,1:60
	uint8_T  State;//Check HAll Type(bit2),Speed_dir(bit1),HALL_Type(bit0)
	uint16_T HallReadTemp;//hall 3bit��cba
	uint16_T _HallReadTemp;//hall 3bit��cba
}HALL_Sensor;

typedef struct {
	uint16_T Vbus;//��Դadcֵ
	float Vbus_V;//��Դ��ѹ
	float potentiometer;//��λ��adcֵ
	float Temperature;
	uint8_T ADC_offset;//ADC�Ƿ��Ѿ�У׼
	Struct_OPAMP O1,O2,O3;//����Ŵ���
	
  Struct_ExtU *rtU;
	uint8_T Pole;//���������
	 
	HALL_Sensor Hall;//���������� 
	
	float Theta;//��Ƕ�
	float TheataAdd;//��Ƕ� ���ٶ�
	float Speed;//��Ƕ� �ٶ�
	float Speed_Last;//��һ���ٶ�,��������ٶ�
	float Speed_Integral;//�ٶȻ��� integral

} Struct_Boder_Data;

extern Struct_Boder_Data Boder_Data; 






/*Plot-------------Start---------------------------------------*/
#define CH_COUNT 7
typedef struct{
	float fdata[CH_COUNT];//��ͼ������
	unsigned char tail[4];//����֡β
}Struct_Frame_Data;

extern Struct_Frame_Data Frame_Data_type;

void Plot_Data_UpLoad(void);
/*Plot-------------End---------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif /* __USER_FDCAN_H__ */
