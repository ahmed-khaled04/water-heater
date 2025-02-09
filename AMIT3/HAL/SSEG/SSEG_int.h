
#ifndef HAL_SSEG_SSEG_INT_H_
#define HAL_SSEG_SSEG_INT_H_

typedef struct {
	u8 SSEG_u8DataPort ;
	u8 SSEG_u8DataPinarr[4];
	u8 SSEG_u8EnPort;
	u8 SSEG_u8EnPin;
}SSEG_t;

void SSEG_voidEnable(SSEG_t * Copy_u8Seg);
void SSEG_voidDisable(SSEG_t * Copy_u8Seg);
void SSEG_voidWirteNum(u8 Copy_u8num , SSEG_t * Copy_u8Seg);
void SSEG_voidWriteOnTwo(u8 Copy_u8num , SSEG_t * Copy_u8Seg1 , SSEG_t * Copy_u8Seg2);
u8 intToBCD(u8 num);
#endif /* HAL_SSEG_SSEG_INT_H_ */
