#ifndef _INC_DEMO_H_
#define _INC_DEMO_H_

#include "global.h"

uint16_t Demo_FLASH_function_uint16(void);
uint32_t Demo_FLASH_function_uint32(void);

#pragma CODE_SECTION(Demo_RAM_function_uint16, "ramfuncs");
#pragma CODE_SECTION(Demo_RAM_function_uint32, "ramfuncs");

uint16_t Demo_RAM_function_uint16(void);
uint32_t Demo_RAM_function_uint32(void);

#endif /* INC_DEMO_H_ */
