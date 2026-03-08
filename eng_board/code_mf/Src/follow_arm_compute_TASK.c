//
// Created by 21481 on 2026/3/9.
//


#include "main.h"
#include "cmsis_os.h"
#include "BOARD_COMMUNICATION_TASK.h"
#include "follow_arm_compute_TASK.h"
#include "GET_RC_TASK.h"


void follow_arm_compute_TASK()
{
    while (1)
    {
        if(rcData.rc.s[0] == 1 && rcData.rc.s[1] == 1)
        {
            MOTOR2_LAPS = 0 ;
            motor2_power_up_ecd = follow_arm.motor0 ;
            MOTOR3_LAPS = 0 ;
            motor3_power_up_ecd = follow_arm.motor1 ;
            MOTOR4_LAPS = 0 ;
            motor4_power_up_ecd = follow_arm.motor2 ;
            MOTOR5_LAPS = 0 ;
            motor5_power_up_ecd = follow_arm.motor3 ;
            MOTOR6_LAPS = 0 ;
            motor6_power_up_ecd = follow_arm.motor4 ;
            MOTOR7_LAPS = 0 ;
            motor7_power_up_ecd = follow_arm.motor5 ;

        }

        motor2_getAbscissa();
        motor3_getAbscissa();
        motor4_getAbscissa();
        motor5_getAbscissa();
        motor6_getAbscissa();
        motor7_getAbscissa();



        osDelay(1);
    }
}



void motor2_getAbscissa()
{
    if((motor2_last_ecd - follow_arm.motor0) > 4000)
    {

        MOTOR2_LAPS++ ;

    }
    if((follow_arm.motor0 - motor2_last_ecd ) > 4000)
    {

        MOTOR2_LAPS-- ;

    }

    motor2_last_ecd = follow_arm.motor0 ;

    MOTOR2_ABSCISSA = ((8191.0f * (float)MOTOR2_LAPS + (float)follow_arm.motor0 - (float)motor2_power_up_ecd) / 8191.0f) * 2.0f * (float)M_PI ;


}


void motor3_getAbscissa()
{
    if((motor3_last_ecd - follow_arm.motor1) > 4000)
    {

        MOTOR3_LAPS++ ;

    }
    if((follow_arm.motor1 - motor3_last_ecd ) > 4000)
    {

        MOTOR3_LAPS-- ;

    }

    motor3_last_ecd = follow_arm.motor1 ;

    MOTOR3_ABSCISSA = ((8191.0f * (float)MOTOR3_LAPS + (float)follow_arm.motor1 - (float)motor3_power_up_ecd) / 8191.0f) * 2.0f * (float)M_PI ;


}

void motor4_getAbscissa()
{
    if((motor4_last_ecd - follow_arm.motor2) > 4000)
    {

        MOTOR4_LAPS++ ;

    }
    if((follow_arm.motor2 - motor4_last_ecd ) > 4000)
    {

        MOTOR4_LAPS-- ;

    }

    motor4_last_ecd = follow_arm.motor2 ;

    MOTOR4_ABSCISSA = ((8191.0f * (float)MOTOR4_LAPS + (float)follow_arm.motor2 - (float)motor4_power_up_ecd) / 8191.0f) * 2.0f * (float)M_PI ;


}


void motor5_getAbscissa()
{
    if((motor5_last_ecd - follow_arm.motor3) > 4000)
    {

        MOTOR5_LAPS++ ;

    }
    if((follow_arm.motor3 - motor5_last_ecd ) > 4000)
    {

        MOTOR5_LAPS-- ;

    }

    motor5_last_ecd = follow_arm.motor3 ;

    MOTOR5_ABSCISSA = ((8191.0f * (float)MOTOR5_LAPS + (float)follow_arm.motor3 - (float)motor5_power_up_ecd) / 8191.0f) * 2.0f * (float)M_PI ;


}


void motor6_getAbscissa()
{
    if((motor6_last_ecd - follow_arm.motor4) > 4000)
    {

        MOTOR6_LAPS++ ;

    }
    if((follow_arm.motor4 - motor6_last_ecd ) > 4000)
    {

        MOTOR6_LAPS-- ;

    }

    motor6_last_ecd = follow_arm.motor4 ;

    MOTOR6_ABSCISSA = ((8191.0f * (float)MOTOR6_LAPS + (float)follow_arm.motor4 - (float)motor6_power_up_ecd) / 8191.0f) * 2.0f * (float)M_PI ;


}


void motor7_getAbscissa()
{
    if((motor7_last_ecd - follow_arm.motor5) > 4000)
    {

        MOTOR7_LAPS++ ;

    }
    if((follow_arm.motor5 - motor7_last_ecd ) > 4000)
    {

        MOTOR7_LAPS-- ;

    }

    motor7_last_ecd = follow_arm.motor5 ;

    MOTOR7_ABSCISSA = ((8191.0f * (float)MOTOR7_LAPS + (float)follow_arm.motor5 - (float)motor7_power_up_ecd) / 8191.0f) * 2.0f * (float)M_PI ;


}







