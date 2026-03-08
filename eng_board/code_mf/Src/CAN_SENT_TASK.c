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
        switch (rcData.rc.s[1])
        {
            case 0:
            {
                DM_CAN_SENT(DM_NO_CURRENT);
                break;
            }

            case 1:
            {
                DM_CAN_SENT(DM_GIVE_CURRENT);
                break;

            }

            case 2:
            {
                DM_CAN_SENT(DM_GIVE_CURRENT);
                break;
            }

            default:
            {
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
    if(DM4310_01.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4310_01.can_channel, DM4310_01.can_id, DM4310_01.motor_type, DM4310_01.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4310_01.can_channel, DM4310_01.can_id, DM4310_01.motor_type, 0.0f);
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
        dm_motor_mode_set(CMD_ENABLE_MODE, DM4310_01.can_channel, DM4310_01.can_id);
    }


    //第二个电机
    if(DM4310_02.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4310_02.can_channel, DM4310_02.can_id, DM4310_02.motor_type, DM4310_02.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4310_02.can_channel, DM4310_02.can_id, DM4310_02.motor_type, 0.0f);
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
        dm_motor_mode_set(CMD_ENABLE_MODE, DM4310_02.can_channel, DM4310_02.can_id);
    }

    //第三个电机
    if(DM4310_03.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4310_03.can_channel, DM4310_03.can_id, DM4310_03.motor_type, DM4310_03.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4310_03.can_channel, DM4310_03.can_id, DM4310_03.motor_type, 0.0f);
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
        dm_motor_mode_set(CMD_ENABLE_MODE, DM4310_03.can_channel, DM4310_03.can_id);
    }


    //第四个电机
    if(DM4310_04.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4310_04.can_channel, DM4310_04.can_id, DM4310_04.motor_type, DM4310_04.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4310_04.can_channel, DM4310_04.can_id, DM4310_04.motor_type, 0.0f);
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
        dm_motor_mode_set(CMD_ENABLE_MODE, DM4310_04.can_channel, DM4310_04.can_id);
    }

    //第5个电机
    if(DM4340_05.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4340_05.can_channel, DM4340_05.can_id, DM4340_05.motor_type, DM4340_05.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4340_05.can_channel, DM4340_05.can_id, DM4340_05.motor_type, 0.0f);
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
        dm_motor_mode_set(CMD_ENABLE_MODE, DM4340_05.can_channel,DM4340_05.can_id);
    }


    //第6个电机
    if(DM4340_06.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4340_06.can_channel, DM4340_06.can_id, DM4340_06.motor_type, DM4340_06.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4340_06.can_channel, DM4340_06.can_id, DM4340_06.motor_type, 0.0f);
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
        dm_motor_mode_set(CMD_ENABLE_MODE, DM4340_06.can_channel,DM4340_06.can_id);
    }


    //第七个电机
    if(DM4340_07.online_state == DM_MOTOR_SAFE)
    {
        switch (DM_can_sent_state)
        {
            case DM_GIVE_CURRENT:
            {
                Dm_Can_Send(DM4340_07.can_channel, DM4340_07.can_id, DM4340_07.motor_type, DM4340_07.give_tor);
                break;
            }
            case DM_NO_CURRENT:
            {
                Dm_Can_Send(DM4340_07.can_channel, DM4340_07.can_id, DM4340_07.motor_type, 0.0f);
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
        dm_motor_mode_set(CMD_ENABLE_MODE, DM4340_07.can_channel,DM4340_07.can_id);
    }


}

