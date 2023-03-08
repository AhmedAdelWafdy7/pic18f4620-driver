/* 
 * File:   mcal_interrupt_manager.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 2:44 AM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* -------------------includes----------------------*/
#include "mcal_interrupt_config.h"
/* ------------------------Macro Declaration------------------ */
/* ------------------------Macro Function Declaration--------- */
/*--------------------------Data Types Declaration------------ */
/* --------------------------Software Declaration------------- */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 source);
void RB5_ISR(uint8 source);
void RB6_ISR(uint8 source);
void RB7_ISR(uint8 source);
void ADC_ISR(void);
void TMR0_ISR(void);
void TMR1_ISR(void);
void TMR2_ISR(void);
void TMR3_ISR(void);
void CCP1_ISR(void);
void CCP2_ISR(void);
void EUSART_TX_ISR(void);
void EUSART_RX_ISR(void);
void I2C_ISR(void);
void I2C_BC_ISR(void);
void MSSP_SPI_ISR(void);


#endif	/* MCAL_INTERRUPT_MANAGER_H */

