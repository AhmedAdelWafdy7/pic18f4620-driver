/* 
 * File:   hal_ccp.h
 * Author: Ahmed Adel
 *
 * Created on February 19, 2023, 8:25 PM
 */
#ifndef HAL_CCP_H
#define	HAL_CCP_H
/*----------------------- includes ------------------------*/

#include "../GPIO/hal_gpio.h"
#include "../proc/pic18f4620.h"
#include "../../mca_layerl/mcal_std_types.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "ccp_cfg.h"
/*------------------------ Macro Declaration --------------------*/

/* CCP module mode select */
#define CCP_MODULE_DISABLE                          ((uint8)0x00)
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH            ((uint8)0x02)
#define CCP_CAPTURE_MODE_EVERY_FALLING_EDGE         ((uint8)0x04)
#define CCP_CAPTURE_MODE_EVERY_RISING_EDGE          ((uint8)0x05)
#define CCP_CAPTURE_MODE_EVERY_4_RISING_EDGE        ((uint8)0x06)
#define CCP_CAPTURE_MODE_EVERY_16_RISING_EDGE       ((uint8)0x07)
#define CCP_COMPARE_MODE_SET_PIN_LOW                ((uint8)0x08)
#define CCP_COMPARE_MODE_SET_PIN_HIGH               ((uint8)0x09)
#define CCP_COMPARE_MODE_GENERATE_SW_INTERRUPT      ((uint8)0x0A)
#define CCP_COMPARE_MODE_TRIGGER_EVENT              ((uint8)0x0B)
#define CCP_PWM_MODE                                ((uint8)0x0C)

/* CCP1 capture mode state */
#define CCP1_CAPTURE_MODE_READY                     0x01
#define CCP1_CAPTURE_MODE_NOT_READY                 0x00

/* CCP1 compare mode state */
#define CCP1_CAPTURE_MODE_READY                     0x01
#define CCP1_CAPTURE_MODE_NOT_READY                 0x00

/* Timer2 Input Clock Post-scaler */
#define CCP_TIMER2_POSTSCALER_DIV_BY_1       1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2       2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3       3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4       4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5       5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6       6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7       7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8       8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9       9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10      10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11      11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12      12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13      13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14      14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15      15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16      16

/* Timer2 Input Clock Pre-scaler */
#define CCP_TIMER2_PRESCALER_DIV_BY_1        1
#define CCP_TIMER2_PRESCALER_DIV_BY_4        4
#define CCP_TIMER2_PRESCALER_DIV_BY_16       16
/*-------------------------Macro Function Declaration ------------------*/

/* Set the CCP1 Mode Variant */
#define CCP1_SET_MODE(_CONFIG)  (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG)  (CCP2CONbits.CCP2M = _CONFIG)
/*---------------------------Data Types Declaration---------------------------*/
typedef enum{
    CCP_CAPTURE_MODE_SELECTED = 0,
    CCP_COMPARE_MODE_SELECTED,
    CCP_PWM_MODE_SELECTED        
}ccp1_mode_t;

typedef union{
    struct{
        uint8 ccpr_low;
        uint8 ccpr_high;
    };
    struct{
        uint8 ccpr_16Bit;
    };
}CCP_REG_T;
typedef enum{
    CCP1_INST = 0,
    CCP2_INST        
}ccp_inst_t;

typedef enum{
    CCP1_CCP2_TIMER3 = 0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1
}ccp_capture_timer_t;

typedef struct{
    ccp_inst_t ccp_inst;
    ccp1_mode_t ccp_mode;
    uint8 ccp_mode_variant;
    pin_config_t    ccp_pin;
    ccp_capture_timer_t ccp_capture_time;
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)
    uint32 PWM_Frequncy;
    uint8 timer2_postscaler_value : 4;
    uint8 timer2_prescaler_value : 2;
    
#endif
#if CCP1_interrupt_feature_enable == Interrupt_Feature_enable
    void(* CCP1_InterruptHandler)(void);
    interrupt_priority_cfg CCP1_priority;
#endif 
#if CCP2_interrupt_feature_enable == Interrupt_Feature_enable
    void(* CCP2_InterruptHandler)(void);
    interrupt_priority_cfg CCP2_priority;
#endif     
}ccp_t;
/*-------------------------------software Declaration--------------------------*/
STD_ReturnType CCP_Init(const ccp_t *ccp_obj);
STD_ReturnType CCP_DeInit(const ccp_t *ccp_obj);
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)
STD_ReturnType CCP_PWM_Set_duty(const ccp_t *ccp_obj,const uint8 duty);
STD_ReturnType CCP_PWM_Start(const ccp_t *ccp_obj);
STD_ReturnType CCP_PWM_Stop(const ccp_t *ccp_obj);
#endif
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED)
STD_ReturnType CCP_Is_COMPARE_Complete(uint8*compare_status);
STD_ReturnType CCP_COMPARE_Set_Value(const ccp_t *ccp_obj,uint16 compare_value);
#endif
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED)
STD_ReturnType CCP_Is_CAPTURE_Ready(uint16 *capture_status);
STD_ReturnType CCP_CAPTURE_Read_Value(uint16 *capture_value);
#endif

#endif	/* HAL_CCP_H */

