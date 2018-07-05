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
#include "font_xbf.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* 宋体16点阵定义 */
#define XBF_Font16BaseAdd 0x00000000
GUI_FONT XBF_Font16;
GUI_XBF_DATA XBF_Data16;
FIL Fontfile16;

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
FATFS fs;
FRESULT ret;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
 * @brief            XBF字体的回调函数, 16点阵
 * @param  Off       地址偏移
 * @param  NumBytes  需要读出的字节数
 * @param  pVoid     指针变量，一般用于带文件系统时的FIL类型变量
 * @param  pBuffer   获取字体的点阵数据
 * @return           0 表示成功 1 表示失败
 */
static int _cbGetData16(U32 Off, U16 NumBytes, void *pVoid, void *pBuffer)
{
    FIL *FontFile;
    UINT bytesread;

    FontFile = (FIL *)pVoid;

    ret = f_lseek(FontFile, Off + XBF_Font16BaseAdd);
    if (ret != FR_OK)
    {
        return 1;
    }

    ret = f_read(FontFile, pBuffer, NumBytes, &bytesread);
    if (ret != FR_OK)
    {
        return 1;
    }

    return 0;
}

/* Public functions ----------------------------------------------------------*/
/**
 * @brief  挂载Flash文件系统
 */
void GUI_MountFlash(void)
{
    ret = f_mount(&fs, "", 0);
    if (ret != FR_OK)
    {
        return;
    }
}

/**
 * @brief  创建XBF字体
 */
void GUI_SetXBF(void)
{
    ret = f_open(&Fontfile16, "font.bin", FA_READ);
    if (ret != FR_OK)
    {
        return;
    }

    /* 创建16点阵字体 */
    GUI_XBF_CreateFont(&XBF_Font16,       /* GUI_FONT类型变量     */
                       &XBF_Data16,       /* GUI_XBF_DATA类型变量 */
                       GUI_XBF_TYPE_PROP, /* 字体类型             */
                       _cbGetData16,      /* 回调函数             */
                       &Fontfile16);      /* 回调函数参数         */
}
