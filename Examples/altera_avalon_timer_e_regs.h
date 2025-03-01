/*
 * altera_avalon_timer_e_regs.h
 *
 *  Created on: 1 mar 2025
 *      Author: Olova
 */

#ifndef ALTERA_AVALON_TIMER_E_REGS_H_	// If this file has been read by the
#define ALTERA_AVALON_TIMER_E_REGS_H_	// linker before, the
									// linker will skip all the lines until
									// the next #endif
#include <io.h>						// include HAL macro
#include <system.h>					// include base adress definitions

// The following three macros will write to control registers
#define TIMER_STOP  IOWR_32DIRECT(TIMER_E_IP_0_BASE, 0, 0x00000000)
#define TIMER_RESET IOWR_32DIRECT(TIMER_E_IP_0_BASE, 0, 0x40000000)
#define TIMER_START IOWR_32DIRECT(TIMER_E_IP_0_BASE, 0, 0x80000000)

// The following macro will read from dataregister ns, s, m
#define TIMER_READ_NS IORD_32DIRECT(TIMER_E_IP_0_BASE, 4)
#define TIMER_READ_S IORD_32DIRECT(TIMER_E_IP_0_BASE, 8)
#define TIMER_READ_M IORD_32DIRECT(TIMER_E_IP_0_BASE, 12)


#endif /* ALTERA_AVALON_TIMER_E_REGS_H_ */
