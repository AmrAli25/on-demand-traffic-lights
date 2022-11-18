/*
 * timers.h
 *
 * Created: 11/10/2022 9:14:16 PM
 *  Author: AmrAli
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "../../Utilities/micro_config.h"

typedef enum EN_TIMERSError_t
{
	TIMERS_OK, TIMERS_ERROR
}EN_TIMERSError_t;

#define no_prescaler	1
#define clk_8			2
#define clk_64			3
#define clk_256			4
#define clk_1024		5

/* Timer 0*/
EN_TIMERSError_t TIMER0_init_normal(uint8_t initial_value);
EN_TIMERSError_t TIMER0_start(uint8_t prescaler);
EN_TIMERSError_t TIMER0_stop(void);
EN_TIMERSError_t TIMER0_interrupt_enable(void);
EN_TIMERSError_t TIMER0_CLR_OVF(void);

/* Timer 2*/
EN_TIMERSError_t TIMER2_init_normal(uint8_t initial_value);
EN_TIMERSError_t TIMER2_start(uint8_t prescaler);
EN_TIMERSError_t TIMER2_stop(void);
EN_TIMERSError_t TIMER2_interrupt_enable(void);
EN_TIMERSError_t TIMER2_CLR_OVF(void);





#endif /* TIMERS_H_ */