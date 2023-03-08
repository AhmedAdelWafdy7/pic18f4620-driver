/* 
 * File:   mcal_internal_interrupt.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 3:02 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/*---------------------includes-------------------------*/

#include "mcal_interrupt_config.h"

/*------------------Function Declaration------------------------*/
#if ADC_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for ADC interrupt */
#define ADC_Interrupt_disable()         (PIE1bits.ADIE=0)

/* Set the interrupt enable for ADC interrupt */
#define ADC_Interrupt_enable()          (PIE1bits.ADIE=1)

/* Clear the interrupt flag for ADC interrupt */
#define ADC_Interrupt_flag_clear()      (PIR1bits.ADIF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set ADC Interrupt Priority to be High Priority */
#define ADC_HighPrioritySet()           (IPR1bits.ADIP=1)

/* Set ADC Interrupt Priority to be Low Priority */
#define ADC_LowPrioritySet()           (IPR1bits.ADIP=10)

#endif

#endif

#if TIMER0_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for ADC interrupt */
#define TIMER0_Interrupt_disable()         (INTCONbits.TMR0IE=0)

/* Set the interrupt enable for ADC interrupt */
#define TIMER0_Interrupt_enable()          (INTCONbits.TMR0IE=1)

/* Clear the interrupt flag for ADC interrupt */
#define TIMER0_Interrupt_flag_clear()      (INTCONbits.TMR0IF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set TIMER0 Interrupt Priority to be High Priority */
#define TIMER0_HighPrioritySet()           (INTCON2bits.TMR0IP=1)

/* Set Timer0 Interrupt Priority to be Low Priority */
#define TIMER0_LowPrioritySet()           (INTCON2bits.TMR0IP=0)

#endif

#endif


#if TIMER1_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for TIMER1 interrupt */
#define TIMER1_Interrupt_disable()         (PIE1bits.TMR1IE=0)

/* Set the interrupt enable for TIMER1 interrupt */
#define TIMER1_Interrupt_enable()          (PIE1bits.TMR1IE=1)

/* Clear the interrupt flag for TIMER1 interrupt */
#define TIMER1_Interrupt_flag_clear()      (PIR1bits.TMR1IF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set TIMER1 Interrupt Priority to be High Priority */
#define TIMER1_HighPrioritySet()           (IPR1bits.TMR1IP=1)

/* Set TIMER1 Interrupt Priority to be Low Priority */
#define TIMER1_LowPrioritySet()           (IPR1bits.TMR1IP=0)

#endif

#endif

#if TIMER1_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for TIMER2 interrupt */
#define TIMER2_Interrupt_disable()         (PIE1bits.TMR2IE=0)

/* Set the interrupt enable for TIMER2 interrupt */
#define TIMER2_Interrupt_enable()          (PIE1bits.TMR2IE=1)

/* Clear the interrupt flag for TIMER2 interrupt */
#define TIMER2_Interrupt_flag_clear()      (PIR1bits.TMR2IF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set TIMER2 Interrupt Priority to be High Priority */
#define TIMER2_HighPrioritySet()           (IPR1bits.TMR2IP=1)

/* Set TIMER2 Interrupt Priority to be Low Priority */
#define TIMER2_LowPrioritySet()           (IPR1bits.TMR2IP=0)

#endif

#endif


#if TIMER3_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for TIMER3 interrupt */
#define TIMER3_Interrupt_disable()         (PIE2bits.TMR3IE=0)

/* Set the interrupt enable for TIMER3 interrupt */
#define TIMER3_Interrupt_enable()          (PIE2bits.TMR3IE=1)

/* Clear the interrupt flag for TIMER3 interrupt */
#define TIMER3_Interrupt_flag_clear()      (PIR2bits.TMR3IF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set TIMER3 Interrupt Priority to be High Priority */
#define TIMER3_HighPrioritySet()           (IPR2bits.TMR3IP=1)

/* Set TIMER2 Interrupt Priority to be Low Priority */
#define TIMER3_LowPrioritySet()           (IPR2bits.TMR3IP=0)

#endif

#endif

#if CCP1_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for CCP1 interrupt */
#define CCP1_Interrupt_disable()         (PIE1bits.CCP1IE=0)

/* Set the interrupt enable for CCP1 interrupt */
#define CCP1_Interrupt_enable()          (PIE1bits.CCP1IE=1)

/* Clear the interrupt flag for CCP1 interrupt */
#define CCP1_Interrupt_flag_clear()      (PIR1bits.CCP1IF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set CCP1 Interrupt Priority to be High Priority */
#define CCP1_HighPrioritySet()           (IPR1bits.CCP1IP=1)

/* Set CCP1 Interrupt Priority to be Low Priority */
#define CCP1_LowPrioritySet()           (IPR1bits.CCP1IP=0)

#endif

#endif

#if CCP2_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for CCP2 interrupt */
#define CCP2_Interrupt_disable()         (PIE2bits.CCP2IE=0)

/* Set the interrupt enable for CCP2 interrupt */
#define CCP2_Interrupt_enable()          (PIE2bits.CCP2IE=1)

/* Clear the interrupt flag for CCP2 interrupt */
#define CCP2_Interrupt_flag_clear()      (PIR2bits.CCP2IF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set CCP2 Interrupt Priority to be High Priority */
#define CCP2_HighPrioritySet()           (IPR2bits.CCP2IP=1)

/* Set CCP2 Interrupt Priority to be Low Priority */
#define CCP2_LowPrioritySet()           (IPR2bits.CCP2IP=0)

#endif

#endif



#if EUSART_TX_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for EUSART_TX interrupt */
#define EUSART_TX_Interrupt_disable()         (PIE1bits.TXIE=0)

/* Set the interrupt enable for EUSART_TX interrupt */
#define EUSART_TX_Interrupt_enable()          (PIE1bits.TXIE=1)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set EUSART_TX Interrupt Priority to be High Priority */
#define EUSART_TX_HighPrioritySet()           (IPR1bits.TXIP=1)

/* Set EUSART_TX Interrupt Priority to be Low Priority */
#define EUSART_TX_LowPrioritySet()           (IPR1bits.TXIP=0)

#endif
#endif



#if EUSART_RX_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for EUSART_RX interrupt */
#define EUSART_RX_Interrupt_disable()         (PIE1bits.RCIE=0)

/* Set the interrupt enable for EUSART_RX interrupt */
#define EUSART_RX_Interrupt_enable()          (PIE1bits.RCIE=1)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set EUSART_RX Interrupt Priority to be High Priority */
#define EUSART_RX_HighPrioritySet()           (IPR1bits.RCIP=1)

/* Set EUSART_RX Interrupt Priority to be Low Priority */
#define EUSART_RX_LowPrioritySet()           (IPR1bits.RCIP=0)

#endif
#endif

#if I2C_interrupt_feature_enable==Interrupt_Feature_enable

/* Clear the interrupt enable for I2C interrupt */
#define I2C_Interrupt_disable()         (PIE1bits.SSPIE=0)
#define I2C_BUS_COL_Interrupt_disable()         (PIE2bits.BCLIE=0)

/* Set the interrupt enable for I2C interrupt */
#define I2C_Interrupt_enable()          (PIE1bits.SSPIE=1)
#define I2C_BUS_COL_Interrupt_enable()         (PIE2bits.BCLIE=1)
/* Clear the interrupt flag for I2C interrupt */
#define I2C_Interrupt_flag_clear()      (PIR1bits.SSPIF=0)
#define I2C_BUS_COL_Interrupt_flag_clear()         (PIR2bits.BCLIF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set I2C Interrupt Priority to be High Priority */
#define I2C_HighPrioritySet()           (IPR1bits.SSPIP=1)
#define I2C_BUS_COL_HighPrioritySet()           (IPR2bits.BCLIP=1)

/* Set I2C Interrupt Priority to be Low Priority */
#define I2C_LowPrioritySet()           (IPR1bits.SSPIP=0)
#define I2C_BUS_COL_LowPrioritySet()           (IPR2bits.BCLIP=0)

#endif
#endif

#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE==Interrupt_Feature_enable

/* Clear the interrupt enable for MSSP_SPI interrupt */
#define MSSP_SPI_Interrupt_disable()         (PIE1bits.SSPIE=0)

/* Set the interrupt enable for MSSP_SPI interrupt */
#define MSSP_SPI_Interrupt_enable()          (PIE1bits.SSPIE=1)

/* Clear the interrupt flag for MSSP_SPI interrupt */
#define MSSP_SPI_Interrupt_flag_clear()      (PIR1bits.SSPIF=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set MSSP_SPI Interrupt Priority to be High Priority */
#define MSSP_SPI_HighPrioritySet()           (IPR1bits.SSPIP=1)

/* Set MSSP_SPI Interrupt Priority to be Low Priority */
#define MSSP_SPI_LowPrioritySet()           (IPR1bits.SSPIP=0)

#endif

#endif
/*------------------DataTypes Declaration------------------------*/
/*----------------------------------SoftWareInterface--------------------*/
#endif	/* MCAL_INTERNAL_INTERRUPT_H */

