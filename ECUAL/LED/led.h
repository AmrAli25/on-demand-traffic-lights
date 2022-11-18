/*
 * led.h
 *
 * Created: 11/10/2022 9:30:49 PM
 *  Author: AmrAli
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/TIMERS/timers.h"

typedef enum EN_LEDError_t
{
	LED_OK, LED_ERROR
}EN_LEDError_t;

extern uint8_t stop;


EN_LEDError_t LED_init(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_on(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_off(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_blink_1(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t LED_blink_2(uint8_t ledPort, uint8_t ledPin);
EN_LEDError_t delay_sec_normal(uint8_t numOfOverflow);
EN_LEDError_t delay_sec_pedestrian(uint8_t numOfOverflow);
EN_LEDError_t LED_yellow_blink(void);
EN_LEDError_t LED_toggle(uint8_t ledPort, uint8_t ledPin);






#endif /* LED_H_ */