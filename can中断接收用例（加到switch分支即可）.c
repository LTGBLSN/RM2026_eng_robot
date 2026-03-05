
                case 0x1C:
                {
                    int16_t DATA_CUSTOM_A ;//这里为自定义数据A，可改成任意从自定义控制器传过来的数据A

                    DATA_CUSTOM_A = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    rcData.rc.s[0] = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    rcData.rc.ch[0] = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    rcData.rc.ch[1] = (int16_t)((rx_data[6] << 8) | rx_data[7]);
                    break;
                }
                case 0x2C:
                {
                    int16_t DATA_CUSTOM_B ;//这里为自定义数据A，可改成任意从自定义控制器传过来的数据B

                    DATA_CUSTOM_B   = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    rcData.rc.s[1]  = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    rcData.rc.ch[2] = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    rcData.rc.ch[3] = (int16_t)((rx_data[6] << 8) | rx_data[7]);
                    break;
                }
                case 0xA1:
                {
                    follow_arm.motor0 = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    follow_arm.motor1 = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    follow_arm.motor2 = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    follow_arm.motor3 = (int16_t)((rx_data[6] << 8) | rx_data[7]);
                    break;
                }
                case 0xA2:
                {
                    follow_arm.motor4 = (int16_t)((rx_data[0] << 8) | rx_data[1]);
                    follow_arm.motor5 = (int16_t)((rx_data[2] << 8) | rx_data[3]);
                    follow_arm.clamp = (int16_t)((rx_data[4] << 8) | rx_data[5]);
                    follow_arm.stateA = rx_data[6];
                    follow_arm.stateB = rx_data[7];
                    break;
                }
