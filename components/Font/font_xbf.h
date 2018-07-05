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
#ifndef __FONT_XBF_H
#define __FONT_XBF_H

/* Includes ------------------------------------------------------------------*/
#include "GUI.h"
#include "fatfs.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
extern GUI_FONT XBF_Font16;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void GUI_MountFlash(void);
void GUI_SetXBF(void);

/* End of define module include ----------------------------------------------*/
#endif