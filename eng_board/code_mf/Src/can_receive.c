//
// Created by 21481 on 2026/1/30.
//


#include "main.h"
#include "DJI_motors.h"
#include "dm_motor.h"
#include "can_receive.h"
#include "GET_RC_TASK.h"
#include "BOARD_COMMUNICATION_TASK.h"

//motor data read
#define get_motor_measure(ptr, data)                                    \
    {                                                                   \
        (ptr)->last_ecd = (ptr)->ecd;                                   \
        (ptr)->ecd = (uint16_t)((data)[0] << 8 | (data)[1]);            \
        (ptr)->speed_rpm = (uint16_t)((data)[2] << 8 | (data)[3]);      \
        (ptr)->given_current = (uint16_t)((data)[4] << 8 | (data)[5]);  \
        (ptr)->temperate = (data)[6];                                   \
    }
/**
  * @brief          HAL库FDCAN接收回调函数
  * @param[in]      hfdcan: FDCAN句柄指针
  * @param[in]      RxFifo0ITs: 中断类型标识
  * @retval         none
  */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
    // 检查是否是“收到新消息”中断
    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != 0)
    {
        FDCAN_RxHeaderTypeDef rx_header;
        uint8_t rx_data[8];

        // 1. 从 FIFO0 获取报文
        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rx_header, rx_data) != HAL_OK)
        {
            return;
        }

        // 2. 判断是哪一路 CAN
        if (hfdcan->Instance == FDCAN1)
        {
            // FDCAN1 逻辑
            switch (rx_header.Identifier) // F4是StdId，H7是Identifier
            {
                case 0x201:
                case 0x202:
                case 0x203:
                case 0x204:
                case 0x205:
                case 0x206:
                case 0x207:
                {
                    uint8_t i = rx_header.Identifier - 0x201;
                    get_motor_measure(&motor_can1_data[i], rx_data);
                    break;
                }


                case 0x11:
                {
                    DM_motors_parse(&DM4310_01, rx_data);
                    DM4310_01.last_online_time = HAL_GetTick() ;
                    break;
                }
                case 0x12:
                {
                    DM_motors_parse(&DM4310_02, rx_data);
                    DM4310_02.last_online_time = HAL_GetTick() ;
                    break;
                }
                case 0x13:
                {
                    DM_motors_parse(&DM4310_03, rx_data);
                    DM4310_03.last_online_time = HAL_GetTick() ;
                    break;
                }
                case 0x14:
                {
                    DM_motors_parse(&DM4310_04, rx_data);
                    DM4310_04.last_online_time = HAL_GetTick() ;
                    break;
                }
                default:
                    break;
            }
        }
        else if (hfdcan->Instance == FDCAN2)
        {
            // FDCAN2 逻辑
            switch (rx_header.Identifier)
            {
                case 0x201:
                case 0x202:
                case 0x203:
                case 0x204:
                case 0x205:
                case 0x206:
                case 0x207:
                {
                    uint8_t i = rx_header.Identifier - 0x201;
                    get_motor_measure(&motor_can2_data[i], rx_data);
                    break;
                }

                case 0x15:
                {
                    DM_motors_parse(&DM4340_05, rx_data);
                    DM4340_05.last_online_time = HAL_GetTick() ;
                    break;
                }

                case 0x16:
                {
                    DM_motors_parse(&DM4340_06, rx_data);
                    DM4340_06.last_online_time = HAL_GetTick() ;
                    break;
                }

                case 0x17:
                {
                    DM_motors_parse(&DM4340_07, rx_data);
                    DM4340_07.last_online_time = HAL_GetTick() ;
                    break;
                }
                default:
                    break;
            }
        }

        else if (hfdcan->Instance == FDCAN3)
        {
            // FDCAN3 逻辑
            switch (rx_header.Identifier)
            {
                case 0x201:
                case 0x202:
                case 0x203:
                case 0x204:
                case 0x205:
                case 0x206:
                case 0x207:
                {
                    uint8_t i = rx_header.Identifier - 0x201;
                    get_motor_measure(&motor_can3_data[i], rx_data);
                    break;
                }




                case 0x1C:
                {
                    int16_t DATA_CUSTOM_A ;//这里为自定义数据A，可改成任意从自定义控制器传过来的数据A

                    DATA_CUSTOM_A = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    rcData.rc.s[0] = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    rcData.rc.ch[0] = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    rcData.rc.ch[1] = (int16_t)((rx_data[6] << 8) | rx_data[7]);
                    break;
                }
                case 0x2C:
                {
                    int16_t DATA_CUSTOM_B ;//这里为自定义数据A，可改成任意从自定义控制器传过来的数据B

                    DATA_CUSTOM_B   = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    rcData.rc.s[1]  = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    rcData.rc.ch[2] = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    rcData.rc.ch[3] = (int16_t)((rx_data[6] << 8) | rx_data[7]);
                    break;
                }
                case 0xA1:
                {
                    follow_arm.motor0 = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    follow_arm.motor1 = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    follow_arm.motor2 = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    follow_arm.motor3 = (int16_t)((rx_data[6] << 8) | rx_data[7]);
                    break;
                }
                case 0xA2:
                {
                    follow_arm.motor4 = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    follow_arm.motor5 = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    follow_arm.clamp = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    follow_arm.stateA = rx_data[6];
                    follow_arm.stateB = rx_data[7];
                    break;
                }

                default:
                    break;
            }
        }
    }
}


/**
 * @brief  解析达妙电机反馈数据并更新到指定结构体
 * @param  motor_ptr: 指向对应电机结构体的指针 (例如 &DM4340_01)
 * @param  rx_DM_data: 接收到的 8 字节原始数据
 */
void DM_motors_parse(struct dm_motor *motor_ptr, const uint8_t rx_DM_data[8])
{
    if (motor_ptr == NULL) return;

    int p_int;
    int v_int;
    int t_int;

    // 1. 解析原始数据
    motor_ptr->state = (rx_DM_data[0]) >> 4;
    p_int = (rx_DM_data[1] << 8) | rx_DM_data[2];
    v_int = (rx_DM_data[3] << 4) | (rx_DM_data[4] >> 4);
    t_int = ((rx_DM_data[4] & 0xF) << 8) | rx_DM_data[5];

    // 2. 转换并仅更新反馈数成员，不触碰其他成员
    motor_ptr->return_angle = uint_to_float(p_int, DM4340_P_MIN, DM4340_P_MAX, 16);
    motor_ptr->return_speed = uint_to_float(v_int, DM4340_V_MIN, DM4340_V_MAX, 12);
    motor_ptr->return_tor   = uint_to_float(t_int, DM4340_T_MIN, DM4340_T_MAX, 12);
    motor_ptr->Tmos         = (float)(rx_DM_data[6]);
    motor_ptr->Tcoil        = (float)(rx_DM_data[7]);

    // 此时，motor_ptr->target_angle 等其他成员完全不会被改变
}