//
// Created by 21481 on 2026/1/29.
//

#ifndef DM_H723_LIB_REMOTE_CONTROL_H
#define DM_H723_LIB_REMOTE_CONTROL_H

#include "main.h"

#define DBUS 0
#define SBUS 1
#define VTM  2

#define REMOTE_TYPE VTM//遥控器协议切换，DBUS或SBUS

#define SBUS_CHANNEL_MAX 1811.0f
#define SBUS_CHANNEL_MIN 174.0f
#define SBUS_CHANNEL_MID ((SBUS_CHANNEL_MAX + SBUS_CHANNEL_MIN) / 2)
#define SBUS_CHANNEL_HALF_RANGE ((SBUS_CHANNEL_MAX - SBUS_CHANNEL_MIN) / 2)

#define DBUS_CHANNEL_HALF_RANGE 660.0f

#define VTM_CHANNEL_MAX 1684.0f
#define VTM_CHANNEL_MIN 364.0f
#define VTM_CHANNEL_MID ((VTM_CHANNEL_MAX + VTM_CHANNEL_MIN) / 2)
#define VTM_CHANNEL_HALF_RANGE ((VTM_CHANNEL_MAX - VTM_CHANNEL_MIN) / 2)



#if REMOTE_TYPE == SBUS



#define SBUS_BUFF_SIZE	25

extern uint8_t rx_subs_buff[SBUS_BUFF_SIZE];




typedef struct
{
    uint16_t online;

    struct
    {
        int16_t ch[10];
    } rc;

    struct
    {
        /* STICK VALUE */
        int16_t left_vert;
        int16_t left_hori;
        int16_t right_vert;
        int16_t right_hori;
    } joy;

    struct
    {
        /* VAR VALUE */
        float a;
        float b;
    } var;

    struct
    {
        /* KEY VALUE */
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t f;
        uint8_t g;
        uint8_t h;
    } key;
} subs_remoter_t;
extern subs_remoter_t sbus_remoter;




#endif




#if REMOTE_TYPE == DBUS



#define DBUS_FRAME_SIZE      18
#define DBUS_BUFF_SIZE       (DBUS_FRAME_SIZE * 2) // 这里的缓存设大一点防止溢出
#define RC_CH_VALUE_OFFSET   1024

typedef struct {
    struct {
        int16_t ch[5];       // 4个摇杆通道 + 1个左侧拨轮
        uint8_t s[2];        // 2个三档开关
    } rc;

    struct {
        int16_t x;
        int16_t y;
        int16_t z;
        uint8_t press_l;
        uint8_t press_r;
    } mouse;

    struct {
        uint16_t v;          // 键盘按键值
    } key;

    uint16_t online;         // 在线状态
} dbus_ctrl_t;

extern dbus_ctrl_t dbus_remoter;
extern uint8_t rx_dbus_buff[DBUS_BUFF_SIZE];

void dbus_frame_parse(dbus_ctrl_t *remoter, uint8_t *buf);

#endif



//vtm

#define VTM_ALL_BUFF_SIZE       256

extern uint8_t rx_VTM_buff[VTM_ALL_BUFF_SIZE];
extern struct remote_data_t vtm_remoter;

struct remote_data_t
{
    uint8_t sof_1;
    uint8_t sof_2;
    uint64_t ch_0:11;
    uint64_t ch_1:11;
    uint64_t ch_3:11;
    uint64_t ch_2:11;
    uint64_t mode_sw:2;//中间档位开关
    uint64_t pause:1;//暂停按键
    uint64_t fn_1:1;//fn按键
    uint64_t fn_2:1;//旋转相机按键
    uint64_t ch_4:11;//波轮
    uint64_t trigger:1;//扳机按键

    int16_t mouse_x;
    int16_t mouse_y;
    int16_t mouse_z;
    uint8_t mouse_left:2;//左键
    uint8_t mouse_right:2;//右键
    uint8_t mouse_middle:2;//中键
    uint16_t key;
    uint16_t crc16;
} __attribute__((packed)) ;

void Process_VTM_Data(uint8_t *pData, uint16_t size);
void Process_Custom_Controller_Data(uint8_t *pData, uint16_t size);






#endif //DM_H723_LIB_REMOTE_CONTROL_H
