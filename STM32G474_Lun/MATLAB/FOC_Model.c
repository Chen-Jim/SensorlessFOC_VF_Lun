/*
 * File: FOC_Model.c
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 3.181
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Feb 29 20:09:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FOC_Model.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#include <stddef.h>

/* Named constants for Chart: '<S1>/Chart1' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define IN_ThetaAlign                  ((uint8_T)5U)
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Exported block signals */
real32_T ialpha;                       /* '<S1>/Clark' */
real32_T ibeta;                        /* '<S1>/Clark' */
real32_T ualpha;                       /* '<S1>/In_park' */
real32_T ubeta;                        /* '<S1>/In_park' */
real32_T state;                        /* '<S1>/Chart1' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
curr_kpki_type curr_kpki = {
  /* curr_d_ki */
  35.0F,

  /* curr_d_kp */
  0.17F
};

spd_kpki_type spd_kpki = {
  /* spd_ki */
  0.0144F,

  /* spd_kp */
  0.3389F
};

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
static void Clark(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic, real32_T
                  *rty_ialpha, real32_T *rty_ibeta);
static void In_park(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta_sin,
                    real32_T rtu_theta_cos, real32_T *rty_ualpha, real32_T
                    *rty_ubeta);
static void Park(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T rtu_theta_sin,
                 real32_T rtu_theta_cos, real32_T *rty_id, real32_T *rty_iq);
static void rate_scheduler(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Output and update for atomic system: '<S1>/Clark' */
static void Clark(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic, real32_T
                  *rty_ialpha, real32_T *rty_ibeta)
{
  /* Sum: '<S3>/Add1' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Sum: '<S3>/Add'
   */
  *rty_ialpha = 0.666666687F * rtu_ia - (rtu_ib + rtu_ic) * 0.333333343F;

  /* Gain: '<S3>/Gain2' incorporates:
   *  Sum: '<S3>/Add2'
   */
  *rty_ibeta = (rtu_ib - rtu_ic) * 0.577350259F;
}

/* Output and update for atomic system: '<S1>/In_park' */
static void In_park(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta_sin,
                    real32_T rtu_theta_cos, real32_T *rty_ualpha, real32_T
                    *rty_ubeta)
{
  /* Sum: '<S11>/Add' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   */
  *rty_ualpha = rtu_ud * rtu_theta_cos - rtu_uq * rtu_theta_sin;

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   */
  *rty_ubeta = rtu_ud * rtu_theta_sin + rtu_uq * rtu_theta_cos;
}

/* Output and update for atomic system: '<S1>/Park' */
static void Park(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T rtu_theta_sin,
                 real32_T rtu_theta_cos, real32_T *rty_id, real32_T *rty_iq)
{
  /* Sum: '<S13>/Add' incorporates:
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product1'
   */
  *rty_id = rtu_ialpha * rtu_theta_cos + rtu_ibeta * rtu_theta_sin;

  /* Sum: '<S13>/Add1' incorporates:
   *  Product: '<S13>/Product2'
   *  Product: '<S13>/Product3'
   */
  *rty_iq = rtu_ibeta * rtu_theta_cos - rtu_ialpha * rtu_theta_sin;
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void FOC_Model_step(void)
{
  int32_T VecSector;
  real32_T rtb_Add5;
  real32_T rtb_Cos;
  real32_T rtb_DeadZone;
  real32_T rtb_DeadZone_f;
  real32_T rtb_DeadZone_h;
  real32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_Gain;
  real32_T rtb_Gain2;
  real32_T rtb_Gain4;
  real32_T rtb_Gain8;
  real32_T rtb_Gain_p;
  real32_T rtb_IProdOut;
  real32_T rtb_Product1_a;
  real32_T rtb_RateTransition;
  real32_T rtb_Saturation_n;
  real32_T rtb_Sin;
  int16_T rtb_IProdOut_p;
  int8_T rtb_Gain_l;
  int8_T rtb_RateTransition_0;

  /* Outputs for Atomic SubSystem: '<S1>/Clark' */
  /* SignalConversion generated from: '<S1>/Clark' incorporates:
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   */
  Clark(rtU.ia, rtU.ib, rtU.ic, &ialpha, &ibeta);

  /* End of Outputs for SubSystem: '<S1>/Clark' */

  /* Chart: '<S1>/Chart1' incorporates:
   *  Inport: '<Root>/MotorOnOff'
   */
  if (rtDW.temporalCounter_i1 < 16383U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c7_FOC_Model == 0U) {
    rtDW.is_active_c7_FOC_Model = 1U;
    rtDW.is_c7_FOC_Model = IN_IDLE;
  } else {
    switch (rtDW.is_c7_FOC_Model) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 100) {
        rtDW.is_c7_FOC_Model = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.ZReset = 0.0F;
        rtDW.cnt = 0.0F;
      } else if (rtU.MotorOnOff == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
      } else {
        state = 2.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;

     case IN_IDLE:
      if (rtU.MotorOnOff == 1.0F) {
        rtDW.is_c7_FOC_Model = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        state = 1.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;

     case IN_OpenStage:
      if (rtU.MotorOnOff == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 10000) {
        rtDW.is_c7_FOC_Model = IN_ThetaAlign;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        if (rtDW.cnt == 1.0F) {
          rtDW.ZReset = 1.0F;
        }

        rtDW.cnt = 1.0F;
        state = 3.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;

     case IN_RunStage:
      if (rtU.MotorOnOff == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
      } else {
        state = 5.0F;
        rtDW.RestsSingal = 1.0;
      }
      break;

     default:
      /* case IN_ThetaAlign: */
      if (rtDW.temporalCounter_i1 >= 10) {
        rtDW.is_c7_FOC_Model = IN_RunStage;
      } else {
        state = 4.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart1' */

  /* RateTransition: '<S1>/Rate Transition3' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */

  /* SwitchCase: '<S1>/Switch Case1' */
  switch ((int32_T)state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/theta_fd'
     */
    rtDW.Merge = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  SignalConversion generated from: '<S4>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S5>/Constant'
     *  SignalConversion generated from: '<S5>/theta_fd'
     */
    rtDW.Merge = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S5>/Constant1'
     *  SignalConversion generated from: '<S5>/iq_ref'
     */
    rtDW.Merge1 = 3.0F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    if ((rtDW.ZReset > 0.0F) && (rtDW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      rtDW.DiscreteTimeIntegrator_DSTATE_b = 0.0F;
    }

    rtb_DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE_b;

    /* End of DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */

    /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */
    if ((rtDW.ZReset > 0.0F) && (rtDW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
      rtDW.DiscreteTimeIntegrator1_DSTAT_j = 0.0F;
    }

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S6>/Constant'
     *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
     *  Math: '<S6>/Mod'
     */
    rtDW.Merge = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTAT_j, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S6>/Constant2'
     *  SignalConversion generated from: '<S6>/iq_ref'
     */
    rtDW.Merge1 = 3.0F;

    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_b += 0.0134041291F;
    if (rtDW.ZReset > 0.0F) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 1;
    } else if (rtDW.ZReset < 0.0F) {
      rtDW.DiscreteTimeIntegrator_PrevRese = -1;
    } else if (rtDW.ZReset == 0.0F) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 0;
    } else {
      rtDW.DiscreteTimeIntegrator_PrevRese = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTAT_j += 0.0001F * rtb_DiscreteTimeIntegrator;
    if (rtDW.ZReset > 0.0F) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 1;
    } else if (rtDW.ZReset < 0.0F) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = -1;
    } else if (rtDW.ZReset == 0.0F) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 0;
    } else {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */
    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
     *  Math: '<S8>/Mod'
     *  SignalConversion generated from: '<S8>/Theta_fd'
     */
    rtDW.Merge = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Constant: '<S8>/Constant4'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator2'
     *  Product: '<S8>/Product1'
     *  Sum: '<S8>/Add4'
     */
    rtDW.Merge1 = 1.0F - rtDW.DiscreteTimeIntegrator2_DSTATE * 0.7F;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0134041291F;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S8>/Constant5'
     */
    rtDW.DiscreteTimeIntegrator2_DSTATE += 1.0E-6F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/theta_Close'
     *  UnitDelay: '<S1>/Unit Delay1'
     */
    rtDW.Merge = rtDW.UnitDelay1_DSTATE;

    /* Merge: '<S1>/Merge1' incorporates:
     *  SignalConversion generated from: '<S7>/iq_CloseRef'
     */
    rtDW.Merge1 = rtDW.RateTransition3;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case1' */

  /* Trigonometry: '<S1>/Sin' */
  rtb_Sin = sinf(rtDW.Merge);

  /* Trigonometry: '<S1>/Cos' */
  rtb_Cos = cosf(rtDW.Merge);

  /* Outputs for Atomic SubSystem: '<S1>/Park' */
  Park(ialpha, ibeta, rtb_Sin, rtb_Cos, &rtb_Add5, &rtb_Gain_p);

  /* End of Outputs for SubSystem: '<S1>/Park' */

  /* Sum: '<S15>/Sum1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_DiscreteTimeIntegrator = 0.0F - rtb_Add5;

  /* Sum: '<S167>/Sum' incorporates:
   *  Constant: '<S15>/Constant3'
   *  Constant: '<S1>/Constant1'
   *  DiscreteIntegrator: '<S158>/Integrator'
   *  Product: '<S163>/PProd Out'
   *  Sum: '<S15>/Sum1'
   */
  rtb_DeadZone = (0.0F - rtb_Add5) * curr_kpki.curr_d_kp + (real32_T)
    rtDW.Integrator_DSTATE_fq * 0.0001F;

  /* Sum: '<S15>/Sum7' */
  rtb_IProdOut = rtDW.Merge1 - rtb_Gain_p;

  /* Sum: '<S217>/Sum' incorporates:
   *  Constant: '<S15>/Constant1'
   *  DiscreteIntegrator: '<S208>/Integrator'
   *  Product: '<S213>/PProd Out'
   */
  rtb_DeadZone_h = rtb_IProdOut * 0.6F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S165>/Saturation' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_Add5 = 12.4707661F;
  } else if (rtb_DeadZone < -12.4707661F) {
    rtb_Add5 = -12.4707661F;
  } else {
    rtb_Add5 = rtb_DeadZone;
  }

  /* End of Saturate: '<S165>/Saturation' */

  /* Saturate: '<S215>/Saturation' */
  if (rtb_DeadZone_h > 12.4707661F) {
    rtb_Gain_p = 12.4707661F;
  } else if (rtb_DeadZone_h < -12.4707661F) {
    rtb_Gain_p = -12.4707661F;
  } else {
    rtb_Gain_p = rtb_DeadZone_h;
  }

  /* End of Saturate: '<S215>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S1>/In_park' */
  /* SignalConversion generated from: '<S1>/In_park' */
  In_park(rtb_Add5, rtb_Gain_p, rtb_Sin, rtb_Cos, &ualpha, &ubeta);

  /* End of Outputs for SubSystem: '<S1>/In_park' */

	
	
	
	
	
	
  /* Outport: '<Root>/Tcmp1' incorporates:
   *  MATLAB Function: '<S1>/svpwm2'
   */
  rtY.Tcmp1 = 0.0F;

  /* Outport: '<Root>/Tcmp2' incorporates:
   *  MATLAB Function: '<S1>/svpwm2'
   */
  rtY.Tcmp2 = 0.0F;

  /* Outport: '<Root>/Tcmp3' incorporates:
   *  MATLAB Function: '<S1>/svpwm2'
   */
  rtY.Tcmp3 = 0.0F;

  /* MATLAB Function: '<S1>/svpwm2' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Inport: '<Root>/VDC'
   */
  rtb_Cos = 1.73205078F * ualpha;
  VecSector = (((ubeta + rtb_Cos < 0.0F) << 2) + ((rtb_Cos > ubeta) << 1)) +
    (ubeta > 0.0F);
  rtb_Cos = 16000.0F / rtU.VDC;
  switch (VecSector) {
   case 1:
    rtb_Sin = (-1.5F * ualpha + 0.866025388F * ubeta) * rtb_Cos;
    rtb_Cos *= 1.5F * ualpha + 0.866025388F * ubeta;
    break;

   case 2:
    rtb_Sin = (1.5F * ualpha + 0.866025388F * ubeta) * rtb_Cos;
    rtb_Cos = -(1.73205078F * ubeta * rtb_Cos);
    break;

   case 3:
    rtb_Sin = -((-1.5F * ualpha + 0.866025388F * ubeta) * rtb_Cos);
    rtb_Cos *= 1.73205078F * ubeta;
    break;

   case 4:
    rtb_Sin = -(1.73205078F * ubeta * rtb_Cos);
    rtb_Cos *= -1.5F * ualpha + 0.866025388F * ubeta;
    break;

   case 5:
    rtb_Sin = 1.73205078F * ubeta * rtb_Cos;
    rtb_Cos = -((1.5F * ualpha + 0.866025388F * ubeta) * rtb_Cos);
    break;

   default:
    rtb_Sin = -((1.5F * ualpha + 0.866025388F * ubeta) * rtb_Cos);
    rtb_Cos = -((-1.5F * ualpha + 0.866025388F * ubeta) * rtb_Cos);
    break;
  }

  rtb_DeadZone_f = rtb_Sin + rtb_Cos;
  if (rtb_DeadZone_f > 16000.0F) {
    rtb_Sin /= rtb_DeadZone_f;
    rtb_Cos /= rtb_Sin + rtb_Cos;
  }

  rtb_DeadZone_f = (16000.0F - (rtb_Sin + rtb_Cos)) / 4.0F;
  rtb_Sin = rtb_Sin / 2.0F + rtb_DeadZone_f;
  switch (VecSector) {
   case 1:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Sin;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_DeadZone_f;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Cos / 2.0F + rtb_Sin;
    break;

   case 2:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_DeadZone_f;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Cos / 2.0F + rtb_Sin;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Sin;
    break;

   case 3:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_DeadZone_f;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Sin;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Cos / 2.0F + rtb_Sin;
    break;

   case 4:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Cos / 2.0F + rtb_Sin;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Sin;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_DeadZone_f;
    break;

   case 5:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Cos / 2.0F + rtb_Sin;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_DeadZone_f;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Sin;
    break;

   case 6:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Sin;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Cos / 2.0F + rtb_Sin;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_DeadZone_f;
    break;
  }

  /* Math: '<S20>/Mod' incorporates:
   *  Constant: '<S20>/Constant'
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
   */
  rtb_Sin = rt_modf_snf(rtDW.DiscreteTimeIntegrator_DSTATE, 6.28318548F);

  /* Sum: '<S20>/Add5' incorporates:
   *  Product: '<S20>/Product'
   *  Product: '<S20>/Product1'
   *  Trigonometry: '<S20>/Cos'
   *  Trigonometry: '<S20>/Sin'
   *  UnitDelay: '<S19>/Unit Delay1'
   *  UnitDelay: '<S19>/Unit Delay5'
   */
  rtb_Cos = (0.0F - rtDW.UnitDelay1_DSTATE_a * cosf(rtb_Sin)) - sinf(rtb_Sin) *
    rtDW.UnitDelay5_DSTATE;

  /* Sum: '<S64>/Sum' incorporates:
   *  DiscreteIntegrator: '<S55>/Integrator'
   *  Gain: '<S60>/Proportional Gain'
   */
  rtb_DeadZone_f = 212.1F * rtb_Cos + rtDW.Integrator_DSTATE_f;

  /* Saturate: '<S62>/Saturation' */
  if (rtb_DeadZone_f > 6283.18555F) {
    rtb_Saturation_n = 6283.18555F;
  } else if (rtb_DeadZone_f < -6283.18555F) {
    rtb_Saturation_n = -6283.18555F;
  } else {
    rtb_Saturation_n = rtb_DeadZone_f;
  }

  /* End of Saturate: '<S62>/Saturation' */

  /* Gain: '<S12>/Gain' */
  rtb_Gain = 2.38732409F * rtb_Saturation_n;

  /* Outport: '<Root>/LunWm' */
  rtY.LunWm = rtb_Gain;

  /* Outport: '<Root>/LunTheta' */
  rtY.LunTheta = rtb_Sin;

  /* RateTransition: '<S1>/Rate Transition' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtb_RateTransition = rtb_Gain;
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* RateLimiter: '<S1>/Rate Limiter1' incorporates:
   *  Inport: '<Root>/Speed_ref'
   */
  rtb_Add5 = rtU.Speed_ref - rtDW.PrevY;
  if (rtb_Add5 > 0.55F) {
    rtb_Add5 = rtDW.PrevY + 0.55F;
  } else if (rtb_Add5 < -0.55F) {
    rtb_Add5 = rtDW.PrevY + -0.55F;
  } else {
    rtb_Add5 = rtU.Speed_ref;
  }

  rtDW.PrevY = rtb_Add5;

  /* End of RateLimiter: '<S1>/Rate Limiter1' */

  /* RateTransition: '<S1>/Rate Transition1' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    uint32_T Speed_loop_ELAPS_T;

    /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/Speed_loop'
     */
    if (rtDW.Speed_loop_RESET_ELAPS_T) {
      Speed_loop_ELAPS_T = 0U;
    } else {
      Speed_loop_ELAPS_T = rtM->Timing.clockTick1 - rtDW.Speed_loop_PREV_T;
    }

    rtDW.Speed_loop_PREV_T = rtM->Timing.clockTick1;
    rtDW.Speed_loop_RESET_ELAPS_T = false;

    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

    /* If: '<S1>/If' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Inport: '<Root>/Speed_ref'
     *  Sum: '<S1>/Sum'
     *  Sum: '<S1>/Sum1'
     */
    if ((rtU.Speed_ref - rtb_Gain) + 20.0 > 0.0) {
      rtb_Add5 = rtU.Speed_ref;
    }

    /* End of If: '<S1>/If' */

    /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/Speed_loop'
     */
    /* Sum: '<S14>/Sum2' */
    rtb_RateTransition = rtb_Add5 - rtb_RateTransition;

    /* DiscreteIntegrator: '<S106>/Integrator' incorporates:
     *  RateTransition: '<S1>/Rate Transition2'
     */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S106>/Integrator' */
      rtb_Add5 = rtDW.Integrator_DSTATE_p;
    } else if ((rtDW.RestsSingal > 0.0) && (rtDW.Integrator_PrevResetState <= 0))
    {
      /* DiscreteIntegrator: '<S106>/Integrator' */
      rtb_Add5 = 0.0F;
    } else {
      /* DiscreteIntegrator: '<S106>/Integrator' */
      rtb_Add5 = 0.001F * (real32_T)Speed_loop_ELAPS_T * rtDW.Integrator_PREV_U
        + rtDW.Integrator_DSTATE_p;
    }

    /* End of DiscreteIntegrator: '<S106>/Integrator' */

    /* Sum: '<S115>/Sum' incorporates:
     *  Gain: '<S111>/Proportional Gain'
     */
    rtb_Gain_p = spd_kpki.spd_kp * rtb_RateTransition + rtb_Add5;

    /* Saturate: '<S113>/Saturation' incorporates:
     *  DeadZone: '<S99>/DeadZone'
     */
    if (rtb_Gain_p > 3.0F) {
      /* Saturate: '<S113>/Saturation' */
      rtDW.Saturation = 3.0F;
      rtb_Gain_p -= 3.0F;
    } else {
      if (rtb_Gain_p < -3.0F) {
        /* Saturate: '<S113>/Saturation' */
        rtDW.Saturation = -3.0F;
      } else {
        /* Saturate: '<S113>/Saturation' */
        rtDW.Saturation = rtb_Gain_p;
      }

      if (rtb_Gain_p >= -3.0F) {
        rtb_Gain_p = 0.0F;
      } else {
        rtb_Gain_p -= -3.0F;
      }
    }

    /* End of Saturate: '<S113>/Saturation' */

    /* Gain: '<S103>/Integral Gain' */
    rtb_RateTransition *= spd_kpki.spd_ki;

    /* Update for DiscreteIntegrator: '<S106>/Integrator' incorporates:
     *  RateTransition: '<S1>/Rate Transition2'
     */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE_p = rtb_Add5;
    if (rtDW.RestsSingal > 0.0) {
      rtDW.Integrator_PrevResetState = 1;
    } else if (rtDW.RestsSingal < 0.0) {
      rtDW.Integrator_PrevResetState = -1;
    } else if (rtDW.RestsSingal == 0.0) {
      rtDW.Integrator_PrevResetState = 0;
    } else {
      rtDW.Integrator_PrevResetState = 2;
    }

    /* Switch: '<S97>/Switch1' incorporates:
     *  Constant: '<S97>/Constant'
     *  Constant: '<S97>/Constant2'
     *  Constant: '<S97>/Constant5'
     *  RelationalOperator: '<S97>/fix for DT propagation issue'
     */
    if (rtb_Gain_p > 0.0F) {
      rtb_Gain_l = 1;
    } else {
      rtb_Gain_l = -1;
    }

    /* End of Switch: '<S97>/Switch1' */

    /* Switch: '<S97>/Switch2' incorporates:
     *  Constant: '<S97>/Constant3'
     *  Constant: '<S97>/Constant4'
     *  Constant: '<S97>/Constant5'
     *  RelationalOperator: '<S97>/fix for DT propagation issue1'
     */
    if (rtb_RateTransition > 0.0F) {
      rtb_RateTransition_0 = 1;
    } else {
      rtb_RateTransition_0 = -1;
    }

    /* End of Switch: '<S97>/Switch2' */

    /* Switch: '<S97>/Switch' incorporates:
     *  Constant: '<S97>/Constant5'
     *  Logic: '<S97>/AND3'
     *  RelationalOperator: '<S97>/Equal1'
     *  RelationalOperator: '<S97>/Relational Operator'
     */
    if ((rtb_Gain_p != 0.0F) && (rtb_Gain_l == rtb_RateTransition_0)) {
      /* Update for DiscreteIntegrator: '<S106>/Integrator' incorporates:
       *  Constant: '<S97>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S106>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_RateTransition;
    }

    /* End of Switch: '<S97>/Switch' */
    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* Gain: '<S19>/Gain' incorporates:
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  rtb_Gain_p = 0.0001F * rtDW.UnitDelay1_DSTATE_f;

  /* Sum: '<S19>/Add6' incorporates:
   *  UnitDelay: '<S19>/Unit Delay2'
   */
  rtb_Add5 = rtDW.UnitDelay2_DSTATE - ialpha;

  /* Gain: '<S19>/Gain5' */
  rtb_RateTransition = 1.4F * rtb_Add5;

  /* Gain: '<S19>/Gain2' incorporates:
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  rtb_Gain2 = 0.0186915882F * rtDW.UnitDelay1_DSTATE_a;

  /* Gain: '<S19>/Gain4' */
  rtb_Gain4 = -0.399999976F * rtb_Add5;

  /* Product: '<S19>/Product1' incorporates:
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  rtb_Product1_a = rtb_Gain_p * rtDW.UnitDelay1_DSTATE_a;

  /* Sum: '<S19>/Add5' incorporates:
   *  UnitDelay: '<S19>/Unit Delay4'
   */
  rtb_Add5 = rtDW.UnitDelay4_DSTATE - ibeta;

  /* Gain: '<S19>/Gain8' incorporates:
   *  UnitDelay: '<S19>/Unit Delay5'
   */
  rtb_Gain8 = 0.0186915882F * rtDW.UnitDelay5_DSTATE;

  /* DeadZone: '<S48>/DeadZone' */
  if (rtb_DeadZone_f > 6283.18555F) {
    rtb_DeadZone_f -= 6283.18555F;
  } else if (rtb_DeadZone_f >= -6283.18555F) {
    rtb_DeadZone_f = 0.0F;
  } else {
    rtb_DeadZone_f -= -6283.18555F;
  }

  /* End of DeadZone: '<S48>/DeadZone' */

  /* Gain: '<S52>/Integral Gain' */
  rtb_Cos *= 2500.0F;

  /* DeadZone: '<S151>/DeadZone' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_DeadZone -= 12.4707661F;
  } else if (rtb_DeadZone >= -12.4707661F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -12.4707661F;
  }

  /* End of DeadZone: '<S151>/DeadZone' */

  /* Product: '<S155>/IProd Out' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  rtb_IProdOut_p = (int16_T)floorf(rtb_DiscreteTimeIntegrator *
    curr_kpki.curr_d_ki);

  /* DeadZone: '<S201>/DeadZone' */
  if (rtb_DeadZone_h > 12.4707661F) {
    rtb_DeadZone_h -= 12.4707661F;
  } else if (rtb_DeadZone_h >= -12.4707661F) {
    rtb_DeadZone_h = 0.0F;
  } else {
    rtb_DeadZone_h -= -12.4707661F;
  }

  /* End of DeadZone: '<S201>/DeadZone' */

  /* Product: '<S205>/IProd Out' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  rtb_IProdOut *= 71.0F;

  /* Outport: '<Root>/Outport1' */
  rtY.Outport1 = rtb_Gain;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_Sin;

  /* Update for RateTransition: '<S1>/Rate Transition3' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition3_Buffer0 = rtDW.Saturation;
  }

  /* End of Update for RateTransition: '<S1>/Rate Transition3' */

  /* Switch: '<S149>/Switch1' incorporates:
   *  Constant: '<S149>/Constant'
   *  Constant: '<S149>/Constant2'
   *  RelationalOperator: '<S149>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    rtb_Gain_l = 1;
  } else {
    rtb_Gain_l = -1;
  }

  /* End of Switch: '<S149>/Switch1' */

  /* Switch: '<S149>/Switch2' incorporates:
   *  Constant: '<S149>/Constant3'
   *  Constant: '<S149>/Constant4'
   *  Constant: '<S149>/Constant5'
   *  RelationalOperator: '<S149>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_p > 0) {
    rtb_RateTransition_0 = 1;
  } else {
    rtb_RateTransition_0 = -1;
  }

  /* End of Switch: '<S149>/Switch2' */

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Constant1'
   *  Logic: '<S149>/AND3'
   *  RelationalOperator: '<S149>/Equal1'
   *  RelationalOperator: '<S149>/Relational Operator'
   */
  if ((rtb_DeadZone != 0.0F) && (rtb_Gain_l == rtb_RateTransition_0)) {
    rtb_IProdOut_p = 0;
  }

  /* End of Switch: '<S149>/Switch' */

  /* Update for DiscreteIntegrator: '<S158>/Integrator' */
  rtDW.Integrator_DSTATE_fq += rtb_IProdOut_p;

  /* Switch: '<S199>/Switch1' incorporates:
   *  Constant: '<S199>/Constant'
   *  Constant: '<S199>/Constant2'
   *  Constant: '<S199>/Constant5'
   *  RelationalOperator: '<S199>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_h > 0.0F) {
    rtb_Gain_l = 1;
  } else {
    rtb_Gain_l = -1;
  }

  /* End of Switch: '<S199>/Switch1' */

  /* Switch: '<S199>/Switch2' incorporates:
   *  Constant: '<S199>/Constant3'
   *  Constant: '<S199>/Constant4'
   *  Constant: '<S199>/Constant5'
   *  RelationalOperator: '<S199>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_RateTransition_0 = 1;
  } else {
    rtb_RateTransition_0 = -1;
  }

  /* End of Switch: '<S199>/Switch2' */

  /* Switch: '<S199>/Switch' incorporates:
   *  Constant: '<S199>/Constant1'
   *  Constant: '<S199>/Constant5'
   *  Logic: '<S199>/AND3'
   *  RelationalOperator: '<S199>/Equal1'
   *  RelationalOperator: '<S199>/Relational Operator'
   */
  if ((rtb_DeadZone_h != 0.0F) && (rtb_Gain_l == rtb_RateTransition_0)) {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S199>/Switch' */

  /* Update for DiscreteIntegrator: '<S208>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_IProdOut;

  /* Update for UnitDelay: '<S19>/Unit Delay1' incorporates:
   *  Product: '<S19>/Product'
   *  Sum: '<S19>/Add'
   *  UnitDelay: '<S19>/Unit Delay5'
   */
  rtDW.UnitDelay1_DSTATE_a = (rtDW.UnitDelay1_DSTATE_a - rtDW.UnitDelay5_DSTATE *
    rtb_Gain_p) + rtb_RateTransition;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.0001F * rtb_Saturation_n;

  /* Update for UnitDelay: '<S19>/Unit Delay5' incorporates:
   *  Gain: '<S19>/Gain10'
   *  Sum: '<S19>/Add3'
   */
  rtDW.UnitDelay5_DSTATE = (rtDW.UnitDelay5_DSTATE + rtb_Product1_a) + 1.4F *
    rtb_Add5;

  /* Switch: '<S46>/Switch1' incorporates:
   *  Constant: '<S46>/Constant'
   *  Constant: '<S46>/Constant2'
   *  Constant: '<S46>/Constant5'
   *  RelationalOperator: '<S46>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_f > 0.0F) {
    rtb_Gain_l = 1;
  } else {
    rtb_Gain_l = -1;
  }

  /* End of Switch: '<S46>/Switch1' */

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S46>/Constant3'
   *  Constant: '<S46>/Constant4'
   *  Constant: '<S46>/Constant5'
   *  RelationalOperator: '<S46>/fix for DT propagation issue1'
   */
  if (rtb_Cos > 0.0F) {
    rtb_RateTransition_0 = 1;
  } else {
    rtb_RateTransition_0 = -1;
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Constant: '<S46>/Constant5'
   *  Logic: '<S46>/AND3'
   *  RelationalOperator: '<S46>/Equal1'
   *  RelationalOperator: '<S46>/Relational Operator'
   */
  if ((rtb_DeadZone_f != 0.0F) && (rtb_Gain_l == rtb_RateTransition_0)) {
    rtb_Cos = 0.0F;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Update for DiscreteIntegrator: '<S55>/Integrator' */
  rtDW.Integrator_DSTATE_f += 0.0001F * rtb_Cos;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_f = rtb_Saturation_n;

  /* Update for UnitDelay: '<S19>/Unit Delay2' incorporates:
   *  Gain: '<S19>/Gain1'
   *  Gain: '<S19>/Gain3'
   *  Sum: '<S19>/Add1'
   */
  rtDW.UnitDelay2_DSTATE = ((0.869719625F * rtDW.UnitDelay2_DSTATE - rtb_Gain2)
    + 0.0186915882F * ualpha) + rtb_Gain4;

  /* Update for UnitDelay: '<S19>/Unit Delay4' incorporates:
   *  Gain: '<S19>/Gain6'
   *  Gain: '<S19>/Gain7'
   *  Gain: '<S19>/Gain9'
   *  Sum: '<S19>/Add4'
   */
  rtDW.UnitDelay4_DSTATE = ((0.869719625F * rtDW.UnitDelay4_DSTATE - rtb_Gain8)
    + 0.0186915882F * ubeta) + -0.399999976F * rtb_Add5;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void FOC_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem2' */
  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */
  rtDW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem2' */

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Speed_loop'
   */
  /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator' */
  rtDW.Integrator_PrevResetState = 2;

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Speed_loop'
   */
  rtDW.Speed_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S106>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
