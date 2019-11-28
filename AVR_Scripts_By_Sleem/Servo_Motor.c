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
#include "Servo_Motor.h"
#include "Timer.h"


void SERVOMOTOR_init(uint8 duty_cycle)
{
	Timer_ConfigType Timer0_Config = {FAST_PWM, NON_INVERTING, F_CPU_1024};

	Timer0_init(&Timer0_Config);						/* Initialize Timer2 driver */
	Timer0_duty_cycle( (255 * duty_cycle)/100 );			/* Set PWM for 100% duty cycle */
}

void SERVOMOTOR_direction(uint8 a_forward , uint8 a_reverse)
{

	SERVOMOTOR_DDR = SERVOMOTOR_DDR | (1<<RIGHT);    /* Configure FORWARD pin of the motor as output pin */
	SERVOMOTOR_DDR = SERVOMOTOR_DDR | (1<<LEFT);    /* Configure REVERSE pin of the motor as output pin */

	SERVOMOTOR_PORT = (SERVOMOTOR_PORT & 0xFE) | (a_forward << RIGHT);
	SERVOMOTOR_PORT = (SERVOMOTOR_PORT & 0xFD) | (a_reverse << LEFT);
}

void SERVOMOTOR_deinit()
{
	Timer0_deinit();
	SERVOMOTOR_PORT = (SERVOMOTOR_PORT & 0xFE) | (0 << RIGHT);
	SERVOMOTOR_PORT = (SERVOMOTOR_PORT & 0xFD) | (0 << LEFT);
}
