/******************************************************************************
 *
 * Module: Servo Motor
 *
 * File Name: Servo_Motor.h
 *
 * Description: Header file for the Servo motor
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/

#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
#include "Timer.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Interfacing HW Description*/
#define SERVOMOTOR_DDR 	DDRD
#define SERVOMOTOR_PORT  PORTD

#define RIGHT 	PD0
#define LEFT 	PD1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the motor driver.
 */
void SERVOMOTOR_init( uint8 );
/*
 * Description :
 * Function responsible for set the direction of the motor [clockwise or anti-clockwise].
 */
void SERVOMOTOR_direction( uint8 , uint8 );
/*
 * Description :
 * Function responsible for de-initialize the motor driver.
 */
void SERVOMOTOR_deinit();

#endif /* SERVO_MOTOR_H_ */
