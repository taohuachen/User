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
#include "buffer.h"
#include "usbd_cdc_if.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern BUFFER_TypeDef CDC_TxBuffer;
extern BUFFER_TypeDef CDC_RxBuffer;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
void StartTaskFunc(void const *argument)
{
    uint32_t len;

    for (;;)
    {
        osSemaphoreWait(CDC_RxBinarySemHandle, osWaitForever);
        len = Buffer_DataLen(&CDC_RxBuffer);
        Buffer_Read(&CDC_RxBuffer, CDC_TxBuffer.DataPtr, len);
        CDC_Transmit_FS(CDC_TxBuffer.DataPtr, len);
        osSemaphoreWait(CDC_TxBinarySemHandle, osWaitForever);
        
        LED_Toggle();
        osDelay(500);
    }
}
