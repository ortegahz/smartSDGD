/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:38:32
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-08 15:19:25
 * @FilePath:
 * @Description:
 */

#include "nvic.h"

/*!
    \brief      configure the TIMER interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void nvic_config(void)
{
    nvic_irq_enable(TIMER2_IRQn, 0, 0);
}