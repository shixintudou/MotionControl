/*
 * control1br_data.c
 *
 * Code generation for model "control1br".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Jan 10 09:27:11 2024
 *
 * Target selection: MTRealTime_ZYNQ.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control1br.h"
#include "control1br_private.h"

/* Block parameters (default storage) */
P_control1br_T control1br_P = {
  /* Mask Parameter: DiscretePIDController1_I
   * Referenced by: '<S144>/Integral Gain'
   */
  20.0,

  /* Mask Parameter: DiscretePIDController1_InitialC
   * Referenced by: '<S154>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S75>/Proportional Gain'
   */
  15.0,

  /* Mask Parameter: DiscretePIDController1_P
   * Referenced by: '<S171>/Proportional Gain'
   */
  0.4,

  /* Mask Parameter: RepeatingSequence_rep_seq_y
   * Referenced by: '<S3>/Look-Up Table1'
   */
  { -1.0, 1.0, -1.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: period
   * Referenced by: '<S3>/Constant'
   */
  0.00066667,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S3>/Look-Up Table1'
   */
  { 0.0, 0.00033333333333333332, 0.00066666666666666664 },

  /* Expression: 550
   * Referenced by: '<Root>/Constant'
   */
  550.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S154>/Integrator'
   */
  0.0001,

  /* Expression: 1/220/sqrt(2)
   * Referenced by: '<Root>/Gain'
   */
  0.0032141217326661247
};
