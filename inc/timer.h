#ifndef _INC_TIMER_H_
#define _INC_TIMER_H_

#include "global.h"

extern TIMER_Handle timer2_h;
extern volatile uint16_t timer2_overflow;

void timer2_init(void);
void timer2_tic(void);
void timer2_toc(void);
void timer2_resetCount(void);
uint32_t timer2_getCount(void);
uint16_t timer2_getOverflow(void);
interrupt void timer2_isr(void);

#endif /* F28027_UART_TO_PWM_INC_TICK_H_ */
