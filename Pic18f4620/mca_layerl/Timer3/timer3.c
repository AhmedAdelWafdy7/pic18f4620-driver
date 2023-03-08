#include "timer3.h"

#if TIMER3_interrupt_feature_enable==Interrupt_Feature_enable
static void (*TMR3_InterruptHandler)(void)=NULL;
#endif

static uint16 timer3_preload=0;
static inline void Timer3_Mode_select(const timer3_t *_timer);

void TMR3_ISR(void){
    TIMER1_Interrupt_flag_clear();
    TMR3H=(timer3_preload)>>8;
    TMR3L=(uint8)(timer3_preload);
    if(TMR3_InterruptHandler){
        TMR3_InterruptHandler();
    }
}


/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer3_Init(const timer3_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER3_MODULE_DISABLE();
       TIMER3_PRESCALER_SELECT(_timer->timer3_prescaler_value);
       Timer3_Mode_select(_timer);
       TMR3H=(_timer->timer3_preload_value)>>8;
       TMR3L=(uint8)(_timer->timer3_preload_value);
       timer3_preload = _timer->timer3_preload_value;
       /* interrupt configurations */
#if TIMER3_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER3_Interrupt_enable();
       TIMER3_Interrupt_flag_clear();
       TMR3_InterruptHandler=_timer->TMR3_InterruptHandler;
       /* Interrupt priority configurations */
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=_timer->priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           TIMER3_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==_timer->priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           TIMER3_LowPrioritySet();
       }
       else { /* NO THING */ }
#else
       INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
       INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
#endif
       TIMER3_MODULE_ENABLE();
       ret = E_OK;
   }
   return ret;    
}
/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer3_DeInit(const timer3_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER3_MODULE_DISABLE();
#if TIMER3_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER3_Interrupt_disable();
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
STD_ReturnType Timer3_Write_Value(const timer3_t *_timer,uint16 _value){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TMR3H=(_value)>>8;
       TMR3L= (uint8)(_value);
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
STD_ReturnType Timer3_Read_Value(const timer3_t *_timer,uint16 *_value){
   STD_ReturnType ret = E_OK;
   uint8 l_tmr3l=0,l_tmr3h=0;
   if(NULL == _timer || NULL== _value)
   {
       ret = E_NOT_OK;
    
   }
   else{
       l_tmr3l=TMR3L;
       l_tmr3h=TMR3H;
       *_value=(uint16)(l_tmr3h<<8)+(l_tmr3l);
       ret = E_OK;
   }
   return ret;    
}

static inline void Timer3_Mode_select(const timer3_t *_timer){
    if(TIMER3_TIMER_MODE == _timer->timer3_mode){
        TIMER3_TIMER_MODE_ENABLE();
    }
    else if(TIMER3_COUNTER_MODE == _timer->timer3_mode){
        TIMER3_COUNTER_MODE_ENABLE();
        if(TIMER3_ASYNC_COUNTER_MODE == _timer->timer3_counter_mode){
            TIMER3_ASYNC_COUNTER_MODE_ENABLE();
        }
        else if(TIMER3_SYNC_COUNTER_MODE == _timer->timer3_counter_mode){
            TIMER3_SYNC_COUNTER_MODE_ENABLE();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }    
}
