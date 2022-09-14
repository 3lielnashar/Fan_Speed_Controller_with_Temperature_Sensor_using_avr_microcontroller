 /******************************************************************************
 *
 * Module: pwm
 *
 * File Name: pwm.hc
 *
 * Description: header file for the AVR pwm driver
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{

NON_INVERTING =2 , INVERTING =3

}PWM_MODE_OF_OPERATION;

typedef enum{

F_CPU_1=1,F_CPU8,F_CPU64,F_CPU256,F_CPU1024

}CLOCK_PRESCALER;

typedef struct{
	uint16 compare_value;
	PWM_MODE_OF_OPERATION mode;
    CLOCK_PRESCALER prescaler;
    uint16 initial_value;

}CONFIG_PWM;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * initialize timer0 to generate PWM signal in OC0 pin as output signal.
 * it takes the initial value & required clock & mode of operation and
 * the compare value which will store in OCR0 REG
  */

void PWM_timer0init(const CONFIG_PWM* Config_PWM0 );

/*
 * Description :
 * initialize timer1 to start counting by choosing the required mode operation &
 * prescaler & initial value and the compare value if compare mode required
 */

void PWM_timer1init(const CONFIG_PWM* Config_PWM1 );


/*
 * Description :
 * initialize timer2 to generate PWM signal in OC2 pin as output signal.
 * it takes the initial value & required clock & mode of operation and
 * the compare value which will store in OCR2 REG
  */

void PWM_timer2init(const CONFIG_PWM* Config_PWM2 );


/*
 * Description :
 */
void PWM_timer0DeInit(void);
/*
 * Description :
 */
void PWM_timer1DeInit(void);

/*
 * Description :
 */

void PWM_timer2DeInit(void);

#endif /* PWM_H_ */
