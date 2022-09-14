 /******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: DC_MOTOR.h
 *
 * Description: header file for the AVR DC_MOTOR driver
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/

/*******************************************************************************
 *                              Definitions                        *
 *******************************************************************************/


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"std_types.h"
#define MOTOR1_ON
#define MOTOR2_OFF
#ifdef MOTOR1_ON
#define IN1_PORT  PORTB_ID
#define IN1_PIN  PIN0_ID
#define IN2_PORT  PORTB_ID
#define IN2_PIN  PIN1_ID
#endif

#ifdef MOTOR2_ON
#define IN3_PORT  PORTB_ID
#define IN3_PIN  PIN2_ID
#define IN4_PORT  PORTC_ID
#define IN4_PIN  PIN3_ID

#endif
/*******************************************************************************
 *                            Types Declaration                    *
 *******************************************************************************/

typedef enum {
	STOP, CLOCK_WISE, ANTI_CLOCK_WISE
} Motor_Direction;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

#ifdef MOTOR1_ON
void DC_MOTOR1_init(void);
void DC_MOTOR1_setDirection(const Motor_Direction direction1,uint8 speed);
void DC_MOTOR1_deinit(void);
#endif
#ifdef MOTOR2_ON
void DC_MOTOR2_init(void);
void DC_MOTOR2_setDirection(const Motor_Direction direction2,uint8 speed);
void DC_MOTOR2_deinit(void)
#endif


#endif /* DC_MOTOR_H_ */
