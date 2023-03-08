/* 
 * File:   hal_gpio.h
 * Author: Ahmed Adel
 *
 * Created on September 19, 2022, 6:22 PM
 */

#include "hal_ccp.h"
/* Interrupt handler */
#if CCP1_interrupt_feature_enable == Interrupt_Feature_enable
    static void(* CCP1_InterruptHandler)(void) = NULL;
#endif
#if CCP2_interrupt_feature_enable == Interrupt_Feature_enable
    static void(* CCP2_InterruptHandler)(void) = NULL;
#endif
    
/* Helper fuctions */
static void CCP_Interrupt_Config(const ccp_t *ccp_obj);    
static void CCP_Mode_Timer_Select(const ccp_t *ccp_obj);    
static void CCP_PWM_Config(const ccp_t *ccp_obj);    
static STD_ReturnType CCP_Capture_Config(const ccp_t *ccp_obj);    
static STD_ReturnType CCP_Compare_Config(const ccp_t *ccp_obj);    

void CCP1_ISR(void){
    CCP1_Interrupt_flag_clear();
    if(CCP1_InterruptHandler){
        CCP1_InterruptHandler();
    }
}
void CCP2_ISR(void){
    CCP2_Interrupt_flag_clear();
    if(CCP2_InterruptHandler){
        CCP2_InterruptHandler();
    }
}
/**
 * 
 * @param ccp_obj
 * @return 
 */
STD_ReturnType CCP_Init(const ccp_t *ccp_obj){
   STD_ReturnType ret = E_OK;
   if(NULL == ccp_obj)
   {
       ret = E_NOT_OK;
    }
   else{
        /* CCP Module Disable */
       if(CCP1_INST == ccp_obj->ccp_inst){
           CCP1_SET_MODE(CCP_MODULE_DISABLE);
       }
       else if(CCP2_INST == ccp_obj->ccp_inst){
           CCP2_SET_MODE(CCP_MODULE_DISABLE);
       }
       else{ /* NO thing*/ }
       /* CCP Capture Mode Intialize */
       if(CCP_CAPTURE_MODE_SELECTED == ccp_obj->ccp_mode){
          CCP_Capture_Config(ccp_obj);
       }
       /* CCP Compare Mode Intialize */
       else if(CCP_COMPARE_MODE_SELECTED == ccp_obj->ccp_mode){
           CCP_Compare_Config(ccp_obj);
       }
       /* CCP PWM Mode Intialize */
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)       
       ret = CCP_PWM_Config(ccp_obj);
#endif       
       /* CCP Pin Configration */
       ret = gpio_pin_intialize(&(ccp_obj->ccp_pin));
       /* CCP Interrupt Configration */
       CCP_Interrupt_Config(ccp_obj);
       ret = E_OK;
   }
   return ret;
}
/**
 * 
 * @param ccp_obj
 * @return 
 */
STD_ReturnType CCP_DeInit(const ccp_t *ccp_obj){
   STD_ReturnType ret = E_OK;
   if(NULL == ccp_obj)
   {
       ret = E_NOT_OK;
    }
   else{
        /* CCP Module Disable */
       if(CCP1_INST == ccp_obj->ccp_inst){
           CCP1_SET_MODE(CCP_MODULE_DISABLE);
#if CCP1_interrupt_feature_enable == Interrupt_Feature_enable
           CCP1_Interrupt_disable();
#endif           
       }
       else if(CCP2_INST == ccp_obj->ccp_inst){
           CCP2_SET_MODE(CCP_MODULE_DISABLE);
#if CCP2_interrupt_feature_enable == Interrupt_Feature_enable
           CCP2_Interrupt_disable();
#endif
       }
       else{ /* NO thing*/ }
   }
   return ret;    
}

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED)
STD_ReturnType CCP_Is_CAPTURE_Ready(uint16 *capture_status){
   STD_ReturnType ret = E_OK;
   if(NULL == capture_status)
   {
       ret = E_NOT_OK;
    }
   else{
       if(CCP1_CAPTURE_MODE_READY == PIR1bits.CCP1IF){
           *capture_status = CCP1_CAPTURE_MODE_READY;
           CCP1_Interrupt_flag_clear();
       }
       else{
           *capture_status = CCP1_CAPTURE_MODE_NOT_READY;
       }
       ret = E_OK;
   }
   return ret;
}
STD_ReturnType CCP_CAPTURE_Read_Value(uint16 *capture_value){
   STD_ReturnType ret = E_OK;
   CCP_REG_T capture_temp_value = {.ccpr_low =0,.ccpr_high =0};
   if(NULL == capture_value)
   {
       ret = E_NOT_OK;
    }
   else{
       capture_temp_value.ccpr_low = CCPR1L;
       capture_temp_value.ccpr_high = CCPR1H;
       ret = E_OK;
   }
   return ret;
}
#endif
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED)
STD_ReturnType CCP_Is_COMPARE_Complete(uint8*compare_status){
   STD_ReturnType ret = E_OK;
   if(NULL == compare_status)
   {
       ret = E_NOT_OK;
    }
   else{
       if(CCP1_CAPTURE_MODE_READY == PIR1bits.CCP1IF){
           *compare_status = CCP1_CAPTURE_MODE_READY;
       }
       else{
           *compare_status = CCP1_CAPTURE_MODE_NOT_READY;
       }
       ret = E_OK;
   }
   return ret;
}
STD_ReturnType CCP_COMPARE_Set_Value(const ccp_t *ccp_obj,uint16 compare_value){
   STD_ReturnType ret = E_OK;
   CCP_REG_T capture_temp_value = {.ccpr_low =0,.ccpr_high =0};
   if(NULL == ccp_obj)
   {
       ret = E_NOT_OK;
    }
   else{
       if(CCP1_INST == ccp_obj->ccp_inst){
           CCPR1L = capture_temp_value.ccpr_low;
           CCPR1H = capture_temp_value.ccpr_high;
       }
       else if(CCP2_INST == ccp_obj->ccp_inst){
           CCPR2L = capture_temp_value.ccpr_low;
           CCPR2H = capture_temp_value.ccpr_high;
       }
       else{
           
       }
   }
}
#endif

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)
STD_ReturnType CCP_PWM_Set_duty(const ccp_t *ccp_obj,const uint8 duty){
   STD_ReturnType ret = E_OK;
   uint16 l_duty_temp = 0;
   if(NULL == ccp_obj)
   {
       ret = E_NOT_OK;
    }
   else{
       l_duty_temp = (uint16)(4*(PR2H))*(duty/100);
       if(CCP1_INST == ccp_obj->ccp_inst){
           CCP1CONbits.DC1B = (uint8) (l_duty_temp &0x0003);
           CCPR1L = (uint8) (l_duty_temp >> 2);
       }
       else if(CCP2_INST == ccp_obj->ccp_inst){
           CCP2CONbits.DC2B = (uint8) (l_duty_temp &0x0003);
           CCPR2L = (uint8) (l_duty_temp >> 2);
       }
       else{
           
       }
       ret = E_OK;
   }
   return ret;
}
STD_ReturnType CCP_PWM_Start(const ccp_t *ccp_obj){
   STD_ReturnType ret = E_OK;
   if(NULL == ccp_obj)
   {
       ret = E_NOT_OK;
    }
   else{
       if(CCP1_INST == ccp_obj->ccp_inst){
           CCP1CONbits.CCP1M = CCP_PWM_MODE;
       }
       else if(CCP2_INST == ccp_obj->ccp_inst){
           CCP2CONbits.CCP2M = CCP_PWM_MODE;
       }
       else{
           
       }
       ret = E_OK;
   }
   return ret;
}

STD_ReturnType CCP_PWM_Stop(const ccp_t *ccp_obj){
   STD_ReturnType ret = E_OK;
   if(NULL == ccp_obj)
   {
       ret = E_NOT_OK;
    }
   else{
       if(CCP1_INST == ccp_obj->ccp_inst){
           CCP1CONbits.CCP1M = CCP_MODULE_DISABLE;
       }
       else if(CCP2_INST == ccp_obj->ccp_inst){
           CCP2CONbits.CCP2M = CCP_MODULE_DISABLE;
       }
       else{
           
       }
       ret = E_OK;
   }
   return ret;
}
#endif

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)       
    static void CCP_PWM_Config(const ccp_t *ccp_obj){
       if(CCP1_INST == ccp_obj->ccp_inst){
           if(CCP_PWM_MODE == ccp_obj->ccp_mode){
               CCP1_SET_MODE(CCP_PWM_MODE);
           }
           else{}
       }
       else if(CCP2_INST == ccp_obj->ccp_inst){
           if(CCP_PWM_MODE == ccp_obj->ccp_mode){
               CCP2_SET_MODE(CCP_PWM_MODE);
           }
           else{}
       }
       else{
           
       }    
    /* PWM Frequency Initialization */
       PR2 = (uint8)((_XTAL_FREQ /(ccp_obj->PWM_Frequncy *4.0 *ccp_obj->timer2_prescaler_value * ccp_obj->timer2_postscaler_value))-1);
    }    
#endif
    
static void CCP_Interrupt_Config(const ccp_t *ccp_obj){
    /* CCP1 Interrupt Configuration */
#if CCP1_interrupt_feature_enable == Interrupt_Feature_enable
    CCP1_Interrupt_enable();
    CCP1_Interrupt_flag_clear();
    CCP1_InterruptHandler = ccp_obj->CCP1_InterruptHandler;
    /* Interrupt priority Configuration */
#if Interrupt_Priority_Levels_Enable == Interrupt_Feature_enable
    INTERRUPT_PRIORITY_LEVELS_ENABLE();
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=ccp_obj->priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           CCP1_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==ccp_obj->priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           CCP1_LowPrioritySet();
       }
       else { /* NO THING */ }
#else  
       INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
       INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
#endif

    /* CCP2 Interrupt Configuration */
#if CCP2_interrupt_feature_enable == Interrupt_Feature_enable
    CCP2_Interrupt_enable();
    CCP2_Interrupt_flag_clear();
    CCP2_InterruptHandler = ccp_obj->CCP2_InterruptHandler;
    /* Interrupt priority Configuration */
#if Interrupt_Priority_Levels_Enable == Interrupt_Feature_enable
    INTERRUPT_PRIORITY_LEVELS_ENABLE();
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=ccp_obj->priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           CCP2_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==ccp_obj->priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           CCP2_LowPrioritySet();
       }
       else { /* NO THING */ }
#else  
       INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
       INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
#endif
       
}
   
static void CCP_Mode_Timer_Select(const ccp_t *ccp_obj){
   if(CCP1_CCP2_TIMER3 == ccp_obj->ccp_capture_time){
        /* Timer3 is the capture/compare clock source for the CCP modules */
        T3CONbits.T3CCP1 = 0; 
        T3CONbits.T3CCP2 = 1;
    }
    else if(CCP1_TIMER1_CCP2_TIMER3 == ccp_obj->ccp_capture_time){
        /* Timer3 is the capture/compare clock source for CCP2 */
        /* Timer1 is the capture/compare clock source for CCP1 */
        T3CONbits.T3CCP1 = 1;
        T3CONbits.T3CCP2 = 0;
    }
    else if(CCP1_CCP2_TIMER1 == ccp_obj->ccp_capture_time){
        /* Timer1 is the capture/compare clock source for the CCP modules */
        T3CONbits.T3CCP1 = 0;
        T3CONbits.T3CCP2 = 0;
    }
    else{ /* Nothing */ }
}

static STD_ReturnType CCP_Capture_Config(const ccp_t *ccp_obj){
   STD_ReturnType ret = E_OK;
       if(CCP1_INST == ccp_obj->ccp_inst){
        /* CCP1 Module Capture variants Mode Initialization */
        switch(ccp_obj->ccp_mode_variant){
            case CCP_CAPTURE_MODE_EVERY_FALLING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_EVERY_FALLING_EDGE); break;
            case CCP_CAPTURE_MODE_EVERY_RISING_EDGE  : CCP1_SET_MODE(CCP_CAPTURE_MODE_EVERY_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_EVERY_4_RISING_EDGE  : CCP1_SET_MODE(CCP_CAPTURE_MODE_EVERY_4_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_EVERY_16_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_EVERY_16_RISING_EDGE); break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else if(CCP2_INST == ccp_obj->ccp_inst){
        /* CCP2 Module Capture variants Mode Initialization */
        switch(ccp_obj->ccp_mode_variant){
            case CCP_CAPTURE_MODE_EVERY_FALLING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_EVERY_FALLING_EDGE); break;
            case CCP_CAPTURE_MODE_EVERY_RISING_EDGE  : CCP2_SET_MODE(CCP_CAPTURE_MODE_EVERY_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_EVERY_4_RISING_EDGE  : CCP2_SET_MODE(CCP_CAPTURE_MODE_EVERY_4_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_EVERY_16_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_EVERY_16_RISING_EDGE); break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else{ /* Nothing */ }
   CCP_Mode_Timer_Select(ccp_obj);
   return ret;
}


static STD_ReturnType CCP_Compare_Config(const ccp_t *ccp_obj){
   STD_ReturnType ret = E_OK;
       if(CCP1_INST == ccp_obj->ccp_inst){
        /* CCP1 Module Compare variants Mode Initialization */
        switch(ccp_obj->ccp_mode_variant){
            case CCP_COMPARE_MODE_SET_PIN_LOW      : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);      break;
            case CCP_COMPARE_MODE_SET_PIN_HIGH     : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);     break;
            case CCP_COMPARE_MODE_TOGGLE_ON_MATCH  : CCP1_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);  break;
            case CCP_COMPARE_MODE_GENERATE_SW_INTERRUPT : CCP1_SET_MODE(CCP_COMPARE_MODE_GENERATE_SW_INTERRUPT); break;
            case CCP_COMPARE_MODE_TRIGGER_EVENT        : CCP1_SET_MODE(CCP_COMPARE_MODE_TRIGGER_EVENT);        break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else if(CCP2_INST == ccp_obj->ccp_inst){
        /* CCP1 Module Compare variants Mode Initialization */
        switch(ccp_obj->ccp_mode_variant){
            case CCP_COMPARE_MODE_SET_PIN_LOW      : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);      break;
            case CCP_COMPARE_MODE_SET_PIN_HIGH     : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);     break;
            case CCP_COMPARE_MODE_TOGGLE_ON_MATCH  : CCP2_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);  break;
            case CCP_COMPARE_MODE_GENERATE_SW_INTERRUPT : CCP2_SET_MODE(CCP_COMPARE_MODE_GENERATE_SW_INTERRUPT); break;
            case CCP_COMPARE_MODE_TRIGGER_EVENT        : CCP2_SET_MODE(CCP_COMPARE_MODE_TRIGGER_EVENT);        break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else{ /* Nothing */ }
    
   CCP_Mode_Timer_Select(ccp_obj);
   return ret;
}

