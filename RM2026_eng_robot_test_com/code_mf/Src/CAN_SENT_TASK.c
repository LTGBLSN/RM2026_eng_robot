//
// Created by 21481 on 2026/1/30.
//



#include "cmsis_os.h"
#include "DJI_motors.h"
#include "remote_control.h"
#include "can_receive.h"
#include "dm_motor.h"
#include "GET_RC_TASK.h"
#include "CAN_SENT_TASK.h"
#include "ERROR_DETECTION.h"

void CAN_SENT_TASK()
{
    while (1)
    {
        switch (rcData.rc.s_only_tvm[2])
        {
            case 0:
            {
                FDCAN_DJI_motors(0, 0, 0, 0, 0x200, CAN_CHANNEL_2);
                FDCAN_DJI_motors(0, 0, 0, 0, 0x1FF, CAN_CHANNEL_2);
                DM_CAN_SENT(DM_NO_CURRENT);
                break;
            }

            case 1:
            {//起立但轮毂不动
                {


                    FDCAN_DJI_motors(0, 0, 0, 0, 0x200, CAN_CHANNEL_2);
                    FDCAN_DJI_motors(0, 0, 0, 0, 0x1FF, CAN_CHANNEL_2);
                    DM_CAN_SENT(DM_GIVE_CURRENT);
                    break;
                }
            }

            case 2:
            {//移动
                FDCAN_DJI_motors(
                        CHASSIS_3508_ID1_GIVEN_CURRENT,
                        CHASSIS_3508_ID2_GIVEN_CURRENT,
                        CHASSIS_3508_ID3_GIVEN_CURRENT,
                        CHASSIS_3508_ID4_GIVEN_CURRENT,
                        0x200, CAN_CHANNEL_2);

                FDCAN_DJI_motors(
                        CHASSIS_3508_ID5_GIVEN_CURRENT,
                        CHASSIS_3508_ID6_GIVEN_CURRENT,
                        0,
                        0,
                        0x1FF, CAN_CHANNEL_2);

                DM_CAN_SENT(DM_GIVE_CURRENT);
                break;
            }

            default:
            {
                FDCAN_DJI_motors(0, 0, 0, 0, 0x200, CAN_CHANNEL_2);
                FDCAN_DJI_motors(0, 0, 0, 0, 0x1FF, CAN_CHANNEL_2);
                DM_CAN_SENT(DM_NO_CURRENT);



                break;
            }


        }

        osDelay(1);
    }
}





void DM_CAN_SENT(uint8_t DM_can_sent_state)
{
    //第一个电机
    if(DM4340_01.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4340_01.can_channel, DM4340_01.can_id, DM4340_01.motor_type, DM4340_01.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4340_01.can_channel, DM4340_01.can_id, DM4340_01.motor_type, 0.0f);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else//电机保活
    {
        dm_motor_mode_set(CMD_ENABLE_MODE, CAN_CHANNEL_1,DM4340_01.can_id);
    }


    //第二个电机
    if(DM4340_02.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4340_02.can_channel, DM4340_02.can_id, DM4340_02.motor_type, DM4340_02.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4340_02.can_channel, DM4340_02.can_id, DM4340_02.motor_type, 0.0f);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else//电机保活
    {
        dm_motor_mode_set(CMD_ENABLE_MODE, CAN_CHANNEL_1,DM4340_02.can_id);
    }

    //第三个电机
    if(DM4340_03.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4340_03.can_channel, DM4340_03.can_id, DM4340_03.motor_type, DM4340_03.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4340_03.can_channel, DM4340_03.can_id, DM4340_03.motor_type, 0.0f);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else//电机保活
    {
        dm_motor_mode_set(CMD_ENABLE_MODE, CAN_CHANNEL_1,DM4340_03.can_id);
    }


    //第四个电机
    if(DM4340_04.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4340_04.can_channel, DM4340_04.can_id, DM4340_04.motor_type, DM4340_04.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4340_04.can_channel, DM4340_04.can_id, DM4340_04.motor_type, 0.0f);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else//电机保活
    {
        dm_motor_mode_set(CMD_ENABLE_MODE, CAN_CHANNEL_1,DM4340_04.can_id);
    }


}

