#include "timer1.h"
#if TIMER1_interrupt_feature_enable==Interrupt_Feature_enable
static void (*TMR1_InterruptHandler)(void)=NULL;
#endif

static uint16 timer1_preload=0;
static inline void Timer1_Mode_select(const timer1_t *_timer);

void TMR1_ISR(void){
    TIMER1_Interrupt_flag_clear();
    TMR1H=(timer1_preload)>>8;
    TMR1L=(uint8)(timer1_preload);
    if(TMR1_InterruptHandler){
        TMR1_InterruptHandler();
    }
}
/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer1_Init(const timer1_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER1_MODULE_DISABLE();
       TIMER1_PRESCALER_SELECT(_timer->timer1_prescaler_value);
       Timer1_Mode_select(_timer);
       TMR1H=(_timer->timer1_preload_value)>>8;
       TMR1L=(uint8)(_timer->timer1_preload_value);
       timer1_preload = _timer->TMR1_InterruptHandler;
       /* interrupt configurations */
#if TIMER1_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER1_Interrupt_enable();
       TIMER1_Interrupt_flag_clear();
       TMR1_InterruptHandler=_timer->TMR1_InterruptHandler;
       /* Interrupt priority configurations */
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=_timer->priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           TIMER1_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==_timer->priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           TIMER1_LowPrioritySet();
       }
       else { /* NO THING */ }
#else 
       INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
       INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
       
#endif
       TIMER1_MODULE_ENABLE();
       ret = E_OK;
   }
   return ret;

}
/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer1_DeInit(const timer1_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER1_MODULE_DISABLE();
#if TIMER1_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER1_Interrupt_disable();
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
STD_ReturnType Timer1_Write_Value(const timer1_t *_timer,uint16 _value){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TMR1H=(_value)>>8;
       TMR1L= (uint8)(_value);
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
STD_ReturnType Timer1_Read_Value(const timer1_t *_timer,uint16 *_value){
   STD_ReturnType ret = E_OK;
   uint8 l_tmr1l=0,l_tmr1h=0;
   if(NULL == _timer || NULL== _value)
   {
       ret = E_NOT_OK;
    
   }
   else{
       l_tmr1l=TMR1L;
       l_tmr1h=TMR1H;
       *_value=(uint16)(l_tmr1h<<8)+(l_tmr1l);
       ret = E_OK;
   }
   return ret;

}

static inline void Timer1_Mode_select(const timer1_t *_timer){
    if(TIMER1_TIMER_MODE == _timer->timer1_mode){
        TIMER1_TIMER_MODE_ENABLE();
    }
    else if(TIMER1_COUNTER_MODE ==_timer->timer1_mode){
        if(TIMER1_ASYNC_COUNTER_MODE== _timer->timer1_counter_mode){
            TIMER1_ASYNC_COUNTER_MODE_ENABLE();
        }
        else if (TIMER1_SYNC_COUNTER_MODE== _timer->timer1_counter_mode){
            TIMER1_SYNC_COUNTER_MODE_ENABLE();
        }
        else{ /* NO THING */ }
    }
    else{ /* NO THING */ }
}
