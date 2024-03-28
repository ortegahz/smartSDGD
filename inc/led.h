/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:35:02
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-03-28 16:46:58
 * @FilePath: /smartSDGD/inc/led.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef LED_H
#define LED_H

#include "gd32w515p_eval.h"
#include "systick.h"

void test_status_led_init(void);
void flash_led(int times);

#endif
