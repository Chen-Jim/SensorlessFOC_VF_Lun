/*
 * File: FOC_Model.h
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

#ifndef RTW_HEADER_FOC_Model_h_
#define RTW_HEADER_FOC_Model_h_
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T RestsSingal;                  /* '<S1>/Chart1' */
  real32_T RateTransition3;            /* '<S1>/Rate Transition3' */
  real32_T Merge;                      /* '<S1>/Merge' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Saturation;                 /* '<S113>/Saturation' */
  real32_T ZReset;                     /* '<S1>/Chart1' */
  real32_T UnitDelay1_DSTATE;          /* '<S1>/Unit Delay1' */
  real32_T Integrator_DSTATE;          /* '<S208>/Integrator' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S19>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S20>/Discrete-Time Integrator' */
  real32_T UnitDelay5_DSTATE;          /* '<S19>/Unit Delay5' */
  real32_T Integrator_DSTATE_f;        /* '<S55>/Integrator' */
  real32_T UnitDelay1_DSTATE_f;        /* '<S12>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S19>/Unit Delay2' */
  real32_T UnitDelay4_DSTATE;          /* '<S19>/Unit Delay4' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S8>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S8>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S6>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_j;/* '<S6>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_p;        /* '<S106>/Integrator' */
  real32_T RateTransition3_Buffer0;    /* '<S1>/Rate Transition3' */
  real32_T PrevY;                      /* '<S1>/Rate Limiter1' */
  real32_T Integrator_PREV_U;          /* '<S106>/Integrator' */
  real32_T cnt;                        /* '<S1>/Chart1' */
  uint32_T Speed_loop_PREV_T;          /* '<S1>/Speed_loop' */
  int16_T Integrator_DSTATE_fq;        /* '<S158>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S1>/Chart1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S6>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S6>/Discrete-Time Integrator1' */
  int8_T Integrator_PrevResetState;    /* '<S106>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S106>/Integrator' */
  uint8_T is_active_c7_FOC_Model;      /* '<S1>/Chart1' */
  uint8_T is_c7_FOC_Model;             /* '<S1>/Chart1' */
  boolean_T Speed_loop_RESET_ELAPS_T;  /* '<S1>/Speed_loop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T Speed_ref;                  /* '<Root>/Speed_ref' */
  real32_T MotorOnOff;                 /* '<Root>/MotorOnOff' */
  real32_T VDC;                        /* '<Root>/VDC' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Tcmp1;                      /* '<Root>/Tcmp1' */
  real32_T Tcmp2;                      /* '<Root>/Tcmp2' */
  real32_T Tcmp3;                      /* '<Root>/Tcmp3' */
  real32_T LunWm;                      /* '<Root>/LunWm' */
  real32_T LunTheta;                   /* '<Root>/LunTheta' */
  real32_T Outport1;                   /* '<Root>/Outport1' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct curr_kpki_tag {
  real32_T curr_d_ki;                  /* Referenced by: '<S15>/Constant4' */
  real32_T curr_d_kp;                  /* Referenced by: '<S15>/Constant3' */
} curr_kpki_type;

typedef struct spd_kpki_tag {
  real32_T spd_ki;                   /* Referenced by: '<S103>/Integral Gain' */
  real32_T spd_kp;               /* Referenced by: '<S111>/Proportional Gain' */
} spd_kpki_type;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T ialpha;                /* '<S1>/Clark' */
extern real32_T ibeta;                 /* '<S1>/Clark' */
extern real32_T ualpha;                /* '<S1>/In_park' */
extern real32_T ubeta;                 /* '<S1>/In_park' */
extern real32_T state;                 /* '<S1>/Chart1' */

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern curr_kpki_type curr_kpki;
extern spd_kpki_type spd_kpki;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S8>/Add1' : Unused code path elimination
 * Block '<S8>/Add2' : Unused code path elimination
 * Block '<S8>/Constant3' : Unused code path elimination
 * Block '<S8>/Mod1' : Unused code path elimination
 * Block '<S8>/Product' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope2' : Unused code path elimination
 * Block '<S8>/Scope3' : Unused code path elimination
 * Block '<S8>/Scope4' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('PMSM_sin_hf_vs_test/FOC_Model')    - opens subsystem PMSM_sin_hf_vs_test/FOC_Model
 * hilite_system('PMSM_sin_hf_vs_test/FOC_Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PMSM_sin_hf_vs_test'
 * '<S1>'   : 'PMSM_sin_hf_vs_test/FOC_Model'
 * '<S2>'   : 'PMSM_sin_hf_vs_test/FOC_Model/Chart1'
 * '<S3>'   : 'PMSM_sin_hf_vs_test/FOC_Model/Clark'
 * '<S4>'   : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem'
 * '<S5>'   : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem1'
 * '<S6>'   : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem2'
 * '<S7>'   : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem3'
 * '<S8>'   : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem4'
 * '<S9>'   : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem5'
 * '<S10>'  : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem6'
 * '<S11>'  : 'PMSM_sin_hf_vs_test/FOC_Model/In_park'
 * '<S12>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer'
 * '<S13>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Park'
 * '<S14>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop'
 * '<S15>'  : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller'
 * '<S16>'  : 'PMSM_sin_hf_vs_test/FOC_Model/svpwm2'
 * '<S17>'  : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem4/If Action Subsystem2'
 * '<S18>'  : 'PMSM_sin_hf_vs_test/FOC_Model/If Action Subsystem4/If Action Subsystem3'
 * '<S19>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/Discrete Luenberger Observer'
 * '<S20>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL'
 * '<S21>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller'
 * '<S22>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Anti-windup'
 * '<S23>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/D Gain'
 * '<S24>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Filter'
 * '<S25>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Filter ICs'
 * '<S26>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/I Gain'
 * '<S27>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Ideal P Gain'
 * '<S28>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S29>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Integrator'
 * '<S30>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Integrator ICs'
 * '<S31>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/N Copy'
 * '<S32>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/N Gain'
 * '<S33>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/P Copy'
 * '<S34>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Parallel P Gain'
 * '<S35>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Reset Signal'
 * '<S36>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Saturation'
 * '<S37>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Saturation Fdbk'
 * '<S38>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Sum'
 * '<S39>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Sum Fdbk'
 * '<S40>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tracking Mode'
 * '<S41>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tracking Mode Sum'
 * '<S42>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tsamp - Integral'
 * '<S43>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tsamp - Ngain'
 * '<S44>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/postSat Signal'
 * '<S45>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/preSat Signal'
 * '<S46>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S47>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S48>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S49>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/D Gain/Disabled'
 * '<S50>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Filter/Disabled'
 * '<S51>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Filter ICs/Disabled'
 * '<S52>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S53>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S54>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S55>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Integrator/Discrete'
 * '<S56>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S57>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S58>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/N Gain/Disabled'
 * '<S59>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/P Copy/Disabled'
 * '<S60>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S61>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Reset Signal/Disabled'
 * '<S62>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Saturation/Enabled'
 * '<S63>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S64>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Sum/Sum_PI'
 * '<S65>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S66>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S67>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S68>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S69>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S70>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S71>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Lunberger Observer/PLL/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S72>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3'
 * '<S73>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Anti-windup'
 * '<S74>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/D Gain'
 * '<S75>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Filter'
 * '<S76>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Filter ICs'
 * '<S77>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/I Gain'
 * '<S78>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain'
 * '<S79>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S80>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Integrator'
 * '<S81>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Integrator ICs'
 * '<S82>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/N Copy'
 * '<S83>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/N Gain'
 * '<S84>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/P Copy'
 * '<S85>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain'
 * '<S86>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Reset Signal'
 * '<S87>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Saturation'
 * '<S88>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk'
 * '<S89>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Sum'
 * '<S90>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk'
 * '<S91>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tracking Mode'
 * '<S92>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S93>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral'
 * '<S94>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S95>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/postSat Signal'
 * '<S96>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/preSat Signal'
 * '<S97>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S98>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S99>'  : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S100>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/D Gain/Disabled'
 * '<S101>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Filter/Disabled'
 * '<S102>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Filter ICs/Disabled'
 * '<S103>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/I Gain/Internal Parameters'
 * '<S104>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S105>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S106>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Integrator/Discrete'
 * '<S107>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Integrator ICs/Internal IC'
 * '<S108>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S109>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/N Gain/Disabled'
 * '<S110>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/P Copy/Disabled'
 * '<S111>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S112>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Reset Signal/External Reset'
 * '<S113>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Saturation/Enabled'
 * '<S114>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S115>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S116>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S117>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S118>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S119>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S120>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S121>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S122>' : 'PMSM_sin_hf_vs_test/FOC_Model/Speed_loop/PID Controller3/preSat Signal/Forward_Path'
 * '<S123>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1'
 * '<S124>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2'
 * '<S125>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Anti-windup'
 * '<S126>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/D Gain'
 * '<S127>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Filter'
 * '<S128>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Filter ICs'
 * '<S129>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/I Gain'
 * '<S130>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S131>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S132>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Integrator'
 * '<S133>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Integrator ICs'
 * '<S134>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/N Copy'
 * '<S135>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/N Gain'
 * '<S136>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/P Copy'
 * '<S137>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S138>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Reset Signal'
 * '<S139>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Saturation'
 * '<S140>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S141>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Sum'
 * '<S142>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S143>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tracking Mode'
 * '<S144>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S145>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S146>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S147>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/postSat Signal'
 * '<S148>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/preSat Signal'
 * '<S149>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S150>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S151>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S152>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S153>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S154>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S155>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S156>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S157>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S158>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S159>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S160>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S161>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S162>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S163>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S164>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S165>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S166>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S167>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S168>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S169>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S170>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S171>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S172>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S173>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S174>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S175>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Anti-windup'
 * '<S176>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/D Gain'
 * '<S177>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Filter'
 * '<S178>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Filter ICs'
 * '<S179>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/I Gain'
 * '<S180>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S181>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S182>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Integrator'
 * '<S183>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Integrator ICs'
 * '<S184>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/N Copy'
 * '<S185>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/N Gain'
 * '<S186>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/P Copy'
 * '<S187>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S188>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Reset Signal'
 * '<S189>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Saturation'
 * '<S190>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S191>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Sum'
 * '<S192>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S193>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tracking Mode'
 * '<S194>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S195>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S196>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S197>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/postSat Signal'
 * '<S198>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/preSat Signal'
 * '<S199>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S200>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S201>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S202>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S203>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S204>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S205>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S206>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S207>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S208>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S209>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S210>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S211>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S212>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S213>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S214>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S215>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S216>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S217>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S218>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S219>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S220>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S221>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S222>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S223>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S224>' : 'PMSM_sin_hf_vs_test/FOC_Model/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
