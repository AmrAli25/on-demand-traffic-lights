#include "interrupts.h"

void main (void)
{
	Ext_interrupt_init(INT_1, low_level);
}