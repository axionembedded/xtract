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

#ifndef _ARM_ETB_H_
#define _ARM_ETB_H_

#include <stdint.h>

#define ETB_STS_EMPTY_MASK                (1UL << 3)
#define ETB_CTL_ENABLE_TRACE_CAPTURE_MASK (1UL << 0)

#define ETB_RDP                 (0x004U)   /* RAM Depth Register */
#define ETB_STS                 (0x00CU)   /* Status Register */
#define ETB_RRD                 (0x010U)   /* RAM Read Data Register */
#define ETB_RRP                 (0x014U)   /* RAM Read Pointer Register */
#define ETB_RWP                 (0x018U)   /* RAM Write Pointer Register */
#define ETB_TRG                 (0x01CU)   /* Trigger Count Register */
#define ETB_CTL                 (0x020U)   /* Control Register */

#endif /* _ARM_ETB_H_ */