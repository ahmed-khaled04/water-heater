
#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

/*
$07 ($27) ADMUX  REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0 214
$06 ($26) ADCSRA ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0 216
$05 ($25) ADCH   ADC Data Register High Byte 217
$04 ($24) ADCL   ADC Data Register Low Byte 217
*/

#define ADC_ADMUX_REG       *((volatile u8*)(0x27))

#define ADC_ADMUX_REFS1      7
#define ADC_ADMUX_REFS0      6
#define ADC_ADMUX_ADLAR      5


#define ADC_ADCSRA_REG      *((volatile u8*)(0x26))

#define ADC_ADCSRA_ADEN      7
#define ADC_ADCSRA_ADSC      6
#define ADC_ADCSRA_ADATE     5
#define ADC_ADCSRA_ADIF      4
#define ADC_ADCSRA_ADIE      3
#define ADC_ADCSRA_ADPS2     2
#define ADC_ADCSRA_ADPS1     1
#define ADC_ADCSRA_ADPS0     0


#define ADC_ADCL_REG        *((volatile u8*)(0x24))
#define ADC_ADCH_REG        *((volatile u8*)(0x25))


#define ADC_ADC_REG         *((volatile u16*)(0x24))

#define ADC_PRESCALER_MASK	0b11100000



#endif /* MCAL_ADC_ADC_PRIV_H_ */
