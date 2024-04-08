/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:38:32
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-07 18:24:09
 * @FilePath: /smartSDGD/src/gpio.c
 * @Description:
 */

#include "rcu.h"

/*!
    \brief      RCU configuration function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void rcu_config(void)
{
    /* enable the GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    /* enable DMA clock */
    rcu_periph_clock_enable(RCU_DMA1);
    /* enable TIMER0 clock */
    // rcu_periph_clock_enable(RCU_TIMER0);
    /* enable ADC clock */
    rcu_periph_clock_enable(RCU_ADC);
    adc_clock_config(ADC_ADCCK_HCLK_DIV6);
}