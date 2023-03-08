#include "timer0.h"
#if TIMER0_interrupt_feature_enable==Interrupt_Feature_enable
static void (*TMR0_InterruptHandler)(void)=NULL;
#endif

static uint16 timer0_preload=0;

static inline void Timer0_Register_Size_Config(const timer0_t *_timer);
static inline void Timer0_Prescaler_Config(const timer0_t *_timer);
static inline void Timer0_Mode_select(const timer0_t *_timer);

void TMR0_ISR(void){
    TIMER0_Interrupt_flag_clear();
    TMR0H=(timer0_preload)>>8;
    TMR0L=(uint8)(timer0_preload);
    if(TMR0_InterruptHandler){
        TMR0_InterruptHandler();
    }
}
/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer0_Init(const timer0_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER0_MODULE_DISABLE();
       Timer0_Prescaler_Config(_timer);
       Timer0_Mode_select(_timer);
       Timer0_Register_Size_Config(_timer);
       TMR0H=(_timer->timer0_preload_value)>>8;
       TMR0L=(uint8)(_timer->timer0_preload_value);
       timer0_preload = _timer->TMR0_InterruptHandler;
       /* interrupt configurations */
#if TIMER0_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER0_Interrupt_enable();
       TIMER0_Interrupt_flag_clear();
       TMR0_InterruptHandler=_timer->TMR0_InterruptHandler;
       /* Interrupt priority configurations */
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=_timer->priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           TIMER0_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==_timer->priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           TIMER0_LowPrioritySet();
       }
       else { /* NO THING */ }
#endif
#endif
       TIMER0_MODULE_ENABLE();
       ret = E_OK;
   }
   return ret;
}
/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer0_DeInit(const timer0_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER0_MODULE_DISABLE();
#if TIMER0_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER0_Interrupt_disable();
#endif       
       ret = E_OK;
   }
   return ret;
}
/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
STD_ReturnType Timer0_Write_Value(const timer0_t *_timer,uint16 _value){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TMR0H=(_value)>>8;
       TMR0L= (uint8)(_value);
       ret = E_OK;
   }
   return ret;
}
/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
STD_ReturnType Timer0_Read_Value(const timer0_t *_timer,uint16 *_value){
   STD_ReturnType ret = E_OK;
   uint8 l_tmr0l=0,l_tmr0h=0;
   if(NULL == _timer || NULL== _value)
   {
       ret = E_NOT_OK;
    
   }
   else{
       l_tmr0l=TMR0L;
       l_tmr0h=TMR0H;
       *_value=(uint16)(l_tmr0h<<8)+(l_tmr0l);
       ret = E_OK;
   }
   return ret;
}

/**
 * 
 * @param _timer
 */
static inline void Timer0_Register_Size_Config(const timer0_t *_timer){
    if(TIMER0_8BIT_REGISTER_MODE==_timer->timer0_register_size){
        TIMER0_8BIT_REGISTER_MODE_ENABLE();
    }
    else if(TIMER0_16BIT_REGISTER_MODE==_timer->timer0_register_size){
        TIMER0_16BIT_REGISTER_MODE_ENABLE();
    }
    else {/* NO THING */}
}
/**
 * 
 * @param _timer
 */
static inline void Timer0_Prescaler_Config(const timer0_t *_timer){
    if(TIMER0_PRESCALER_ENABLE_CFG==_timer->prescaler_enable){
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS=_timer->prescaler_value;
    }
    else if(TIMER0_PRESCALER_DISABLE_CFG==_timer->prescaler_enable){
        TIMER0_PRESCALER_DISABLE();
    }
    else { /* NO THING */ }
}
/**
 * 
 * @param _timer
 */
static inline void Timer0_Mode_select(const timer0_t *_timer){
    if(TIMER0_TIMER_MODE == _timer->timer0_mode){
        TIMER0_TIMER_MODE_ENABLE();
    }
    else if(TIMER0_COUNTER_MODE ==_timer->timer0_mode){
        TIMER0_COUNTER_MODE_ENABLE();
        if(TIMER0_COUNTER_RISING_EDGE_CFG== _timer->timer0_counter_edge){
            TIMER0_RISING_EDGE_ENABLE();
        }
        else if (TIMER0_COUNTER_FALLING_EDGE_CFG== _timer->timer0_counter_edge){
            TIMER0_FALLING_EDGE_ENABLE();
        }
        else{ /* NO THING */ }
    }
    else{ /* NO THING */ }
}