#ifndef __SVPWM_H
#define __SVPWM_H

/* =================================================================================
File name:       __SVPWM_H.H  
===================================================================================*/

#include "math.h"
#include "user_uploader.h"

//Clarke

typedef struct
{
     float  As;
     float  Bs;
     float  Cs;
//Clanke变换:				Input [As,Bs] 					 -->  Output [Alpha,Beta]
     float  Alpha;
     float  Beta; 
	
     float  Angle;

//Park变换:					Input [Alpha,Beta,Angle] -->  Output [Ds,Qs]
     float  Ds;
     float  Qs;
		 float Cosine,Sine;
} clarke_park;
void clarke_calc(clarke_park *v);
//反变换
void iclarke_calc(clarke_park *iv);

//Park变换
void park_calc(clarke_park *v);
//反变换
void ipark_calc(clarke_park *v);
//park变换End



//SVPWM   
//Park变换:					Input [Alpha,Beta,Angle] -->  Output [Tcmp1,Tcmp2,Tcmp3] 
typedef struct{         
		unsigned int  Tpwm;
		float  Udc;
    clarke_park p_clarke_park;
    float  Tcmp1;                // Output: reference phase-a switching function
    float  Tcmp2;                // Output: reference phase-b switching function
    float  Tcmp3;                // Output: reference phase-c switching function
    int VecSector;       // Space vector sector
}svpwm_Typedef; 
 
/*-----------------------------------------------------------------------------
Default initalizer for the SVGEN object.
-----------------------------------------------------------------------------*/                     
#define SVGEN_DEFAULTS { 0,0,0,0,0,0,0}    
/*------------------------------------------------------------------------------
    Space Vector  Generator (SVGEN) Macro Definition
------------------------------------------------------------------------------*/
void svpwm_calc(svpwm_Typedef* v);

void SVPWM(float Valpha, float Vbeta, float v_bus,
                  float pwmABC[3]);
#endif

