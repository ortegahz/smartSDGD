/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 15:18:22
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-03-28 16:33:40
 * @FilePath: /smartSDGD/src/main.c
 * @Description:
 */
#include "gd32w51x.h"
#include "systick.h"
#include <stdio.h>
#include "gd32w515p_eval.h"

void test_status_led_init(void);
void flash_led(int times);
void test_key_init(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    systick_config();
    test_status_led_init();
    gd_eval_com_init(EVAL_COM0);
    printf("\n\rhello world !!!\n\r");

    while (1)
    {
        flash_led(1);
    }
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(EVAL_COM0, (uint8_t)ch);
    while (RESET == usart_flag_get(EVAL_COM0, USART_FLAG_TBE))
        ;
    return ch;
}

/*!
    \brief      test status LED initialize
    \param[in]  none
    \param[out] none
    \retval     none
*/
void test_status_led_init(void)
{
    /* LEDs initialize */
    gd_eval_led_init(LED1);
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
}

/*!
    \brief      LED blink function
    \param[in]  times: the blink times of LEDs
    \param[out] none
    \retval     none
*/
void flash_led(int times)
{
    int i;

    for (i = 0; i < times; i++)
    {
        /* insert 200 ms delay */
        delay_1ms(200);

        /* turn on LEDs */
        gd_eval_led_on(LED1);
        gd_eval_led_on(LED2);
        gd_eval_led_on(LED3);

        /* insert 200 ms delay */
        delay_1ms(200);

        /* turn off LEDs */
        gd_eval_led_off(LED1);
        gd_eval_led_off(LED2);
        gd_eval_led_off(LED3);
    }
}
