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
#include "DC_Motor.h"
#include "Timer.h"


void DCMOTOR_init(uint8 duty_cycle)
{
	Timer_ConfigType Timer2_Config = {FAST_PWM, NON_INVERTING, F_CPU_1024};

	Timer2_init(&Timer2_Config);		/* Initialize Timer2 driver */
	Timer2_duty_cycle( duty_cycle );			/* Set PWM for 100% duty cycle */
}

void DCMOTOR_direction(uint8 a_forward , uint8 a_reverse)
{

	DCMOTOR_DDR = DCMOTOR_DDR | (1<<FORWARD);    /* Configure FORWARD pin of the motor as output pin */
	DCMOTOR_DDR = DCMOTOR_DDR | (1<<REVERSE);    /* Configure REVERSE pin of the motor as output pin */

	DCMOTOR_PORT = (DCMOTOR_PORT & 0xFE) | (a_forward << FORWARD);
	DCMOTOR_PORT = (DCMOTOR_PORT & 0xFD) | (a_reverse << REVERSE);
}

void DCMOTOR_deinit()
{
	Timer2_deinit();
	DCMOTOR_PORT = (DCMOTOR_PORT & 0xFE) | (0 << FORWARD);
	DCMOTOR_PORT = (DCMOTOR_PORT & 0xFD) | (0 << REVERSE);
}
