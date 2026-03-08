//
// Created by 21481 on 2026/2/14.
//



#include <string.h>
#include "remote_control.h"
#include "usart.h"

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef * huart, uint16_t Size)
{

    if(huart->Instance == UART5)
    {

#if REMOTE_TYPE == SBUS
        if (Size <= SBUS_BUFF_SIZE)
        {
            HAL_UARTEx_ReceiveToIdle_DMA(&huart5, rx_subs_buff, SBUS_BUFF_SIZE * 2); // 接收完毕后重启
            sbus_frame_parse(&sbus_remoter, rx_subs_buff);
//			memset(rx_buff, 0, BUFF_SIZE);
        }
        else  // 接收数据长度大于BUFF_SIZE，错误处理
        {
            HAL_UARTEx_ReceiveToIdle_DMA(&huart5, rx_subs_buff, SBUS_BUFF_SIZE * 2); // 接收完毕后重启
            memset(rx_subs_buff, 0, SBUS_BUFF_SIZE);
        }
#endif

#if REMOTE_TYPE == DBUS
        // DBUS一帧固定18字节
        if (Size == DBUS_FRAME_SIZE)
        {
            dbus_frame_parse(&dbus_remoter, rx_dbus_buff);
        }

        // 重新开启DMA接收
        HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_dbus_buff, DBUS_BUFF_SIZE);
        // 注意：H7开启了Cache时，可能需要在这里处理DCache的一致性 (SCB_InvalidateDCache_by_Addr)
#endif
    }
    if(huart->Instance == UART7)
    {
        // --- 遥控器包处理 ---
        if (rx_VTM_buff[0] == 0xA9)
        {
            Process_VTM_Data(rx_VTM_buff, Size);
        }
            // --- 自定义控制器/裁判系统处理 (以后扩展用) ---
        else if (rx_VTM_buff[0] == 0xA5)
        {

            // 这里可以写另一个函数，如 Process_Referee_Data(rx_VTM_buff, Size);
            Process_Custom_Controller_Data(rx_VTM_buff, Size);

        }



        HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_VTM_buff, VTM_ALL_BUFF_SIZE);
    }




}


void HAL_UART_ErrorCallback(UART_HandleTypeDef * huart)
{
    if(huart->Instance == UART5)
    {
#if REMOTE_TYPE == SBUS
        HAL_UARTEx_ReceiveToIdle_DMA(&huart5, rx_subs_buff, SBUS_BUFF_SIZE * 2); // 接收发生错误后重启
        memset(rx_subs_buff, 0, SBUS_BUFF_SIZE);							   // 清除接收缓存
#endif

#if REMOTE_TYPE == DBUS
        HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_dbus_buff, DBUS_BUFF_SIZE);
#endif

    }
    if(huart->Instance == UART7)
    {
        HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_VTM_buff, VTM_ALL_BUFF_SIZE);
    }




}