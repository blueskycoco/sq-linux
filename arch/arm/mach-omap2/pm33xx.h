/*
 * AM33XX Power Management Routines
 *
 * Copyright (C) 2012 Texas Instruments Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ARCH_ARM_MACH_OMAP2_PM33XX_H
#define __ARCH_ARM_MACH_OMAP2_PM33XX_H

#include <mach/hardware.h>	/* XXX Is this the right one to include? */
#include "control.h"
#include "mux33xx.h"

#ifndef __ASSEMBLER__
extern void __iomem *am33xx_get_ram_base(void);

extern int am33xx_map_i2c0(void);
extern void __iomem *am33xx_get_i2c0_base(void);
extern void am33xx_fill_i2c_scl_sch(u32 *sleep_scll, u32 *sleep_sclh,
			     u32 *wake_scll, u32 *wake_sclh);
extern u32 sram_sleep_data_start, sram_sleep_data_sz;
extern u32 sram_wake_data_start, sram_wake_data_sz;

/*
 * This enum is used to index the array passed to suspend routine with
 * parameters that vary across DDR2 and DDR3 sleep sequence.
 *
 * Since these are used to load into registers by suspend code,
 * entries here must always be in sync with the suspend code
 * in arm/mach-omap2/sleep33xx.S
 */
enum suspend_cfg_params {
	MEMORY_TYPE = 0,
	SUSP_VTP_CTRL_VAL,
	EVM_ID,
	CPU_REV,
	SUSPEND_STATE,
	NEEDS_CORE_VOLTAGE_SCALING,
	SUSPEND_CFG_PARAMS_END /* Must be the last entry */
};

struct a8_wkup_m3_ipc_data {
	int resume_addr;
	int sleep_mode;
	int ipc_data1;
	int ipc_data2;
} am33xx_lp_ipc;

#endif /* ASSEMBLER */

#define M3_TXEV_EOI			(AM33XX_CTRL_BASE + 0x1324)
#define A8_M3_IPC_REGS			(AM33XX_CTRL_BASE + 0x1328)
#define DS_RESUME_BASE			0x40300000
#define DS_IPC_DEFAULT			0xffffffff
#define M3_UMEM				0x44D00000

#define	DS0_ID				0x3
#define DS1_ID				0x5
#define CPUIDLE_ID			0x10

#define M3_STATE_UNKNOWN		-1
#define M3_STATE_RESET			0
#define M3_STATE_INITED			1
#define M3_STATE_MSG_FOR_LP		2
#define M3_STATE_MSG_FOR_RESET		3
#define M3_STATE_MSG_FOR_CPUIDLE	4

#define VTP_CTRL_READY		(0x1 << 5)
#define VTP_CTRL_ENABLE		(0x1 << 6)
#define VTP_CTRL_LOCK_EN	(0x1 << 4)
#define VTP_CTRL_START_EN	(0x1)

#define DDR_IO_CTRL		(AM33XX_CTRL_BASE + 0x0E04)
#define VTP0_CTRL_REG		(AM33XX_CTRL_BASE + 0x0E0C)
#define DDR_CMD0_IOCTRL		(AM33XX_CTRL_BASE + 0x1404)
#define DDR_CMD1_IOCTRL		(AM33XX_CTRL_BASE + 0x1408)
#define DDR_CMD2_IOCTRL		(AM33XX_CTRL_BASE + 0x140C)
#define DDR_DATA0_IOCTRL	(AM33XX_CTRL_BASE + 0x1440)
#define DDR_DATA1_IOCTRL	(AM33XX_CTRL_BASE + 0x1444)

#define MEM_TYPE_DDR2		2

#define SUSP_VTP_CTRL_DDR2	0x10117
#define SUSP_VTP_CTRL_DDR3	0x0

#define CPU_REV_1		1
#define CPU_REV_2		2

#define M3_VERSION_UNKNOWN		0x0000ffff

#define PM_DS0			0
#define PM_STANDBY		1


/* For i2c handling in core voltage scaling */
#define OMAP_I2C_SYSC_AUTOIDLE	(1 << 0)

#define OMAP_I2C_STAT_BB		(1 << 12)
#define OMAP_I2C_STAT_ARDY		(1 << 2)
#define OMAP_I2C_STAT_NACK		(1 << 1)
#define OMAP_I2C_STAT_AL		(1 << 0)

#define OMAP_I2C_CON_EN			(1 << 15)
#define OMAP_I2C_CON_MST		(1 << 10)
#define OMAP_I2C_CON_TRX		(1 << 9)
#define OMAP_I2C_CON_STP		(1 << 1)
#define OMAP_I2C_CON_STT		(1 << 0)

#define OMAP_I2C_SYSC_REG			0x10
#define OMAP_I2C_STAT_RAW_REG		0x24
#define OMAP_I2C_STAT_REG			0x28
#define OMAP_I2C_IRQENABLE_SET		0x2c
#define OMAP_I2C_IRQENABLE_CLR		0x30
#define OMAP_I2C_CNT_REG			0x98
#define OMAP_I2C_DATA_REG			0x9c
#define OMAP_I2C_CON_REG			0xa4
#define OMAP_I2C_SA_REG				0xac
#define OMAP_I2C_PSC_REG			0xb0
#define OMAP_I2C_SCLL_REG			0xb4
#define OMAP_I2C_SCLH_REG			0xb8

#endif
