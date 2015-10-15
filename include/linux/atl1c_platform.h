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

#ifndef _LINUX_ATKL1C_PLATFORM_H
#define _LINUX_ATKL1C_PLATFORM_H

#include <linux/err.h>

struct atl1c_platform_data {
	unsigned char mac_addr[6];
};

#ifdef CONFIG_ATL1C_PLATFORM_DATA
int atl1c_set_platform_data(const struct atl1c_platform_data *data);
struct atl1c_platform_data *atl1c_get_platform_data(void);
#else
static inline
int atl1c_set_platform_data(const struct atl1c_platform_data *data)
{
	return -ENOSYS;
}

static inline
struct atl1c_platform_data *atl1c_get_platform_data(void)
{
	return ERR_PTR(-ENOSYS);
}
#endif

#endif /* _LINUX_ATKL1C_PLATFORM_H */
