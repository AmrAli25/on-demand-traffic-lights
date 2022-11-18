#include "dio.h"


void main(void)
{
	DIO_init(PORT_C, PIN0, OUT);
	DIO_toggle(PORT_C, PIN0);
	DIO_write(PORT_C, PIN0, HIGH);
}
