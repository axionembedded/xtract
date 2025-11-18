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
#define ETMv3_CR                0x000U   /* Control Register */
#define ETMv3_CCR               0x004U   /* Configuration Code Register */
#define ETMv3_TRIGGER           0x008U   /* Trigger Event Register */
#define ETMv3_ASICCR            0x00CU   /* ASIC Control Register */
#define ETMv3_SR                0x010U   /* Status Register */
#define ETMv3_SCR               0x014U   /* System Configuration Register */
#define ETMv3_TSSCR             0x018U   /* Trace Enable Start/Stop Control Register */
#define ETMv3_TECR2             0x01CU   /* Trace Enable Control 2 Register */
#define ETMv3_TEEVR             0x020U   /* Trace Enable Event Register */
#define ETMv3_TECR1             0x024U   /* Trace Enable Control 1 Register */

/* FIFOFULL Configuration */
#define ETMv3_FFRR              0x028U   /* FIFOFULL Region Register */
#define ETMv3_FFLR              0x02CU   /* FIFOFULL Level Register */

/* ViewData Configuration */
#define ETMv3_VDEVR             0x030U   /* ViewData Event Register */
#define ETMv3_VDCR1             0x034U   /* ViewData Control 1 Register */
#define ETMv3_VDCR2             0x038U   /* ViewData Control 2 Register */
#define ETMv3_VDCR3             0x03CU   /* ViewData Control 3 Register */

/* Address Comparators */
#define ETMv3_ACVR0             0x040U                 /* Address Comparator Value Register 0 */
#define ETMv3_ACVR1             (ETMv3_ACVR0 + 0x4U)   /* Address Comparator Value Register 1 */
#define ETMv3_ACVR2             (ETMv3_ACVR1 + 0x4U)   /* Address Comparator Value Register 2 */
#define ETMv3_ACVR3             (ETMv3_ACVR2 + 0x4U)   /* Address Comparator Value Register 3 */
#define ETMv3_ACVR4             (ETMv3_ACVR3 + 0x4U)   /* Address Comparator Value Register 4 */
#define ETMv3_ACVR5             (ETMv3_ACVR4 + 0x4U)   /* Address Comparator Value Register 5 */
#define ETMv3_ACVR6             (ETMv3_ACVR5 + 0x4U)   /* Address Comparator Value Register 6 */
#define ETMv3_ACVR7             (ETMv3_ACVR6 + 0x4U)   /* Address Comparator Value Register 7 */
#define ETMv3_ACVR8             (ETMv3_ACVR7 + 0x4U)   /* Address Comparator Value Register 8 */
#define ETMv3_ACVR9             (ETMv3_ACVR8 + 0x4U)   /* Address Comparator Value Register 9 */
#define ETMv3_ACVR10            (ETMv3_ACVR9 + 0x4U)   /* Address Comparator Value Register 10 */
#define ETMv3_ACVR11            (ETMv3_ACVR10 + 0x4U)  /* Address Comparator Value Register 11 */
#define ETMv3_ACVR12            (ETMv3_ACVR11 + 0x4U)  /* Address Comparator Value Register 12 */
#define ETMv3_ACVR13            (ETMv3_ACVR12 + 0x4U)  /* Address Comparator Value Register 13 */
#define ETMv3_ACVR14            (ETMv3_ACVR13 + 0x4U)  /* Address Comparator Value Register 14 */
#define ETMv3_ACVR15            (ETMv3_ACVR14 + 0x4U)  /* Address Comparator Value Register 15 */
#define ETMv3_ACTR0             0x080U                 /* Address Comparator Type Register 0 */
#define ETMv3_ACTR1             (ETMv3_ACTR0 + 0x4U)   /* Address Comparator Type Register 1 */
#define ETMv3_ACTR2             (ETMv3_ACTR1 + 0x4U)   /* Address Comparator Type Register 2 */
#define ETMv3_ACTR3             (ETMv3_ACTR2 + 0x4U)   /* Address Comparator Type Register 3 */
#define ETMv3_ACTR4             (ETMv3_ACTR3 + 0x4U)   /* Address Comparator Type Register 4 */
#define ETMv3_ACTR5             (ETMv3_ACTR4 + 0x4U)   /* Address Comparator Type Register 5 */
#define ETMv3_ACTR6             (ETMv3_ACTR5 + 0x4U)   /* Address Comparator Type Register 6 */
#define ETMv3_ACTR7             (ETMv3_ACTR6 + 0x4U)   /* Address Comparator Type Register 7 */
#define ETMv3_ACTR8             (ETMv3_ACTR7 + 0x4U)   /* Address Comparator Type Register 8 */
#define ETMv3_ACTR9             (ETMv3_ACTR8 + 0x4U)   /* Address Comparator Type Register 9 */
#define ETMv3_ACTR10            (ETMv3_ACTR9 + 0x4U)   /* Address Comparator Type Register 10 */
#define ETMv3_ACTR11            (ETMv3_ACTR10 + 0x4U)  /* Address Comparator Type Register 11 */
#define ETMv3_ACTR12            (ETMv3_ACTR11 + 0x4U)  /* Address Comparator Type Register 12 */
#define ETMv3_ACTR13            (ETMv3_ACTR12 + 0x4U)  /* Address Comparator Type Register 13 */
#define ETMv3_ACTR14            (ETMv3_ACTR13 + 0x4U)  /* Address Comparator Type Register 14 */
#define ETMv3_ACTR15            (ETMv3_ACTR14 + 0x4U)  /* Address Comparator Type Register 15 */

/* Data Comparators */
#define ETMv3_DCVR0             0x0C0U                 /* Data Comparator Value Register 0 */
#define ETMv3_DCVR1             (ETMv3_DCVR0 + 0x4U)   /* Data Comparator Value Register 1 */
#define ETMv3_DCVR2             (ETMv3_DCVR1 + 0x4U)   /* Data Comparator Value Register 2 */
#define ETMv3_DCVR3             (ETMv3_DCVR2 + 0x4U)   /* Data Comparator Value Register 3 */
#define ETMv3_DCVR4             (ETMv3_DCVR3 + 0x4U)   /* Data Comparator Value Register 4 */
#define ETMv3_DCVR5             (ETMv3_DCVR4 + 0x4U)   /* Data Comparator Value Register 5 */
#define ETMv3_DCVR6             (ETMv3_DCVR5 + 0x4U)   /* Data Comparator Value Register 6 */
#define ETMv3_DCVR7             (ETMv3_DCVR6 + 0x4U)   /* Data Comparator Value Register 7 */
#define ETMv3_DCVR8             (ETMv3_DCVR7 + 0x4U)   /* Data Comparator Value Register 8 */
#define ETMv3_DCVR9             (ETMv3_DCVR8 + 0x4U)   /* Data Comparator Value Register 9 */
#define ETMv3_DCVR10            (ETMv3_DCVR9 + 0x4U)   /* Data Comparator Value Register 10 */
#define ETMv3_DCVR11            (ETMv3_DCVR10 + 0x4U)  /* Data Comparator Value Register 11 */
#define ETMv3_DCVR12            (ETMv3_DCVR11 + 0x4U)  /* Data Comparator Value Register 12 */
#define ETMv3_DCVR13            (ETMv3_DCVR12 + 0x4U)  /* Data Comparator Value Register 13 */
#define ETMv3_DCVR14            (ETMv3_DCVR13 + 0x4U)  /* Data Comparator Value Register 14 */
#define ETMv3_DCVR15            (ETMv3_DCVR14 + 0x4U)  /* Data Comparator Value Register 15 */
#define ETMv3_DCMR0             0x100U                 /* Data Comparator Mask Register 0 */
#define ETMv3_DCMR1             (ETMv3_DCMR0 + 0x4U)   /* Data Comparator Mask Register 1 */
#define ETMv3_DCMR2             (ETMv3_DCMR1 + 0x4U)   /* Data Comparator Mask Register 2 */
#define ETMv3_DCMR3             (ETMv3_DCMR2 + 0x4U)   /* Data Comparator Mask Register 3 */
#define ETMv3_DCMR4             (ETMv3_DCMR3 + 0x4U)   /* Data Comparator Mask Register 4 */
#define ETMv3_DCMR5             (ETMv3_DCMR4 + 0x4U)   /* Data Comparator Mask Register 5 */
#define ETMv3_DCMR6             (ETMv3_DCMR5 + 0x4U)   /* Data Comparator Mask Register 6 */
#define ETMv3_DCMR7             (ETMv3_DCMR6 + 0x4U)   /* Data Comparator Mask Register 7 */
#define ETMv3_DCMR8             (ETMv3_DCMR7 + 0x4U)   /* Data Comparator Mask Register 8 */
#define ETMv3_DCMR9             (ETMv3_DCMR8 + 0x4U)   /* Data Comparator Mask Register 9 */
#define ETMv3_DCMR10            (ETMv3_DCMR9 + 0x4U)   /* Data Comparator Mask Register 10 */
#define ETMv3_DCMR11            (ETMv3_DCMR10 + 0x4U)  /* Data Comparator Mask Register 11 */
#define ETMv3_DCMR12            (ETMv3_DCMR11 + 0x4U)  /* Data Comparator Mask Register 12 */
#define ETMv3_DCMR13            (ETMv3_DCMR12 + 0x4U)  /* Data Comparator Mask Register 13 */
#define ETMv3_DCMR14            (ETMv3_DCMR13 + 0x4U)  /* Data Comparator Mask Register 14 */
#define ETMv3_DCMR15            (ETMv3_DCMR14 + 0x4U)  /* Data Comparator Mask Register 15 */

/* Counters */
#define ETMv3_CNTRLDVR0         0x140U                     /* Counter Reload Value Register 0 */
#define ETMv3_CNTRLDVR1         (ETMv3_CNTRLDVR0 + 0x4U)   /* Counter Reload Value Register 1 */
#define ETMv3_CNTRLDVR2         (ETMv3_CNTRLDVR1 + 0x4U)   /* Counter Reload Value Register 2 */
#define ETMv3_CNTRLDVR3         (ETMv3_CNTRLDVR2 + 0x4U)   /* Counter Reload Value Register 3 */
#define ETMv3_CNTENR0           0x150U                     /* Counter Enable Register 0 */
#define ETMv3_CNTENR1           (ETMv3_CNTENR0 + 0x4U)     /* Counter Enable Register 1 */
#define ETMv3_CNTENR2           (ETMv3_CNTENR1 + 0x4U)     /* Counter Enable Register 2 */
#define ETMv3_CNTENR3           (ETMv3_CNTENR2 + 0x4U)     /* Counter Enable Register 3 */
#define ETMv3_CNTRLDEVR0        0x160U                     /* Counter Reload Event Register 0 */
#define ETMv3_CNTRLDEVR1        (ETMv3_CNTRLDEVR0 + 0x4U)  /* Counter Reload Event Register 1 */
#define ETMv3_CNTRLDEVR2        (ETMv3_CNTRLDEVR1 + 0x4U)  /* Counter Reload Event Register 2 */
#define ETMv3_CNTRLDEVR3        (ETMv3_CNTRLDEVR2 + 0x4U)  /* Counter Reload Event Register 3 */
#define ETMv3_CNTVR0            0x170U                     /* Counter Value Register 0 */
#define ETMv3_CNTVR1            (ETMv3_CNTVR0 + 0x4U)      /* Counter Value Register 1 */
#define ETMv3_CNTVR2            (ETMv3_CNTVR1 + 0x4U)      /* Counter Value Register 2 */
#define ETMv3_CNTVR3            (ETMv3_CNTVR2 + 0x4U)      /* Counter Value Register 3 */

/* Sequencer */
#define ETMv3_SQabEVR0          0x180U                     /* Sequencer State Transistion Event Register 0 */
#define ETMv3_SQabEVR1          (ETMv3_SQabEVR0 + 0x4U)    /* Sequencer State Transistion Event Register 1 */
#define ETMv3_SQabEVR2          (ETMv3_SQabEVR1 + 0x4U)    /* Sequencer State Transistion Event Register 2 */
#define ETMv3_SQabEVR3          (ETMv3_SQabEVR2 + 0x4U)    /* Sequencer State Transistion Event Register 3 */
#define ETMv3_SQabEVR4          (ETMv3_SQabEVR3 + 0x4U)    /* Sequencer State Transistion Event Register 4 */
#define ETMv3_SQabEVR5          (ETMv3_SQabEVR4 + 0x4U)    /* Sequencer State Transistion Event Register 5 */
#define ETMv3_SQR               0x19CU                     /* Current Sequencer State Register */

/* External Output Event Registers */
#define ETMv3_EXTOUTEVR0          0x1A0U                    /* External Output Event Register 0 */
#define ETMv3_EXTOUTEVR1          (ETMv3_EXTOUTEVR0 + 0x4U) /* External Output Event Register 1 */
#define ETMv3_EXTOUTEVR2          (ETMv3_EXTOUTEVR1 + 0x4U) /* External Output Event Register 2 */
#define ETMv3_EXTOUTEVR3          (ETMv3_EXTOUTEVR2 + 0x4U) /* External Output Event Register 3 */

/* Context ID Comparators */
#define ETMv3_CIDCVR0             0x1B0U                    /* Context ID Comparator Value Register 0 */
#define ETMv3_CIDCVR1             (ETMv3_CIDCMR0 + 0x4U)    /* Context ID Comparator Value Register 1 */
#define ETMv3_CIDCVR2             (ETMv3_CIDCMR1 + 0x4U)    /* Context ID Comparator Value Register 2 */
#define ETMv3_CIDCMR              0x1BCU                    /* Context ID Comparator Mask Register */

/* Other ETM Trace Registers */
#define ETMv3_IMPLSPR0            0x1C0                     /* Implementation-specific Register 0 */
#define ETMv3_IMPLSPR1            (ETMv3_IMPLSPR0 + 0x4U)   /* Implementation-specific Register 1 */
#define ETMv3_IMPLSPR2            (ETMv3_IMPLSPR1 + 0x4U)   /* Implementation-specific Register 2 */
#define ETMv3_IMPLSPR3            (ETMv3_IMPLSPR2 + 0x4U)   /* Implementation-specific Register 3 */
#define ETMv3_IMPLSPR4            (ETMv3_IMPLSPR3 + 0x4U)   /* Implementation-specific Register 4 */
#define ETMv3_IMPLSPR5            (ETMv3_IMPLSPR4 + 0x4U)   /* Implementation-specific Register 5 */
#define ETMv3_IMPLSPR6            (ETMv3_IMPLSPR5 + 0x4U)   /* Implementation-specific Register 6 */
#define ETMv3_IMPLSPR7            (ETMv3_IMPLSPR6 + 0x4U)   /* Implementation-specific Register 7 */

#define ETMv3_SYNCFR              0x1E0U                    /* Synchronization Frequency Register */
#define ETMv3_IDR                 0x1E4U                    /* ID Register */
#define ETMv3_CCER                0x1E8U                    /* Condition Code Extension Register */
#define ETMv3_EXTINSELR           0x1ECU                    /* Extended External Input Selection Register */
#define ETMv3_TESSEICR            0x1F0U                    /* TraceEnable Start/Stop EmbeddedICE Control Register */
#define ETMv3_EIBCR               0x1F4U                    /* EmbeddedICE Behavior Control Register */
#define ETMv3_TSEVR               0x1F8U                    /* Timestamp Event Register */
#define ETMv3_AUXCR               0x1FCU                    /* Auxiliary Control Register */
#define ETMv3_TRACEIDR            0x200U                    /* Trace ID Register */
#define ETMv3_IDR2                0x208U                    /* ETM ID Register 2*/
#define ETMv3_VMIDCVR             0x240U                    /* VMID Comparator Value Register */

/* ETM Management Registers */
#define ETMv3_OSLAR               0x300U                    /* OS Lock Access Register */
#define ETMv3_OSLSR               0x304U                    /* OS Lock Status Register */
#define ETMv3_OSSRR               0x308U                    /* OS Save And Restore Register */

/* Other ETM Management Registers */
#define ETMv3_PDCR                0x310U                    /* Power Down Control Register */
#define ETMv3_PDSR                0x314U                    /* Device Power-Down Status Register */

/* ETM Management Registers */
#define ETMv3_ITCTRL              0xF00U                    /* Integration Mode Control Register */
#define ETMv3_CLAIMSET            0xFA0U                    /* Claim Tag Set Register */
#define ETMv3_CLAIMCLR            0xFA4U                    /* Claim Tag Clear Register */
#define ETMv3_LAR                 0xFB0U                    /* Lock Access Register */
#define ETMv3_LSR                 0xFB4U                    /* Lock Status Register */
#define ETMv3_AUTHSTATUS          0xFB8U                    /* Authentication Status Register */

#define ETMv3_DEVID               0xFC8U                    /* CoreSight Device Configuration Register */
#define ETMv3_DEVTYPE             0xFCCU                    /* CoreSight Device Type Register */

/* Peripheral And Component ID Registers */
#define ETMv3_PIDR4               0xFD0U                    /* Peripheral ID4 Register */
#define ETMv3_PIDR5               0xFD4U                    /* Peripheral ID5 Register */
#define ETMv3_PIDR6               0xFD8U                    /* Peripheral ID6 Register */
#define ETMv3_PIDR7               0xFDCU                    /* Peripheral ID7 Register */
#define ETMv3_PIDR0               0xFE0U                    /* Peripheral ID0 Register */
#define ETMv3_PIDR1               0xFE4U                    /* Peripheral ID1 Register */
#define ETMv3_PIDR2               0xFE8U                    /* Peripheral ID2 Register */
#define ETMv3_PIDR3               0xFECU                    /* Peripheral ID3 Register */
#define ETMv3_CIDR0               0xFF0U                    /* Component ID0 Register */
#define ETMv3_CIDR1               0xFF4U                    /* Component ID1 Register */
#define ETMv3_CIDR2               0xFF8U                    /* Component ID2 Register */
#define ETMv3_CIDR3               0xFFCU                    /* Component ID3 Register */

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