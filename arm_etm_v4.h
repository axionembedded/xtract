#ifndef _ARM_ETM_V4_H
#define _ARM_ETM_V4_H

#include <stdint.h>

/*
 * ARM Embedded Trace Macrocell (ETM) v4 Register Definitions
 * Reference: ARM Architecture Reference Manual (ETMv4.x)
 */

// Base offset for ETM registers (to be mapped as appropriate)
#define ETM_BASE_ADDR      0x00000000U

// Common ETM v4 Registers (Offsets are from base)
#define ETM_REG_IDR            0x000   // Identification Register
#define ETM_REG_CR             0x004   // Control Register
#define ETM_REG_STATUS         0x008   // Status Register
#define ETM_REG_TRIGEVT        0x020   // Trigger Event Register
#define ETM_REG_CTRL           0x100   // Main Control Register
#define ETM_REG_TRACEIDR       0x200   // Trace Stream ID Register
#define ETM_REG_CONFIGR        0x204   // Configuration Register
#define ETM_REG_EVENTR         0x208   // Event Control Register
#define ETM_REG_SYNCFR         0x20C   // Synchronization Frequency Register
#define ETM_REG_TSCR           0x220   // Timestamp Control Register
#define ETM_REG_SCR            0x224   // System Configuration Register
#define ETM_REG_VIEWDATA       0x300   // View Data Register

// ... Add more registers as needed

// Useful bitfields (examples)
#define ETM_CR_POWERDOWN         (1U << 0)
#define ETM_CR_PROGRAMMING       (1U << 1)
#define ETM_CR_ETMEN             (1U << 0)

#define ETM_STATUS_PROGBIT       (1U << 0)
#define ETM_STATUS_TRACEREADY    (1U << 2)

// ETM configuration structure (for user abstraction)
typedef struct {
    volatile uint32_t idr;          // 0x000
    volatile uint32_t cr;           // 0x004
    volatile uint32_t status;       // 0x008
    uint32_t reserved1[5];
    volatile uint32_t trigevt;      // 0x020
    uint32_t reserved2[59];
    volatile uint32_t ctrl;         // 0x100
    uint32_t reserved3[63];
    volatile uint32_t traceidr;     // 0x200
    volatile uint32_t configr;      // 0x204
    volatile uint32_t eventr;       // 0x208
    volatile uint32_t syncfr;       // 0x20C
    uint32_t reserved4[5];
    volatile uint32_t tscr;         // 0x220
    volatile uint32_t scr;          // 0x224
    uint32_t reserved5[55];
    volatile uint32_t viewdata;     // 0x300
} arm_etm_v4_t;

// Macros to access ETM
#define ARM_ETM_V4   ((arm_etm_v4_t *)ETM_BASE_ADDR)

// Example usage:
// ARM_ETM_V4->CR = ETM_CR_PROGRAMMING | ETM_CR_POWERDOWN;

#endif // _ARM_ETM_V4_H