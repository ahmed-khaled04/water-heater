/*
 * EXTI_int.h
 *
 *  Created on: 6 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

void EXTI_EnableINT0(void);
void EXTI_EnableINT1(void);
void EXTI_EnableINT2(void);

void EXTI_DisableINT0(void);
void EXTI_DisableINT1(void);
void EXTI_DisableINT2(void);

void EXTI_InitINT0();
void EXTI_InitINT1();
void EXTI_InitINT2();

void EXTI_voidChangeSenseControl(u8 Copy_u8IntNum , u8 Copy_u8Sensenum);
void EXTI_voidSetINT0_Callback(void (*pf)(void));
void EXTI_voidSetINT1_Callback(void (*pf)(void));
void EXTI_voidSetINT2_Callback(void (*pf)(void));



#endif /* MCAL_EXTI_EXTI_INT_H_ */
