#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
#include "SSEG_int.h"


void SSEG_voidEnable(SSEG_t * Copy_u8Seg){
	DIO_voidSetPinVlaue(Copy_u8Seg->SSEG_u8EnPort ,Copy_u8Seg->SSEG_u8EnPin , DIO_PIN_HIGH);
}
void SSEG_voidDisable(SSEG_t * Copy_u8Seg){
	DIO_voidSetPinVlaue(Copy_u8Seg->SSEG_u8EnPort ,Copy_u8Seg->SSEG_u8EnPin , DIO_PIN_LOW);

}
void SSEG_voidWirteNum(u8 Copy_u8num , SSEG_t * Copy_u8Seg){
	for(u8 i = 0 ; i< 4 ; i++)
	{

		DIO_voidSetPinVlaue(Copy_u8Seg->SSEG_u8DataPort , Copy_u8Seg->SSEG_u8DataPinarr[i] , GET_BIT(Copy_u8num , i));
	}
}

void SSEG_voidWriteOnTwo(u8 Copy_u8num , SSEG_t * Copy_u8Seg1 , SSEG_t * Copy_u8Seg2){
	Copy_u8num = intToBCD(Copy_u8num);
	SSEG_voidWirteNum((Copy_u8num & 0x0F) , Copy_u8Seg2);
	SSEG_voidWirteNum((Copy_u8num >> 4) , Copy_u8Seg1);

}


u8 intToBCD(u8 num) {
    if (num > 99) return 0;  // Ensure it's within the valid range (0-99)

    u8 tens = (num / 10) << 4;  // Shift the tens digit to the upper 4 bits
    u8 ones = num % 10;         // Keep the ones digit in the lower 4 bits

    return (tens | ones); // Combine both into a single BCD byte
}


