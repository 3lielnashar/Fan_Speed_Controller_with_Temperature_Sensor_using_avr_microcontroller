 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: header file for the AVR ADC driver
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_reference_selection;

typedef enum
{
	F_CPU_2 = 1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_prescaler;

typedef struct
{
	ADC_reference_selection REFS;
	ADC_prescaler Prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define ADC_OPERATING_METHOD_POLLING
#ifdef ADC_OPERATING_METHOD_INTERRUPT
extern volatile uint16 g_adcResult;
#endif

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

#ifdef ADC_OPERATING_METHOD_POLLING
/* for POLLING method */
uint16 ADC_readChannel(uint8 channel_num);
#else
/* for INTERRUPT method */
void ADC_readChannel(const ADC_MUX_PIN channel_num);
#endif

#endif /* ADC_H_ */
