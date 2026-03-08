//
// Created by 21481 on 2026/3/4.
//

#ifndef DM_H723_LIB_CHASSIS_TASK_H
#define DM_H723_LIB_CHASSIS_TASK_H


#include "dm_motor.h"


#define CHASSIS_3508_SPEED_PID_OUT_MAX 16384.0f
#define CHASSIS_3508_SPEED_PID_KI_MAX 16384.0f


#define CHASSIS_3508_ID1_SPEED_PID_KP 5.0f
#define CHASSIS_3508_ID1_SPEED_PID_KI 0.1f
#define CHASSIS_3508_ID1_SPEED_PID_KD 0.0f

#define CHASSIS_3508_ID2_SPEED_PID_KP 5.0f
#define CHASSIS_3508_ID2_SPEED_PID_KI 0.1f
#define CHASSIS_3508_ID2_SPEED_PID_KD 0.0f

#define CHASSIS_3508_ID3_SPEED_PID_KP 5.0f
#define CHASSIS_3508_ID3_SPEED_PID_KI 0.1f
#define CHASSIS_3508_ID3_SPEED_PID_KD 0.0f

#define CHASSIS_3508_ID4_SPEED_PID_KP 5.0f
#define CHASSIS_3508_ID4_SPEED_PID_KI 0.1f
#define CHASSIS_3508_ID4_SPEED_PID_KD 0.0f

#define CHASSIS_3508_ID5_SPEED_PID_KP 10.0f
#define CHASSIS_3508_ID5_SPEED_PID_KI 0.1f
#define CHASSIS_3508_ID5_SPEED_PID_KD 0.0f

#define CHASSIS_3508_ID6_SPEED_PID_KP 10.0f
#define CHASSIS_3508_ID6_SPEED_PID_KI 0.1f
#define CHASSIS_3508_ID6_SPEED_PID_KD 0.0f





#define CHASSIS_4310_SPEED_PID_OUT_MAX 5.0f
#define CHASSIS_4310_SPEED_PID_KI_MAX 5.0f

#define CHASSIS_4340_SPEED_PID_OUT_MAX 15.0f
#define CHASSIS_4340_SPEED_PID_KI_MAX 15.0f


#define CHASSIS_4310_ID1_SPEED_PID_KP 1.0f
#define CHASSIS_4310_ID1_SPEED_PID_KI 0.05f
#define CHASSIS_4310_ID1_SPEED_PID_KD 0.0f

#define CHASSIS_4310_ID2_SPEED_PID_KP 1.0f
#define CHASSIS_4310_ID2_SPEED_PID_KI 0.05f
#define CHASSIS_4310_ID2_SPEED_PID_KD 0.0f

#define CHASSIS_4310_ID3_SPEED_PID_KP 1.0f
#define CHASSIS_4310_ID3_SPEED_PID_KI 0.05f
#define CHASSIS_4310_ID3_SPEED_PID_KD 0.0f

#define CHASSIS_4310_ID4_SPEED_PID_KP 2.0f
#define CHASSIS_4310_ID4_SPEED_PID_KI 0.05f
#define CHASSIS_4310_ID4_SPEED_PID_KD 0.0f

#define CHASSIS_4340_ID5_SPEED_PID_KP 8.0f
#define CHASSIS_4340_ID5_SPEED_PID_KI 0.02f
#define CHASSIS_4340_ID5_SPEED_PID_KD 0.0f

#define CHASSIS_4340_ID6_SPEED_PID_KP 8.0f
#define CHASSIS_4340_ID6_SPEED_PID_KI 0.02f
#define CHASSIS_4340_ID6_SPEED_PID_KD 0.0f


#define CHASSIS_4340_ID7_SPEED_PID_KP 10.0f
#define CHASSIS_4340_ID7_SPEED_PID_KI 0.02f
#define CHASSIS_4340_ID7_SPEED_PID_KD 0.0f


#define CHASSIS_4310_ANGLE_PID_OUT_MAX 2.0f
#define CHASSIS_4310_ANGLE_PID_KI_MAX 0.0f

#define CHASSIS_4340_ANGLE_PID_OUT_MAX 2.0f
#define CHASSIS_4340_ANGLE_PID_KI_MAX 0.0f

#define CHASSIS_4340_ID1_ANGLE_PID_KP 2.0f
#define CHASSIS_4340_ID1_ANGLE_PID_KI 0.0f
#define CHASSIS_4340_ID1_ANGLE_PID_KD 0.0f

#define CHASSIS_4340_ID2_ANGLE_PID_KP 2.0f
#define CHASSIS_4340_ID2_ANGLE_PID_KI 0.0f
#define CHASSIS_4340_ID2_ANGLE_PID_KD 0.0f

#define CHASSIS_4340_ID3_ANGLE_PID_KP 2.0f
#define CHASSIS_4340_ID3_ANGLE_PID_KI 0.0f
#define CHASSIS_4340_ID3_ANGLE_PID_KD 0.0f

#define CHASSIS_4340_ID4_ANGLE_PID_KP 2.0f
#define CHASSIS_4340_ID4_ANGLE_PID_KI 0.0f
#define CHASSIS_4340_ID4_ANGLE_PID_KD 0.0f

#define CHASSIS_4340_ID5_ANGLE_PID_KP 2.0f
#define CHASSIS_4340_ID5_ANGLE_PID_KI 0.0f
#define CHASSIS_4340_ID5_ANGLE_PID_KD 0.0f

#define CHASSIS_4340_ID6_ANGLE_PID_KP 2.0f
#define CHASSIS_4340_ID6_ANGLE_PID_KI 0.0f
#define CHASSIS_4340_ID6_ANGLE_PID_KD 0.0f

#define CHASSIS_4340_ID7_ANGLE_PID_KP 2.0f
#define CHASSIS_4340_ID7_ANGLE_PID_KI 0.0f
#define CHASSIS_4340_ID7_ANGLE_PID_KD 0.0f



#define MOTOR1_MAX_ANGLE  1.00f
#define MOTOR1_MIN_ANGLE 0.00f

#define MOTOR2_MAX_ANGLE 1.00f
#define MOTOR2_MIN_ANGLE (-1.00f)

#define MOTOR3_MAX_ANGLE 1.78f
#define MOTOR3_MIN_ANGLE (-1.78f)

#define MOTOR4_MAX_ANGLE 1.47f
#define MOTOR4_MIN_ANGLE (-1.00f)

#define MOTOR5_MAX_ANGLE 3.00f
#define MOTOR5_MIN_ANGLE 0.00f

#define MOTOR6_MAX_ANGLE 2.10f
#define MOTOR6_MIN_ANGLE 0.00f

#define MOTOR7_MAX_ANGLE 0.90f
#define MOTOR7_MIN_ANGLE (-0.96f)



#define RC_2_WHEEL_VX_KP 4.0f
#define RC_2_WHEEL_VY_KP (-4.0f)
#define RC_2_WHEEL_VROUND_KP 4.0f

#define WHEEL_2_TRACK_VX_KP 1.0f
#define WHEEL_2_TRACK_VROUND_KP 1.0f

void eng_all_4340_given_angle_get();
void eng_all_4340_pid_control();

void chassis_all_3508_speed_get();
void chassis_caterpillar_track_speed_get();
void chassis_wheel_all_speed_get();
void chassis_wheel_3508_speed_compute();
void chassis_track_3508_speed_compute();


void chassis_3508_pid_control();

void chassis_3508_id1_speed_pid_init(void);
int16_t chassis_3508_id1_speed_pid_loop(float chassis_3508_ID1_speed_set_loop);
void chassis_3508_id2_speed_pid_init(void);
int16_t chassis_3508_id2_speed_pid_loop(float chassis_3508_ID2_speed_set_loop);
void chassis_3508_id3_speed_pid_init(void);
int16_t chassis_3508_id3_speed_pid_loop(float chassis_3508_ID3_speed_set_loop);
void chassis_3508_id4_speed_pid_init(void);
int16_t chassis_3508_id4_speed_pid_loop(float chassis_3508_ID4_speed_set_loop);
void chassis_3508_id5_speed_pid_init(void);
int16_t chassis_3508_id5_speed_pid_loop(float chassis_3508_ID5_speed_set_loop);
void chassis_3508_id6_speed_pid_init(void);
int16_t chassis_3508_id6_speed_pid_loop(float chassis_3508_ID6_speed_set_loop);

void chassis_4340_id1_speed_pid_init(void);
float chassis_4340_id1_speed_pid_loop(float chassis_4340_ID1_speed_set_loop);
void chassis_4340_id2_speed_pid_init(void);
float chassis_4340_id2_speed_pid_loop(float chassis_4340_ID2_speed_set_loop);
void chassis_4340_id4_speed_pid_init(void);
float chassis_4340_id3_speed_pid_loop(float chassis_4340_ID3_speed_set_loop);
void chassis_4340_id3_speed_pid_init(void);
float chassis_4340_id4_speed_pid_loop(float chassis_4340_ID4_speed_set_loop);
void chassis_4340_id5_speed_pid_init(void);
float chassis_4340_id5_speed_pid_loop(float chassis_4340_ID5_speed_set_loop);
void chassis_4340_id6_speed_pid_init(void);
float chassis_4340_id6_speed_pid_loop(float chassis_4340_ID6_speed_set_loop);
void chassis_4340_id7_speed_pid_init(void);
float chassis_4340_id7_speed_pid_loop(float chassis_4340_ID7_speed_set_loop);




void chassis_4340_id1_angle_pid_init(void);
float chassis_4340_id1_angle_pid_loop(float chassis_4340_ID1_angle_set_loop);
void chassis_4340_id2_angle_pid_init(void);
float chassis_4340_id2_angle_pid_loop(float chassis_4340_ID2_angle_set_loop);
void chassis_4340_id3_angle_pid_init(void);
float chassis_4340_id3_angle_pid_loop(float chassis_4340_ID3_angle_set_loop);
void chassis_4340_id4_angle_pid_init(void);
float chassis_4340_id4_angle_pid_loop(float chassis_4340_ID4_angle_set_loop);
void chassis_4340_id5_angle_pid_init(void);
float chassis_4340_id5_angle_pid_loop(float chassis_4340_ID5_angle_set_loop);
void chassis_4340_id6_angle_pid_init(void);
float chassis_4340_id6_angle_pid_loop(float chassis_4340_ID6_angle_set_loop);
void chassis_4340_id7_angle_pid_init(void);
float chassis_4340_id7_angle_pid_loop(float chassis_4340_ID7_angle_set_loop);







#endif //DM_H723_LIB_CHASSIS_TASK_H
