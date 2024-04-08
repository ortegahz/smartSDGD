/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 15:18:22
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-08 15:35:29
 * @FilePath: /smartSDGD/src/main.c
 * @Description: main
 */

#include "gd32w51x.h"
#include "gd32w515p_eval.h"
#include "gpio.h"
#include "rcu.h"
#include "adc.h"
#include "dma.h"
#include "time.h"
#include "nvic.h"

uint16_t adc_value;

int main(void)
{
    systick_config();
    rcu_config();
    gpio_config();
    dma_config();
    timer_config();
    adc_config();
    gd_eval_com_init(EVAL_COM0);
    test_status_led_init();
    smoke_control_init();
    nvic_config();

    printf("\n\rsmoke detector !!!\n\r");

    while (1)
    {
        // flash_smoke_transmitter();
        // delay_1ms(1000);
        // printf("off result is %d \n", adc_value);
    }
}
