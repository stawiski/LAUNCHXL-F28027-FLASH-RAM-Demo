#include "global.h"

/*

This is a demo to show the difference in execution speed from FLASH and RAM on Texas Instrument's C2000 Launchpad Kit (LAUNCHXL-F28027).

The demo executes different CPU-heavy functions, that were placed in FLASH or RAM, and prints their execution time as well as results.
The demo functions compute fibonacci numbers up to some set limit.

It is worth noting, that different results are expected, while using different optimization options!

CPU runs at max clock, 60 MHz
UART runs at 3750000 (3.75 MHz) baud rate

Results are in RESULTS.txt.

*/

void main(void)
{
	setup_handles();
	init_system();

	UART_init();
	timer2_init();
	leds_init();

	PIE_enable(pie_h);
    CPU_enableGlobalInts(cpu_h);
    CPU_enableDebugInt(cpu_h);

	UART_printf("\r\n\r\n");
	UART_printf(" ### F28027 LaunchPad ; FLASH vs. RAM Demo ; by Mikolaj Stawiski ###\r\n\r\n");
	UART_printf("CPU_FREQ_MHZ = %u\r\n", CPU_FREQ_MHZ);

	UART_printf("Press any key to start the code...");
	UART_readByteWait();
	UART_printf("\r\n");

	while(1)
	{
		UART_printf("Starting Demo FLASH...\r\n");
		{
			volatile uint16_t flash_result_uint16 = 0;
			volatile uint32_t flash_result_uint32 = 0;

			timer2_tic();
			flash_result_uint16 = Demo_FLASH_function_uint16();
			flash_result_uint32 = Demo_FLASH_function_uint32();
			timer2_toc();

			UART_printf("\tresult (uint16) = %u\r\n", flash_result_uint16);
			UART_printf("\tresult (uint32) = %n\r\n", flash_result_uint32);

			UART_printf("\ttimer2_getCount = %n\r\n", timer2_getCount());
			if (timer2_getOverflow()) UART_printf("\ttimer2_getOverflow = %u\r\n", timer2_getOverflow());
			UART_printf("\r\n");
		}

		UART_printf("Starting Demo RAM...\r\n");
		{
			volatile uint16_t ram_result_uint16 = 0;
			volatile uint32_t ram_result_uint32 = 0;

			timer2_tic();
			ram_result_uint16 = Demo_RAM_function_uint16();
			ram_result_uint32 = Demo_RAM_function_uint32();
			timer2_toc();

			UART_printf("\tresult (uint16) = %u\r\n", ram_result_uint16);
			UART_printf("\tresult (uint32) = %n\r\n", ram_result_uint32);

			UART_printf("\ttimer2_getCount = %n\r\n", timer2_getCount());
			if (timer2_getOverflow()) UART_printf("\ttimer2_getOverflow = %u\r\n", timer2_getOverflow());
			UART_printf("\r\n");
		}

		UART_readByteWait(); // pause
	}
}
