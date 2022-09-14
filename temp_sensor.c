 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "temp_sensor.h"

#include "adc.h"
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
#ifdef ADC_OPERATING_METHOD_INTERRUPT
	{// INTERRUPT_METHOD
		ADC_readChannel(SENSOR_CHANNEL_ID);
		adc_value = g_adcResult;
	}
#else // POLLING METHOD
     adc_value =ADC_readChannel(2);
#endif
	/* Calculate the temperature from the ADC value*/
	temp_value =
			(uint8) (((uint32) adc_value * SENSOR_MAX_TEMPERATURE
					* ADC_REF_VOLT_VALUE)
					/ (ADC_MAXIMUM_VALUE * SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}


