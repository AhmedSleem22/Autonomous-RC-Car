/*******************************************************************************
 *
 * File Name: timer2.c
 *
 * Description: Source file for the timer2 driver
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/

#include "Timer.h"

/*******************************************************************************
 *                      		     TIMER 0                                   *
 *******************************************************************************/

void Timer0_init(const Timer_ConfigType * Config_Ptr )
{
   TCCR0 = (TCCR0 & 0xB7 ) | ((Config_Ptr->mode & 0x01) << 3) | ((Config_Ptr->mode & 0x02) << 5); 	/* Set fast PWM Mode*/

   TCCR0 = (TCCR0 & 0xCF ) | (Config_Ptr->state << 4); 	/* Set non-inverting mode */

   TCCR0 = (TCCR0 & 0xF8 ) | (Config_Ptr->clock);		/* Set prescaler starts PWM */
}

void Timer0_duty_cycle( uint32 duty_cycle)
{
	DDRB = (DDRB & 0xF7) | (1 << PB3);			/* PB3 (OC0) as output */
	OCR0 = duty_cycle;							/* Set PWM duty cycle */
}

void Timer0_compare_value( uint32 OC_value)
{
	OCR0 = OC_value;				/* Set PWM for 50% duty cycle */
}

void Timer0_deinit()
{
	TCCR0 = 0x00;
}

/*******************************************************************************
 *                      		     TIMER 1                                   *
 *******************************************************************************/

void Timer1_init(const Timer_ConfigType * Config_Ptr )
{
	ICR1 = 2499;
	TCCR1A = (TCCR1A & 0xFC ) | (Config_Ptr->mode & 0x03);
	TCCR1B = (TCCR1B & 0xE7 ) | ((Config_Ptr->mode & 0x0C) << 1); 	/* Set fast PWM Mode*/

	TCCR1A = (TCCR1A & 0x3F ) | (Config_Ptr->state << 6); 			/* Set non-inverting mode */

	TCCR1B = (TCCR1B & 0xF8 ) | (Config_Ptr->clock);				/* Set prescaler starts PWM */
}

void Timer1_duty_cycle(uint32 F_PWM, uint32 duty_cycle)
{
	ICR1 = F_PWM;								/* Set TOP count for timer1 in ICR1 register */
	DDRD  = (DDRD & 0xDF) | (1 << PD5);			/* PD5 (OC1A) as output */
	OCR1A = duty_cycle;							/* Set PWM duty cycle */
}

void Timer1_compare_value( uint32 OC_value)
{
	OCR1A = OC_value;							/* Set PWM for 50% duty cycle */
}

void Timer1_deinit()
{
	TCCR1A = 0x00;
	TCCR1B = 0x00;
}

/*******************************************************************************
 *                      		     TIMER 2                                   *
 *******************************************************************************/

void Timer2_init(const Timer_ConfigType * Config_Ptr )
{
   TCCR2 = (TCCR2 & 0xB7 ) | ((Config_Ptr->mode & 0x01) << 3) | ((Config_Ptr->mode & 0x02) << 5); 	/* set fast PWM Mode*/

   TCCR2 = (TCCR2 & 0xCF ) | (Config_Ptr->state << 4); 	/* Set non-inverting mode */

   TCCR2 = (TCCR2 & 0xF8 ) | (Config_Ptr->clock);		/* Set prescaler starts PWM */
}

void Timer2_duty_cycle( uint8 duty_cycle)
{
	DDRD = (DDRD & 0xFE) | (1 << PD7);			/* PD7 as output */
	OCR2 = duty_cycle;							/* Set PWM duty cycle */
}

void Timer2_compare_value( uint8 OCR_value)
{
	OCR2 = OCR_value;							/* Set PWM for 50% duty cycle */
}

void Timer2_deinit()
{
	TCCR2 = 0x00;
}
