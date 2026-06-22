/*******************************************************************************
 * File Name: cycfg_peripherals.h
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include <infineon_kconfig.h>
#include <zephyr/device.h>

#include <infineon_autanalog.h>

#include "cy_pdl.h"
#include "cy_autanalog.h"
#include "cy_autanalog_sar.h"

#define CYBSP_AUTONOMOUS_ANALOG_ENABLED 1U
#define CYBSP_AUTONOMOUS_ANALOG_lppass_IRQ pass_interrupt_lppass_IRQn
#define CYBSP_AUTONOMOUS_ANALOG_fifo_IRQ pass_interrupt_fifo_IRQn
#define CYBSP_AUTONOMOUS_CONTROLLER_ENABLED 1U
#define CYBSP_SAR_ADC_ENABLED 1U
#define CYBSP_AUTONOMOUS_CONTROLLER_STATE_0_ENABLED 1U
#define CYBSP_AUTONOMOUS_CONTROLLER_STATE_1_ENABLED 1U
#define CYBSP_AUTONOMOUS_CONTROLLER_STATE_2_ENABLED 1U
#define CYBSP_SAR_ADC_SCAN_GRP_0_ENABLED 1U
#define temp_sensor_mx_ENABLED 1U
#define CYBSP_SAR_ADC_SCAN_GRP_0_SCAN_0_ENABLED 1U

extern cy_stc_autanalog_cfg_t autonomous_analog_cfg;
extern cy_stc_autanalog_stt_t autonomous_analog_stt[];
extern cy_stc_autanalog_t autonomous_analog_init;
extern cy_en_autanalog_ac_out_trigger_mask_t CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[];
extern cy_stc_autanalog_ac_t CYBSP_AUTONOMOUS_CONTROLLER_cfg;
extern cy_stc_autanalog_stt_ac_t CYBSP_AUTONOMOUS_CONTROLLER_stt[];
extern cy_stc_autanalog_sar_mux_chan_t CYBSP_SAR_ADC_mux_ch_cfg[];
extern cy_stc_autanalog_sar_sta_lp_t CYBSP_SAR_ADC_sta_lp_cfg;
extern cy_stc_autanalog_sar_sta_t CYBSP_SAR_ADC_sta_cfg;
extern cy_stc_autanalog_sar_seq_tab_lp_t CYBSP_SAR_ADC_seq_lp_cfg[];
extern cy_stc_autanalog_sar_t CYBSP_SAR_ADC_cfg;
extern cy_stc_autanalog_stt_sar_t CYBSP_SAR_ADC_stt[];




#endif /* CYCFG_PERIPHERALS_H */
