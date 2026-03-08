//
// Created by 21481 on 2025/12/15.
//

#ifndef DM_H723_LIB_DM_MOTOR_H
#define DM_H723_LIB_DM_MOTOR_H

#include "struct_typedef.h"
#include "main.h"


#define LIMIT_MIN_MAX(x,min,max) (x) = (((x)<=(min))?(min):(((x)>=(max))?(max):(x)))




#define DM8009P 0x00
#define DM4310 0x01
#define DM3507 0x02
#define DM4340 0x03
#define XIAOMI 0x04



#define CMD_ENABLE_MODE      0x01
#define CMD_DISABLE_MODE      0x02
#define CMD_ZERO_POSITION   0x03


#define DM8009P_P_MIN (-12.5f)    // Radians
#define DM8009P_P_MAX 12.5f
#define DM8009P_V_MIN (-45.0f)    // Rad/s
#define DM8009P_V_MAX 45.0f
#define DM8009P_KP_MIN 0.0f     // N-m/rad
#define DM8009P_KP_MAX 500.0f
#define DM8009P_KD_MIN 0.0f     // N-m/rad/s
#define DM8009P_KD_MAX 5.0f
#define DM8009P_T_MIN (-54.0f)
#define DM8009P_T_MAX 54.0f


#define DM4310_P_MIN (-12.5f)    // Radians
#define DM4310_P_MAX 12.5f
#define DM4310_V_MIN (-30.0f)    // Rad/s
#define DM4310_V_MAX 30.0f
#define DM4310_KP_MIN 0.0f     // N-m/rad
#define DM4310_KP_MAX 500.0f
#define DM4310_KD_MIN 0.0f     // N-m/rad/s
#define DM4310_KD_MAX 5.0f
#define DM4310_T_MIN (-10.0f)
#define DM4310_T_MAX 10.0f

#define DM3507_P_MIN (-12.5f)    // Radians
#define DM3507_P_MAX 12.5f
#define DM3507_V_MIN (-30.0f)    // Rad/s
#define DM3507_V_MAX 30.0f
#define DM3507_KP_MIN 0.0f     // N-m/rad
#define DM3507_KP_MAX 500.0f
#define DM3507_KD_MIN 0.0f     // N-m/rad/s
#define DM3507_KD_MAX 5.0f
#define DM3507_T_MIN (-10.0f)
#define DM3507_T_MAX 10.0f


#define DM4340_P_MIN (-12.5f)    // Radians
#define DM4340_P_MAX 12.5f
#define DM4340_V_MIN (-10.0f)    // Rad/s
#define DM4340_V_MAX 10.0f
#define DM4340_KP_MIN 0.0f     // N-m/rad
#define DM4340_KP_MAX 500.0f
#define DM4340_KD_MIN 0.0f     // N-m/rad/s
#define DM4340_KD_MAX 5.0f
#define DM4340_T_MIN (-28.0f)
#define DM4340_T_MAX 28.0f


#define XIAOMI_P_MIN (-12.5f)    // Radians
#define XIAOMI_P_MAX 12.5f
#define XIAOMI_V_MIN (-45.0f)    // Rad/s
#define XIAOMI_V_MAX 45.0f
#define XIAOMI_KP_MIN 0.0f     // N-m/rad
#define XIAOMI_KP_MAX 500.0f
#define XIAOMI_KD_MIN 0.0f     // N-m/rad/s
#define XIAOMI_KD_MAX 5.0f
#define XIAOMI_T_MIN (-18.0f)
#define XIAOMI_T_MAX 18.0f

extern struct dm_motor DM4310_01 ;
extern struct dm_motor DM4310_02 ;
extern struct dm_motor DM4310_03 ;
extern struct dm_motor DM4310_04 ;
extern struct dm_motor DM4340_05 ;
extern struct dm_motor DM4340_06 ;
extern struct dm_motor DM4340_07 ;




struct dm_motor{

    //设置部分
    uint8_t motor_type ;//电机类型，8009还是4310还是3507
    uint8_t can_id;//id(board->motor)
    uint8_t can_master_id;//master_id(motor->board)
    uint8_t can_channel;//can1还是can2

    //回传部分
    uint8_t online_state ;//在线状态
    uint8_t state;//状态
    float return_angle;//回传位置
    float return_speed;//回传速度
    float return_tor;//回传力矩
    float Tmos;//mos温度
    float Tcoil;//线圈温度
    uint32_t last_online_time;//上一次返回数据的时间

    //控制部分
    float give_angle;//目标位置（非MIT！）
    float give_speed;//目标速度（非MIT！）
    float give_tor;//发送的力矩

};


void dm_motor_init();
void dm_motor_mode_set(uint8_t cmd , uint8_t can_channel , uint8_t can_id);
void Dm_Can_Send( uint8_t can_channel , uint8_t can_id , uint8_t motor_type , float give_tor );

static void DMCanTransmit(uint8_t *buf, uint8_t len, uint8_t can_channel, uint8_t motor_id);

uint16_t float_to_uint(float x, float x_min, float x_max, uint8_t bits);
float uint_to_float(int x_int, float x_min, float x_max, int bits);

#endif //DM_H723_LIB_DM_MOTOR_H
