/*
 * arch/powerpc/math-emu/evfsnabs.c
 *
 * Copyright (C) 2006 Freescale Semiconductor, Inc. All rights reserved.
 *
 * Author: Ebony Zhu, ebony.zhu@freescale.com
 *
 * Description:
 * This file is the implementation of SPE instruction "evfsnabs"
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */

#include <linux/types.h>
#include <linux/errno.h>
#include <asm/uaccess.h>

int
evfsnabs(u32 *rD, u32 *rA)
{
	rD[0] = rA[0] | 0x80000000;
	rD[1] = rA[1] | 0x80000000;

#ifdef DEBUG
	printk("%s: D %p, A %p: ", __FUNCTION__, rD, rA);
	printk("\n");
#endif

	return 0;
}
