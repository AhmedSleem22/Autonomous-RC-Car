/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_Motor.h
 *
 * Description: Header file for the DC motor
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Interfacing HW Description*/
#define DCMOTOR_DDR 	DDRC
#define DCMOTOR_PORT  PORTC

#define FORWARD 	PC0
#define REVERSE 	PC1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the motor driver.
 */
void DCMOTOR_init( uint8 );
/*
 * Description :
 * Function responsible for set the direction of the motor [clockwise or anti-clockwise].
 */
void DCMOTOR_direction(uint8 , uint8);
/*
 * Description :
 * Function responsible for de-initialize the motor driver.
 */
void DCMOTOR_deinit();

#endif /* DC_MOTOR_H_ */
