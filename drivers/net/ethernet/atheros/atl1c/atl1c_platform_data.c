/*
 * This file is part of atl1c
 *
 * Copyright (C) 2015 Compulab Ltd.
 *
 * Author: Ilya Ledvich <ilya@compulab.co.il>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/err.h>
#include <linux/atl1c_platform.h>

static struct atl1c_platform_data *platform_data;

int atl1c_set_platform_data(const struct atl1c_platform_data *data)
{
	if (platform_data)
		return -EBUSY;
	if (!data)
		return -EINVAL;

	platform_data = kmemdup(data, sizeof(*data), GFP_KERNEL);
	if (!platform_data)
		return -ENOMEM;

	return 0;
}
EXPORT_SYMBOL(atl1c_set_platform_data);

struct atl1c_platform_data *atl1c_get_platform_data(void)
{
	if (!platform_data)
		return ERR_PTR(-ENODEV);

	return platform_data;
}
EXPORT_SYMBOL(atl1c_get_platform_data);
