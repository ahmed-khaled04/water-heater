/*
 * EXTI_priv.h
 *
 *  Created on: 6 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_
/*
$3B ($5B) GICR   INT1 INT0 INT2 – – – IVSEL IVCE 47, 67
$3A ($5A) GIFR   INTF1 INTF0 INTF2 – – – – – 68
$35 ($55) MCUCR  SE SM2 SM1 SM0 ISC11 ISC10 ISC01 ISC00 32, 66
$34 ($54) MCUCSR JTD ISC2 – JTRF WDRF BORF EXTRF PORF 40, 67, 228*/


#define EXTI_GICR_REG       *((volatile u8 *)(0x5b))

#define EXTI_GICR_INT1     7
#define EXTI_GICR_INT0     6
#define EXTI_GICR_INT2     5

#define EXTI_GIFR_REG      *((volatile u8 *)(0x5a))

#define EXTI_GIFR_INTF1   7
#define EXTI_GIFR_INTF0   6
#define EXTI_GIFR_INTF2   5

#define EXTI_MCUCR_REG     *((volatile u8 *)(0x55))

#define EXTI_MCUCR_ISC00   0
#define EXTI_MCUCR_ISC01   1
#define EXTI_MCUCR_ISC10   2
#define EXTI_MCUCR_ISC11   3

#define EXTI_MCUCSR_REG    *((volatile u8 *)(0x54))

#define EXTI_MCUCSR_ISC2   6


 #define  EXTI_RISIG_EDGE     0
 #define  EXTI_FALLING_EDGE   1
 #define  EXTI_ANY_CHANGE     2
 #define  EXTI_LOW_LEVEL      3



#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
