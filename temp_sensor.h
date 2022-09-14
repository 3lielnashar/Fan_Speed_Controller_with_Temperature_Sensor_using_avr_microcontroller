 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: temp_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Ali Elnashar
 *
 *******************************************************************************/

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         PIN_2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* TEMP_SENSOR_H_ */
