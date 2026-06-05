/*
 * Copyright (c) 2025 Infineon Technologies AG,
 * or an affiliate of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/mbox.h>

#if defined(CONFIG_CPU_CORTEX_M4) || defined(CONFIG_CPU_CORTEX_M55)
#define TX_ID (1)
#define RX_ID (0)
bool coreA = true;

#else
#define TX_ID (0)
#define RX_ID (1)
bool coreA;

#endif /* #if CONFIG_CPU_CORTEX_M4 || CONFIG_CPU_CORTEX_M55 */

static void rx_callback(const struct device *dev, uint32_t channel, void *user_data,
			struct mbox_msg *data)
{
	printk("Pong [%s] (on channel %d [data %d, %d])\n", coreA ? "core A" : "core B", channel,
	       *((uint32_t *)data->data), data->size);
}

static void tx_callback(const struct device *dev, uint32_t channel, void *user_data,
			struct mbox_msg *data)
{
	printk("--> TX DONE (channel : %d)\n", channel);
}

__attribute__((section(".cy_sharedmem"))) uint32_t data;

int main(void)
{
	const struct device *dev;

	data = 0;

	printk("Hello from APP [%s]\n", coreA ? "core A" : "core B");

	dev = DEVICE_DT_GET(DT_NODELABEL(mbox0));

	if (mbox_register_callback(dev, RX_ID, rx_callback, NULL)) {
		printk("mbox_register_callback() error\n");
		return 0;
	}

	if (mbox_register_callback(dev, TX_ID, tx_callback, NULL)) {
		printk("mbox_register_callback() error\n");
		return 0;
	}

	if (mbox_set_enabled(dev, RX_ID, 1)) {
		printk("mbox_set_enable() error\n");
		return 0;
	}

	while (1) {
		struct mbox_msg msg = {.data = &data, .size = sizeof(data)};

		printk("Ping [%s] (on channel %d)\n", coreA ? "core A" : "core B", TX_ID);

		if (mbox_send(dev, TX_ID, &msg) < 0) {
			printk("mbox_send() error [%s]\n", coreA ? "core A" : "core B");
		} else {
			data++;
		}
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
