/* drivers/leds/ledtrig-sleep.c
 *
 * Copyright (C) 2007 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/earlysuspend.h>
#include <linux/leds.h>
#include <linux/suspend.h>

DEFINE_LED_TRIGGER(ledtrig_sleep)

static void ledtrig_sleep_early_suspend(struct early_suspend *h)
{
	led_trigger_event(ledtrig_sleep, LED_FULL);
}

static void ledtrig_sleep_early_resume(struct early_suspend *h)
{
	led_trigger_event(ledtrig_sleep, LED_OFF);
}

static struct early_suspend ledtrig_sleep_early_suspend_handler = {
	.suspend = ledtrig_sleep_early_suspend,
	.resume = ledtrig_sleep_early_resume,
};

static int __init ledtrig_sleep_init(void)
{
	led_trigger_register_simple("sleep", &ledtrig_sleep);
	register_early_suspend(&ledtrig_sleep_early_suspend_handler);
	return 0;
}

static void __exit ledtrig_sleep_exit(void)
{
	unregister_early_suspend(&ledtrig_sleep_early_suspend_handler);
	led_trigger_unregister_simple(ledtrig_sleep);
}

module_init(ledtrig_sleep_init);
module_exit(ledtrig_sleep_exit);

