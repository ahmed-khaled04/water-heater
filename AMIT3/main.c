#define F_CPU 16000000UL
#include "util/delay.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include"Service/STD_types.h"
#include"Service/bit_math.h"
#include"MCAl/DIO/DIO_int.h"
#include"MCAl/PORT/PORT_int.h"
#include"MCAl/GIE/GIE_int.h"
#include"MCAl/EXTI/EXTI_int.h"
#include "HAL/CLCD/CLCD_int.h"
#include "HAL/KPAD/KPAD_int.h"
#include "HAL/SSEG/SSEG_int.h"
#include "MCAL/ADC/ADC_int.h"

void Cooling_element();
void turn_Off_Cooling_Element();
void turn_On_Heating_Element();
void turn_On_Cooling_Element();
u16 get_Temperature();



int main()
{
	PORT_voidInit();
	ADC_voidInit();

	u8 datapins1[4] = {DIO_PIN0 , 1 , 2 , 3};
	u8 datapins2[] = {4 , 5 , 6 , 7};

	SSEG_t seg1;
	seg1.SSEG_u8DataPinarr[0] = datapins1[0];
	seg1.SSEG_u8DataPinarr[1] = datapins1[1];
	seg1.SSEG_u8DataPinarr[2] = datapins1[2];
	seg1.SSEG_u8DataPinarr[3] = datapins1[3];
	seg1.SSEG_u8DataPort = 3;
	seg1.SSEG_u8EnPin = 0;
	seg1.SSEG_u8EnPort = 0;
	SSEG_t seg2;
	seg2.SSEG_u8DataPinarr[0] = datapins2[0];
	seg2.SSEG_u8DataPinarr[1] = datapins2[1];
	seg2.SSEG_u8DataPinarr[2] = datapins2[2];
	seg2.SSEG_u8DataPinarr[3] = datapins2[3];
	seg2.SSEG_u8DataPort = 3;
	seg2.SSEG_u8EnPin = 0;
	seg2.SSEG_u8EnPort = 0;
	GIE_voidEnableGlobalInterrupt();
	u8 u8num=0;
	u8num = intToBCD(u8num);
	int i = 0;
	int temp = 60;
	int temp_sen = 65;
	int counter = 1;
	int enable = 1;
	while(1)
	{
			temp_sen =get_Temperature() *4.37/10;
			SSEG_voidWriteOnTwo(temp, &seg1, &seg2);
			if(counter == 1)
			{
			if(temp + 4 > temp_sen)
			{
				turn_On_Heating_Element();
				turn_Off_Cooling_Element();
			}
			if(temp < temp_sen + 4)
			{
				turn_On_Cooling_Element();
				turn_Off_Heating_Element();
			}
			counter =1;
			}
			if(DIO_u8GetPinValue(1,1) == 1)
			{
				counter = 1;
				temp++;
				if(temp > 99)
					temp=45;
				_delay_ms(20);
			}
			if(DIO_u8GetPinValue(0,5) == 1)
			{
				_delay_ms(25);
				counter = 1;
				temp--;
			}
			if(DIO_u8GetPinValue(0,7) == 1)
			{
				turn_Off_Cooling_Element();
				turn_Off_Heating_Element();
				_delay_ms(25);
				while(enable == 1)
				{
					turn_Off_Cooling_Element();
					turn_Off_Heating_Element();
					if(DIO_u8GetPinValue(0,7) == 1)
					{
						_delay_ms(25);
						enable = 0;
						break;
					}
				}
				counter = 1;
				enable = 1;
			}



	}

}
void turn_Off_Cooling_Element()
{
	DIO_voidSetPinVlaue(1,0,0);
}
void turn_Off_Heating_Element()
{
	DIO_voidSetPinVlaue(2,0,0);
}
void turn_On_Heating_Element()
{
	DIO_voidSetPinVlaue(2,0,1);
}
void turn_On_Cooling_Element()
{
	DIO_voidSetPinVlaue(1,0,1);
}
u16 get_Temperature()
{
	return (ADC_u16StartConversion(1));
}






