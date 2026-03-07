//
// Created by 21481 on 2026/3/2.
//

#include "main.h"
#include "fdcan.h"
#include "cmsis_os.h"
#include "BOARD_COMMUNICATION_TASK.h"
#include "can_receive.h"
#include "GET_RC_TASK.h"

struct follow_arm_data follow_arm;

void BOARD_COMMUNICATION_TASK()
{
    while (1)
    {

//        chassis_motor_0_3_2_arm(follow_arm.motor0,
//                                follow_arm.motor1,
//                                follow_arm.motor2,
//                                follow_arm.motor3,
//                                0xA1,
//                                CAN_CHANNEL_3);
//
//
//        chassis_motor_4_clamp_state_2_arm(follow_arm.motor4,
//                                          follow_arm.motor5,
//                                          follow_arm.clamp,
//                                          follow_arm.stateA,
//                                          follow_arm.stateB,
//                                          0xA2,
//                                          CAN_CHANNEL_3);
//        chassis_rc_2_arm(0,
//                         rcData.rc.s_only_tvm[1],
//                         rcData.rc.ch[0],
//                         rcData.rc.ch[1],
//                         0x1C,
//                         CAN_CHANNEL_3);
//
//        chassis_rc_2_arm(0,
//                         rcData.rc.s_only_tvm[2],
//                         rcData.rc.ch[2],
//                         rcData.rc.ch[3],
//                         0x2C,
//                         CAN_CHANNEL_3);





        osDelay(1);
    }
}

void chassis_motor_4_clamp_state_2_arm(int16_t motor4 , int16_t motor5 , int16_t clamp , uint8_t stateA , uint8_t stateB , uint16_t id, uint8_t can_channel)
{
    // 假设这些全局变量已经定义，或者在函数内部定义
    FDCAN_TxHeaderTypeDef tx_message;
    uint8_t can_send_data[8];

    // 1. 配置发送报文头部
    tx_message.Identifier = id;
    tx_message.IdType = FDCAN_STANDARD_ID;   // 标准 ID
    tx_message.TxFrameType = FDCAN_DATA_FRAME; // 数据帧
    tx_message.DataLength = FDCAN_DLC_BYTES_8; // 数据长度：8字节

    // 以下是 FDCAN 特有的配置项，因你用的是 Classic Mode，全设为 OFF/Disable
    tx_message.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    tx_message.BitRateSwitch = FDCAN_BRS_OFF;      // 不开启速率切换
    tx_message.FDFormat = FDCAN_CLASSIC_CAN;       // 经典 CAN 模式
    tx_message.TxEventFifoControl = FDCAN_NO_TX_EVENTS; // 不保存发送事件
    tx_message.MessageMarker = 0;                  // 消息标记

    // 2. 填充数据（大端模式：高8位在前，低8位在后）
    can_send_data[0] = motor4 >> 8;
    can_send_data[1] = motor4;
    can_send_data[2] = motor5 >> 8;
    can_send_data[3] = motor5;
    can_send_data[4] = clamp >> 8;
    can_send_data[5] = clamp;
    can_send_data[6] = stateA;
    can_send_data[7] = stateB;

    // 3. 发送函数：FDCAN 使用的是 AddMessageToTxFifoQ
    if (can_channel == 1)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &tx_message, can_send_data) != HAL_OK)
        {
        }
    }
    else if (can_channel == 2)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &tx_message, can_send_data) != HAL_OK)
        {
        }
    } else if (can_channel == 3)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &tx_message, can_send_data) != HAL_OK)
        {
        }
    }
}


void chassis_motor_0_3_2_arm(int16_t motor0 , int16_t motor1 , int16_t motor2 , int16_t motor3 , uint16_t id, uint8_t can_channel)
{
    // 假设这些全局变量已经定义，或者在函数内部定义
    FDCAN_TxHeaderTypeDef tx_message;
    uint8_t can_send_data[8];

    // 1. 配置发送报文头部
    tx_message.Identifier = id;
    tx_message.IdType = FDCAN_STANDARD_ID;   // 标准 ID
    tx_message.TxFrameType = FDCAN_DATA_FRAME; // 数据帧
    tx_message.DataLength = FDCAN_DLC_BYTES_8; // 数据长度：8字节

    // 以下是 FDCAN 特有的配置项，因你用的是 Classic Mode，全设为 OFF/Disable
    tx_message.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    tx_message.BitRateSwitch = FDCAN_BRS_OFF;      // 不开启速率切换
    tx_message.FDFormat = FDCAN_CLASSIC_CAN;       // 经典 CAN 模式
    tx_message.TxEventFifoControl = FDCAN_NO_TX_EVENTS; // 不保存发送事件
    tx_message.MessageMarker = 0;                  // 消息标记

    // 2. 填充数据（大端模式：高8位在前，低8位在后）
    can_send_data[0] = motor0 >> 8;
    can_send_data[1] = motor0;
    can_send_data[2] = motor1 >> 8;
    can_send_data[3] = motor1;
    can_send_data[4] = motor2 >> 8;
    can_send_data[5] = motor2;
    can_send_data[6] = motor3 >> 8;;
    can_send_data[7] = motor3;

    // 3. 发送函数：FDCAN 使用的是 AddMessageToTxFifoQ
    if (can_channel == 1)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &tx_message, can_send_data) != HAL_OK)
        {
        }
    }
    else if (can_channel == 2)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &tx_message, can_send_data) != HAL_OK)
        {
        }
    } else if (can_channel == 3)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &tx_message, can_send_data) != HAL_OK)
        {
        }
    }
}



void chassis_rc_2_arm(int16_t data , int16_t rc_s , int16_t rc_ch_A , int16_t rc_ch_B , uint16_t id, uint8_t can_channel)
{
    // 假设这些全局变量已经定义，或者在函数内部定义
    FDCAN_TxHeaderTypeDef tx_message;
    uint8_t can_send_data[8];

    // 1. 配置发送报文头部
    tx_message.Identifier = id;
    tx_message.IdType = FDCAN_STANDARD_ID;   // 标准 ID
    tx_message.TxFrameType = FDCAN_DATA_FRAME; // 数据帧
    tx_message.DataLength = FDCAN_DLC_BYTES_8; // 数据长度：8字节

    // 以下是 FDCAN 特有的配置项，因你用的是 Classic Mode，全设为 OFF/Disable
    tx_message.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    tx_message.BitRateSwitch = FDCAN_BRS_OFF;      // 不开启速率切换
    tx_message.FDFormat = FDCAN_CLASSIC_CAN;       // 经典 CAN 模式
    tx_message.TxEventFifoControl = FDCAN_NO_TX_EVENTS; // 不保存发送事件
    tx_message.MessageMarker = 0;                  // 消息标记

    // 2. 填充数据（大端模式：高8位在前，低8位在后）
    can_send_data[0] = data >> 8;
    can_send_data[1] = data;
    can_send_data[2] = rc_s >> 8;
    can_send_data[3] = rc_s;
    can_send_data[4] = rc_ch_A >> 8;
    can_send_data[5] = rc_ch_A;
    can_send_data[6] = rc_ch_B >> 8;;
    can_send_data[7] = rc_ch_B;

    // 3. 发送函数：FDCAN 使用的是 AddMessageToTxFifoQ
    if (can_channel == 1)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &tx_message, can_send_data) != HAL_OK)
        {
        }
    }
    else if (can_channel == 2)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &tx_message, can_send_data) != HAL_OK)
        {
        }
    } else if (can_channel == 3)
    {
        if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &tx_message, can_send_data) != HAL_OK)
        {
        }
    }
}

