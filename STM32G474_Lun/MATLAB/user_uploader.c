/* Includes ------------------------------------------------------------------*/
#include "user_uploader.h"

#include "usart.h"
//Struct_ExtU rtU;
/*板载参数数据管理*/
Struct_Boder_Data Boder_Data={
.O1.adc_value=0,
.O1.offset=2042,
.O1.gain=0,

.O2.adc_value=0,
.O2.offset=2040,
.O2.gain=0,

.O3.adc_value=0,
.O3.offset=1975,
.O3.gain=0,
//.rtU=&rtU,
.Pole =4
};

/*CAN_TX_RX-------------Start---------------------------------------*/
//		HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1,&TxHeader,FDCAN1_TxData);
/*CAN_TX_RX-------------End---------------------------------------*/



/*Plot-------------Start---------------------------------------*/

/*绘折线图上传数据帧*/
Struct_Frame_Data Frame_Data_type={
.fdata={0x00},
.tail={0x00, 0x00, 0x80, 0x7f}
};

void Plot_Data_UpLoad(void)
{
//		Frame_Data_type.fdata[0] = Boder_Data.potentiometer;
//		Frame_Data_type.fdata[1] = Boder_Data.rtU->ia;
//		Frame_Data_type.fdata[2] = Boder_Data.rtU->ib;
//		Frame_Data_type.fdata[3] = Boder_Data.rtU->ic;
//		UART_DMA_Tx((uint8_T*)(&Frame_Data_type),sizeof(Frame_Data_type));
		HAL_UART_Transmit_DMA(&huart3,(uint8_T*)(&Frame_Data_type),sizeof(Frame_Data_type));
}
/*Plot-------------End---------------------------------------*/



 