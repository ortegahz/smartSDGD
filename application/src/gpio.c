/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:38:32
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-08 18:43:16
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
    uint32_t timeDelaySampleLight = 1 << 14;
    uint32_t timeDelaySampleDark = 1 << 14;

    gd_eval_led_on(SMK_IRF);
    delay_xms(timeDelaySampleLight);
    g_irfValue = g_adcValue;
    gd_eval_led_off(SMK_IRF);

    gd_eval_led_on(SMK_UVF);
    delay_xms(timeDelaySampleLight);
    g_uvfValue = g_adcValue;
    gd_eval_led_off(SMK_UVF);

    gd_eval_led_on(SMK_IRB);
    delay_xms(timeDelaySampleLight);
    g_irbValue = g_adcValue;
    gd_eval_led_off(SMK_IRB);

    delay_xms(timeDelaySampleDark);
    g_darkValue = g_adcValue;

    printf("\n\r[PARSER] %d, %d, %d, %d # irf, uvf, irb, dark\n\r", g_irfValue, g_uvfValue, g_irbValue, g_darkValue);
}

void gpio_config(void)
{
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_2);
}