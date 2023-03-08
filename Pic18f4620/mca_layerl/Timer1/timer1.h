/* 
 * File:   timer1.h
 * Author: Ahmed Adel
 *
 * Created on February 7, 2023, 6:03 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H
/*----------------------- includes ------------------------*/

#include "../GPIO/hal_gpio.h"
#include "../proc/pic18f4620.h"
#include "../../mca_layerl/mcal_std_types.h"
#include "../interrupt/mcal_internal_interrupt.h"
/*------------------------ Macro Declaration --------------------*/

/* Timer or counter */
#define TIMER1_COUNTER_MODE             1
#define TIMER1_TIMER_MODE               0
/* Timer1 external clock input synchronization */
#define TIMER1_ASYNC_COUNTER_MODE       1
#define TIMER1_SYNC_COUNTER_MODE        0
/* Timer1 oscillator */
#define TIMER1_OSCILLATOR_ENABLE        1
#define TIMER1_OSCILLATOR_DISABLE       0
/* TIMER1 input clock prescaler */
#define TIMER1_PRESCALER_DIV_BY_1       0
#define TIMER1_PRESCALER_DIV_BY_2       1
#define TIMER1_PRESCALER_DIV_BY_4       2
#define TIMER1_PRESCALER_DIV_BY_8       3
/* 16-bit mode Read/Write */
#define TIMER1_RW_REG_8BIT_MODE         0
#define TIMER1_RW_REG_16BIT_MODE        1

/*-------------------------Macro Function Declaration ------------------*/

/* Enable or disable Timer1 module */
#define TIMER1_MODULE_ENABLE()                  (T1CONbits.TMR1ON=1)
#define TIMER1_MODULE_DISABLE()                 (T1CONbits.TMR1ON=0)
/* Timer1 clock source  */
#define TIMER1_TIMER_MODE_ENABLE()              (T1CONbits.TMR1CS=0)
#define TIMER1_COUNTER_MODE_ENABLE()            (T1CONbits.TMR1CS=1)
/* Timer1 external clock input synchronization */
#define TIMER1_ASYNC_COUNTER_MODE_ENABLE()      (T1CONbits.T1SYNC=1)       
#define TIMER1_SYNC_COUNTER_MODE_ENABLE()       (T1CONbits.T1SYNC=0)
/* Timer1 oscillator */
#define TIMER1_OSCILLATOR_HW_ENABLE()           (T1CONbits.T1OSCEN=1)      
#define TIMER1_OSCILLATOR_HW_DISABLE()          (T1CONbits.T1OSCEN=0)
/* TIMER1 input clock prescaler */
#define TIMER1_PRESCALER_SELECT(_PRESCALER_)    (T1CONbits.T1CKPS=_PRESCALER_)
/* Timer1 System Clock Status */
#define TIMER1_SYSTEM_CLK_STATUS()              (T1CONbits.T1RUN)
/* 16-bit mode Read/Write */
#define TIMER1_RW_REG_8BIT_MODE_ENABLE()        (T1CONbits.RD16=0)
#define TIMER1_RW_REG_16BIT_MODE_ENABLE()       (T1CONbits.RD16=1)
/*---------------------------Data Types Declaration---------------------------*/
typedef struct{
#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    void(* TMR1_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    uint8 timer1_prescaler_value;
    uint16 timer1_preload_value;
    uint8 timer1_mode : 1;
    uint8 timer1_counter_mode : 1;
    uint8 timer1_osc_cfg : 1;
    uint8 timer1_reg_wr_mode : 1;
    uint8 timer0_reserved : 2;
}timer1_t;
/*-------------------------------software Declaration--------------------------*/
STD_ReturnType Timer1_Init(const timer1_t *_timer);
STD_ReturnType Timer1_DeInit(const timer1_t *_timer);
STD_ReturnType Timer1_Write_Value(const timer1_t *_timer,uint16 _value);
STD_ReturnType Timer1_Read_Value(const timer1_t *_timer,uint16 *_value);

#endif	/* TIMER1_H */

