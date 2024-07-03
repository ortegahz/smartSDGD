/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:38:32
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-08 09:50:56
 * @FilePath: /smartSDGD/src/time.c
 * @Description:
 */

#include "time.h"
#include "gd32w51x.h"

static void timer_config_adc_trigge(void)
{
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;

    timer_deinit(TIMER0);

    /* TIMER0 configuration */
    timer_initpara.prescaler = 5;
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection = TIMER_COUNTER_UP;
    timer_initpara.period = 399;
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER0, &timer_initpara);

    /* CH0 configuration in PWM mode1 */
    timer_ocintpara.ocpolarity = TIMER_OC_POLARITY_LOW;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_channel_output_config(TIMER0, TIMER_CH_0, &timer_ocintpara);

    timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_0, 100);
    timer_channel_output_mode_config(TIMER0, TIMER_CH_0, TIMER_OC_MODE_PWM1);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);

    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER0);
    timer_primary_output_config(TIMER0, ENABLE);
    timer_enable(TIMER0);
}

static void timer_config_smoke_sample(void)
{
    /* ----------------------------------------------------------------------------
    TIMER2 Configuration:
    TIMER2CLK = SystemCoreClock/9000 = 20KHz.
    TIMER2 configuration is timing mode, and the timing is 1s(1000/20000 = 1 / 20 s).
    ---------------------------------------------------------------------------- */
    timer_parameter_struct timer_initpara;

    /* enable the peripherals clock */
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
    rcu_periph_clock_enable(RCU_TIMER2);

    /* deinit a TIMER */
    timer_deinit(TIMER2);
    /* initialize TIMER init parameter struct */
    timer_struct_para_init(&timer_initpara);
    /* TIMER2 configuration */
    timer_initpara.prescaler = 8999;
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection = TIMER_COUNTER_UP;
    timer_initpara.period = 1000;
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
    timer_init(TIMER2, &timer_initpara);

    /* clear interrupt bit */
    timer_interrupt_flag_clear(TIMER2, TIMER_INT_FLAG_UP);
    /* enable the TIMER interrupt */
    timer_interrupt_enable(TIMER2, TIMER_INT_UP);
    /* enable a TIMER */
    timer_enable(TIMER2);
}

void timer_config(void)
{
    timer_config_smoke_sample();
}