/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 15:18:22
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-03-28 16:49:22
 * @FilePath: /smartSDGD/src/main.c
 * @Description: main
 */

#include "gd32w51x.h"
#include "gd32w515p_eval.h"
#include "led.h"

int main(void)
{
    systick_config();
    test_status_led_init();
    gd_eval_com_init(EVAL_COM0);

    printf("\n\rsmoke detector !!!\n\r");

    while (1)
    {
        flash_led(1);
    }
}
