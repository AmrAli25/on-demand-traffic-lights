/*
 * app.c
 *
 * Created: 11/10/2022 9:30:28 PM
 *  Author: AmrAli
 */ 


#include "app.h"

uint8_t STATE;
uint8_t Car_red_f, Car_green_f, Car_yellow_f;



void App_start(void)
{
	
	// normal mode traffic lights initialize
	LED_init(PORT_A, PIN0);     // RED
	LED_init(PORT_A, PIN1);     // YELLOW
	LED_init(PORT_A, PIN2);		// GREEN
	
	// first state all off
	LED_off(PORT_A, PIN0);		// RED OFF
	LED_off(PORT_A, PIN1);		// YELLOW OFF
	LED_off(PORT_A, PIN2);		// GREEN OFF
	
	// pedestrian mode traffic lights initialize
	LED_init(PORT_B, PIN0);     // RED
	LED_init(PORT_B, PIN1);     // YELLOW
	LED_init(PORT_B, PIN2);		// GREEN
	
	// first state all off
	LED_off(PORT_B, PIN0);		// RED OFF
	LED_off(PORT_B, PIN1);		// YELLOW OFF
	LED_off(PORT_B, PIN2);		// GREEN OFF
	
	// initialize INT0
	BUTTON_interruptInit(INT_0, rising_edge);
	
	// default state is normal
	STATE = NORMAL;
	
	
	
	while(1)
	{
		switch(STATE)
		{
			case NORMAL:
			// the default state as the start is all leds is off
				LED_off(PORT_B, PIN0);
				LED_off(PORT_B, PIN1);
				LED_off(PORT_B, PIN2);
				LED_off(PORT_A, PIN0);
				LED_off(PORT_A, PIN1);
				LED_off(PORT_A, PIN2);
				stop = 0;
				
				// rest the flags for the states
				Car_red_f = LOW;
				Car_yellow_f = LOW;
				LED_on(PORT_A, PIN2);		// CAR GREEN ON
				Car_green_f = HIGH;			// wait for the pedestrian button to activate (STATE 2) --> (car green led on & pedestrian red on for 5 sec)
				delay_sec_normal(19);		// delay 5 second
					
				if (Car_green_f == LOW)		// check if the pedestrian button is pressed (STATE 2)
				{
					break;
				}
				LED_off(PORT_A, PIN2);		// CAR GREEN OFF
				
				// rest the flags if changed in the interrupt
				Car_green_f = LOW;
				Car_red_f = LOW;
				LED_blink_2(PORT_A, PIN1);	// CAR YELLOW BLINK .5 sec
				Car_yellow_f = HIGH;		// wait for the pedestrian button to activate (STATE 3)--> (car yellow blink & ped yellow blink for 5 sec)
				LED_blink_1(PORT_A, PIN1);	// CAR YELLOW BLINK 4.5 sec
				if (Car_yellow_f == LOW)	// check if the pedestrian button is pressed (STATE 2)
				{
					break;
				}
				LED_off(PORT_A, PIN1);		// CAR YELLOW OFF
				
				// rest flags if changed in the interrupt
				Car_green_f = LOW;
				Car_yellow_f = LOW;
				LED_on(PORT_A, PIN0);		// CAR RED ON
				Car_red_f = HIGH;			// wait for the pedestrian button to activate (STATE 1)--> (car red on & ped green on for 5 sec)  
				delay_sec_normal(19);		// delay 5 sec
				
				if (Car_red_f == LOW)		// check if the pedestrian button is pressed (STATE 1)
				{
					break;
				}
				LED_off(PORT_A, PIN0);		// CAR RED OFF
				
				Car_green_f = LOW;
				Car_red_f = LOW;
				LED_blink_2(PORT_A, PIN1);	// CAR YELLOW BLINK .5 sec
				Car_yellow_f = HIGH;		// wait for the pedestrian button to activate (STATE 3)--> (car yellow blink & ped yellow blink for 5 sec)
				LED_blink_1(PORT_A, PIN1);	// CAR YELLOW BLINK 4.5 sec
				if (Car_yellow_f == LOW)	// check if the pedestrian button is pressed (STATE 3)
				{
					break;
				}
				LED_off(PORT_A, PIN1);		// CAR YELLOW OFF
			break;
			case PEDESTRIAN:
				
				if (Car_red_f == LOW)			//  (STATE 1)--> (car red on & ped green on for 5 sec) 
				{
					LED_on(PORT_A, PIN0);		// CAR RED on
					LED_on(PORT_B,PIN2);		// PED GREEN on
					delay_sec_normal(19);		// 5 sec
					
					STATE = NORMAL;				// return to normal mode
					LED_off(PORT_A, PIN0);		// CAR RED off
					LED_off(PORT_B, PIN2);		// PED GREEN off
					LED_yellow_blink();			// blink car yellow & pedestrian yellow 
					LED_on(PORT_B, PIN0);		// PED RED on
					LED_on(PORT_A, PIN2);		// CAR GREEN on
					delay_sec_normal(19);
				}
				else if (Car_green_f == LOW)	// (STATE 2) --> (car green led on & pedestrian red on for 5 sec)
				{
					LED_off(PORT_B, PIN0 );		// PED RED off
					LED_off(PORT_A, PIN2);		// CAR GREEN off
					LED_on(PORT_B, PIN2);		// PED GREEN on
					LED_on(PORT_A, PIN0);		// CAR RED on
					delay_sec_normal(19);	
					
					STATE = NORMAL;				 // return to normal mode
					LED_off(PORT_A, PIN0);      // CAR RED off
					LED_off(PORT_B, PIN2);	   // PED GREEN off
					LED_yellow_blink();		
					LED_on(PORT_A, PIN2);		// CAR GREEN on
					LED_on(PORT_B, PIN0);		// PED RED on		
					delay_sec_normal(15);		
					
				}
				else if (Car_yellow_f == LOW)	// (STATE 3) --> (car green led on & pedestrian red on for 5 sec)
				{
					
				
					LED_on(PORT_A, PIN0);		// CAR RED on
					delay_sec_normal(19);
					
					STATE = NORMAL;				// return to normal mode
					LED_off(PORT_A, PIN0);     // CAR RED off
					LED_off(PORT_B, PIN2);		// PED GREEN off
					LED_yellow_blink();
					LED_on(PORT_A, PIN2);		// CAR GREEN on
					LED_on(PORT_B, PIN0);		// PED RED on
					delay_sec_normal(15);
				}
			break; 
		}
		
	}
}

ISR(INT0_vect)
{
	if (Car_red_f == HIGH && Car_green_f == LOW && Car_yellow_f == LOW)
	{
		Car_red_f = LOW;		// set the flag to start (STATE 1)
		Car_green_f = HIGH;		// insure that no flag is raised 
		Car_yellow_f = HIGH;
		
		STATE = PEDESTRIAN;		// change to pedestrian mode
		LED_on(PORT_B, PIN2);	// PED GREEN on
	}
	else if (Car_green_f == HIGH && Car_red_f == LOW && Car_yellow_f == LOW)
	{
		Car_green_f = LOW;		// set the flag to start (STATE 2)
		Car_red_f = HIGH;		// insure that no flag is raised
		Car_yellow_f = HIGH;
		
		STATE = PEDESTRIAN;		// change to pedestrian mode
		LED_off(PORT_A, PIN2);
		LED_yellow_blink();
		LED_on(PORT_A, PIN0);
		LED_on(PORT_B, PIN2);
	}
	else if (Car_yellow_f == HIGH && Car_red_f == LOW && Car_green_f == LOW)
	{
		Car_yellow_f = LOW;		// set the flag to start (STATE 3)
		Car_red_f = HIGH;		// insure that no flag is raised
		Car_green_f = HIGH;
		
		STATE = PEDESTRIAN;		// change to pedestrian mode
		LED_yellow_blink();
		LED_on(PORT_B, PIN2);
		stop = 1;
		
	}
}