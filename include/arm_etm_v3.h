/**
MIT License

Copyright (c) 2025 Axion Embedded

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * ARM Embedded Trace Macrocell (ETM) v3.x Register Definitions
 * Reference: ARM IHI 0014 (ETM Architecture Specification v3.x)
 *
 * This header provides register offsets, key bitfields, and base structures for
 * programming the ARM ETM v3 hardware block.
 */

#ifndef _ARM_ETM_V3_H_
#define _ARM_ETM_V3_H_

#include <stdint.h>

/* ETM v3 Register Offsets (from the ETM base address) */
#define ETMv3_CR                0x000   /* Control Register */
#define ETMv3_SR                0x010   /* Status Register */
#define ETMv3_TRIGEVR           0x020   /* Trigger Event Register */
#define ETMv3_CTRL2             0x028   /* Control Register 2 */
#define ETMv3_TRACEIDR          0x200   /* Trace ID Register */
#define ETMv3_CONFIGR           0x004   /* Configuration Code Register */
#define ETMv3_TEEVR             0x024   /* Trace Enable Event Register */
#define ETMv3_FFSR              0x300   /* Formatter and Flush Status Register */
#define ETMv3_FFCR              0x304   /* Formatter and Flush Control Register */
#define ETMv3_SYNCFR            0x304   /* Synchronization Frequency Register (sometimes aliased) */
#define ETMv3_IDR               0x1E4   /* ID Register */
#define ETMv3_CCER              0x1E8   /* Configuration Code Extension Register */
#define ETMv3_TSCR              0x304   /* Timestamp Control Register (sometimes aliased) */

/* Control Register (ETMv3_CR) Bitfields */
#define ETMv3_CR_POWERDOWN          (1U << 0)
#define ETMv3_CR_PROGRAMMING        (1U << 10)
#define ETMv3_CR_ETMEN              (1U << 11)

/* Status Register (ETMv3_SR) Bitfields */
#define ETMv3_SR_PROGBIT            (1U << 0)

/* Trace Enable Event Register (ETMv3_TEEVR) Bitfields */
#define ETMv3_TEEVR_ENABLE          (1U << 0)

/* Formatter and Flush Control Register (ETMv3_FFCR) Bitfields */
#define ETMv3_FFCR_EN               (1U << 0)
#define ETMv3_FFCR_STOPPED          (1U << 1)

/* ETM v3 Main Registers Structure */
typedef struct {
    volatile uint32_t cr;        /* 0x000: Control Register */
    volatile uint32_t configr;   /* 0x004: Configuration Code Register */
    uint32_t _reserved1[2];
    volatile uint32_t sr;        /* 0x010: Status Register */
    uint32_t _reserved2[3];
    volatile uint32_t trigevr;   /* 0x020: Trigger Event Register */
    volatile uint32_t teevr;     /* 0x024: Trace Enable Event Register */
    volatile uint32_t ctrl2;     /* 0x028: Control Register 2 */
    uint32_t _reserved3[0x7F - 0x0A];      /* Pad to 0x200 */
    volatile uint32_t traceidr;  /* 0x200: Trace ID Register */
    uint32_t _reserved4[0x7B];   /* Pad to 0x300 */
    volatile uint32_t ffsr;      /* 0x300: Formatter and Flush Status Register */
    volatile uint32_t ffcr;      /* 0x304: Formatter and Flush Control Register */
    /* Additional registers can be mapped as needed */
} etmv3_regs_t;

/* ETM v3 Identification Macros */
#define ETMv3_ID_MASK               0xFFF
#define ETMv3_ID_ETM                0x410 /* Value in ETMv3_IDR for ETM */

/* Example usage: (replace ETM_BASE with your ETM peripheral base address)
    #define ETM_BASE   0xF8801000
    etmv3_regs_t *etm = (etmv3_regs_t *)ETM_BASE;
    etm->cr = ETMv3_CR_PROGRAMMING; // Enter programming mode
*/

/* For full programming, see the ETM v3 Architecture Specification. */

#endif /* _ARM_ETM_V3_H_ */