/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file       can_receive.c/h
  * @brief      there is CAN interrupt function  to receive motor data,
  *             and CAN send function to send motor current to control motor.
  *             ������CAN�жϽ��պ��������յ������,CAN���ͺ������͵���������Ƶ��.
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Dec-26-2018     RM              1. done
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */

#include "CAN_receive.h"
#include "main.h"
#include "gimbal_motor_control.h"


extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;
//motor data read
#define get_motor_measure(ptr, data)                                    \
    {                                                                   \
        (ptr)->last_ecd = (ptr)->ecd;                                   \
        (ptr)->ecd = (uint16_t)((data)[0] << 8 | (data)[1]);            \
        (ptr)->speed_rpm = (uint16_t)((data)[2] << 8 | (data)[3]);      \
        (ptr)->given_current = (uint16_t)((data)[4] << 8 | (data)[5]);  \
        (ptr)->temperate = (data)[6];                                   \
    }
/*
motor data,  0:chassis motor1 3508;1:chassis motor3 3508;2:chassis motor3 3508;3:chassis motor4 3508;
4:yaw gimbal_vx motor 6020;5:pitch gimbal_vx motor 6020;6:trigger motor 2006;
�������, 0:���̵��1 3508���,  1:���̵��2 3508���,2:���̵��3 3508���,3:���̵��4 3508���;
4:yaw��̨��� 6020���; 5:pitch��̨��� 6020���; 6:������� 2006���*/
motor_measure_t motor_can1_data[7];
motor_measure_t motor_can2_data[7];

static CAN_TxHeaderTypeDef  shoot1234_tx_message;
static uint8_t              shoot1234_can_send_data[8];
static CAN_TxHeaderTypeDef  shoot5678_tx_message;
static uint8_t              shoot5678_can_send_data[8];
static CAN_TxHeaderTypeDef  chassis_tx_message;
static uint8_t              chassis_can_send_data[8];
static CAN_TxHeaderTypeDef  yaw_tx_message;
static uint8_t              yaw_can_send_data[8];

/**
  * @brief          hal CAN fifo call back, receive motor data
  * @param[in]      hcan, the point to CAN handle
  * @retval         none
  */
/**
  * @brief          hal��CAN�ص�����,���յ������
  * @param[in]      hcan:CAN���ָ��
  * @retval         none
  */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if(hcan == &hcan1)
    {
        CAN_RxHeaderTypeDef can1_rx_header;
        uint8_t can1_rx_data[8];

        HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &can1_rx_header, can1_rx_data);

        switch (can1_rx_header.StdId)
        {
            case CAN_3508_M1_ID:
            case CAN_3508_M2_ID:
            case CAN_3508_M3_ID:
            case CAN_3508_M4_ID:
            case CAN_YAW_MOTOR_ID:
            case CAN_PIT_MOTOR_ID:
            case CAN_TRIGGER_MOTOR_ID:
            {
                static uint8_t i = 0;
                //get motor id
                i = can1_rx_header.StdId - CAN_3508_M1_ID;
                get_motor_measure(&motor_can1_data[i], can1_rx_data);
                break;
            }

            default:
            {
                break;
            }
        }
    } else if(hcan == &hcan2)
    {
        CAN_RxHeaderTypeDef can2_rx_header;
        uint8_t can2_rx_data[8];

        HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &can2_rx_header, can2_rx_data);

        switch (can2_rx_header.StdId)
        {
            case CAN_3508_M1_ID:
            case CAN_3508_M2_ID:
            case CAN_3508_M3_ID:
            case CAN_3508_M4_ID:
            case CAN_YAW_MOTOR_ID:
            case CAN_PIT_MOTOR_ID:
            case CAN_TRIGGER_MOTOR_ID:
            {
                static uint8_t i = 0;
                //get motor id
                i = can2_rx_header.StdId - CAN_3508_M1_ID;
                get_motor_measure(&motor_can2_data[i], can2_rx_data); // ע������ʹ���� motor_can2_data ����
                break;
            }

            default:
            {
                break;
            }
        }
//        pitch_motor_mean_speed_compute();//pitch�ٶȾ�ֵ�˲� ����
    }
}




void CAN1_cmd_chassis(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4)
{
    uint32_t send_mail_box;
    chassis_tx_message.StdId = CAN_CHASSIS_ALL_ID;
    chassis_tx_message.IDE = CAN_ID_STD;
    chassis_tx_message.RTR = CAN_RTR_DATA;
    chassis_tx_message.DLC = 0x08;
    chassis_can_send_data[0] = motor1 >> 8;
    chassis_can_send_data[1] = motor1;
    chassis_can_send_data[2] = motor2 >> 8;
    chassis_can_send_data[3] = motor2;
    chassis_can_send_data[4] = motor3 >> 8;
    chassis_can_send_data[5] = motor3;
    chassis_can_send_data[6] = motor4 >> 8;
    chassis_can_send_data[7] = motor4;

    HAL_CAN_AddTxMessage(&hcan1, &chassis_tx_message, chassis_can_send_data, &send_mail_box);
}

//����can2����������ͺ���
void CAN1_cmd_yaw_pitch_toggle(int16_t pitch, int16_t yaw, int16_t motor3, int16_t motor4)
{
    uint32_t send_mail_box;
    yaw_tx_message.StdId = CAN_GIMBAL_ALL_ID_1_4;
    yaw_tx_message.IDE = CAN_ID_STD;
    yaw_tx_message.RTR = CAN_RTR_DATA;
    yaw_tx_message.DLC = 0x08;
    yaw_can_send_data[0] = pitch >> 8;
    yaw_can_send_data[1] = pitch;
    yaw_can_send_data[2] = yaw >> 8;
    yaw_can_send_data[3] = yaw;
    yaw_can_send_data[4] = motor3 >> 8;
    yaw_can_send_data[5] = motor3;
    yaw_can_send_data[6] = motor4 >> 8;
    yaw_can_send_data[7] = motor4;

    HAL_CAN_AddTxMessage(&hcan1, &yaw_tx_message, yaw_can_send_data, &send_mail_box);
}

//Ħ���ֵ���������ͺ���
void CAN2_cmd_friction_wheels_1234(int16_t friction_wheel1, int16_t friction_wheel2, int16_t friction_wheel3, int16_t friction_wheel4)
{
    uint32_t send_mail_box;
    shoot1234_tx_message.StdId = CAN_CHASSIS_ALL_ID;
    shoot1234_tx_message.IDE = CAN_ID_STD;
    shoot1234_tx_message.RTR = CAN_RTR_DATA;
    shoot1234_tx_message.DLC = 0x08;
    shoot1234_can_send_data[0] = friction_wheel1 >> 8;
    shoot1234_can_send_data[1] = friction_wheel1;
    shoot1234_can_send_data[2] = friction_wheel2 >> 8;
    shoot1234_can_send_data[3] = friction_wheel2;
    shoot1234_can_send_data[4] = friction_wheel3 >> 8;
    shoot1234_can_send_data[5] = friction_wheel3;
    shoot1234_can_send_data[6] = friction_wheel4 >> 8;
    shoot1234_can_send_data[7] = friction_wheel4;

    HAL_CAN_AddTxMessage(&hcan2, &shoot1234_tx_message, shoot1234_can_send_data, &send_mail_box);
}

//Ħ���ֵ���������ͺ���
void CAN2_cmd_friction_wheels_5678(int16_t friction_wheel5, int16_t friction_wheel6, int16_t motor7, int16_t none)
{
    uint32_t send_mail_box;
    shoot5678_tx_message.StdId = CAN_GIMBAL_ALL_ID_1_4;
    shoot5678_tx_message.IDE = CAN_ID_STD;
    shoot5678_tx_message.RTR = CAN_RTR_DATA;
    shoot5678_tx_message.DLC = 0x08;
    shoot5678_can_send_data[0] = friction_wheel5 >> 8;
    shoot5678_can_send_data[1] = friction_wheel5;
    shoot5678_can_send_data[2] = friction_wheel6 >> 8;
    shoot5678_can_send_data[3] = friction_wheel6;
    shoot5678_can_send_data[4] = motor7 >> 8;
    shoot5678_can_send_data[5] = motor7;
    shoot5678_can_send_data[6] = none >> 8;
    shoot5678_can_send_data[7] = none;

    HAL_CAN_AddTxMessage(&hcan2, &shoot5678_tx_message, shoot5678_can_send_data, &send_mail_box);
}
