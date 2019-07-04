/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2019 Kontron Electronics GmbH
 *
 * Configuration settings for the Kontron N8000 i.MX8MM SMARC module.
 */
#ifndef __KONTRON_MX8MM_CONFIG_H
#define __KONTRON_MX8MM_CONFIG_H

#ifdef CONFIG_SPL_BUILD
#include <config.h>
#endif

/* Board and environment settings */
#define CONFIG_MXC_UART_BASE		UART3_BASE_ADDR
#define CONFIG_HOSTNAME			"kontron-n8000"

#define KONTRON_ENV_KERNEL_MTDPARTS	"mtdparts=spi1.0:128k(spl),832k(u-boot),64k(env)"
#define KONTRON_ENV_KERNEL_CONSOLE	"console=ttymxc2,115200"

#define KONTRON_ENV_KERNEL_ADDR		"0x43000000"
#define KONTRON_ENV_FDT_ADDR		"0x42000000"
#define KONTRON_ENV_PXE_ADDR		"0x43000000"
#define KONTRON_ENV_RAMDISK_ADDR	"0x43000000"

/* Common options for Kontron Electronics boards */
#include "kontron_common.h"

#ifndef CONFIG_SPL_BUILD
#define BOOT_TARGET_DEVICES(func) \
        func(MMC, mmc, 1) \
        func(MMC, mmc, 0) \
        func(PXE, pxe, na)
#include <config_distro_bootcmd.h>
/* Do not try to probe USB net adapters for net boot */
#undef BOOTENV_RUN_NET_USB_START
#define BOOTENV_RUN_NET_USB_START
#else
#define BOOTENV
#endif

#define CONFIG_LOADADDR			0x40200000
#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR
#define CONFIG_SYS_BOOTM_LEN		SZ_64M
#define CONFIG_SPL_MAX_SIZE		(148 * SZ_1K)
#define CONFIG_FSL_USDHC

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SPL_STACK		0x91fff0
#define CONFIG_SPL_BSS_START_ADDR	0x910000
#define CONFIG_SPL_BSS_MAX_SIZE		SZ_8K
#define CONFIG_SYS_SPL_MALLOC_START	0x42200000
#define CONFIG_SYS_SPL_MALLOC_SIZE	SZ_512K
#define CONFIG_MALLOC_F_ADDR		0x930000 /* malloc f used before GD_FLG_FULL_MALLOC_INIT set */
#endif

//#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_FEC_MXC_PHYADDR		0
#define FEC_QUIRK_ENET_MAC
#define IMX_FEC_BASE			0x30BE0000

#endif /* __KONTRON_MX8MM_CONFIG_H */
