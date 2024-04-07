/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:35:02
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-07 10:23:05
 * @FilePath:
 * @Description:
 */
#ifndef GPIO_H
#define GPIO_H

#include "gd32w515p_eval.h"
#include "systick.h"

void smoke_control_init(void);
void test_status_led_init(void);
void flash_led(int times);
void flash_smoke_transmitter(void);
void gpio_config(void);

#endif
