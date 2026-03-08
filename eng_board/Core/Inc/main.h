/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#define INIT_FINISH 1
#define INIT_INCOMPLETE 0



/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern float gyro[3], accel[3], temp;
extern float INS_quat[4] ;
extern float INS_angle[3] ;
extern float INS_degree[3] ;


extern int16_t CHASSIS_3508_ID1_GIVEN_CURRENT;
extern int16_t CHASSIS_3508_ID2_GIVEN_CURRENT;
extern int16_t CHASSIS_3508_ID3_GIVEN_CURRENT;
extern int16_t CHASSIS_3508_ID4_GIVEN_CURRENT;
extern int16_t CHASSIS_3508_ID5_GIVEN_CURRENT;
extern int16_t CHASSIS_3508_ID6_GIVEN_CURRENT;

extern float CHASSIS_3508_ID1_GIVEN_SPEED;
extern float CHASSIS_3508_ID2_GIVEN_SPEED;
extern float CHASSIS_3508_ID3_GIVEN_SPEED;
extern float CHASSIS_3508_ID4_GIVEN_SPEED;
extern float CHASSIS_3508_ID5_GIVEN_SPEED;
extern float CHASSIS_3508_ID6_GIVEN_SPEED;

extern float chassis_wheel_vx;
extern float chassis_wheel_vy;
extern float chassis_wheel_vround;
extern float chassis_track_vx;
extern float chassis_track_vround;

extern uint32_t time ;



extern uint8_t motor2_init_state ;
extern int16_t motor2_last_ecd ;
extern int16_t MOTOR2_LAPS ;
extern float MOTOR2_ABSCISSA ;
extern int16_t motor2_power_up_ecd ;

extern uint8_t motor3_init_state ;
extern int16_t motor3_last_ecd ;
extern int16_t MOTOR3_LAPS ;
extern float MOTOR3_ABSCISSA ;
extern int16_t motor3_power_up_ecd ;

extern uint8_t motor4_init_state ;
extern int16_t motor4_last_ecd ;
extern int16_t MOTOR4_LAPS ;
extern float MOTOR4_ABSCISSA ;
extern int16_t motor4_power_up_ecd ;

extern uint8_t motor5_init_state ;
extern int16_t motor5_last_ecd ;
extern int16_t MOTOR5_LAPS ;
extern float MOTOR5_ABSCISSA ;
extern int16_t motor5_power_up_ecd ;

extern uint8_t motor6_init_state ;
extern int16_t motor6_last_ecd ;
extern int16_t MOTOR6_LAPS ;
extern float MOTOR6_ABSCISSA ;
extern int16_t motor6_power_up_ecd ;

extern uint8_t motor7_init_state ;
extern int16_t motor7_last_ecd ;
extern int16_t MOTOR7_LAPS ;
extern float MOTOR7_ABSCISSA ;
extern int16_t motor7_power_up_ecd ;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define POWER_OUT2_Pin GPIO_PIN_13
#define POWER_OUT2_GPIO_Port GPIOC
#define POWER_OUT1_Pin GPIO_PIN_14
#define POWER_OUT1_GPIO_Port GPIOC
#define POWER_OUT5V_Pin GPIO_PIN_15
#define POWER_OUT5V_GPIO_Port GPIOC
#define ACC_CS_Pin GPIO_PIN_0
#define ACC_CS_GPIO_Port GPIOC
#define GYRO_CS_Pin GPIO_PIN_3
#define GYRO_CS_GPIO_Port GPIOC
#define ACC_INT_Pin GPIO_PIN_10
#define ACC_INT_GPIO_Port GPIOE
#define GYRO_INT_Pin GPIO_PIN_12
#define GYRO_INT_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
