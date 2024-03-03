#include "svpwm_clarke_park.h"

#ifdef __cplusplus
extern "C"
{
#endif    
	

//////#define  CONSTANT_Tpwm   												(8000) //与定时器计数最大值相同
//////svpwm_Typedef motor_svpwm={
//////.Tpwm=CONSTANT_Tpwm,
//////.Udc=24,
//////};
//////	



	
//Clarke变换
void clarke_calc(clarke_park *v)
{ 
	v->Alpha = (v->As - (v->Bs + v->Cs) * 0.5F) * 2.0F / 3.0F;//等幅值变换
  v->Beta = (v->Bs - v->Cs) * 0.866025388F * 2.0F / 3.0F;//0.866025388F==sqrt(3)/2
}
//反变换
void iclarke_calc(clarke_park *iv)
{ 
     iv->As = iv->Alpha;
     iv->Bs = 0.5f* ( 1.732050808F*iv->Beta - iv->Alpha);
     iv->Cs =  -(iv->As + iv->Bs);
}
//Clarke变换End 


//Park变换
void park_calc(clarke_park *v)
{
//	float Cosine,Sine;
//	Sine = sin(v->Angle);
//	Cosine = cos(v->Angle);  
	v->Ds = v->Alpha * v->Cosine + v->Beta * v->Sine;
	v->Qs = - v->Alpha * v->Sine + v->Beta *v->Cosine;
}
void ipark_calc(clarke_park *v)
{
//	float Cosine,Sine;
//	Sine = sin(v->Angle);
//	Cosine = cos(v->Angle); 
	v->Alpha = v->Cosine * v->Ds - v->Sine * v->Qs;
	v->Beta  = v->Sine * v->Ds + v->Cosine * v->Qs;
}
//Park变换 
////给定DS,QS,Angle 输出波形::VQs,VDs Max is Udc*2/3;
//给定Alpha,Beta 输出波形::VQs,VDs Max is Udc*2/3;
void svpwm_calc(svpwm_Typedef* v)
{
  float T1;
  float T1_tmp;
  float rtb_ualpha;
  float rtb_ubeta;   
	//反Park变换
//	T1 = sin(v->p_clarke_park.Angle);
//  rtb_ubeta = cos(v->p_clarke_park.Angle);
//	T1=v->p_clarke_park.Sine;
//	rtb_ubeta=v->p_clarke_park.Cosine;
//  rtb_ualpha = (float)v->p_clarke_park.Ds * rtb_ubeta - (float)v->p_clarke_park.Qs * T1;
//  rtb_ubeta = (float)v->p_clarke_park.Ds * T1 + (float)v->p_clarke_park.Qs * rtb_ubeta; 
	
  rtb_ualpha = (float)v->p_clarke_park.Alpha;
  rtb_ubeta = (float)v->p_clarke_park.Beta ;
	
	T1_tmp=1.73205078F * rtb_ualpha;
  v->VecSector =  
		(( rtb_ubeta+T1_tmp < 0.0F )<<2)+
		(( T1_tmp > rtb_ubeta)<<1)+
		(  rtb_ubeta > 0.0F); 
 														
	T1_tmp = v->Tpwm / v->Udc;
  switch (v->VecSector) {
   case 1:
    T1 = (-1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * T1_tmp;
    rtb_ualpha = (1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * T1_tmp;
    break;

   case 2:
    T1 = (1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * (T1_tmp);
    rtb_ualpha = -(1.73205078F * rtb_ubeta * T1_tmp);
    break;

   case 3:
    T1 = -((-1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * (T1_tmp));
    rtb_ualpha = 1.73205078F * rtb_ubeta * T1_tmp;
    break;

   case 4:
    T1 = -(1.73205078F * rtb_ubeta * T1_tmp);
    rtb_ualpha = (-1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * (T1_tmp);
    break;

   case 5:
    T1 = 1.73205078F * rtb_ubeta * T1_tmp;
    rtb_ualpha = -((1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * (T1_tmp));
    break;

   default:
    T1 = -((1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * (T1_tmp));
    rtb_ualpha = -((-1.5F * rtb_ualpha + 0.866025388F * rtb_ubeta) * (T1_tmp));
    break;
  }

  rtb_ubeta = T1 + rtb_ualpha;
  if (rtb_ubeta > v->Tpwm) {
    T1 /= rtb_ubeta;
    rtb_ualpha /= T1 + rtb_ualpha;
  }

  rtb_ubeta = (v->Tpwm - (T1 + rtb_ualpha)) / 4.0F;
  T1 = T1 / 2.0F + rtb_ubeta;
  switch (v->VecSector) {
   case 1: 
    v->Tcmp1 = T1; 
    v->Tcmp2 = rtb_ubeta; 
    v->Tcmp3 = rtb_ualpha / 2.0F + T1;
    break;

   case 2: 
    v->Tcmp1 = rtb_ubeta; 
    v->Tcmp2 = rtb_ualpha / 2.0F + T1; 
    v->Tcmp3 = T1;
    break;

   case 3: 
    v->Tcmp1 = rtb_ubeta; 
    v->Tcmp2 = T1; 
    v->Tcmp3 = rtb_ualpha / 2.0F + T1;
    break;

   case 4: 
    v->Tcmp1 = rtb_ualpha / 2.0F + T1; 
    v->Tcmp2 = T1; 
    v->Tcmp3 = rtb_ubeta;
    break;

   case 5: 
    v->Tcmp1 = rtb_ualpha / 2.0F + T1; 
    v->Tcmp2 = rtb_ubeta; 
    v->Tcmp3 = T1;
    break;

   case 6: 
    v->Tcmp1 = T1; 
    v->Tcmp2 = rtb_ualpha / 2.0F + T1; 
    v->Tcmp3 = rtb_ubeta;
    break;
  }
}
//零序注入SPWM
void SVPWM(float rtu_Valpha, float rtu_Vbeta, float rtu_v_bus,
                  float rty_tABC[3])
{
  float rtb_Min;
  float rtb_Sum1_j;
  float rtb_Sum_p;
 
  rtb_Min = -0.5F * rtu_Valpha;
 
  rtb_Sum1_j = 0.866025388F * rtu_Vbeta;
 
  rtb_Sum_p = rtb_Min + rtb_Sum1_j;
 
  rtb_Sum1_j = rtb_Min - rtb_Sum1_j;
  
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_p), rtb_Sum1_j) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_p), rtb_Sum1_j)) * -0.5F;
 
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_p;
  rty_tABC[2] = rtb_Min + rtb_Sum1_j;
  
  rty_tABC[0] = (-rty_tABC[0] / rtu_v_bus + 0.5F) * CONSTANT_Tpwm;
  rty_tABC[1] = (-rty_tABC[1] / rtu_v_bus + 0.5F) * CONSTANT_Tpwm;
  rty_tABC[2] = (-rty_tABC[2] / rtu_v_bus + 0.5F) * CONSTANT_Tpwm;
}
#ifdef __cplusplus
}
#endif
