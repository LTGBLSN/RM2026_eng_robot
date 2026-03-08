//
// Created by 21481 on 2026/1/29.
//

#include "main.h"
#include "uart_printf.h"
#include "cmsis_os.h"
#include "remote_control.h"
#include "IMU_DATA_GET.h"
#include "DJI_motors.h"
#include "dm_motor.h"
#include "GET_RC_TASK.h"
#include "BOARD_COMMUNICATION_TASK.h"

void DEBUG_UART_TASK()
{
    while (1)
    {
        usart1_printf("%f,%f,%f,%f,%f,%f \r\n",
                      MOTOR2_ABSCISSA,
                      MOTOR3_ABSCISSA,
                      MOTOR4_ABSCISSA,
                      MOTOR5_ABSCISSA,
                      MOTOR6_ABSCISSA,
                      MOTOR7_ABSCISSA);
        osDelay(1);
    }
}

