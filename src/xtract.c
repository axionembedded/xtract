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

#include "xtract.h"
#include "arm_etm.h"

#define ETM_ID_REGISTER_PRESENT_MASK (1UL << 31)

static uint32_t etm_base_address;
static id_register_t id;

bool xtract_etm_init(uint32_t etm_base_addr)
{
	uint32_t cr;
    uint32_t ccr;

    etm_base_address = etm_base_addr;

    cr = *((volatile uint32_t *)(etm_base_address + ETM_CR));
    if (cr == 0)
    {
    	return false;
    }

    ccr = *((volatile uint32_t *)(etm_base_address + ETM_CCR));
    if ((ccr & ETM_ID_REGISTER_PRESENT_MASK) == 0U)
    {
        return false;
    }

    id.value = *((volatile uint32_t *)(etm_base_addr + ETM_IDR));

    return (id.etm_major_arch_version == ETM_MAJOR_ARCH_VERSION_3);
}

uint8_t xtract_etm_get_major_version(void)
{
    return id.etm_major_arch_version;
}

uint8_t xtract_etm_get_minor_version(void)
{
    return id.etm_minor_arch_version;
}
