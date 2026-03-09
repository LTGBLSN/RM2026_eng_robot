//
// Created by 21481 on 2025/3/16.
//

#ifndef BUBING_RM2025_UART_SENT_H
#define BUBING_RM2025_UART_SENT_H

void uart_sent_debug();


struct follow_arm_data
{
    int16_t motor0;
    int16_t motor1;
    int16_t motor2;
    int16_t motor3;
    int16_t motor4;
    int16_t motor5;
    int16_t clamp;
    int16_t motor7;
    int16_t motor8;
    int16_t motor9;
    uint8_t stateA;
    uint8_t stateB;

} __attribute__((packed)) ;




#endif //BUBING_RM2025_UART_SENT_H
