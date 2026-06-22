/*
 * SPDX-FileCopyrightText: <text>Copyright (c) 2026 Infineon Technologies AG,
 * or an affiliate of Infineon Technologies AG. All rights reserved.</text>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Low-power autonomous analog audio sample.
 *
 * Uses the autonomous analog in low power mode to detect acoustic
 * activity and prints the detected audio frame to the console.
 *
 *   1. CTB0 OA0 amplifies the analog microphone signal.
 *   2. PTCOMP comparators perform Acoustic Activity Detection (AAD)
 *      by comparing the preamp output against two PRB reference
 *      voltages.
 *   3. The SAR ADC samples the preamp output in LP mode through an
 *      internal MUX channel.  Results are collected in a 512-word
 *      FIFO; a watermark interrupt fires every 160 samples (~10 ms).
 *   4. The AC state machine is started by ifx_autanalog_fw_trigger().
 *   5. Audio frame statistics are printed to the console using the
 *      ADC stream API (RTIO-based).
 */

#include <inttypes.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/rtio/rtio.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>
#include <cycfg_peripherals.h>

#define ADC_SCAN_DELAY_MSEC         (500U)
#define SAR_ADC_INDEX               (0U)
#define SAR_ADC_SEQENCER            (0U)
#define SAR_ADC_CHANNEL             (0U)
#define SAR_ADC_VREF_MV             (1800U)

int main(void)
{
    uint32_t result;
    int32_t sar_adc_count;
    int16_t chipTemp;
    uint8_t  sarIdx       = 0U;
    uint8_t  sarSequencer = 0U;
    uint8_t  sarChannel   = 0U;
    uint32_t VrefmV       = 900U; /* Vbgr = 0.9V */

    /* Initialize SAR ADC */
    result = Cy_AutAnalog_Init(&autonomous_analog_init);
    if (CY_AUTANALOG_SUCCESS != result)
    {
 	    printf("init error\r\n");
    }

    // the following workarount for B0 slicon to unload bandgap trimming data as temp sensor was trimming based on untrimmed bandgap
	INFRA->AREF.VREF_TRIM1 = 0U;
	INFRA->AREF.VREF_TRIM2 = 0U;

    /* Start autonomous control of the ADC */
    Cy_AutAnalog_StartAutonomousControl();



    /* Read ADC result */
	while(1){

		
	    sar_adc_count = Cy_AutAnalog_SAR_ReadResult(SAR_ADC_INDEX,
												    CY_AUTANALOG_SAR_INPUT_MUX,
	                                                SAR_ADC_CHANNEL);

	
	    /* Convert ADC counts to temperaturue */
        chipTemp = Cy_AutAnalog_SAR_CountsTo_degreeC(SAR_ADC_INDEX, true, 
                                                     SAR_ADC_SEQENCER, 
                                                     SAR_ADC_CHANNEL, 
                                                     sar_adc_count);
 	
	    /* Print ADC output in millivolts */
	    printf("ADC Count = %d; Temperature (degree C) = %d\r\n", sar_adc_count, chipTemp);

		k_msleep(500);
	}


	return 0;
}
