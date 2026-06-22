/*******************************************************************************
 * File Name: cycfg_peripherals.c
 *
 * Description:
 * Analog configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.34.0.9502
 * mtb-dsl-pse8xxgp 1.2.0.895
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#include <cycfg_peripherals.h>
#include "cy_autanalog_sar.h"
#include "cy_autanalog.h"

#define CYBSP_GENERAL_PURPOSE_TIMER_INPUT_DISABLED 0x7U
#define emUSB_OS_Timer_INPUT_DISABLED 0x7U
#define CYBSP_GENERAL_PURPOSE_TIMER_2_INPUT_DISABLED 0x7U
#define CYBSP_PWM_LED_CTRL_INPUT_DISABLED 0x7U
#define CYBSP_SMARTIO_PWM_INPUT_DISABLED 0x7U

cy_stc_autanalog_cfg_t autonomous_analog_cfg =
{
    .prb = NULL,
    .ac = &CYBSP_AUTONOMOUS_CONTROLLER_cfg,

    .sar =
    {
        &CYBSP_SAR_ADC_cfg, 
    },
};
cy_stc_autanalog_stt_t autonomous_analog_stt[] =
{
    {
        .ac = &CYBSP_AUTONOMOUS_CONTROLLER_stt[0U],
        .prb = NULL,

        .sar =
        {
            &CYBSP_SAR_ADC_stt[0U], 
        },
    },
    {
        .ac = &CYBSP_AUTONOMOUS_CONTROLLER_stt[1U],
        .prb = NULL,

        .sar =
        {
            &CYBSP_SAR_ADC_stt[1U], 
        },
    },
    {
        .ac = &CYBSP_AUTONOMOUS_CONTROLLER_stt[2U],
        .prb = NULL,

        .sar =
        {
            &CYBSP_SAR_ADC_stt[2U], 
        },
    },
};
cy_stc_autanalog_t autonomous_analog_init =
{
    .configuration = &autonomous_analog_cfg,
    .numSttEntries = sizeof(autonomous_analog_stt)/sizeof(autonomous_analog_stt[0U]),
    .stateTransitionTable = &autonomous_analog_stt[0U],
};
cy_en_autanalog_ac_out_trigger_mask_t CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[] =
{
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
    CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, 
};
cy_stc_autanalog_ac_t CYBSP_AUTONOMOUS_CONTROLLER_cfg =
{
    .gpioOutEn =  
 CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
    .mask =
    {
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[0U], 
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[1U], 
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[2U], 
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[3U], 
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[4U], 
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[5U], 
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[6U], 
        &CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[7U], 
    },
    .timer =
    {
        .enable = false,
        .clkSrc = CY_AUTANALOG_TIMER_CLK_LP,
        .period = 0U,
    },
};
cy_stc_autanalog_stt_ac_t CYBSP_AUTONOMOUS_CONTROLLER_stt[] =
{
    {
        .unlock = true,
        .lpMode = true,
        .condition = CY_AUTANALOG_STT_AC_CONDITION_BLOCK_READY,
        .action = CY_AUTANALOG_STT_AC_ACTION_WAIT_FOR,
        .branchState = 1U,
        .trigInt = false,
        .count = 0U,
        .unlockGpioOut = false,
        .gpioOut = CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
    },
    {
        .unlock = false,
        .lpMode = false,
        .condition = CY_AUTANALOG_STT_AC_CONDITION_SAR_DONE,
        .action = CY_AUTANALOG_STT_AC_ACTION_WAIT_FOR,
        .branchState = 0U,
        .trigInt = false,
        .count = 0U,
        .unlockGpioOut = false,
        .gpioOut = CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
    },
    {
        .unlock = false,
        .lpMode = false,
        .condition = CY_AUTANALOG_STT_AC_CONDITION_FALSE,
        .action = CY_AUTANALOG_STT_AC_ACTION_STOP,
        .branchState = 0U,
        .trigInt = false,
        .count = 0U,
        .unlockGpioOut = false,
        .gpioOut = CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
    },
};
cy_stc_autanalog_sar_mux_chan_t CYBSP_SAR_ADC_mux_ch_cfg[] =
{
    {
        .posPin = CY_AUTANALOG_SAR_PIN_MUX_TEMP_SENSOR,
        .sign = true,
        .posCoeff = CY_AUTANALOG_SAR_CH_COEFF_DISABLED,
        .negPin = CY_AUTANALOG_SAR_PIN_MUX_TEMP_SENSOR,
        .buffBypass = false,
        .accShift = true,
        .negCoeff = CY_AUTANALOG_SAR_CH_COEFF_DISABLED,
        .muxLimit = CY_AUTANALOG_SAR_LIMIT_STATUS_DISABLED,
        .fifoSel = CY_AUTANALOG_FIFO_DISABLED,
    },
};
cy_stc_autanalog_sar_sta_lp_t CYBSP_SAR_ADC_sta_lp_cfg =
{
    .lpDiffEn = true,
    .lpVref = CY_AUTANALOG_SAR_VREF_VBGR,
    .lpSampleTime =
    {
        5U, 
        5U, 
        5U, 
        5U, 
    },
};
cy_stc_autanalog_sar_sta_t CYBSP_SAR_ADC_sta_cfg =
{
    .lpStaCfg = &CYBSP_SAR_ADC_sta_lp_cfg,
    .hsStaCfg = NULL,
    .posBufPwr = CY_AUTANALOG_SAR_BUF_PWR_ULTRA_LOW_RAIL,
    .negBufPwr = CY_AUTANALOG_SAR_BUF_PWR_ULTRA_LOW,
    .accMode = CY_AUTANALOG_SAR_ACC_ACCUNDUMP,
    .startupCal = CY_AUTANALOG_SAR_CAL_DISABLED,
    .chanID = false,
    .shiftMode = true,
    .intMuxChan =
    {
        &CYBSP_SAR_ADC_mux_ch_cfg[0U], 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .limitCond =
    {
        NULL, 
        NULL, 
        NULL, 
        NULL, 
    },
    .muxResultMask =  
 CY_AUTANALOG_SAR_CHAN_MASK_MUX0,
    .firResultMask =  
 CY_AUTANALOG_SAR_MASK_FIR_DISABLED,
};
cy_stc_autanalog_sar_seq_tab_lp_t CYBSP_SAR_ADC_seq_lp_cfg[] =
{
    {
        .chanEn = true,
        .mux0Sel = CY_AUTANALOG_SAR_CHAN_CFG_MUX0,
        .sampleTimeEn = true,
        .sampleTime = CY_AUTANALOG_SAR_SAMPLE_TIME0,
        .accEn = true,
        .accCount = CY_AUTANALOG_SAR_ACC_CNT32,
        .calReq = CY_AUTANALOG_SAR_CAL_DISABLED,
        .nextAction = CY_AUTANALOG_SAR_NEXT_ACTION_GO_TO_ENTRY_ADDR,
    },
};
cy_stc_autanalog_sar_t CYBSP_SAR_ADC_cfg =
{
    .sarStaCfg = &CYBSP_SAR_ADC_sta_cfg,
    .hsSeqTabNum = 0U,
    .hsSeqTabArr = NULL,
    .lpSeqTabNum = sizeof(CYBSP_SAR_ADC_seq_lp_cfg)/sizeof(CYBSP_SAR_ADC_seq_lp_cfg[0U]),
    .lpSeqTabArr = &CYBSP_SAR_ADC_seq_lp_cfg[0U],
    .firNum = 0U,
    .firCfg = NULL,
    .fifoCfg = NULL,
};
cy_stc_autanalog_stt_sar_t CYBSP_SAR_ADC_stt[] =
{
    {
        .unlock = true,
        .enable = true,
        .trigger = false,
        .entryState = 0U,
    },
    {
        .unlock = true,
        .enable = true,
        .trigger = true,
        .entryState = 0U,
    },
    {
        .unlock = true,
        .enable = true,
        .trigger = false,
        .entryState = 0U,
    },
};

