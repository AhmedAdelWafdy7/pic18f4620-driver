/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 2:42 AM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

#define Interrupt_Feature_enable                1U
//#define Interrupt_Priority_Levels_Enable            Interrupt_Feature_enable     
#define ADC_interrupt_feature_enable                Interrupt_Feature_enable
#define External_Interrupt_INTx_Feature_Enable      Interrupt_Feature_enable
#define External_Interrupt_OnChange_Feature_Enable  Interrupt_Feature_enable
#define TIMER0_interrupt_feature_enable             Interrupt_Feature_enable
#define TIMER1_interrupt_feature_enable             Interrupt_Feature_enable
#define TIMER2_interrupt_feature_enable             Interrupt_Feature_enable
#define TIMER3_interrupt_feature_enable             Interrupt_Feature_enable
#define CCP1_interrupt_feature_enable               Interrupt_Feature_enable
#define CCP2_interrupt_feature_enable               Interrupt_Feature_enable
#define EUSART_RX_interrupt_feature_enable          Interrupt_Feature_enable
#define EUSART_TX_interrupt_feature_enable          Interrupt_Feature_enable
#define I2C_interrupt_feature_enable          Interrupt_Feature_enable
#define MSSP_SPI_INTERRUPT_FEATURE_ENABLE          Interrupt_Feature_enable

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

