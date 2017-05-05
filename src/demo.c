/*
 * demo.c
 *
 *  Created on: 4 maj 2017
 *      Author: miki
 */

#include "demo.h"

uint16_t Demo_FLASH_function_uint16(void)
{
	uint16_t number_a, number_b, number_fib;

	number_a = number_b = 1;
	number_fib = 0;

	while (number_fib < 0x7FFF)
	{
		number_fib = number_a + number_b;
		number_a = number_b;
		number_b = number_fib;
	}

	return number_fib;
}

uint32_t Demo_FLASH_function_uint32(void)
{
	uint32_t number_a, number_b, number_fib;

	number_a = number_b = 1;
	number_fib = 0;

	while (number_fib < 0x7FFFFFFF)
	{
		number_fib = number_a + number_b;
		number_a = number_b;
		number_b = number_fib;
	}

	return number_fib;
}

uint16_t Demo_RAM_function_uint16(void)
{
	uint16_t number_a, number_b, number_fib;

	number_a = number_b = 1;
	number_fib = 0;

	while (number_fib < 0x7FFF)
	{
		number_fib = number_a + number_b;
		number_a = number_b;
		number_b = number_fib;
	}

	return number_fib;
}

uint32_t Demo_RAM_function_uint32(void)
{
	uint32_t number_a, number_b, number_fib;

	number_a = number_b = 1;
	number_fib = 0;

	while (number_fib < 0x7FFFFFFF)
	{
		number_fib = number_a + number_b;
		number_a = number_b;
		number_b = number_fib;
	}

	return number_fib;
}
