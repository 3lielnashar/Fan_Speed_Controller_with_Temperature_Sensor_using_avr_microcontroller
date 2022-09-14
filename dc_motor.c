 /******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: DC_MOTOR.c
 *
 * Description: Source file for the AVR DC_MOTOR driver
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/

#include"gpio.h"
#include"dc_motor.h"
#include "pwm.h"
#ifdef MOTOR1_ON
void DC_MOTOR1_init(void)
{
	GPIO_setupPinDirection(IN1_PORT, IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(IN2_PORT, IN2_PIN, PIN_OUTPUT);
	GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
	GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
}
void DC_MOTOR1_setDirection(const Motor_Direction direction1,uint8 speed) {
    speed = 2.55 * speed;
    CONFIG_PWM Config_PWM0 = {speed, NON_INVERTING , F_CPU8 ,0};
    PWM_timer0init(&Config_PWM0);
	if (direction1 == STOP) {
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
	} else if (direction1 == CLOCK_WISE) {
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
	} else {
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_HIGH);
	}

}
void DC_MOTOR1_deinit(void){

	PWM_timer0DeInit();

}
#endif
#ifdef MOTOR2_ON
void DC_MOTOR2_init(void)
{
	GPIO_setupPinDirection(IN3_PORT,IN3_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(IN4_PORT,IN4_PIN,PIN_OUTPUT);
	GPIO_writePin(IN3_PORT, IN3_PIN, LOGIC_LOW);
	GPIO_writePin(IN4_PORT, IN4_PIN, LOGIC_LOW);
}
void DC_MOTOR2_setDirection(const Motor_Direction direction2, uint8 speed){

	if (direction2 == STOP) {
		GPIO_writePin(IN3_PORT, IN3_PIN, LOGIC_LOW);
			GPIO_writePin(IN4_PORT, IN4_PIN, LOGIC_LOW);
	} else if (direction2 == CLOCK_WISE) {
		GPIO_writePin(IN3_PORT, IN3_PIN, LOGIC_HIGH);
			GPIO_writePin(IN4_PORT, IN4_PIN, LOGIC_LOW);
	} else {
		GPIO_writePin(IN3_PORT, IN3_PIN, LOGIC_LOW);
			GPIO_writePin(IN4_PORT, IN4_PIN, LOGIC_HIGH);
	}

}
#endif
