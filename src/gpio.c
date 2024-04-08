/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:38:32
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-08 15:27:51
 * @FilePath: /smartSDGD/src/gpio.c
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
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

static void delay_xms(uint32_t n)
{
    uint32_t i;
    for (i = 0; i < n; i++)
    {
        __NOP();
    }
}

void flash_smoke_transmitter(void)
{
    uint32_t timeDelay = 1 << 14;

    // delay_1ms(2000);

    /* turn on LEDs */
    gd_eval_led_on(SMK_IRF);
    // delay_1ms(timeDelay);
    delay_xms(timeDelay);
    printf("irf on result is %d \n", adc_value);

    gd_eval_led_on(SMK_UVF);
    // delay_1ms(timeDelay);
    delay_xms(timeDelay);
    printf("uvf on result is %d \n", adc_value);

    // gd_eval_led_on(SMK_IRB);

    /* turn off LEDs */
    gd_eval_led_off(SMK_IRF);
    gd_eval_led_off(SMK_UVF);
    // gd_eval_led_off(SMK_IRB);
    // delay_1ms(timeDelay);
    delay_xms(timeDelay);

    printf("off result is %d \n", adc_value);
}

void gpio_config(void)
{
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_2);
}