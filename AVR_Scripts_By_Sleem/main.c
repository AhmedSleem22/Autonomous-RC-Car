/******************************************************************************
 *
 * Module: DC_Moter
 *
 * File Name: DC_Motor.c
 *
 * Description: Soucre file for the motor
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/

#include "micro_config.h"
#include "Timer.h"
#include "DC_Motor.h"
#include "Servo_Motor.h"

int main()
{
	/* configure pin PA0, PA1, PA2 and PA3 as input pins */
	DDRA &= ~(1<<PA0);
	PORTA |= (1<<PA0);

	DDRA &= ~(1<<PA1);
	PORTA |= (1<<PA1);

	DDRA &= ~(1<<PA2);
	PORTA |= (1<<PA2);

	DDRA &= ~(1<<PA3);
	PORTA |= (1<<PA3);

	while(1)
	{
		if( BIT_IS_CLEAR(PINA,PA0) )
		{
			DCMOTOR_init(255);
			DCMOTOR_direction(1 , 0);
		}

		if( BIT_IS_CLEAR(PINA,PA1) )
		{
			DCMOTOR_init(255);
			DCMOTOR_direction(0 , 1);
		}

		if( BIT_IS_CLEAR(PINA,PA2) )
		{
			SERVOMOTOR_init(255);
			SERVOMOTOR_direction(1 , 0);		/* Set Servo shaft at 0° position by 1.5 ms pulse */
		}

		if( BIT_IS_CLEAR(PINA,PA3) )
		{
			SERVOMOTOR_init(255);
			SERVOMOTOR_direction(0 , 1);		/* Set Servo shaft at 180° position by 2 ms pulse */
		}

		if ( BIT_IS_SET(PINA,PA2) && BIT_IS_SET(PINA,PA3) )
		{
			SERVOMOTOR_deinit();
		}

		if ( BIT_IS_SET(PINA,PA0) && BIT_IS_SET(PINA,PA1) )
		{
			DCMOTOR_deinit();
		}
	}
}
