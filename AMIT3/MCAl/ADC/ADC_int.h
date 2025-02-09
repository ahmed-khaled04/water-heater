/*
 * ADC_int.h
 *
 *  Created on: 7 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define ADC_U8_CHANNEL_0       0
#define ADC_U8_CHANNEL_1       1
#define ADC_U8_CHANNEL_2       2
#define ADC_U8_CHANNEL_3       3
#define ADC_U8_CHANNEL_4       4
#define ADC_U8_CHANNEL_5       5
#define ADC_U8_CHANNEL_6       6
#define ADC_U8_CHANNEL_7       7


void ADC_voidInit();

u16 ADC_u16StartConversion(u8 Copy_u8ChannelID);

#endif /* MCAL_ADC_ADC_INT_H_ */
