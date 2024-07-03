/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:35:02
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-08 16:41:55
 * @FilePath:
 * @Description:
 */
#ifndef MAIN_H
#define MAIN_H

#include "gd32w51x.h"
#include "gd32w515p_eval.h"
#include "gpio.h"
#include "rcu.h"
#include "adc.h"
#include "dma.h"
#include "time.h"
#include "nvic.h"

extern uint16_t g_adcValue, g_irfValue, g_uvfValue, g_irbValue, g_darkValue;

#endif
