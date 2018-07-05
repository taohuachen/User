/**
 *******************************************************************************
 * @file    : 
 * @author  : 
 * @version : 
 * @date    : 
 * @brief   : 
 *******************************************************************************
 * @attention
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "app.h"
#include "SEGGER_SYSVIEW.h"

/* Variables -----------------------------------------------------------------*/
osThreadId StartTaskHandle;

osSemaphoreId CDC_TxBinarySemHandle;
osSemaphoreId CDC_RxBinarySemHandle;

/* Function prototypes -------------------------------------------------------*/
/* Init FreeRTOS */
void MX_FREERTOS_Init(void)
{
    /* 初始化SystemView */
    SEGGER_SYSVIEW_Conf();

    /* 创建线程 */
    osThreadDef(StartTask, StartTaskFunc, osPriorityNormal, 0, 128);
    StartTaskHandle = osThreadCreate(osThread(StartTask), NULL);

    /* 创建通信工具 */
    osSemaphoreDef(CDC_TxBinarySem);
    CDC_TxBinarySemHandle = osSemaphoreCreate(osSemaphore(CDC_TxBinarySem), 1);

    osSemaphoreDef(CDC_RxBinarySem);
    CDC_RxBinarySemHandle = osSemaphoreCreate(osSemaphore(CDC_RxBinarySem), 1);

    /* 启动RTOS */
    osKernelStart();
}

/* This function handles System tick timer */
void SysTick_Handler(void)
{
    osSystickHandler();
}
