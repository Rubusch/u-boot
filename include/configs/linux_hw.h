/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2005, Psyent Corporation <www.psyent.com>
 * Scott McNutt <smcnutt@psyent.com>
 * (C) Copyright 2010, Thomas Chou <thomas@wytron.com.tw>
 * adjusted for a nios2 customized setup
 * (C) Copyright 2002, Lothar Rubusch <l.rubusch@gmail.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * BOARD/CPU
 */

/*
 * SERIAL
TODO jtag_uart, if possible
 */
#define CONFIG_SYS_NS16550_MEM32

/*
 * Flash
 *
TODO no flash, setup should run in ramfs, only
#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_MAX_FLASH_SECT	1024
*/

/*
 * NET options
 *
TODO no net
#define CONFIG_SYS_RX_ETH_BUFFER	0
#define CONFIG_SYS_FAULT_ECHO_LINK_DOWN
*/

/*
 * BOOTP options
 *
TODO no net
#define CONFIG_BOOTP_BOOTFILESIZE
*/

/*
 * FDT options
 */
#define CONFIG_LMB

/*
 * MEMORY ORGANIZATION
 * -Monitor at top of sdram.
 * -The heap is placed below the monitor
 * -The stack is placed below the heap (&grows down).
e.g.
#define CONFIG_SYS_SDRAM_BASE		0xc8000000
#define CONFIG_SYS_SDRAM_SIZE		0x08000000
 */
#define CONFIG_SYS_SDRAM_BASE		0x04000000
#define CONFIG_SYS_SDRAM_SIZE		0x04000000
#define CONFIG_MONITOR_IS_IN_RAM
#define CONFIG_SYS_MONITOR_LEN		0x80000	/* Reserve 512k */
#define CONFIG_SYS_MONITOR_BASE	(CONFIG_SYS_SDRAM_BASE + \
					 CONFIG_SYS_SDRAM_SIZE - \
					 CONFIG_SYS_MONITOR_LEN)
#define CONFIG_SYS_MALLOC_LEN		0x20000

/*
 * ENVIRONMENT -- Put environment in sector CONFIG_SYS_MONITOR_LEN above
 * CONFIG_SYS_RESET_ADDR, since we assume the monitor is stored at the
 * reset address, no? This will keep the environment in user region
 * of flash. NOTE: the monitor length must be multiple of sector size
 * (which is common practice).
TODO probably no env possible, since no persistent flash, neither nonvolatile ram
 */

#define CONFIG_ENV_SIZE			0x10000	/* 64k, 1 sector */
#define CONFIG_ENV_OVERWRITE		/* Serial change Ok	*/
#define CONFIG_ENV_ADDR			(0xf4000000 + CONFIG_SYS_MONITOR_LEN)

/*
 * MISC
TODO adjust addresses
 */
//#define CONFIG_SYS_LOAD_ADDR		0xcc000000	/* Half of RAM */
#define CONFIG_SYS_LOAD_ADDR		0x08040800
#define CONFIG_LOADADDR			CONFIG_SYS_LOAD_ADDR
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MONITOR_BASE - \
					 CONFIG_ENV_SIZE - \
					 CONFIG_SYS_MALLOC_LEN -	\
					 0x10000)

#endif /* __CONFIG_H */
