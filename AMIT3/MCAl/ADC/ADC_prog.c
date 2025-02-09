#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "ADC_priv.h"
#include "ADC_int.h"



void ADC_voidInit(){


	SET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADPS0);
	SET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADPS1);
	SET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADPS2);

//	select ADC Reference
//	AVCC ,, AREF , 2.56
//	choose AVCC
	SET_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS0);
	CLR_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS1);

//	enable ADC
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN);
}

u16 ADC_u16StartConversion(u8 Copy_u8ChannelID)
{
//	select channel
	if(Copy_u8ChannelID <= 0b00011111)
	{
		ADC_ADMUX_REG &= ADC_PRESCALER_MASK;
		ADC_ADMUX_REG |= Copy_u8ChannelID;
	}

//	start conversion
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC);

//	wait on flag
	while(GET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADIF) == 0);

//	clear flag
	SET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADIF);
//	set ADIF

//	retrun ADC data reg
	return ADC_ADC_REG;

}
