/*
 * sys_service.h
 *
 *  This file is the header for all standard types used in the API code.
 *
 * Copyright (c) 2010, Zarlink Semiconductor, Inc.
 */
#ifndef SYS_SERVICE_H
#define SYS_SERVICE_H
#include "vp_api_types.h"
/* Critical section types */
typedef enum {
	VP_MPI_CRITICAL_SEC, 	/* MPI access critical code section */
	VP_HBI_CRITICAL_SEC, 	/* HBI access critical code section */
	VP_CODE_CRITICAL_SEC, 	/* Critical code section */
	VP_NUM_CRITICAL_SEC_TYPES, /* The number of critical section types */
    VP_CRITICAL_SEC_ENUM_SIZE = FORCE_STANDARD_C_ENUM_SIZE /* Portability Req. */
} VpCriticalSecType;
EXTERN uint8
VpSysEnterCritical(
    VpDeviceIdType deviceId,
    VpCriticalSecType criticalSecType);
EXTERN uint8
VpSysExitCritical(
    VpDeviceIdType deviceId,
    VpCriticalSecType criticalSecType);
EXTERN void
VpSysWait(
    uint8 time);
EXTERN void
VpSysDisableInt(
    VpDeviceIdType deviceId);
EXTERN void
VpSysEnableInt(
    VpDeviceIdType deviceId);
EXTERN bool
VpSysTestInt(
    VpDeviceIdType deviceId);
EXTERN void
VpSysDtmfDetEnable(
    VpDeviceIdType deviceId,
    uint8 channelId);
EXTERN void
VpSysDtmfDetDisable(
    VpDeviceIdType deviceId,
    uint8 channelId);

EXTERN void *
VpSysTestHeapAcquire(
    uint8 *pHeapId);
EXTERN bool
VpSysTestHeapRelease(
    uint8 heapId);
EXTERN void
VpSysPcmCollectAndProcess(
    void *pLineCtx,
    VpDeviceIdType deviceId,
    uint8 channelId,
    uint8 startTimeslot,
    uint16 operationTime,
    uint16 settlingTime,
    uint16 operationMask);

/* Enable the XML tag <DBG> debug output </DBG>  */
#undef ENABLE_DBG_TAG

#ifdef D2MOD_VP
#else
#include <stdio.h>
#endif

#ifdef ENABLE_DBG_TAG
    #include <stdarg.h>
    EXTERN int
    VpSysDebugPrintf(
        const char *format, ...);
#else
    #ifdef D2MOD_VP
        #define VpSysDebugPrintf printk        /* D2MOD  --  kernel debugging */
    #else
        #define VpSysDebugPrintf printf
    #endif
#endif /* ENABLE_DBG_TAG */

#endif /* SYS_SERVICE_H */

