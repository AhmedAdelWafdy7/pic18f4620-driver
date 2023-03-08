#include "timer2.h"

#if TIMER2_interrupt_feature_enable==Interrupt_Feature_enable
static void (*TMR2_InterruptHandler)(void)=NULL;
#endif

static uint16 timer2_preload=0;

void TMR2_ISR(void){
    TIMER2_Interrupt_flag_clear();
    TMR2 = timer2_preload;
    if(TMR2_InterruptHandler){
        TMR2_InterruptHandler();
    }
}
/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer2_Init(const timer2_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER2_MODULE_DISABLE();
       TIMER2_PRESCALER_SELECT(_timer->timer2_prescaler_value);
       TMR2 = _timer->timer2_preload_value;
       timer2_preload = _timer->timer2_preload_value;
       /* interrupt configurations */
#if TIMER2_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER2_Interrupt_enable();
       TIMER2_Interrupt_flag_clear();
       TMR2_InterruptHandler=_timer->TMR2_InterruptHandler;
       /* Interrupt priority configurations */
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=_timer->priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           TIMER2_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==_timer->priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           TIMER2_LowPrioritySet();
       }
       else { /* NO THING */ }
#else
       INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
       INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
#endif
       TIMER2_MODULE_ENABLE();
       ret = E_OK;
   }
   return ret;


}
/**
 * 
 * @param _timer
 * @return 
 */
STD_ReturnType Timer2_DeInit(const timer2_t *_timer){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TIMER2_MODULE_DISABLE();
#if TIMER2_interrupt_feature_enable==Interrupt_Feature_enable
       TIMER2_Interrupt_disable();
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
STD_ReturnType Timer2_Write_Value(const timer2_t *_timer,uint16 _value){
   STD_ReturnType ret = E_OK;
    
   if(NULL == _timer)
   {
       ret = E_NOT_OK;
    
   }
   else{
       TMR2 = _value;
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
STD_ReturnType Timer2_Read_Value(const timer2_t *_timer,uint16 *_value){
   STD_ReturnType ret = E_OK;
   if(NULL == _timer || NULL== _value)
   {
       ret = E_NOT_OK;
    
   }
   else{

       *_value = TMR2;
       ret = E_OK;
   }
   return ret;

}
