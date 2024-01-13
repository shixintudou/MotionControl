/*
 * control1br.h
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

#ifndef RTW_HEADER_control1br_h_
#define RTW_HEADER_control1br_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef control1br_COMMON_INCLUDES_
# define control1br_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* control1br_COMMON_INCLUDES_ */

#include "control1br_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define control1br_rtModel             RT_MODEL_control1br_T

/* Block signals (default storage) */
typedef struct {
  real_T ProportionalGain;             /* '<S75>/Proportional Gain' */
  real_T IntegralGain;                 /* '<S144>/Integral Gain' */
  real_T Subtract1;                    /* '<Root>/Subtract1' */
} B_control1br_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S154>/Integrator' */
} DW_control1br_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Idc;                          /* '<Root>/Idc' */
  real_T Udc;                          /* '<Root>/Udc' */
  real_T Uout1;                        /* '<Root>/Uout1' */
} ExtU_control1br_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T SPWM[4];                   /* '<Root>/SPWM' */
} ExtY_control1br_T;

/* Backward compatible GRT Identifiers */
#define rtB                            control1br_B
#define BlockIO                        B_control1br_T
#define rtU                            control1br_U
#define ExternalInputs                 ExtU_control1br_T
#define rtY                            control1br_Y
#define ExternalOutputs                ExtY_control1br_T
#define rtP                            control1br_P
#define Parameters                     P_control1br_T
#define rtDWork                        control1br_DW
#define D_Work                         DW_control1br_T

/* Parameters (default storage) */
struct P_control1br_T_ {
  real_T DiscretePIDController1_I;     /* Mask Parameter: DiscretePIDController1_I
                                        * Referenced by: '<S144>/Integral Gain'
                                        */
  real_T DiscretePIDController1_InitialC;/* Mask Parameter: DiscretePIDController1_InitialC
                                          * Referenced by: '<S154>/Integrator'
                                          */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S75>/Proportional Gain'
                                        */
  real_T DiscretePIDController1_P;     /* Mask Parameter: DiscretePIDController1_P
                                        * Referenced by: '<S171>/Proportional Gain'
                                        */
  real_T RepeatingSequence_rep_seq_y[3];/* Mask Parameter: RepeatingSequence_rep_seq_y
                                         * Referenced by: '<S3>/Look-Up Table1'
                                         */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: period
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[3];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S3>/Look-Up Table1'
                                        */
  real_T Constant_Value_a;             /* Expression: 550
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S154>/Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/220/sqrt(2)
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_control1br_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_control1br_T control1br_P;

/* Block signals (default storage) */
extern B_control1br_T control1br_B;

/* Block states (default storage) */
extern DW_control1br_T control1br_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_control1br_T control1br_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_control1br_T control1br_Y;

/*====================*
 * External functions *
 *====================*/
extern control1br_rtModel *control1br(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_control1br_T *const control1br_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'control1br'
 * '<S1>'   : 'control1br/Discrete PID Controller'
 * '<S2>'   : 'control1br/Discrete PID Controller1'
 * '<S3>'   : 'control1br/Repeating Sequence'
 * '<S4>'   : 'control1br/Discrete PID Controller/Anti-windup'
 * '<S5>'   : 'control1br/Discrete PID Controller/D Gain'
 * '<S6>'   : 'control1br/Discrete PID Controller/Filter'
 * '<S7>'   : 'control1br/Discrete PID Controller/Filter ICs'
 * '<S8>'   : 'control1br/Discrete PID Controller/I Gain'
 * '<S9>'   : 'control1br/Discrete PID Controller/Ideal P Gain'
 * '<S10>'  : 'control1br/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'control1br/Discrete PID Controller/Integrator'
 * '<S12>'  : 'control1br/Discrete PID Controller/Integrator ICs'
 * '<S13>'  : 'control1br/Discrete PID Controller/N Copy'
 * '<S14>'  : 'control1br/Discrete PID Controller/N Gain'
 * '<S15>'  : 'control1br/Discrete PID Controller/P Copy'
 * '<S16>'  : 'control1br/Discrete PID Controller/Parallel P Gain'
 * '<S17>'  : 'control1br/Discrete PID Controller/Reset Signal'
 * '<S18>'  : 'control1br/Discrete PID Controller/Saturation'
 * '<S19>'  : 'control1br/Discrete PID Controller/Saturation Fdbk'
 * '<S20>'  : 'control1br/Discrete PID Controller/Sum'
 * '<S21>'  : 'control1br/Discrete PID Controller/Sum Fdbk'
 * '<S22>'  : 'control1br/Discrete PID Controller/Tracking Mode'
 * '<S23>'  : 'control1br/Discrete PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'control1br/Discrete PID Controller/postSat Signal'
 * '<S25>'  : 'control1br/Discrete PID Controller/preSat Signal'
 * '<S26>'  : 'control1br/Discrete PID Controller/Anti-windup/Back Calculation'
 * '<S27>'  : 'control1br/Discrete PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S28>'  : 'control1br/Discrete PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S29>'  : 'control1br/Discrete PID Controller/Anti-windup/Disabled'
 * '<S30>'  : 'control1br/Discrete PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S31>'  : 'control1br/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S32>'  : 'control1br/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S33>'  : 'control1br/Discrete PID Controller/D Gain/Disabled'
 * '<S34>'  : 'control1br/Discrete PID Controller/D Gain/External Parameters'
 * '<S35>'  : 'control1br/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S36>'  : 'control1br/Discrete PID Controller/Filter/Cont. Filter'
 * '<S37>'  : 'control1br/Discrete PID Controller/Filter/Differentiator'
 * '<S38>'  : 'control1br/Discrete PID Controller/Filter/Disabled'
 * '<S39>'  : 'control1br/Discrete PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S40>'  : 'control1br/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S41>'  : 'control1br/Discrete PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S42>'  : 'control1br/Discrete PID Controller/Filter ICs/Disabled'
 * '<S43>'  : 'control1br/Discrete PID Controller/Filter ICs/External IC'
 * '<S44>'  : 'control1br/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S45>'  : 'control1br/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S46>'  : 'control1br/Discrete PID Controller/I Gain/Disabled'
 * '<S47>'  : 'control1br/Discrete PID Controller/I Gain/External Parameters'
 * '<S48>'  : 'control1br/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S49>'  : 'control1br/Discrete PID Controller/Ideal P Gain/External Parameters'
 * '<S50>'  : 'control1br/Discrete PID Controller/Ideal P Gain/Internal Parameters'
 * '<S51>'  : 'control1br/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S52>'  : 'control1br/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S53>'  : 'control1br/Discrete PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S54>'  : 'control1br/Discrete PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S55>'  : 'control1br/Discrete PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S56>'  : 'control1br/Discrete PID Controller/Integrator/Continuous'
 * '<S57>'  : 'control1br/Discrete PID Controller/Integrator/Disabled'
 * '<S58>'  : 'control1br/Discrete PID Controller/Integrator/Discrete'
 * '<S59>'  : 'control1br/Discrete PID Controller/Integrator ICs/Disabled'
 * '<S60>'  : 'control1br/Discrete PID Controller/Integrator ICs/External IC'
 * '<S61>'  : 'control1br/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S62>'  : 'control1br/Discrete PID Controller/N Copy/Disabled'
 * '<S63>'  : 'control1br/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S64>'  : 'control1br/Discrete PID Controller/N Copy/External Parameters'
 * '<S65>'  : 'control1br/Discrete PID Controller/N Copy/Internal Parameters'
 * '<S66>'  : 'control1br/Discrete PID Controller/N Gain/Disabled'
 * '<S67>'  : 'control1br/Discrete PID Controller/N Gain/External Parameters'
 * '<S68>'  : 'control1br/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S69>'  : 'control1br/Discrete PID Controller/N Gain/Passthrough'
 * '<S70>'  : 'control1br/Discrete PID Controller/P Copy/Disabled'
 * '<S71>'  : 'control1br/Discrete PID Controller/P Copy/External Parameters Ideal'
 * '<S72>'  : 'control1br/Discrete PID Controller/P Copy/Internal Parameters Ideal'
 * '<S73>'  : 'control1br/Discrete PID Controller/Parallel P Gain/Disabled'
 * '<S74>'  : 'control1br/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S75>'  : 'control1br/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S76>'  : 'control1br/Discrete PID Controller/Parallel P Gain/Passthrough'
 * '<S77>'  : 'control1br/Discrete PID Controller/Reset Signal/Disabled'
 * '<S78>'  : 'control1br/Discrete PID Controller/Reset Signal/External Reset'
 * '<S79>'  : 'control1br/Discrete PID Controller/Saturation/Enabled'
 * '<S80>'  : 'control1br/Discrete PID Controller/Saturation/Passthrough'
 * '<S81>'  : 'control1br/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S82>'  : 'control1br/Discrete PID Controller/Saturation Fdbk/Enabled'
 * '<S83>'  : 'control1br/Discrete PID Controller/Saturation Fdbk/Passthrough'
 * '<S84>'  : 'control1br/Discrete PID Controller/Sum/Passthrough_I'
 * '<S85>'  : 'control1br/Discrete PID Controller/Sum/Passthrough_P'
 * '<S86>'  : 'control1br/Discrete PID Controller/Sum/Sum_PD'
 * '<S87>'  : 'control1br/Discrete PID Controller/Sum/Sum_PI'
 * '<S88>'  : 'control1br/Discrete PID Controller/Sum/Sum_PID'
 * '<S89>'  : 'control1br/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S90>'  : 'control1br/Discrete PID Controller/Sum Fdbk/Enabled'
 * '<S91>'  : 'control1br/Discrete PID Controller/Sum Fdbk/Passthrough'
 * '<S92>'  : 'control1br/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S93>'  : 'control1br/Discrete PID Controller/Tracking Mode/Enabled'
 * '<S94>'  : 'control1br/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S95>'  : 'control1br/Discrete PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S96>'  : 'control1br/Discrete PID Controller/postSat Signal/Feedback_Path'
 * '<S97>'  : 'control1br/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S98>'  : 'control1br/Discrete PID Controller/preSat Signal/Feedback_Path'
 * '<S99>'  : 'control1br/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S100>' : 'control1br/Discrete PID Controller1/Anti-windup'
 * '<S101>' : 'control1br/Discrete PID Controller1/D Gain'
 * '<S102>' : 'control1br/Discrete PID Controller1/Filter'
 * '<S103>' : 'control1br/Discrete PID Controller1/Filter ICs'
 * '<S104>' : 'control1br/Discrete PID Controller1/I Gain'
 * '<S105>' : 'control1br/Discrete PID Controller1/Ideal P Gain'
 * '<S106>' : 'control1br/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S107>' : 'control1br/Discrete PID Controller1/Integrator'
 * '<S108>' : 'control1br/Discrete PID Controller1/Integrator ICs'
 * '<S109>' : 'control1br/Discrete PID Controller1/N Copy'
 * '<S110>' : 'control1br/Discrete PID Controller1/N Gain'
 * '<S111>' : 'control1br/Discrete PID Controller1/P Copy'
 * '<S112>' : 'control1br/Discrete PID Controller1/Parallel P Gain'
 * '<S113>' : 'control1br/Discrete PID Controller1/Reset Signal'
 * '<S114>' : 'control1br/Discrete PID Controller1/Saturation'
 * '<S115>' : 'control1br/Discrete PID Controller1/Saturation Fdbk'
 * '<S116>' : 'control1br/Discrete PID Controller1/Sum'
 * '<S117>' : 'control1br/Discrete PID Controller1/Sum Fdbk'
 * '<S118>' : 'control1br/Discrete PID Controller1/Tracking Mode'
 * '<S119>' : 'control1br/Discrete PID Controller1/Tracking Mode Sum'
 * '<S120>' : 'control1br/Discrete PID Controller1/postSat Signal'
 * '<S121>' : 'control1br/Discrete PID Controller1/preSat Signal'
 * '<S122>' : 'control1br/Discrete PID Controller1/Anti-windup/Back Calculation'
 * '<S123>' : 'control1br/Discrete PID Controller1/Anti-windup/Cont. Clamping Ideal'
 * '<S124>' : 'control1br/Discrete PID Controller1/Anti-windup/Cont. Clamping Parallel'
 * '<S125>' : 'control1br/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S126>' : 'control1br/Discrete PID Controller1/Anti-windup/Disc. Clamping Ideal'
 * '<S127>' : 'control1br/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S128>' : 'control1br/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S129>' : 'control1br/Discrete PID Controller1/D Gain/Disabled'
 * '<S130>' : 'control1br/Discrete PID Controller1/D Gain/External Parameters'
 * '<S131>' : 'control1br/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S132>' : 'control1br/Discrete PID Controller1/Filter/Cont. Filter'
 * '<S133>' : 'control1br/Discrete PID Controller1/Filter/Differentiator'
 * '<S134>' : 'control1br/Discrete PID Controller1/Filter/Disabled'
 * '<S135>' : 'control1br/Discrete PID Controller1/Filter/Disc. Backward Euler Filter'
 * '<S136>' : 'control1br/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S137>' : 'control1br/Discrete PID Controller1/Filter/Disc. Trapezoidal Filter'
 * '<S138>' : 'control1br/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S139>' : 'control1br/Discrete PID Controller1/Filter ICs/External IC'
 * '<S140>' : 'control1br/Discrete PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S141>' : 'control1br/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S142>' : 'control1br/Discrete PID Controller1/I Gain/Disabled'
 * '<S143>' : 'control1br/Discrete PID Controller1/I Gain/External Parameters'
 * '<S144>' : 'control1br/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S145>' : 'control1br/Discrete PID Controller1/Ideal P Gain/External Parameters'
 * '<S146>' : 'control1br/Discrete PID Controller1/Ideal P Gain/Internal Parameters'
 * '<S147>' : 'control1br/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S148>' : 'control1br/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S149>' : 'control1br/Discrete PID Controller1/Ideal P Gain Fdbk/External Parameters'
 * '<S150>' : 'control1br/Discrete PID Controller1/Ideal P Gain Fdbk/Internal Parameters'
 * '<S151>' : 'control1br/Discrete PID Controller1/Ideal P Gain Fdbk/Passthrough'
 * '<S152>' : 'control1br/Discrete PID Controller1/Integrator/Continuous'
 * '<S153>' : 'control1br/Discrete PID Controller1/Integrator/Disabled'
 * '<S154>' : 'control1br/Discrete PID Controller1/Integrator/Discrete'
 * '<S155>' : 'control1br/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S156>' : 'control1br/Discrete PID Controller1/Integrator ICs/External IC'
 * '<S157>' : 'control1br/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S158>' : 'control1br/Discrete PID Controller1/N Copy/Disabled'
 * '<S159>' : 'control1br/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S160>' : 'control1br/Discrete PID Controller1/N Copy/External Parameters'
 * '<S161>' : 'control1br/Discrete PID Controller1/N Copy/Internal Parameters'
 * '<S162>' : 'control1br/Discrete PID Controller1/N Gain/Disabled'
 * '<S163>' : 'control1br/Discrete PID Controller1/N Gain/External Parameters'
 * '<S164>' : 'control1br/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S165>' : 'control1br/Discrete PID Controller1/N Gain/Passthrough'
 * '<S166>' : 'control1br/Discrete PID Controller1/P Copy/Disabled'
 * '<S167>' : 'control1br/Discrete PID Controller1/P Copy/External Parameters Ideal'
 * '<S168>' : 'control1br/Discrete PID Controller1/P Copy/Internal Parameters Ideal'
 * '<S169>' : 'control1br/Discrete PID Controller1/Parallel P Gain/Disabled'
 * '<S170>' : 'control1br/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S171>' : 'control1br/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S172>' : 'control1br/Discrete PID Controller1/Parallel P Gain/Passthrough'
 * '<S173>' : 'control1br/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S174>' : 'control1br/Discrete PID Controller1/Reset Signal/External Reset'
 * '<S175>' : 'control1br/Discrete PID Controller1/Saturation/Enabled'
 * '<S176>' : 'control1br/Discrete PID Controller1/Saturation/Passthrough'
 * '<S177>' : 'control1br/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S178>' : 'control1br/Discrete PID Controller1/Saturation Fdbk/Enabled'
 * '<S179>' : 'control1br/Discrete PID Controller1/Saturation Fdbk/Passthrough'
 * '<S180>' : 'control1br/Discrete PID Controller1/Sum/Passthrough_I'
 * '<S181>' : 'control1br/Discrete PID Controller1/Sum/Passthrough_P'
 * '<S182>' : 'control1br/Discrete PID Controller1/Sum/Sum_PD'
 * '<S183>' : 'control1br/Discrete PID Controller1/Sum/Sum_PI'
 * '<S184>' : 'control1br/Discrete PID Controller1/Sum/Sum_PID'
 * '<S185>' : 'control1br/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S186>' : 'control1br/Discrete PID Controller1/Sum Fdbk/Enabled'
 * '<S187>' : 'control1br/Discrete PID Controller1/Sum Fdbk/Passthrough'
 * '<S188>' : 'control1br/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S189>' : 'control1br/Discrete PID Controller1/Tracking Mode/Enabled'
 * '<S190>' : 'control1br/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S191>' : 'control1br/Discrete PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S192>' : 'control1br/Discrete PID Controller1/postSat Signal/Feedback_Path'
 * '<S193>' : 'control1br/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S194>' : 'control1br/Discrete PID Controller1/preSat Signal/Feedback_Path'
 * '<S195>' : 'control1br/Discrete PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_control1br_h_ */
