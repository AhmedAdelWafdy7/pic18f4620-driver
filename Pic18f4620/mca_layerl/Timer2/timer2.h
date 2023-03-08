/* 
 * File:   timer2.h
 * Author: Ahmed Adel
 *
 * Created on February 8, 2023, 3:04 AM
 */

#ifndef TIMER2_H
#define	TIMER2_H
/*----------------------- includes ------------------------*/

#include "../GPIO/hal_gpio.h"
#include "../proc/pic18f4620.h"
#include "../../mca_layerl/mcal_std_types.h"
#include "../interrupt/mcal_internal_interrupt.h"
/*------------------------ Macro Declaration --------------------*/
/* Timer2 input clock post scaler  */
#define TIMER2_POSTSCALER_DIV_BY_1       0
#define TIMER2_POSTSCALER_DIV_BY_2       1
#define TIMER2_POSTSCALER_DIV_BY_3       2
#define TIMER2_POSTSCALER_DIV_BY_4       3
#define TIMER2_POSTSCALER_DIV_BY_5       4
#define TIMER2_POSTSCALER_DIV_BY_6       5
#define TIMER2_POSTSCALER_DIV_BY_7       6
#define TIMER2_POSTSCALER_DIV_BY_8       7
#define TIMER2_POSTSCALER_DIV_BY_9       8
#define TIMER2_POSTSCALER_DIV_BY_10      9
#define TIMER2_POSTSCALER_DIV_BY_11      10
#define TIMER2_POSTSCALER_DIV_BY_12      11
#define TIMER2_POSTSCALER_DIV_BY_13      12
#define TIMER2_POSTSCALER_DIV_BY_14      13
#define TIMER2_POSTSCALER_DIV_BY_15      14
#define TIMER2_POSTSCALER_DIV_BY_16      15
/* Timer2 Input Clock Pre-scaler */
#define TIMER2_PRESCALER_DIV_BY_1        0
#define TIMER2_PRESCALER_DIV_BY_4        1
#define TIMER2_PRESCALER_DIV_BY_16       2
/*-------------------------Macro Function Declaration ------------------*/
/* Enable or Disable Timer1 Module */
#define TIMER2_MODULE_ENABLE()              (T2CONbits.TMR2ON = 1)
#define TIMER2_MODULE_DISABLE()             (T2CONbits.TMR2ON = 0)

/* Timer2 Input Clock Post-scaler */
#define TIMER2_PRESCALER_SELECT(_PRESCALER_) (T2CONbits.T2CKPS = _PRESCALER_)

/* Timer2 Input Clock Post-scaler */
#define TIMER2_POSTSCALER_SELECT(_POSTSCALER_) (T2CONbits.TOUTPS = _POSTSCALER_)

/*---------------------------Data Types Declaration---------------------------*/
typedef struct{
#if TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    void (* TMR2_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    uint8 timer2_preload_value;
    uint8 timer2_postscaler_value;
    uint8 timer2_prescaler_value;
}timer2_t;
/*-------------------------------software Declaration--------------------------*/
STD_ReturnType Timer2_Init(const timer2_t *_timer);
STD_ReturnType Timer2_DeInit(const timer2_t *_timer);
STD_ReturnType Timer2_Write_Value(const timer2_t *_timer,uint16 _value);
STD_ReturnType Timer2_Read_Value(const timer2_t *_timer,uint16 *_value);

#endif	/* TIMER2_H */

