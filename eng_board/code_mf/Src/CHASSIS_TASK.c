//
// Created by 21481 on 2026/3/4.
//



#include "cmsis_os.h"
#include "dm_motor.h"
#include "pid.h"
#include "DJI_motors.h"
#include "CHASSIS_TASK.h"
#include "GET_RC_TASK.h"
#include "remote_control.h"

pid_type_def chassis_3508_id1_speed_pid;
pid_type_def chassis_3508_id2_speed_pid;
pid_type_def chassis_3508_id3_speed_pid;
pid_type_def chassis_3508_id4_speed_pid;
pid_type_def chassis_3508_id5_speed_pid;
pid_type_def chassis_3508_id6_speed_pid;

pid_type_def chassis_4340_id1_speed_pid;
pid_type_def chassis_4340_id2_speed_pid;
pid_type_def chassis_4340_id3_speed_pid;
pid_type_def chassis_4340_id4_speed_pid;
pid_type_def chassis_4340_id5_speed_pid;
pid_type_def chassis_4340_id6_speed_pid;
pid_type_def chassis_4340_id7_speed_pid;

pid_type_def chassis_4340_id1_angle_pid;
pid_type_def chassis_4340_id2_angle_pid;
pid_type_def chassis_4340_id3_angle_pid;
pid_type_def chassis_4340_id4_angle_pid;
pid_type_def chassis_4340_id5_angle_pid;
pid_type_def chassis_4340_id6_angle_pid;
pid_type_def chassis_4340_id7_angle_pid;



void CHASSIS_TASK()
{

    chassis_4340_id1_speed_pid_init();
    chassis_4340_id2_speed_pid_init();
    chassis_4340_id3_speed_pid_init();
    chassis_4340_id4_speed_pid_init();
    chassis_4340_id5_speed_pid_init();
    chassis_4340_id6_speed_pid_init();
    chassis_4340_id7_speed_pid_init();



    chassis_4340_id1_angle_pid_init();
    chassis_4340_id2_angle_pid_init();
    chassis_4340_id3_angle_pid_init();
    chassis_4340_id4_angle_pid_init();
    chassis_4340_id5_angle_pid_init();
    chassis_4340_id6_angle_pid_init();
    chassis_4340_id7_angle_pid_init();

    dm_motor_init();


    while (1)
    {

        //4340腿角度获取
        eng_all_4340_given_angle_get();


        //4340pid计算
        if(rcData.rc.s[1] == 1 | rcData.rc.s[1] == 2)
        {
            eng_all_4340_pid_control();
        }


        osDelay(1);
    }
}

void eng_all_4340_given_angle_get()
{
    switch (rcData.rc.s[1])
    {
        case 0:
        {

            DM4310_01.give_angle = DM4310_01.give_angle ;
            DM4310_02.give_angle = DM4310_02.give_angle ;
            DM4310_03.give_angle = DM4310_03.give_angle ;
            DM4310_04.give_angle = DM4310_04.give_angle ;
            DM4340_05.give_angle = DM4340_05.give_angle ;
            DM4340_06.give_angle = DM4340_06.give_angle ;
            DM4340_07.give_angle = DM4340_07.give_angle ;
            break;
        }
        case 1:
        {
            DM4310_01.give_angle = 0.0f ;
            DM4310_02.give_angle = MOTOR2_ABSCISSA ;
            DM4310_03.give_angle = -MOTOR3_ABSCISSA ;
            DM4310_04.give_angle = MOTOR4_ABSCISSA ;
            DM4340_05.give_angle = -MOTOR5_ABSCISSA ;
            DM4340_06.give_angle = -MOTOR6_ABSCISSA ;
            DM4340_07.give_angle = MOTOR7_ABSCISSA ;



            break;
        }
        case 2:
        {
            if(rcData.rc.s[0] == 1)
            {
//                DM4340_05.give_angle = DM4340_05.give_angle + 0.000005f * (float)rcData.rc.ch[0];
//                DM4340_06.give_angle = DM4340_06.give_angle - 0.000005f * (float)rcData.rc.ch[1];
//                DM4340_07.give_angle = DM4340_07.give_angle - 0.000005f * (float)rcData.rc.ch[2];
            }
            else
            {
//                DM4310_01.give_angle = DM4310_01.give_angle + 0.000005f * (float)rcData.rc.ch[0];
//                DM4310_02.give_angle = DM4310_02.give_angle - 0.000005f * (float)rcData.rc.ch[1];
//                DM4310_03.give_angle = DM4310_03.give_angle - 0.000005f * (float)rcData.rc.ch[2];
//                DM4310_04.give_angle = DM4310_04.give_angle + 0.000005f * (float)rcData.rc.ch[3];
            }



            break;
        }

        default:
        {
            DM4310_01.give_angle = 0.0f ;
            DM4310_02.give_angle = 0.0f ;
            DM4310_03.give_angle = 0.0f ;
            DM4310_04.give_angle = 0.0f ;
            DM4340_05.give_angle = 0.0f ;
            DM4340_06.give_angle = 0.0f ;
            DM4340_07.give_angle = 0.0f ;
            break;
        }


    }

    if( DM4310_01.give_angle > MOTOR1_MAX_ANGLE )
    {
        DM4310_01.give_angle = MOTOR1_MAX_ANGLE ;
    }
    else if( DM4310_01.give_angle < MOTOR1_MIN_ANGLE )
    {
        DM4310_01.give_angle = MOTOR1_MIN_ANGLE ;
    }

    if( DM4310_02.give_angle > MOTOR2_MAX_ANGLE )
    {
        DM4310_02.give_angle = MOTOR2_MAX_ANGLE ;
    }
    else if( DM4310_02.give_angle < MOTOR2_MIN_ANGLE )
    {
        DM4310_02.give_angle = MOTOR2_MIN_ANGLE ;
    }

    if( DM4310_03.give_angle > MOTOR3_MAX_ANGLE )
    {
        DM4310_03.give_angle = MOTOR3_MAX_ANGLE ;
    }
    else if( DM4310_03.give_angle < MOTOR3_MIN_ANGLE )
    {
        DM4310_03.give_angle = MOTOR3_MIN_ANGLE ;
    }


    if( DM4310_04.give_angle > MOTOR4_MAX_ANGLE )
    {
        DM4310_04.give_angle = MOTOR4_MAX_ANGLE ;
    }
    else if( DM4310_04.give_angle < MOTOR4_MIN_ANGLE )
    {
        DM4310_04.give_angle = MOTOR4_MIN_ANGLE ;
    }


    if( DM4340_05.give_angle > MOTOR5_MAX_ANGLE )
    {
        DM4340_05.give_angle = MOTOR5_MAX_ANGLE ;
    }
    else if( DM4340_05.give_angle < MOTOR5_MIN_ANGLE )
    {
        DM4340_05.give_angle = MOTOR5_MIN_ANGLE ;
    }

    if( DM4340_06.give_angle > MOTOR6_MAX_ANGLE )
    {
        DM4340_06.give_angle = MOTOR6_MAX_ANGLE ;
    }
    else if( DM4340_06.give_angle < MOTOR6_MIN_ANGLE )
    {
        DM4340_06.give_angle = MOTOR6_MIN_ANGLE ;
    }

    if( DM4340_07.give_angle > MOTOR7_MAX_ANGLE )
    {
        DM4340_07.give_angle = MOTOR7_MAX_ANGLE ;
    }
    else if( DM4340_07.give_angle < MOTOR7_MIN_ANGLE )
    {
        DM4340_07.give_angle = MOTOR7_MIN_ANGLE ;
    }




}

void eng_all_4340_pid_control()
{
    DM4310_01.give_speed = chassis_4340_id1_angle_pid_loop(DM4310_01.give_angle);
    DM4310_02.give_speed = chassis_4340_id2_angle_pid_loop(DM4310_02.give_angle);
    DM4310_03.give_speed = chassis_4340_id3_angle_pid_loop(DM4310_03.give_angle);
    DM4310_04.give_speed = chassis_4340_id4_angle_pid_loop(DM4310_04.give_angle);
    DM4340_05.give_speed = chassis_4340_id5_angle_pid_loop(DM4340_05.give_angle);
    DM4340_06.give_speed = chassis_4340_id6_angle_pid_loop(DM4340_06.give_angle);
    DM4340_07.give_speed = chassis_4340_id7_angle_pid_loop(DM4340_07.give_angle);


    DM4310_01.give_tor = chassis_4340_id1_speed_pid_loop(DM4310_01.give_speed);
    DM4310_02.give_tor = chassis_4340_id2_speed_pid_loop(DM4310_02.give_speed);
    DM4310_03.give_tor = chassis_4340_id3_speed_pid_loop(DM4310_03.give_speed);
    DM4310_04.give_tor = chassis_4340_id4_speed_pid_loop(DM4310_04.give_speed);
    DM4340_05.give_tor = chassis_4340_id5_speed_pid_loop(DM4340_05.give_speed);
    DM4340_06.give_tor = chassis_4340_id6_speed_pid_loop(DM4340_06.give_speed);
    DM4340_07.give_tor = chassis_4340_id7_speed_pid_loop(DM4340_07.give_speed);
}



void chassis_all_3508_speed_get()
{
    chassis_wheel_all_speed_get();//轮子
    chassis_caterpillar_track_speed_get();//履带


}



void chassis_wheel_all_speed_get()
{
    chassis_wheel_vx = RC_2_WHEEL_VX_KP * (float)rcData.rc.ch[1];
    chassis_wheel_vy = RC_2_WHEEL_VY_KP * (float)rcData.rc.ch[0];
    chassis_wheel_vround = RC_2_WHEEL_VROUND_KP * (float)rcData.rc.ch[2];
}

void chassis_caterpillar_track_speed_get()
{
    chassis_track_vx = WHEEL_2_TRACK_VX_KP * chassis_wheel_vx;
    chassis_track_vround = WHEEL_2_TRACK_VROUND_KP * chassis_wheel_vround;

}


void chassis_wheel_3508_speed_compute()
{
    CHASSIS_3508_ID1_GIVEN_SPEED = chassis_wheel_vx + chassis_wheel_vy - chassis_wheel_vround ;
    CHASSIS_3508_ID2_GIVEN_SPEED = -chassis_wheel_vx + chassis_wheel_vy - chassis_wheel_vround ;
    CHASSIS_3508_ID3_GIVEN_SPEED = chassis_wheel_vx + chassis_wheel_vy + chassis_wheel_vround ;
    CHASSIS_3508_ID4_GIVEN_SPEED = -chassis_wheel_vx + chassis_wheel_vy + chassis_wheel_vround ;
}

void chassis_track_3508_speed_compute()
{
    CHASSIS_3508_ID5_GIVEN_SPEED = chassis_track_vx + chassis_track_vround ;
    CHASSIS_3508_ID6_GIVEN_SPEED = -chassis_track_vx + chassis_track_vround ;
}


void chassis_3508_pid_control()
{
    //chassis 3508
    CHASSIS_3508_ID1_GIVEN_CURRENT = chassis_3508_id1_speed_pid_loop(CHASSIS_3508_ID1_GIVEN_SPEED);
    CHASSIS_3508_ID2_GIVEN_CURRENT = chassis_3508_id2_speed_pid_loop(CHASSIS_3508_ID2_GIVEN_SPEED);
    CHASSIS_3508_ID3_GIVEN_CURRENT = chassis_3508_id3_speed_pid_loop(CHASSIS_3508_ID3_GIVEN_SPEED);
    CHASSIS_3508_ID4_GIVEN_CURRENT = chassis_3508_id4_speed_pid_loop(CHASSIS_3508_ID4_GIVEN_SPEED);
    CHASSIS_3508_ID5_GIVEN_CURRENT = chassis_3508_id5_speed_pid_loop(CHASSIS_3508_ID5_GIVEN_SPEED);
    CHASSIS_3508_ID6_GIVEN_CURRENT = chassis_3508_id6_speed_pid_loop(CHASSIS_3508_ID6_GIVEN_SPEED);
}








//shoot
void chassis_3508_id1_speed_pid_init(void)
{
    static fp32 chassis_3508_id1_speed_kpkikd[3] = {CHASSIS_3508_ID1_SPEED_PID_KP, CHASSIS_3508_ID1_SPEED_PID_KI, CHASSIS_3508_ID1_SPEED_PID_KD};
    PID_init(&chassis_3508_id1_speed_pid, PID_POSITION, chassis_3508_id1_speed_kpkikd, CHASSIS_3508_SPEED_PID_OUT_MAX, CHASSIS_3508_SPEED_PID_KI_MAX);

}

int16_t chassis_3508_id1_speed_pid_loop(float chassis_3508_ID1_speed_set_loop)
{
    PID_calc(&chassis_3508_id1_speed_pid, motor_can2_data[0].speed_rpm , chassis_3508_ID1_speed_set_loop);
    int16_t chassis_3508_id1_given_current_loop = (int16_t)(chassis_3508_id1_speed_pid.out);

    return chassis_3508_id1_given_current_loop ;

}



void chassis_3508_id2_speed_pid_init(void)
{
    static fp32 chassis_3508_id2_speed_kpkikd[3] = {CHASSIS_3508_ID2_SPEED_PID_KP, CHASSIS_3508_ID2_SPEED_PID_KI, CHASSIS_3508_ID2_SPEED_PID_KD};
    PID_init(&chassis_3508_id2_speed_pid, PID_POSITION, chassis_3508_id2_speed_kpkikd, CHASSIS_3508_SPEED_PID_OUT_MAX, CHASSIS_3508_SPEED_PID_KI_MAX);

}

int16_t chassis_3508_id2_speed_pid_loop(float chassis_3508_ID2_speed_set_loop)
{
    PID_calc(&chassis_3508_id2_speed_pid, motor_can2_data[1].speed_rpm , chassis_3508_ID2_speed_set_loop);
    int16_t chassis_3508_id2_given_current_loop = (int16_t)(chassis_3508_id2_speed_pid.out);

    return chassis_3508_id2_given_current_loop ;

}

void chassis_3508_id3_speed_pid_init(void)
{
    static fp32 chassis_3508_id3_speed_kpkikd[3] = {CHASSIS_3508_ID3_SPEED_PID_KP, CHASSIS_3508_ID3_SPEED_PID_KI, CHASSIS_3508_ID3_SPEED_PID_KD};
    PID_init(&chassis_3508_id3_speed_pid, PID_POSITION, chassis_3508_id3_speed_kpkikd, CHASSIS_3508_SPEED_PID_OUT_MAX, CHASSIS_3508_SPEED_PID_KI_MAX);

}

int16_t chassis_3508_id3_speed_pid_loop(float chassis_3508_ID3_speed_set_loop)
{
    PID_calc(&chassis_3508_id3_speed_pid, motor_can2_data[2].speed_rpm , chassis_3508_ID3_speed_set_loop);
    int16_t chassis_3508_id3_given_current_loop = (int16_t)(chassis_3508_id3_speed_pid.out);

    return chassis_3508_id3_given_current_loop ;

}

void chassis_3508_id4_speed_pid_init(void)
{
    static fp32 chassis_3508_id4_speed_kpkikd[3] = {CHASSIS_3508_ID4_SPEED_PID_KP, CHASSIS_3508_ID4_SPEED_PID_KI, CHASSIS_3508_ID4_SPEED_PID_KD};
    PID_init(&chassis_3508_id4_speed_pid, PID_POSITION, chassis_3508_id4_speed_kpkikd, CHASSIS_3508_SPEED_PID_OUT_MAX, CHASSIS_3508_SPEED_PID_KI_MAX);

}

int16_t chassis_3508_id4_speed_pid_loop(float chassis_3508_ID4_speed_set_loop)
{
    PID_calc(&chassis_3508_id4_speed_pid, motor_can2_data[3].speed_rpm , chassis_3508_ID4_speed_set_loop);
    int16_t chassis_3508_id4_given_current_loop = (int16_t)(chassis_3508_id4_speed_pid.out);

    return chassis_3508_id4_given_current_loop ;

}



void chassis_3508_id5_speed_pid_init(void)
{
    static fp32 chassis_3508_id5_speed_kpkikd[3] = {CHASSIS_3508_ID5_SPEED_PID_KP, CHASSIS_3508_ID5_SPEED_PID_KI, CHASSIS_3508_ID5_SPEED_PID_KD};
    PID_init(&chassis_3508_id5_speed_pid, PID_POSITION, chassis_3508_id5_speed_kpkikd, CHASSIS_3508_SPEED_PID_OUT_MAX, CHASSIS_3508_SPEED_PID_KI_MAX);

}

int16_t chassis_3508_id5_speed_pid_loop(float chassis_3508_ID5_speed_set_loop)
{
    PID_calc(&chassis_3508_id5_speed_pid, motor_can2_data[4].speed_rpm , chassis_3508_ID5_speed_set_loop);
    int16_t chassis_3508_id5_given_current_loop = (int16_t)(chassis_3508_id5_speed_pid.out);

    return chassis_3508_id5_given_current_loop ;

}

void chassis_3508_id6_speed_pid_init(void)
{
    static fp32 chassis_3508_id6_speed_kpkikd[3] = {CHASSIS_3508_ID6_SPEED_PID_KP, CHASSIS_3508_ID6_SPEED_PID_KI, CHASSIS_3508_ID6_SPEED_PID_KD};
    PID_init(&chassis_3508_id6_speed_pid, PID_POSITION, chassis_3508_id6_speed_kpkikd, CHASSIS_3508_SPEED_PID_OUT_MAX, CHASSIS_3508_SPEED_PID_KI_MAX);

}

int16_t chassis_3508_id6_speed_pid_loop(float chassis_3508_ID6_speed_set_loop)
{
    PID_calc(&chassis_3508_id6_speed_pid, motor_can2_data[5].speed_rpm , chassis_3508_ID6_speed_set_loop);
    int16_t chassis_3508_id6_given_current_loop = (int16_t)(chassis_3508_id6_speed_pid.out);

    return chassis_3508_id6_given_current_loop ;

}


void chassis_4340_id1_speed_pid_init(void)
{
    static fp32 chassis_4340_id1_speed_kpkikd[3] = {CHASSIS_4310_ID1_SPEED_PID_KP, CHASSIS_4310_ID1_SPEED_PID_KI, CHASSIS_4310_ID1_SPEED_PID_KD};
    PID_init(&chassis_4340_id1_speed_pid, PID_POSITION, chassis_4340_id1_speed_kpkikd, CHASSIS_4310_SPEED_PID_OUT_MAX, CHASSIS_4310_SPEED_PID_KI_MAX);

}

float chassis_4340_id1_speed_pid_loop(float chassis_4340_ID1_speed_set_loop)
{
    PID_calc(&chassis_4340_id1_speed_pid, DM4310_01.return_speed , chassis_4340_ID1_speed_set_loop);
    float chassis_4340_id1_given_current_loop = (chassis_4340_id1_speed_pid.out);

    return chassis_4340_id1_given_current_loop ;

}

void chassis_4340_id1_angle_pid_init(void)
{
    static fp32 chassis_4340_id1_angle_kpkikd[3] = {CHASSIS_4340_ID1_ANGLE_PID_KP, CHASSIS_4340_ID1_ANGLE_PID_KI, CHASSIS_4340_ID1_ANGLE_PID_KD};
    PID_init(&chassis_4340_id1_angle_pid, PID_POSITION, chassis_4340_id1_angle_kpkikd, CHASSIS_4310_ANGLE_PID_OUT_MAX, CHASSIS_4310_ANGLE_PID_KI_MAX);

}

float chassis_4340_id1_angle_pid_loop(float chassis_4340_ID1_angle_set_loop)
{
    PID_calc(&chassis_4340_id1_angle_pid, DM4310_01.return_angle , chassis_4340_ID1_angle_set_loop);
    float chassis_4340_id1_given_speed_loop = (chassis_4340_id1_angle_pid.out);

    return chassis_4340_id1_given_speed_loop ;

}


void chassis_4340_id2_speed_pid_init(void)
{
    static fp32 chassis_4340_id2_speed_kpkikd[3] = {CHASSIS_4310_ID2_SPEED_PID_KP, CHASSIS_4310_ID2_SPEED_PID_KI, CHASSIS_4310_ID2_SPEED_PID_KD};
    PID_init(&chassis_4340_id2_speed_pid, PID_POSITION, chassis_4340_id2_speed_kpkikd, CHASSIS_4310_SPEED_PID_OUT_MAX, CHASSIS_4310_SPEED_PID_KI_MAX);

}

float chassis_4340_id2_speed_pid_loop(float chassis_4340_ID2_speed_set_loop)
{
    PID_calc(&chassis_4340_id2_speed_pid, DM4310_02.return_speed , chassis_4340_ID2_speed_set_loop);
    float chassis_4340_id2_given_current_loop = (chassis_4340_id2_speed_pid.out);

    return chassis_4340_id2_given_current_loop ;

}

void chassis_4340_id2_angle_pid_init(void)
{
    static fp32 chassis_4340_id2_angle_kpkikd[3] = {CHASSIS_4340_ID2_ANGLE_PID_KP, CHASSIS_4340_ID2_ANGLE_PID_KI, CHASSIS_4340_ID2_ANGLE_PID_KD};
    PID_init(&chassis_4340_id2_angle_pid, PID_POSITION, chassis_4340_id2_angle_kpkikd, CHASSIS_4310_ANGLE_PID_OUT_MAX, CHASSIS_4310_ANGLE_PID_KI_MAX);

}

float chassis_4340_id2_angle_pid_loop(float chassis_4340_ID2_angle_set_loop)
{
    PID_calc(&chassis_4340_id2_angle_pid, DM4310_02.return_angle , chassis_4340_ID2_angle_set_loop);
    float chassis_4340_id2_given_speed_loop = (chassis_4340_id2_angle_pid.out);

    return chassis_4340_id2_given_speed_loop ;

}

void chassis_4340_id3_speed_pid_init(void)
{
    static fp32 chassis_4340_id3_speed_kpkikd[3] = {CHASSIS_4310_ID3_SPEED_PID_KP, CHASSIS_4310_ID3_SPEED_PID_KI, CHASSIS_4310_ID3_SPEED_PID_KD};
    PID_init(&chassis_4340_id3_speed_pid, PID_POSITION, chassis_4340_id3_speed_kpkikd, CHASSIS_4310_SPEED_PID_OUT_MAX, CHASSIS_4310_SPEED_PID_KI_MAX);

}

float chassis_4340_id3_speed_pid_loop(float chassis_4340_ID3_speed_set_loop)
{
    PID_calc(&chassis_4340_id3_speed_pid, DM4310_03.return_speed , chassis_4340_ID3_speed_set_loop);
    float chassis_4340_id3_given_current_loop = (chassis_4340_id3_speed_pid.out);

    return chassis_4340_id3_given_current_loop ;

}

void chassis_4340_id3_angle_pid_init(void)
{
    static fp32 chassis_4340_id3_angle_kpkikd[3] = {CHASSIS_4340_ID3_ANGLE_PID_KP, CHASSIS_4340_ID3_ANGLE_PID_KI, CHASSIS_4340_ID3_ANGLE_PID_KD};
    PID_init(&chassis_4340_id3_angle_pid, PID_POSITION, chassis_4340_id3_angle_kpkikd, CHASSIS_4310_ANGLE_PID_OUT_MAX, CHASSIS_4310_ANGLE_PID_KI_MAX);

}

float chassis_4340_id3_angle_pid_loop(float chassis_4340_ID3_angle_set_loop)
{
    PID_calc(&chassis_4340_id3_angle_pid, DM4310_03.return_angle , chassis_4340_ID3_angle_set_loop);
    float chassis_4340_id3_given_speed_loop = (chassis_4340_id3_angle_pid.out);

    return chassis_4340_id3_given_speed_loop ;

}


void chassis_4340_id4_speed_pid_init(void)
{
    static fp32 chassis_4340_id4_speed_kpkikd[3] = {CHASSIS_4310_ID4_SPEED_PID_KP, CHASSIS_4310_ID4_SPEED_PID_KI, CHASSIS_4310_ID4_SPEED_PID_KD};
    PID_init(&chassis_4340_id4_speed_pid, PID_POSITION, chassis_4340_id4_speed_kpkikd, CHASSIS_4310_SPEED_PID_OUT_MAX, CHASSIS_4310_SPEED_PID_KI_MAX);

}

float chassis_4340_id4_speed_pid_loop(float chassis_4340_ID4_speed_set_loop)
{
    PID_calc(&chassis_4340_id4_speed_pid, DM4310_04.return_speed , chassis_4340_ID4_speed_set_loop);
    float chassis_4340_id4_given_current_loop = (chassis_4340_id4_speed_pid.out);

    return chassis_4340_id4_given_current_loop ;

}


void chassis_4340_id4_angle_pid_init(void)
{
    static fp32 chassis_4340_id4_angle_kpkikd[3] = {CHASSIS_4340_ID4_ANGLE_PID_KP, CHASSIS_4340_ID4_ANGLE_PID_KI, CHASSIS_4340_ID4_ANGLE_PID_KD};
    PID_init(&chassis_4340_id4_angle_pid, PID_POSITION, chassis_4340_id4_angle_kpkikd, CHASSIS_4310_ANGLE_PID_OUT_MAX, CHASSIS_4310_ANGLE_PID_KI_MAX);

}

float chassis_4340_id4_angle_pid_loop(float chassis_4340_ID4_angle_set_loop)
{
    PID_calc(&chassis_4340_id4_angle_pid, DM4310_04.return_angle , chassis_4340_ID4_angle_set_loop);
    float chassis_4340_id4_given_speed_loop = (chassis_4340_id4_angle_pid.out);

    return chassis_4340_id4_given_speed_loop ;

}



void chassis_4340_id5_speed_pid_init(void)
{
    static fp32 chassis_4340_id5_speed_kpkikd[3] = {CHASSIS_4340_ID5_SPEED_PID_KP, CHASSIS_4340_ID5_SPEED_PID_KI, CHASSIS_4340_ID5_SPEED_PID_KD};
    PID_init(&chassis_4340_id5_speed_pid, PID_POSITION, chassis_4340_id5_speed_kpkikd, CHASSIS_4340_SPEED_PID_OUT_MAX, CHASSIS_4340_SPEED_PID_KI_MAX);

}

float chassis_4340_id5_speed_pid_loop(float chassis_4340_ID5_speed_set_loop)
{
    PID_calc(&chassis_4340_id5_speed_pid, DM4340_05.return_speed , chassis_4340_ID5_speed_set_loop);
    float chassis_4340_id5_given_current_loop = (chassis_4340_id5_speed_pid.out);

    return chassis_4340_id5_given_current_loop ;

}


void chassis_4340_id5_angle_pid_init(void)
{
    static fp32 chassis_4340_id5_angle_kpkikd[3] = {CHASSIS_4340_ID5_ANGLE_PID_KP, CHASSIS_4340_ID5_ANGLE_PID_KI, CHASSIS_4340_ID5_ANGLE_PID_KD};
    PID_init(&chassis_4340_id5_angle_pid, PID_POSITION, chassis_4340_id5_angle_kpkikd, CHASSIS_4340_ANGLE_PID_OUT_MAX, CHASSIS_4340_ANGLE_PID_KI_MAX);

}

float chassis_4340_id5_angle_pid_loop(float chassis_4340_ID5_angle_set_loop)
{
    PID_calc(&chassis_4340_id5_angle_pid, DM4340_05.return_angle , chassis_4340_ID5_angle_set_loop);
    float chassis_4340_id5_given_speed_loop = (chassis_4340_id5_angle_pid.out);

    return chassis_4340_id5_given_speed_loop ;

}


void chassis_4340_id6_speed_pid_init(void)
{
    static fp32 chassis_4340_id6_speed_kpkikd[3] = {CHASSIS_4340_ID6_SPEED_PID_KP, CHASSIS_4340_ID6_SPEED_PID_KI, CHASSIS_4340_ID6_SPEED_PID_KD};
    PID_init(&chassis_4340_id6_speed_pid, PID_POSITION, chassis_4340_id6_speed_kpkikd, CHASSIS_4340_SPEED_PID_OUT_MAX, CHASSIS_4340_SPEED_PID_KI_MAX);

}

float chassis_4340_id6_speed_pid_loop(float chassis_4340_ID6_speed_set_loop)
{
    PID_calc(&chassis_4340_id6_speed_pid, DM4340_06.return_speed , chassis_4340_ID6_speed_set_loop);
    float chassis_4340_id6_given_current_loop = (chassis_4340_id6_speed_pid.out);

    return chassis_4340_id6_given_current_loop ;

}


void chassis_4340_id6_angle_pid_init(void)
{
    static fp32 chassis_4340_id6_angle_kpkikd[3] = {CHASSIS_4340_ID6_ANGLE_PID_KP, CHASSIS_4340_ID6_ANGLE_PID_KI, CHASSIS_4340_ID6_ANGLE_PID_KD};
    PID_init(&chassis_4340_id6_angle_pid, PID_POSITION, chassis_4340_id6_angle_kpkikd, CHASSIS_4340_ANGLE_PID_OUT_MAX, CHASSIS_4340_ANGLE_PID_KI_MAX);

}

float chassis_4340_id6_angle_pid_loop(float chassis_4340_ID6_angle_set_loop)
{
    PID_calc(&chassis_4340_id6_angle_pid, DM4340_06.return_angle , chassis_4340_ID6_angle_set_loop);
    float chassis_4340_id6_given_speed_loop = (chassis_4340_id6_angle_pid.out);

    return chassis_4340_id6_given_speed_loop ;

}




void chassis_4340_id7_speed_pid_init(void)
{
    static fp32 chassis_4340_id7_speed_kpkikd[3] = {CHASSIS_4340_ID7_SPEED_PID_KP, CHASSIS_4340_ID7_SPEED_PID_KI, CHASSIS_4340_ID7_SPEED_PID_KD};
    PID_init(&chassis_4340_id7_speed_pid, PID_POSITION, chassis_4340_id7_speed_kpkikd, CHASSIS_4340_SPEED_PID_OUT_MAX, CHASSIS_4340_SPEED_PID_KI_MAX);

}

float chassis_4340_id7_speed_pid_loop(float chassis_4340_ID7_speed_set_loop)
{
    PID_calc(&chassis_4340_id7_speed_pid, DM4340_07.return_speed , chassis_4340_ID7_speed_set_loop);
    float chassis_4340_id7_given_current_loop = (chassis_4340_id7_speed_pid.out);

    return chassis_4340_id7_given_current_loop ;

}


void chassis_4340_id7_angle_pid_init(void)
{
    static fp32 chassis_4340_id7_angle_kpkikd[3] = {CHASSIS_4340_ID7_ANGLE_PID_KP, CHASSIS_4340_ID7_ANGLE_PID_KI, CHASSIS_4340_ID7_ANGLE_PID_KD};
    PID_init(&chassis_4340_id7_angle_pid, PID_POSITION, chassis_4340_id7_angle_kpkikd, CHASSIS_4340_ANGLE_PID_OUT_MAX, CHASSIS_4340_ANGLE_PID_KI_MAX);

}

float chassis_4340_id7_angle_pid_loop(float chassis_4340_ID7_angle_set_loop)
{
    PID_calc(&chassis_4340_id7_angle_pid, DM4340_07.return_angle , chassis_4340_ID7_angle_set_loop);
    float chassis_4340_id7_given_speed_loop = (chassis_4340_id7_angle_pid.out);

    return chassis_4340_id7_given_speed_loop ;

}
