#include "timers.h"

void main (void)
{
	TIMER0_init_normal(0);
	TIMER0_start();
	TIMER0_stop();
	
}