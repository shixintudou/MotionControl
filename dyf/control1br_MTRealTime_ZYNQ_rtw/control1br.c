#define MT_REALTIME_MAINMODELFILE

/*
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

/* Block signals (default storage) */
B_control1br_T control1br_B;

/* Block states (default storage) */
DW_control1br_T control1br_DW;

/* External inputs (root inport signals with default storage) */
ExtU_control1br_T control1br_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_control1br_T control1br_Y;

/* Real-time model */
RT_MODEL_control1br_T control1br_M_;
RT_MODEL_control1br_T *const control1br_M = &control1br_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T q;
  if (rtIsNaN(u0) || rtIsInf(u0) || (rtIsNaN(u1) || rtIsInf(u1))) {
    y = (rtNaN);
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model output function */
static void control1br_output(void)
{
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_LogicalOperator;
  real_T rtb_Subtract;

  /* Gain: '<S75>/Proportional Gain' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  control1br_B.ProportionalGain = control1br_P.DiscretePIDController_P *
    control1br_DW.UnitDelay_DSTATE;

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Clock: '<S3>/Clock'
   *  Constant: '<S3>/Constant'
   *  Lookup_n-D: '<S3>/Look-Up Table1'
   *  Math: '<S3>/Math Function'
   *  S-Function (sfun_tstart): '<S3>/startTime'
   *  Sum: '<S3>/Sum'
   */
  rtb_RelationalOperator = (control1br_B.ProportionalGain >= look1_binlxpw
    (rt_remd_snf(control1br_M->Timing.t[0] - (0.0), control1br_P.Constant_Value),
     control1br_P.LookUpTable1_bp01Data,
     control1br_P.RepeatingSequence_rep_seq_y, 2U));

  /* Logic: '<Root>/Logical Operator' */
  rtb_LogicalOperator = !rtb_RelationalOperator;

  /* Outport: '<Root>/SPWM' */
  control1br_Y.SPWM[0] = rtb_RelationalOperator;
  control1br_Y.SPWM[1] = rtb_LogicalOperator;
  control1br_Y.SPWM[2] = rtb_LogicalOperator;
  control1br_Y.SPWM[3] = rtb_RelationalOperator;

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Uout1'
   */
  rtb_Subtract = control1br_P.Constant_Value_a - control1br_U.Uout1;

  /* Gain: '<S144>/Integral Gain' */
  control1br_B.IntegralGain = control1br_P.DiscretePIDController1_I *
    rtb_Subtract;

  /* Sum: '<Root>/Subtract1' incorporates:
   *  DiscreteIntegrator: '<S154>/Integrator'
   *  Gain: '<Root>/Gain'
   *  Gain: '<S171>/Proportional Gain'
   *  Inport: '<Root>/Idc'
   *  Inport: '<Root>/Udc'
   *  Product: '<Root>/Product'
   *  Sum: '<S183>/Sum'
   */
  control1br_B.Subtract1 = control1br_U.Idc -
    (control1br_P.DiscretePIDController1_P * rtb_Subtract +
     control1br_DW.Integrator_DSTATE) * (control1br_P.Gain_Gain *
    control1br_U.Udc);
}

/* Model update function */
static void control1br_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  control1br_DW.UnitDelay_DSTATE = control1br_B.Subtract1;

  /* Update for DiscreteIntegrator: '<S154>/Integrator' */
  control1br_DW.Integrator_DSTATE += control1br_P.Integrator_gainval *
    control1br_B.IntegralGain;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++control1br_M->Timing.clockTick0)) {
    ++control1br_M->Timing.clockTickH0;
  }

  control1br_M->Timing.t[0] = control1br_M->Timing.clockTick0 *
    control1br_M->Timing.stepSize0 + control1br_M->Timing.clockTickH0 *
    control1br_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++control1br_M->Timing.clockTick1)) {
      ++control1br_M->Timing.clockTickH1;
    }

    control1br_M->Timing.t[1] = control1br_M->Timing.clockTick1 *
      control1br_M->Timing.stepSize1 + control1br_M->Timing.clockTickH1 *
      control1br_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void control1br_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  control1br_DW.UnitDelay_DSTATE = control1br_P.UnitDelay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
  control1br_DW.Integrator_DSTATE = control1br_P.DiscretePIDController1_InitialC;
}

/* Model terminate function */
static void control1br_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  control1br_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  control1br_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  control1br_initialize();
}

void MdlTerminate(void)
{
  control1br_terminate();
}

/* Registration function */
RT_MODEL_control1br_T *control1br(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)control1br_M, 0,
                sizeof(RT_MODEL_control1br_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&control1br_M->solverInfo,
                          &control1br_M->Timing.simTimeStep);
    rtsiSetTPtr(&control1br_M->solverInfo, &rtmGetTPtr(control1br_M));
    rtsiSetStepSizePtr(&control1br_M->solverInfo,
                       &control1br_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&control1br_M->solverInfo, (&rtmGetErrorStatus
      (control1br_M)));
    rtsiSetRTModelPtr(&control1br_M->solverInfo, control1br_M);
  }

  rtsiSetSimTimeStep(&control1br_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&control1br_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = control1br_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    control1br_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    control1br_M->Timing.sampleTimes = (&control1br_M->Timing.sampleTimesArray[0]);
    control1br_M->Timing.offsetTimes = (&control1br_M->Timing.offsetTimesArray[0]);

    /* task periods */
    control1br_M->Timing.sampleTimes[0] = (0.0);
    control1br_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    control1br_M->Timing.offsetTimes[0] = (0.0);
    control1br_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(control1br_M, &control1br_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = control1br_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    control1br_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(control1br_M, 5.0);
  control1br_M->Timing.stepSize0 = 0.0001;
  control1br_M->Timing.stepSize1 = 0.0001;
  control1br_M->solverInfoPtr = (&control1br_M->solverInfo);
  control1br_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&control1br_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&control1br_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  control1br_M->blockIO = ((void *) &control1br_B);
  (void) memset(((void *) &control1br_B), 0,
                sizeof(B_control1br_T));

  /* parameters */
  control1br_M->defaultParam = ((real_T *)&control1br_P);

  /* states (dwork) */
  control1br_M->dwork = ((void *) &control1br_DW);
  (void) memset((void *)&control1br_DW, 0,
                sizeof(DW_control1br_T));

  /* external inputs */
  control1br_M->inputs = (((void*)&control1br_U));
  (void)memset(&control1br_U, 0, sizeof(ExtU_control1br_T));

  /* external outputs */
  control1br_M->outputs = (&control1br_Y);
  (void) memset(&control1br_Y.SPWM[0], 0,
                4U*sizeof(boolean_T));

  /* Initialize Sizes */
  control1br_M->Sizes.numContStates = (0);/* Number of continuous states */
  control1br_M->Sizes.numY = (4);      /* Number of model outputs */
  control1br_M->Sizes.numU = (3);      /* Number of model inputs */
  control1br_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  control1br_M->Sizes.numSampTimes = (2);/* Number of sample times */
  control1br_M->Sizes.numBlocks = (20);/* Number of blocks */
  control1br_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  control1br_M->Sizes.numBlockPrms = (15);/* Sum of parameter "widths" */
  return control1br_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * MT RealTime Model Framework code generation
 *
 * Model : control1br
 * Model version : 1.2
 * RealTime Model Framework version : 2022.0.0.0 (2022)
 * Source generated on : Wed Jan 10 09:27:11 2024
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef MT_ROOTMODEL_control1br
#include "mt_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: MTRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double MTRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return MTRT_GetValueByDataType(ptr, subindex, 6, Complex);

   case 13:
    return MTRT_GetValueByDataType(ptr, subindex, 7, Complex);

   case 15:
    return MTRT_GetValueByDataType(ptr, subindex, 6, Complex);

   case 16:
    return MTRT_GetValueByDataType(ptr, subindex, 6, Complex);

   case 17:
    return MTRT_GetValueByDataType(ptr, subindex, 3, Complex);

   case 18:
    return MTRT_GetValueByDataType(ptr, subindex, 8, Complex);

   case 19:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 20:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 21:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 22:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 23:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 24:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 25:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 26:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);

   case 27:
    return MTRT_GetValueByDataType(ptr, subindex, 0, Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: MTRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t MTRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return MT_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return MT_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return MT_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return MT_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return MT_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return MT_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return MT_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return MT_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return MT_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 17:
    //Type is renamed. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return MTRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return MT_ERROR;
}

extern control1br_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;
  ExtU_control1br_T *rtIN = (ExtU_control1br_T*) S->inputs;
  if (TaskSampleHit[1]) {              // sample and hold
    /* rtIN->Idc Type real_T -> 0 Width [1, 1] */
    MTRT_SetValueByDataType(&rtIN->Idc, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[1]) {              // sample and hold
    /* rtIN->Udc Type real_T -> 0 Width [1, 1] */
    MTRT_SetValueByDataType(&rtIN->Udc, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[1]) {              // sample and hold
    /* rtIN->Uout1 Type real_T -> 0 Width [1, 1] */
    MTRT_SetValueByDataType(&rtIN->Uout1, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 3;
}

int32_t NumOutputPorts(void)
{
  return 4;
}

double mt_extout[4];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;
  ExtY_control1br_T* rtOUT = (ExtY_control1br_T*) S->outputs;
  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->SPWM has width [1, 4] type boolean_T -> 18 */
    mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 0, 18, 0);
    mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 1, 18, 0);
    mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 2, 18, 0);
    mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 3, 18, 0);
  } else {
    index += 4;
  }

  if (data != NULL) {
    memcpy(&data[0], &mt_extout[0], sizeof(mt_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: MT_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t MT_InitExternalOutputs()
{
  int index = 0, count = 0;
  ExtY_control1br_T* rtOUT = (ExtY_control1br_T*) S->outputs;

  /* rtOUT->SPWM has width 4 -> [1, 4] type 18 -> 18 */
  mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 0, 18, 0);
  mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 1, 18, 0);
  mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 2, 18, 0);
  mt_extout[index++] = MTRT_GetValueByDataType(&(rtOUT->SPWM), 3, 18, 0);
  UNUSED_PARAMETER(count);
  return MT_OK;
}

static int32_t MT_ExtListSize DataSection(".MTVS.extlistsize") = 4;
static MT_ExternalIO MT_ExtList[] DataSection(".MTVS.extlist") =
{
  { 1, "Idc", 1, EXT_IN, 1, 1, 1 },

  { 2, "Udc", 1, EXT_IN, 1, 1, 1 },

  { 3, "Uout1", 1, EXT_IN, 1, 1, 1 },

  { 1, "SPWM", 0, EXT_OUT, 4, 1, 4 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
MT_Task MT_TaskList[] DataSection(".MTVS.tasklist") =
{
  { 0, 0.0001, 0 }
};

int32_t MT_NumTasks DataSection(".MTVS.numtasks") = 1;
static const char* MT_CompiledModelName DataSection(".MTVS.compiledmodelname") =
  "control1br";
static const char* MT_CompiledModelVersion = "1.2";
static const char* MT_CompiledModelDateTime = "Wed Jan 10 09:27:11 2024";
static const char* MT_builder DataSection(".MTVS.builder") =
  "MT Model Framework 2022.0.0.0 (2022) for Simulink Coder 9.0 (R2018b)";
static const char* MT_BuilderVersion DataSection(".MTVS.builderversion") =
  "2022.0.0.0";

/*========================================================================*
 * Function: MTRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	MT_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t MTRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kMTOSLinux) && ! defined (standalone )

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, MT_builder, MT_CompiledModelName,
                     MT_CompiledModelVersion, MT_BuilderVersion,
                     MT_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kMTOSLinux) && ! defined (standalone )

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, MT_builder, MT_CompiledModelName,
             MT_CompiledModelVersion, MT_BuilderVersion,
             MT_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return MT_OK;
}

/*========================================================================*
 * Function: MTRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	MT_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
//zhaowei
//DLL_EXPORT int32_t MTRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len, char* blkname, int32_t *bnlen,
//							int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t* dims, int32_t* numdim)
//{
//	int32_t sigidx = *sidx;
//	int32_t i = 0;
//	char *addr = NULL;
//	char *IDblk = 0;
//	int32_t IDport = 0;
//
//	if (sigidx < 0)
//	{
//		/* check if ID has been specified. */
//		if ((ID != NULL) && (ID_len != NULL) &&  (*ID_len > 0))
//		{
//			/* parse ID into blkname and port */
//			addr = strrchr(ID, ':');
//			if (addr == NULL)
//			{
//				return MT_SigListSize;
//			}
//
//			/* Calculate the char offset into the string after the port */
//			i = addr - ID;
//
//			/* malformed ID */
//			if (i<=0)
//			{
//				return MT_SigListSize;
//			}
//
//			IDblk = ID;
//			IDport = atoi(ID+i+1);
//
//			/* lookup the table for matching ID */
//			for (i=0; i<MT_SigListSize; i++)
//			{
//				/* 11 to accomodate ':','/', port number and null character */
//                char *tempID = (char *)calloc(strlen(MT_SigList[i].blockname)+strlen(MT_SigList[i].signalname) + 11, sizeof(char));
//
//                if (strlen(MT_SigList[i].signalname)>0)
//				{
//                    sprintf(tempID,"%s:%d%s%s",MT_SigList[i].blockname,MT_SigList[i].portno+1,"/",MT_SigList[i].signalname);
//				}
//                else
//				{
//                    sprintf(tempID,"%s:%d",MT_SigList[i].blockname,MT_SigList[i].portno+1);
//				}
//
//				if (!strcmp(IDblk,tempID) && IDport==(MT_SigList[i].portno+1))
//				{
//					break;
//				}
//
//                free(tempID);
//			}
//
//			if (i < MT_SigListSize)
//			{
//				sigidx = *sidx = i;
//			}
//			else
//			{
//				return MT_SigListSize;
//			}
//
//		}
//		else
//		{
//			// no index or ID specified.
//			return MT_SigListSize;
//		}
//	}
//
//	if (sigidx>=0 && sigidx<MT_SigListSize)
//	{
//		if (ID != NULL)
//		{
//			// no need for return string to be null terminated!
//			/* 11 to accomodate ':','/', port number and null character */
//			char *tempID = (char *)calloc(strlen(MT_SigList[sigidx].blockname)+strlen(MT_SigList[sigidx].signalname)+ 11, sizeof(char));
//
//            if (strlen(MT_SigList[sigidx].signalname)>0)
//			{
//                sprintf(tempID,"%s:%d%s%s",MT_SigList[sigidx].blockname,MT_SigList[sigidx].portno+1,"/",MT_SigList[sigidx].signalname);
//			}
//            else
//			{
//                sprintf(tempID,"%s:%d",MT_SigList[sigidx].blockname,MT_SigList[sigidx].portno+1);
//			}
//
//			if ((int32_t)strlen(tempID)<*ID_len)
//			{
//				*ID_len = strlen(tempID);
//			}
//
//			strncpy(ID, tempID, *ID_len);
//			free(tempID);
//		}
//
//		if (blkname != NULL)
//		{
//			// no need for return string to be null terminated!
//			if ((int32_t)strlen(MT_SigList[sigidx].blockname)<*bnlen)
//			{
//				*bnlen = strlen(MT_SigList[sigidx].blockname);
//			}
//
//	      	strncpy(blkname, MT_SigList[sigidx].blockname, *bnlen);
//	   	}
//
//	   	if (signame != NULL)
//		{
//			// no need for return string to be null terminated!
//			if ((int32_t)strlen(MT_SigList[sigidx].signalname)<*snlen)
//			{
//				*snlen = strlen(MT_SigList[sigidx].signalname);
//			}
//
//			strncpy(signame, MT_SigList[sigidx].signalname, *snlen);
//	   	}
//
//	   	if (portnum != NULL)
//		{
//	   		*portnum = MT_SigList[sigidx].portno;
//		}
//
//	   	if (dattype != NULL)
//		{
//	   		*dattype = MT_SigList[sigidx].datatype;
//		}
//
//		if (numdim != NULL)
//		{
//			if (*numdim == -1)
//			{
//				*numdim = MT_SigList[sigidx].numofdims;
//			}
//			else if (dims != NULL)
//			{
//				for (i=0;i < *numdim; i++)
//				{
//					dims[i] = MT_SigDimList[MT_SigList[sigidx].dimListOffset +i];
//				}
//			}
//		}
//
//	   	return MT_OK;
//	}
//	return MT_SigListSize;
//}
//zhaowei

/*========================================================================*
 * Function: MTRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	MT_OK if no error
 *========================================================================*/
//zhaowei
//DLL_EXPORT int32_t MTRT_GetParameterIndices(int32_t* indices, int32_t* len)
//{
//	int32_t i;
//
//	if((len == NULL) || (indices == NULL))
//	{
//		return MT_ERROR;
//	}
//
//	if (*len == -1)
//	{
//		*len = MT_ParamListSize;
//	}
//	else
//	{
//		for(i=0; (i < MT_ParamListSize) && (i < *len); i++)
//		{
//			indices[i] = MT_ParamList[i].idx;
//		}
//
//		*len = i;
//	}
//
//	return MT_OK;
//}
//zhaowei

/*========================================================================*
 * Function: MTRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	MT_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
//zhaowei
//DLL_EXPORT int32_t MTRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t* ID_len, char* paramname, int32_t *pnlen,
//						    int32_t *dattype, int32_t* dims, int32_t* numdim)
//{
//	int32_t i = 0;
//	int32_t paramidx = *pidx;
//
//	if (paramidx < 0)
//	{
//		// check if ID has been specified.
//		if ( (ID != NULL) && (ID_len != NULL) && (*ID_len > 0) )
//		{
//			// lookup the table for matching ID
//			for (i=0; i < MT_ParamListSize; i++)
//			{
//				if (strcmp(ID,MT_ParamList[i].paramname) == 0)
//				{
//					/* found matching string */
//					break;
//				}
//			}
//
//			if (i < MT_ParamListSize)
//			{
//				/* note the index into the rtParamAttribs */
//				paramidx = *pidx = i;
//			}
//			else
//			{
//				return MT_ParamListSize;
//			}
//		}
//		else
//		{
//			// no index or ID specified.
//			return MT_ParamListSize;
//		}
//	}
//
//	if ((paramidx >= 0) && (paramidx<MT_ParamListSize))
//	{
//		if(ID != NULL)
//		{
//	    	if ((int32_t)strlen(MT_ParamList[paramidx].paramname) < *ID_len)
//			{
//				*ID_len = strlen(MT_ParamList[paramidx].paramname);
//			}
//			strncpy(ID, MT_ParamList[paramidx].paramname, *ID_len);
//	   	}
//
//	   	if(paramname != NULL)
//		{
//			/* no need for return string to be null terminated! */
//			if ((int32_t)strlen(MT_ParamList[paramidx].paramname) < *pnlen)
//			{
//				*pnlen = strlen(MT_ParamList[paramidx].paramname);
//			}
//		    strncpy(paramname, MT_ParamList[paramidx].paramname, *pnlen);
//	   	}
//
//	   	if (dattype != NULL)
//		{
//	   		*dattype = MT_ParamList[paramidx].datatype;
//		}
//
//	   	if (numdim != NULL)
//		{
//			if (*numdim == -1)
//			{
//				*numdim = MT_ParamList[paramidx].numofdims;
//			}
//			else if (dims != NULL)
//			{
//				for (i = 0; i < *numdim; i++)
//				{
//					dims[i] = MT_ParamDimList[MT_ParamList[paramidx].dimListOffset + i];
//				}
//			}
//		}
//
//	   	return MT_OK;
//	}
//	return MT_ParamListSize;
//}
//zhaowei
/*========================================================================*
 * Function: MTRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	MT_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t MTRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return MT_ExtListSize;
  }

  if (idx != NULL) {
    *idx = MT_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, MT_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = MT_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = MT_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = MT_ExtList[index].dimX;
      dims[1] = MT_ExtList[index].dimY;
    }
  }

  return MT_OK;
}

int32_t MT_InitParamDoubleBuf(void)
{
  return MT_OK;
}

int32_t MT_InitializeParamStruct(void)
{
  return MT_OK;
}

DLL_EXPORT int32_t MTRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  return MT_ERROR;
}

DLL_EXPORT int32_t MTRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  return MT_ERROR;
}

DLL_EXPORT int32_t MTRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  return MT_ERROR;
}

DLL_EXPORT int32_t MTRT_SetVectorParameter(uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  return MT_ERROR;
}

DLL_EXPORT int32_t MTRT_SetScalarParameterInline(uint32_t index, uint32_t
  subindex, double paramvalue)
{
  return MT_ERROR;
}

#endif                                 // of MT_ROOTMODEL_control1br
