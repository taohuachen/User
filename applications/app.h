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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_H
#define __APP_H

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "led.h"

/* Variables -----------------------------------------------------------------*/
extern osSemaphoreId CDC_TxBinarySemHandle;
extern osSemaphoreId CDC_RxBinarySemHandle;

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void MX_FREERTOS_Init(void);
void StartTaskFunc(void const *argument);

/* End of define module include ----------------------------------------------*/
#endif
