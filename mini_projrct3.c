 /******************************************************************************
 *
 * File Name: mini_project3.c
 *
 * Description: main file for mini project3
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/


#include "adc.h"
#include "lcd.h"
#include "temp_sensor.h"
#include"dc_motor.h"

int main(void)
{

	uint8 temp;
	ADC_ConfigType ADC_Config = { INTERNAL, F_CPU_8 };
	ADC_init(&ADC_Config); /* initialize ADC driver */

	LCD_init(); /* initialize LCD driver */
	DC_MOTOR1_init();/* initialize DC_motor driver */

	/* Display this string "fan is =   C" only once on LCD at the first row */
	LCD_moveCursor(0, 4);
	LCD_displayString("fan is ");
	LCD_moveCursor(1, 4);
	/* Display this string "Temp =   C" only once on LCD at the second row */
	LCD_displayString("Temp =    C");

	while (1) {

		temp = LM35_getTemperature();
		if (temp < 30) {
			LCD_moveCursor(0, 11);
			LCD_displayString("OFF");
			DC_MOTOR1_setDirection(STOP,0);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		} else if (temp >= 30 && temp < 60) {
			LCD_moveCursor(0, 11);
			LCD_displayString("ON ");
			DC_MOTOR1_setDirection(CLOCK_WISE,25);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		} else if (temp >= 60 && temp < 90) {
			LCD_moveCursor(0, 11);
			LCD_displayString("ON ");
			DC_MOTOR1_setDirection(CLOCK_WISE,50);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}
		else if (temp >= 90 && temp < 120) {
			LCD_moveCursor(0, 11);
			LCD_displayString("ON ");
			DC_MOTOR1_setDirection(CLOCK_WISE, 75);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			if(temp<100)
				LCD_displayCharacter(' ');;

		}
		else if(temp >=120){
			LCD_moveCursor(0, 11);
			LCD_displayString("ON ");
			DC_MOTOR1_setDirection(CLOCK_WISE,100);
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
		}
		else{
					/* do nothing */
				}
	}
	return 0;
}
