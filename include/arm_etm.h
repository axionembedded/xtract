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

#ifndef _ARM_ETM_H_
#define _ARM_ETM_H_

#include <stdint.h>

#define ETM_MAJOR_ARCH_VERSION_3 0x2U

/* ETM Register Offsets (from the ETM base address) */
#define ETM_CR                 (0x000U)   /* Control Register */
#define ETM_CCR                (0x004U)   /* Configuration Code Register */
#define ETM_TRIGGER            (0x008U)   /* Trigger Event Register */
#define ETM_ASICCR             (0x00CU)   /* ASIC Control Register */
#define ETM_SR                 (0x010U)   /* Status Register */
#define ETM_SCR                (0x014U)   /* System Configuration Register */
#define ETM_TSSCR              (0x018U)   /* Trace Enable Start/Stop Control Register */
#define ETM_TECR2              (0x01CU)   /* Trace Enable Control 2 Register */
#define ETM_TEEVR              (0x020U)   /* Trace Enable Event Register */
#define ETM_TECR1              (0x024U)   /* Trace Enable Control 1 Register */

/* FIFOFULL Configuration */
#define ETM_FFRR              (0x028U)   /* FIFOFULL Region Register */
#define ETM_FFLR              (0x02CU)   /* FIFOFULL Level Register */

/* ViewData Configuration */
#define ETM_VDEVR             (0x030U)   /* ViewData Event Register */
#define ETM_VDCR1             (0x034U)   /* ViewData Control 1 Register */
#define ETM_VDCR2             (0x038U)   /* ViewData Control 2 Register */
#define ETM_VDCR3             (0x03CU)   /* ViewData Control 3 Register */

/* Address Comparators */
#define ETM_ACVR0             (0x040U)             /* Address Comparator Value Register 0 */
#define ETM_ACVR1             (ETM_ACVR0 + 0x4U)   /* Address Comparator Value Register 1 */
#define ETM_ACVR2             (ETM_ACVR1 + 0x4U)   /* Address Comparator Value Register 2 */
#define ETM_ACVR3             (ETM_ACVR2 + 0x4U)   /* Address Comparator Value Register 3 */
#define ETM_ACVR4             (ETM_ACVR3 + 0x4U)   /* Address Comparator Value Register 4 */
#define ETM_ACVR5             (ETM_ACVR4 + 0x4U)   /* Address Comparator Value Register 5 */
#define ETM_ACVR6             (ETM_ACVR5 + 0x4U)   /* Address Comparator Value Register 6 */
#define ETM_ACVR7             (ETM_ACVR6 + 0x4U)   /* Address Comparator Value Register 7 */
#define ETM_ACVR8             (ETM_ACVR7 + 0x4U)   /* Address Comparator Value Register 8 */
#define ETM_ACVR9             (ETM_ACVR8 + 0x4U)   /* Address Comparator Value Register 9 */
#define ETM_ACVR10            (ETM_ACVR9 + 0x4U)   /* Address Comparator Value Register 10 */
#define ETM_ACVR11            (ETM_ACVR10 + 0x4U)  /* Address Comparator Value Register 11 */
#define ETM_ACVR12            (ETM_ACVR11 + 0x4U)  /* Address Comparator Value Register 12 */
#define ETM_ACVR13            (ETM_ACVR12 + 0x4U)  /* Address Comparator Value Register 13 */
#define ETM_ACVR14            (ETM_ACVR13 + 0x4U)  /* Address Comparator Value Register 14 */
#define ETM_ACVR15            (ETM_ACVR14 + 0x4U)  /* Address Comparator Value Register 15 */
#define ETM_ACTR0             (0x080U)             /* Address Comparator Type Register 0 */
#define ETM_ACTR1             (ETM_ACTR0 + 0x4U)   /* Address Comparator Type Register 1 */
#define ETM_ACTR2             (ETM_ACTR1 + 0x4U)   /* Address Comparator Type Register 2 */
#define ETM_ACTR3             (ETM_ACTR2 + 0x4U)   /* Address Comparator Type Register 3 */
#define ETM_ACTR4             (ETM_ACTR3 + 0x4U)   /* Address Comparator Type Register 4 */
#define ETM_ACTR5             (ETM_ACTR4 + 0x4U)   /* Address Comparator Type Register 5 */
#define ETM_ACTR6             (ETM_ACTR5 + 0x4U)   /* Address Comparator Type Register 6 */
#define ETM_ACTR7             (ETM_ACTR6 + 0x4U)   /* Address Comparator Type Register 7 */
#define ETM_ACTR8             (ETM_ACTR7 + 0x4U)   /* Address Comparator Type Register 8 */
#define ETM_ACTR9             (ETM_ACTR8 + 0x4U)   /* Address Comparator Type Register 9 */
#define ETM_ACTR10            (ETM_ACTR9 + 0x4U)   /* Address Comparator Type Register 10 */
#define ETM_ACTR11            (ETM_ACTR10 + 0x4U)  /* Address Comparator Type Register 11 */
#define ETM_ACTR12            (ETM_ACTR11 + 0x4U)  /* Address Comparator Type Register 12 */
#define ETM_ACTR13            (ETM_ACTR12 + 0x4U)  /* Address Comparator Type Register 13 */
#define ETM_ACTR14            (ETM_ACTR13 + 0x4U)  /* Address Comparator Type Register 14 */
#define ETM_ACTR15            (ETM_ACTR14 + 0x4U)  /* Address Comparator Type Register 15 */

/* Data Comparators */
#define ETM_DCVR0             (0x0C0U)             /* Data Comparator Value Register 0 */
#define ETM_DCVR1             (ETM_DCVR0 + 0x4U)   /* Data Comparator Value Register 1 */
#define ETM_DCVR2             (ETM_DCVR1 + 0x4U)   /* Data Comparator Value Register 2 */
#define ETM_DCVR3             (ETM_DCVR2 + 0x4U)   /* Data Comparator Value Register 3 */
#define ETM_DCVR4             (ETM_DCVR3 + 0x4U)   /* Data Comparator Value Register 4 */
#define ETM_DCVR5             (ETM_DCVR4 + 0x4U)   /* Data Comparator Value Register 5 */
#define ETM_DCVR6             (ETM_DCVR5 + 0x4U)   /* Data Comparator Value Register 6 */
#define ETM_DCVR7             (ETM_DCVR6 + 0x4U)   /* Data Comparator Value Register 7 */
#define ETM_DCVR8             (ETM_DCVR7 + 0x4U)   /* Data Comparator Value Register 8 */
#define ETM_DCVR9             (ETM_DCVR8 + 0x4U)   /* Data Comparator Value Register 9 */
#define ETM_DCVR10            (ETM_DCVR9 + 0x4U)   /* Data Comparator Value Register 10 */
#define ETM_DCVR11            (ETM_DCVR10 + 0x4U)  /* Data Comparator Value Register 11 */
#define ETM_DCVR12            (ETM_DCVR11 + 0x4U)  /* Data Comparator Value Register 12 */
#define ETM_DCVR13            (ETM_DCVR12 + 0x4U)  /* Data Comparator Value Register 13 */
#define ETM_DCVR14            (ETM_DCVR13 + 0x4U)  /* Data Comparator Value Register 14 */
#define ETM_DCVR15            (ETM_DCVR14 + 0x4U)  /* Data Comparator Value Register 15 */
#define ETM_DCMR0             (0x100U)             /* Data Comparator Mask Register 0 */
#define ETM_DCMR1             (ETM_DCMR0 + 0x4U)   /* Data Comparator Mask Register 1 */
#define ETM_DCMR2             (ETM_DCMR1 + 0x4U)   /* Data Comparator Mask Register 2 */
#define ETM_DCMR3             (ETM_DCMR2 + 0x4U)   /* Data Comparator Mask Register 3 */
#define ETM_DCMR4             (ETM_DCMR3 + 0x4U)   /* Data Comparator Mask Register 4 */
#define ETM_DCMR5             (ETM_DCMR4 + 0x4U)   /* Data Comparator Mask Register 5 */
#define ETM_DCMR6             (ETM_DCMR5 + 0x4U)   /* Data Comparator Mask Register 6 */
#define ETM_DCMR7             (ETM_DCMR6 + 0x4U)   /* Data Comparator Mask Register 7 */
#define ETM_DCMR8             (ETM_DCMR7 + 0x4U)   /* Data Comparator Mask Register 8 */
#define ETM_DCMR9             (ETM_DCMR8 + 0x4U)   /* Data Comparator Mask Register 9 */
#define ETM_DCMR10            (ETM_DCMR9 + 0x4U)   /* Data Comparator Mask Register 10 */
#define ETM_DCMR11            (ETM_DCMR10 + 0x4U)  /* Data Comparator Mask Register 11 */
#define ETM_DCMR12            (ETM_DCMR11 + 0x4U)  /* Data Comparator Mask Register 12 */
#define ETM_DCMR13            (ETM_DCMR12 + 0x4U)  /* Data Comparator Mask Register 13 */
#define ETM_DCMR14            (ETM_DCMR13 + 0x4U)  /* Data Comparator Mask Register 14 */
#define ETM_DCMR15            (ETM_DCMR14 + 0x4U)  /* Data Comparator Mask Register 15 */

/* Counters */
#define ETM_CNTRLDVR0         (0x140U)                 /* Counter Reload Value Register 0 */
#define ETM_CNTRLDVR1         (ETM_CNTRLDVR0 + 0x4U)   /* Counter Reload Value Register 1 */
#define ETM_CNTRLDVR2         (ETM_CNTRLDVR1 + 0x4U)   /* Counter Reload Value Register 2 */
#define ETM_CNTRLDVR3         (ETM_CNTRLDVR2 + 0x4U)   /* Counter Reload Value Register 3 */
#define ETM_CNTENR0           (0x150U)                 /* Counter Enable Register 0 */
#define ETM_CNTENR1           (ETM_CNTENR0 + 0x4U)     /* Counter Enable Register 1 */
#define ETM_CNTENR2           (ETM_CNTENR1 + 0x4U)     /* Counter Enable Register 2 */
#define ETM_CNTENR3           (ETM_CNTENR2 + 0x4U)     /* Counter Enable Register 3 */
#define ETM_CNTRLDEVR0        (0x160U)                 /* Counter Reload Event Register 0 */
#define ETM_CNTRLDEVR1        (ETM_CNTRLDEVR0 + 0x4U)  /* Counter Reload Event Register 1 */
#define ETM_CNTRLDEVR2        (ETM_CNTRLDEVR1 + 0x4U)  /* Counter Reload Event Register 2 */
#define ETM_CNTRLDEVR3        (ETM_CNTRLDEVR2 + 0x4U)  /* Counter Reload Event Register 3 */
#define ETM_CNTVR0            (0x170U)                 /* Counter Value Register 0 */
#define ETM_CNTVR1            (ETM_CNTVR0 + 0x4U)      /* Counter Value Register 1 */
#define ETM_CNTVR2            (ETM_CNTVR1 + 0x4U)      /* Counter Value Register 2 */
#define ETM_CNTVR3            (ETM_CNTVR2 + 0x4U)      /* Counter Value Register 3 */

/* Sequencer */
#define ETM_SQabEVR0          (0x180U)                 /* Sequencer State Transistion Event Register 0 */
#define ETM_SQabEVR1          (ETM_SQabEVR0 + 0x4U)    /* Sequencer State Transistion Event Register 1 */
#define ETM_SQabEVR2          (ETM_SQabEVR1 + 0x4U)    /* Sequencer State Transistion Event Register 2 */
#define ETM_SQabEVR3          (ETM_SQabEVR2 + 0x4U)    /* Sequencer State Transistion Event Register 3 */
#define ETM_SQabEVR4          (ETM_SQabEVR3 + 0x4U)    /* Sequencer State Transistion Event Register 4 */
#define ETM_SQabEVR5          (ETM_SQabEVR4 + 0x4U)    /* Sequencer State Transistion Event Register 5 */
#define ETM_SQR               (0x19CU)                 /* Current Sequencer State Register */

/* External Output Event Registers */
#define ETM_EXTOUTEVR0          (0x1A0U)                /* External Output Event Register 0 */
#define ETM_EXTOUTEVR1          (ETM_EXTOUTEVR0 + 0x4U) /* External Output Event Register 1 */
#define ETM_EXTOUTEVR2          (ETM_EXTOUTEVR1 + 0x4U) /* External Output Event Register 2 */
#define ETM_EXTOUTEVR3          (ETM_EXTOUTEVR2 + 0x4U) /* External Output Event Register 3 */

/* Context ID Comparators */
#define ETM_CIDCVR0             (0x1B0U)                /* Context ID Comparator Value Register 0 */
#define ETM_CIDCVR1             (ETM_CIDCMR0 + 0x4U)    /* Context ID Comparator Value Register 1 */
#define ETM_CIDCVR2             (ETM_CIDCMR1 + 0x4U)    /* Context ID Comparator Value Register 2 */
#define ETM_CIDCMR              (0x1BCU)                /* Context ID Comparator Mask Register */

/* Other ETM Trace Registers */
#define ETM_IMPLSPR0            (0x1C0)                 /* Implementation-specific Register 0 */
#define ETM_IMPLSPR1            (ETM_IMPLSPR0 + 0x4U)   /* Implementation-specific Register 1 */
#define ETM_IMPLSPR2            (ETM_IMPLSPR1 + 0x4U)   /* Implementation-specific Register 2 */
#define ETM_IMPLSPR3            (ETM_IMPLSPR2 + 0x4U)   /* Implementation-specific Register 3 */
#define ETM_IMPLSPR4            (ETM_IMPLSPR3 + 0x4U)   /* Implementation-specific Register 4 */
#define ETM_IMPLSPR5            (ETM_IMPLSPR4 + 0x4U)   /* Implementation-specific Register 5 */
#define ETM_IMPLSPR6            (ETM_IMPLSPR5 + 0x4U)   /* Implementation-specific Register 6 */
#define ETM_IMPLSPR7            (ETM_IMPLSPR6 + 0x4U)   /* Implementation-specific Register 7 */

#define ETM_SYNCFR              (0x1E0U)                /* Synchronization Frequency Register */
#define ETM_IDR                 (0x1E4U)                /* ID Register */
#define ETM_CCER                (0x1E8U)                /* Condition Code Extension Register */
#define ETM_EXTINSELR           (0x1ECU)                /* Extended External Input Selection Register */
#define ETM_TESSEICR            (0x1F0U)                /* TraceEnable Start/Stop EmbeddedICE Control Register */
#define ETM_EIBCR               (0x1F4U)                /* EmbeddedICE Behavior Control Register */
#define ETM_TSEVR               (0x1F8U)                /* Timestamp Event Register */
#define ETM_AUXCR               (0x1FCU)                /* Auxiliary Control Register */
#define ETM_TRACEIDR            (0x200U)                /* Trace ID Register */
#define ETM_IDR2                (0x208U)                /* ETM ID Register 2*/
#define ETM_VMIDCVR             (0x240U)                /* VMID Comparator Value Register */

/* ETM Management Registers */
#define ETM_OSLAR               (0x300U)                 /* OS Lock Access Register */
#define ETM_OSLSR               (0x304U)                 /* OS Lock Status Register */
#define ETM_OSSRR               (0x308U)                 /* OS Save And Restore Register */

/* Other ETM Management Registers */
#define ETM_PDCR                (0x310U)                  /* Power Down Control Register */
#define ETM_PDSR                (0x314U)                  /* Device Power-Down Status Register */

/* ETM Management Registers */
#define ETM_ITCTRL             (0xF00U)                   /* Integration Mode Control Register */
#define ETM_CLAIMSET           (0xFA0U)                   /* Claim Tag Set Register */
#define ETM_CLAIMCLR           (0xFA4U)                   /* Claim Tag Clear Register */
#define ETM_LAR                (0xFB0U)                   /* Lock Access Register */
#define ETM_LSR                (0xFB4U)                   /* Lock Status Register */
#define ETM_AUTHSTATUS         (0xFB8U)                   /* Authentication Status Register */

#define ETM_DEVID              (0xFC8U)                   /* CoreSight Device Configuration Register */
#define ETM_DEVTYPE            (0xFCCU)                   /* CoreSight Device Type Register */

/* Peripheral And Component ID Registers */
#define ETM_PIDR4              (0xFD0U)                   /* Peripheral ID4 Register */
#define ETM_PIDR5              (0xFD4U)                   /* Peripheral ID5 Register */
#define ETM_PIDR6              (0xFD8U)                   /* Peripheral ID6 Register */
#define ETM_PIDR7              (0xFDCU)                   /* Peripheral ID7 Register */
#define ETM_PIDR0              (0xFE0U)                   /* Peripheral ID0 Register */
#define ETM_PIDR1              (0xFE4U)                   /* Peripheral ID1 Register */
#define ETM_PIDR2              (0xFE8U)                   /* Peripheral ID2 Register */
#define ETM_PIDR3              (0xFECU)                   /* Peripheral ID3 Register */
#define ETM_CIDR0              (0xFF0U)                   /* Component ID0 Register */
#define ETM_CIDR1              (0xFF4U)                   /* Component ID1 Register */
#define ETM_CIDR2              (0xFF8U)                   /* Component ID2 Register */
#define ETM_CIDR3              (0xFFCU)                   /* Component ID3 Register */

/* Control Register (ETM_CR) Bitfields */
#define ETM_CR_POWERDOWN          (1U << 0)
#define ETM_CR_PROGRAMMING        (1U << 10)
#define ETM_CR_ETMEN              (1U << 11)

/* Status Register (ETM_SR) Bitfields */
#define ETM_SR_PROGBIT            (1U << 0)

/* Trace Enable Event Register (ETM_TEEVR) Bitfields */
#define ETM_TEEVR_ENABLE          (1U << 0)

/* Formatter and Flush Control Register (ETM_FFCR) Bitfields */
#define ETM_FFCR_EN               (1U << 0)
#define ETM_FFCR_STOPPED          (1U << 1)

typedef struct {
    union {
    struct {
        uint32_t implementation_revision:4;
        uint32_t etm_minor_arch_version:4;
        uint32_t etm_major_arch_version:4;
        uint32_t processor_family:4;
        uint32_t load_pc_first:1;
        uint32_t reserved0:1;
        uint32_t supports_32bit_thumb_instr:1;
        uint32_t support_for_security_extensions:1;
        uint32_t branch_packet_encoding_implemented:1;
        uint32_t reserved1:3;
        uint32_t implementer_code:4;
        };
        uint32_t value;
    };
}id_register_t;
_Static_assert(sizeof(id_register_t) == 4U, "id_register_t size incorrect");
#endif /* _ARM_ETM_H_ */