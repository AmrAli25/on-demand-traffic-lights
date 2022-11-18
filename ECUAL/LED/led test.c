#include "led.h"

void main(void)
{
	LED_init(PORT_A, PIN0);
	LED_on(PORT_A, PIN0);
	LED_off(PORT_A, PIN0);
	LED_toggle(PORT_A, PIN0);
	
}