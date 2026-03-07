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
        usart1_printf("%d,%d,%d,%d,%d,%d \r\n",
                      follow_arm.motor0,
                      follow_arm.motor1,
                      follow_arm.motor2,
                      follow_arm.motor3,
                      follow_arm.motor4,
                      follow_arm.motor5);
        osDelay(1);
    }
}

