/*!
    \file    gd32w515p_eval.h
    \brief   definitions for GD32W515P_EVAL's leds, keys and COM ports hardware resources

    \version 2023-06-28, V1.1.3, demo for GD32W51x
*/

#ifndef GD32W515P_EVAL_H
#define GD32W515P_EVAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

#include "gd32w51x.h"

    /* exported types */
    typedef enum
    {
        LED1 = 0,
        LED2 = 1,
        LED3 = 2,
        SMK_IRF = 3,
        SMK_UVF = 4,
        SMK_IRB = 5
    } led_typedef_enum;

    typedef enum
    {
        KEY_TAMPER_WAKEUP = 0,
    } key_typedef_enum;

    typedef enum
    {
        KEY_MODE_GPIO = 0,
        KEY_MODE_EXTI = 1
    } keymode_typedef_enum;

/* smoke red forward [SMK-IR2 <--> PC4] */
#define SMK_IRF_PIN GPIO_PIN_4
#define SMK_IRF_GPIO_PORT GPIOC
#define SMK_IRF_GPIO_CLK RCU_GPIOC

/* smoke blue forward [SMK-UV <--> PA7] */
#define SMK_UVF_PIN GPIO_PIN_7
#define SMK_UVF_GPIO_PORT GPIOA
#define SMK_UVF_GPIO_CLK RCU_GPIOA

/* smoke red backward [SMK-IR1 <--> PC5] */
#define SMK_IRB_PIN GPIO_PIN_5
#define SMK_IRB_GPIO_PORT GPIOC
#define SMK_IRB_GPIO_CLK RCU_GPIOC

/* eval board low layer led */
#define LEDn 6U

#define LED1_PIN GPIO_PIN_7
#define LED1_GPIO_PORT GPIOC
#define LED1_GPIO_CLK RCU_GPIOC

#define LED2_PIN GPIO_PIN_6
#define LED2_GPIO_PORT GPIOC
#define LED2_GPIO_CLK RCU_GPIOC

#define LED3_PIN GPIO_PIN_4
#define LED3_GPIO_PORT GPIOB
#define LED3_GPIO_CLK RCU_GPIOB

#define COMn 1U
#define EVAL_COM0 USART2
#define EVAL_COM0_CLK RCU_USART2

#define EVAL_COM0_TX_PIN GPIO_PIN_10
#define EVAL_COM0_RX_PIN GPIO_PIN_11

#define EVAL_COM0_GPIO_PORT GPIOB
#define EVAL_COM0_GPIO_CLK RCU_GPIOB
#define EVAL_COM0_TX_AF GPIO_AF_7
#define EVAL_COM0_RX_AF GPIO_AF_7

#define KEYn 1U

/* tamper push-button */
#define TAMPER_WAKEUP_KEY_PIN GPIO_PIN_2
#define TAMPER_WAKEUP_KEY_GPIO_PORT GPIOA
#define TAMPER_WAKEUP_KEY_GPIO_CLK RCU_GPIOA
#define TAMPER_WAKEUP_KEY_EXTI_LINE EXTI_2
#define TAMPER_WAKEUP_KEY_EXTI_PORT_SOURCE EXTI_SOURCE_GPIOA
#define TAMPER_WAKEUP_KEY_EXTI_PIN_SOURCE EXTI_SOURCE_PIN2
#define TAMPER_WAKEUP_KEY_EXTI_IRQn EXTI2_IRQn

    /* function declarations */
    /* configures led GPIO */
    void gd_eval_led_init(led_typedef_enum lednum);
    /* turn on selected led */
    void gd_eval_led_on(led_typedef_enum lednum);
    /* turn off selected led */
    void gd_eval_led_off(led_typedef_enum lednum);
    /* toggle the selected led */
    void gd_eval_led_toggle(led_typedef_enum lednum);
    /* configure key */
    void gd_eval_key_init(key_typedef_enum key_num, keymode_typedef_enum key_mode);
    /* return the selected button state */
    uint8_t gd_eval_key_state_get(key_typedef_enum button);
    /* configure COM port */
    void gd_eval_com_init(uint32_t com);
    /* retarget the C library printf function to the USART */
    int fputc(int ch, FILE *f);

#ifdef __cplusplus
}
#endif

#endif /* GD32W515P_EVAL_H */
