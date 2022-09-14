 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/
#include <avr/io.h> /* To use the ADC Registers */ /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#ifdef ADC_OPERATING_METHOD_INTERRUPT
 #include <avr/interrupt.h> /* For ADC ISR */
#include <util/delay.h> /* For the delay functions */
 volatile uint16 g_adcResult=0;
#endif
/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
#ifdef ADC_OPERATING_METHOD_INTERRUPT
ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;

}
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	/* ADMUX Register Bits Description:
	 * REFS1:0  to insert the voltage reference selection to REFS pins
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->REFS) << 6);
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 */
	ADCSRA|=(1<<ADEN);
#ifdef ADC_OPERATING_METHOD_POLLING
	{
	/* ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0  choose ADC_Clock ADC must operate in range 50-200Khz
	 */
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->Prescaler);
	}
#else
	{
		/* ADIE    = 1 Enable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADPS2:0  choose ADC_Clock ADC must operate in range 50-200Khz
		 */
		SREG|=(1<<7);
		ADCSRA |= (1 << ADIE);
		ADCSRA = (ADCSRA & 0XF8) | ((Config_Ptr->Prescaler)&0x07);
	}

#endif
}
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
/* for POLLING method */
#ifdef ADC_OPERATING_METHOD_POLLING
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xE0) | (channel_num); /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
/* for INTERRUPT method */
#else
void ADC_readChannel(const ADC_MUX_PIN channel_num) {
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07); /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
	_delay_ms(5);
}
#endif
