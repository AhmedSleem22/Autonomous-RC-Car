/*******************************************************************************
 *
 * File Name: timer2.c
 *
 * Description: Header file for the timer2 driver
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	NORMAL, PWM_PHASE_CORRECT, COMPAER, FAST_PWM, COMPAER1, PWM_PHASE_CORRECT1=11, FAST_PWM1=14
}Timer_Mode;

typedef enum
{
	NON_INVERTING = 2, INVERTING
}Timer_State;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Timer_Clock;

typedef struct
{
	Timer_Mode mode;
	Timer_State state;
	Timer_Clock clock;
}Timer_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 *                      		     TIMER 0                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the Timer0 driver.
 */
void Timer0_init(const Timer_ConfigType* );

/*
 * Description :
 * Function responsible for Set Duty cycle value  for Timer0.
 */
void Timer0_duty_cycle( uint32 );

/*
 * Description :
 * Function responsible for Set compare value  for Timer0.
 */
void Timer0_compare_value( uint32 OC_value);
/*
 * Description :
 * Function responsible for De-initialize the Timer0 driver.
 */
void Timer0_deinit();

/*******************************************************************************
 *                      		     TIMER 1                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the Timer0 driver.
 */
void Timer1_init(const Timer_ConfigType* );

/*
 * Description :
 * Function responsible for Set Duty cycle value  for Timer0.
 */
void Timer1_duty_cycle( uint32, uint32 );

/*
 * Description :
 * Function responsible for Set compare value  for Timer0.
 */
void Timer1_compare_value( uint32 OC_value);
/*
 * Description :
 * Function responsible for De-initialize the Timer0 driver.
 */
void Timer1_deinit();


/*******************************************************************************
 *                      		     TIMER 2                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the Timer2 driver.
 */
void Timer2_init(const Timer_ConfigType* );

/*
 * Description :
 * Function responsible for Set Duty cycle value  for Timer2.
 */
void Timer2_duty_cycle( uint8 );

/*
 * Description :
 * Function responsible for Set compare value  for Timer2.
 */
void Timer2_compare_value( uint8 OC_value);
/*
 * Description :
 * Function responsible for De-initialize the Timer2 driver.
 */
void Timer2_deinit();

#endif /* TIMER_H_ */
