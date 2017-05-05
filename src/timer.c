#include "timer.h"

TIMER_Handle timer2_h;
volatile uint16_t timer2_overflow;

void timer2_init(void)
{
	timer2_h = TIMER_init((void *)TIMER2_BASE_ADDR, sizeof(TIMER_Obj));

	timer2_overflow = 0;
	TIMER_stop(timer2_h);
	timer2_resetCount();

	PIE_registerSystemIntHandler(pie_h, PIE_SystemInterrupts_TINT2, (intVec_t)&timer2_isr);
	TIMER_setPeriod(timer2_h, 0xFFFFFFFF); // maximum uint32 value
	TIMER_setDecimationFactor(timer2_h, 0);
    TIMER_setPreScaler(timer2_h, 0); // let this timer count CPU cycles
    TIMER_reload(timer2_h); // sets the period and prescaler

    TIMER_setEmulationMode(timer2_h, TIMER_EmulationMode_RunFree); // timer will keep on going after the interrupt
    TIMER_enableInt(timer2_h);

    CPU_enableInt(cpu_h, CPU_IntNumber_14); // timer 2 interrupt
}

void timer2_tic(void)
{
	TIMER_stop(timer2_h);
	timer2_overflow = 0;
	timer2_resetCount();
	TIMER_reload(timer2_h);
	TIMER_start(timer2_h);
}

void timer2_toc(void)
{
    TIMER_stop(timer2_h);
}

void timer2_resetCount(void)
{
    TIMER_Obj *timer2 = (TIMER_Obj*)timer2_h;
    timer2->TIM = 0xFFFFFFFF;
}

uint32_t timer2_getCount(void)
{
	return (0xFFFFFFFF - TIMER_getCount(timer2_h)); // those timers are counting down!
}

uint16_t timer2_getOverflow(void)
{
	return timer2_overflow;
}

interrupt void timer2_isr(void)
{
	TIMER_clearFlag(timer2_h);
	if (timer2_overflow < 0xFFFF) timer2_overflow++; // overflow is actually reaching 0, as timer decrements
}
