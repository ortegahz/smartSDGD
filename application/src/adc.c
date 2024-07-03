/*
 * @Author: manu zxthz@126.com
 * @Date: 2024-03-28 16:38:32
 * @LastEditors: manu zxthz@126.com
 * @LastEditTime: 2024-04-08 08:35:23
 * @FilePath:
 * @Description:
 */

#include "adc.h"

/*!
    \brief      ADC configuration function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void adc_config(void)
{
    /* ADC channel length config */
    adc_channel_length_config(ADC_REGULAR_CHANNEL, 1);

    /* ADC regular channel config */
    adc_regular_channel_config(0, ADC_CHANNEL_6, ADC_SAMPLETIME_1POINT5);

    /* ADC external trigger enable */
    // adc_external_trigger_config(ADC_REGULAR_CHANNEL, ENABLE);
    /* ADC external trigger source config */
    // adc_external_trigger_source_config(ADC_REGULAR_CHANNEL, ADC_EXTTRIG_REGULAR_T0_CH0);
    /* ADC data alignment config */

    adc_special_function_config(ADC_CONTINUOUS_MODE, ENABLE);
    adc_data_alignment_config(ADC_DATAALIGN_RIGHT);
    adc_oversample_mode_config(ADC_OVERSAMPLING_ALL_CONVERT, ADC_OVERSAMPLING_SHIFT_NONE, ADC_OVERSAMPLING_RATIO_MUL16);
    adc_oversample_mode_enable();

    /* enable ADC interface */
    adc_enable();
    /* wait for ADC stability */
    delay_1ms(1);

    /* ADC DMA function enable */
    adc_dma_request_after_last_enable();
    adc_dma_mode_enable();
    /* enable ADC software trigger */
    adc_software_trigger_enable(ADC_REGULAR_CHANNEL);
}