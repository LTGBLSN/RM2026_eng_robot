//
// Created by 21481 on 2026/3/2.
//

#ifndef DM_H723_LIB_BOARD_COMMUNICATION_TASK_H
#define DM_H723_LIB_BOARD_COMMUNICATION_TASK_H

#include "main.h"

extern struct follow_arm_data follow_arm;

struct follow_arm_data
{
    int16_t motor0;
    int16_t motor1;
    int16_t motor2;
    int16_t motor3;
    int16_t motor4;
    int16_t motor5;
    int16_t clamp;
    uint8_t stateA;
    uint8_t stateB;

};

void chassis_motor_4_clamp_state_2_arm(int16_t motor4 , int16_t motor5 , int16_t clamp , uint8_t stateA , uint8_t stateB , uint16_t id, uint8_t can_channel);
void chassis_motor_0_3_2_arm(int16_t motor0 , int16_t motor1 , int16_t motor2 , int16_t motor3 , uint16_t id, uint8_t can_channel);
void chassis_rc_2_arm(int16_t data , int16_t rc_s , int16_t rc_ch_A , int16_t rc_ch_B , uint16_t id, uint8_t can_channel);

#endif //DM_H723_LIB_BOARD_COMMUNICATION_TASK_H
