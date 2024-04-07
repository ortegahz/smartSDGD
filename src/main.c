/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 15:18:22
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-07 13:17:29
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

    printf("\n\rsmoke detector !!!\n\r");

    while (1)
    {
        flash_smoke_transmitter();
        printf("the ADC conversion result is 0x%04X \n", adc_value);
    }
}
