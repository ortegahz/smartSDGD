/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:38:32
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-07 10:22:37
 * @FilePath: /smartSDGD/src/gpio.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "gpio.h"

void smoke_control_init(void)
{
    gd_eval_led_init(SMK_IRF);
    gd_eval_led_init(SMK_UVF);
    gd_eval_led_init(SMK_IRB);
}

void test_status_led_init(void)
{
    /* LEDs initialize */
    gd_eval_led_init(LED1);
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
}

void flash_led(int times)
{
    int i;

    for (i = 0; i < times; i++)
    {
        /* insert 200 ms delay */
        delay_1ms(1000);

        /* turn on LEDs */
        gd_eval_led_on(LED1);
        gd_eval_led_on(LED2);
        gd_eval_led_on(LED3);

        /* insert 200 ms delay */
        delay_1ms(1000);

        /* turn off LEDs */
        gd_eval_led_off(LED1);
        gd_eval_led_off(LED2);
        gd_eval_led_off(LED3);
    }
}

void flash_smoke_transmitter(void)
{
    /* insert 200 ms delay */
    delay_1ms(200);

    /* turn on LEDs */
    gd_eval_led_on(SMK_IRF);
    gd_eval_led_on(SMK_UVF);
    gd_eval_led_on(SMK_IRB);

    /* insert 200 ms delay */
    delay_1ms(200);

    /* turn off LEDs */
    gd_eval_led_off(SMK_IRF);
    gd_eval_led_off(SMK_UVF);
    gd_eval_led_off(SMK_IRB);
}

void gpio_config(void)
{
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1);
}