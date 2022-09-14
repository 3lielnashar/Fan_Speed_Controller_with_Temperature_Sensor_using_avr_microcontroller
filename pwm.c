 /******************************************************************************
 *
 * Module: pwm
 *
 * File Name: pwm.c
 *
 * Description: source file for the AVR pwm driver
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/


#include <avr/io.h>
#include"gpio.h"
#include"pwm.h"


 /*******************************************************************************
 *                              Functions definitions                           *
 *******************************************************************************/
/*
 * Description :
 * initialize timer0 to generate PWM signal in OC0 pin as output signal.
 * it takes the initial value & required clock & mode of operation and
 * the compare value which will store in OCR0 REG
  */

void PWM_timer0init(const CONFIG_PWM *Config_PWM0){
	TCNT0 = (uint8) (Config_PWM0->initial_value); /* loading the initial value to start counting from it */
	OCR0 = (uint8) (Config_PWM0->compare_value);/* loading the compare value in OCR0 register*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT); /* setup the direction of OC0 pin as output */

	/* Configure timer controller register
	 * FOC0 = 0         Fast PWM mode
	 * WGM00 , WGM01    (11) for fast PWM mode
	 * COM0:1           choose the PWM mode (inverting - non_inverting).
	 * CS0:2            choose the suitable prescaler for the frequency.
	 */

	TCCR0 |= (1<<WGM00)|(1<<WGM01);
	TCCR0 = (TCCR0 & 0xF8) | (Config_PWM0->prescaler);
	TCCR0 = (TCCR0 & 0xCF) | ((Config_PWM0->mode)<<4);
}

/*
 * Description :
 * initialize timer1 to start counting by choosing the required mode operation &
 * prescaler & initial value and the compare value if compare mode required
 */

void PWM_timer1init(const CONFIG_PWM* Config_PWM1 ){



}


/*
 * Description :
 * initialize timer2 to generate PWM signal in OC2 pin as output signal.
 * it takes the initial value & required clock & mode of operation and
 * the compare value which will store in OCR2 REG
  */

void PWM_timer2init(const CONFIG_PWM* Config_PWM2 ){


}


/*
 * Description :
 */
void PWM_timer0DeInit(void){

TCCR0 = 0;

}
/*
 * Description :
 */
void PWM_timer1DeInit(void){



}

/*
 * Description :
 */

void PWM_timer2DeInit(void){




}
