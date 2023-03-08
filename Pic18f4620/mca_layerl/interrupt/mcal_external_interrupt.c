
#include "mcal_external_interrupt.h"

static void (*INT0_InterruptHandler)(void) = NULL;
static void (*INT1_InterruptHandler)(void) = NULL;
static void (*INT2_InterruptHandler)(void) = NULL;

static void (*RB4_InterruptHandler_HIGH)(void) = NULL;
static void (*RB4_InterruptHandler_LOW)(void) = NULL;
static void (*RB5_InterruptHandler_HIGH)(void) = NULL;
static void (*RB5_InterruptHandler_LOW)(void) = NULL;
static void (*RB6_InterruptHandler_HIGH)(void) = NULL;
static void (*RB6_InterruptHandler_LOW)(void) = NULL;
static void (*RB7_InterruptHandler_HIGH)(void) = NULL;
static void (*RB7_InterruptHandler_LOW)(void) = NULL;


static STD_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);

static STD_ReturnType INT0_SetInterruptHandler(void(*InterruptHandler)(void));
static STD_ReturnType INT1_SetInterruptHandler(void(*InterruptHandler)(void));
static STD_ReturnType INT2_SetInterruptHandler(void(*InterruptHandler)(void));
static STD_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);

static STD_ReturnType Interrupt_RBx_Enable(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_RBx_Disable(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_RBx_Priority_Init(const interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_RBx_Pin_Init(const interrupt_INTx_t *int_obj);

void INT0_ISR(void){
/* INT0 External Interrupt occurred flag must be cleared */    
    External_Int0_InterruptFlagClear();
    
/* Application CallBack to get call every time this ISR executes  */    
    if(INT0_InterruptHandler){INT0_InterruptHandler();}
    else{/* NO THING */}
}
void INT1_ISR(void){
/* INT1 External Interrupt occurred flag must be cleared */        
    External_Int0_InterruptFlagClear();
    
/* Application CallBack to get call every time this ISR executes  */        
    if(INT1_InterruptHandler){INT1_InterruptHandler();}
    else{/* NO THING */}
}void INT2_ISR(void){
/* INT2 External Interrupt occurred flag must be cleared */    
    
    External_Int2_InterruptFlagClear();
    
/* Application CallBack to get call every time this ISR executes  */        
    if(INT2_InterruptHandler){INT2_InterruptHandler();}
    else{/* NO THING */}
}

void RB4_ISR(uint8 source){
/* RB4 External Interrupt occurred flag must be cleared */    
    
    External_RBx_InterruptFlagClear();
    
/* Application CallBack to get call every time this ISR executes  */        
    if(0== source){
        if(RB4_InterruptHandler_HIGH){RB4_InterruptHandler_HIGH();}
        else { /* NOTHING*/ }    
    }
    else if(1== source){
        if(RB4_InterruptHandler_LOW){RB4_InterruptHandler_LOW();}    
        else { /* NOTHING*/ }
    
    }
    else { /* NOTHING*/ }
}

void RB5_ISR(uint8 source){
/* RB4 External Interrupt occurred flag must be cleared */    
    
    External_RBx_InterruptFlagClear();
    
/* Application CallBack to get call every time this ISR executes  */        
    if(0== source){
        if(RB5_InterruptHandler_HIGH){RB5_InterruptHandler_HIGH();}
        else { /* NOTHING*/ }    
    }
    else if(1== source){
        if(RB5_InterruptHandler_LOW){RB5_InterruptHandler_LOW();}    
        else { /* NOTHING*/ }
    
    }
    else { /* NOTHING*/ }
}


void RB6_ISR(uint8 source){
/* RB4 External Interrupt occurred flag must be cleared */    
    
    External_RBx_InterruptFlagClear();
    
/* Application CallBack to get call every time this ISR executes  */        
    if(0== source){
        if(RB6_InterruptHandler_HIGH){RB6_InterruptHandler_HIGH();}
        else { /* NOTHING*/ }    
    }
    else if(1== source){
        if(RB6_InterruptHandler_LOW){RB6_InterruptHandler_LOW();}    
        else { /* NOTHING*/ }
    
    }
    else { /* NOTHING*/ }
}

void RB7_ISR(uint8 source){
/* RB4 External Interrupt occurred flag must be cleared */    
    
    External_RBx_InterruptFlagClear();
    
/* Application CallBack to get call every time this ISR executes  */        
    if(0== source){
        if(RB7_InterruptHandler_HIGH){RB7_InterruptHandler_HIGH();}
        else { /* NOTHING*/ }    
    }
    else if(1== source){
        if(RB7_InterruptHandler_LOW){RB7_InterruptHandler_LOW();}    
        else { /* NOTHING*/ }
    
    }
    else { /* NOTHING*/ }
}

/**
 * 
 * @param int_obj
 * @return 
 */
STD_ReturnType Interrupt_INTx_init(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        /* Disable External Interrupt */
        ret = Interrupt_INTx_Disable(int_obj);
        /* Clear flag for External Interrupt */
        ret = Interrupt_INTx_Clear_Flag(int_obj);
        /* Configure External Interrupt edge */
        ret = Interrupt_INTx_Edge_Init(int_obj);
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable        
        /* Configure External Interrupt Priority */
        ret = Interrupt_INTx_Priority_Init(int_obj);
#endif        
        /* Configure External Interrupt I/O Pin */
        ret = Interrupt_INTx_Pin_Init(int_obj);
        /* Configure Default Interrupt CallBack */
        ret = Interrupt_INTx_SetInterruptHandler(int_obj);
        /* enable External Interrupt */
        ret = Interrupt_INTx_Enable(int_obj);
        
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
STD_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        ret = Interrupt_INTx_Disable(int_obj);
    }
    return ret;

}
/**
 * 
 * @param int_obj
 * @return 
 */
STD_ReturnType Interrupt_RBx_init(const interrupt_RBx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        /* Clear the interrupt enable for external interrupt ,RBx */
        External_RBx_InterruptDisable();
        /* Clear the interrupt flag for external interrupt ,RBx */
        External_RBx_InterruptFlagClear();

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
    INTERRUPT_PRIORITY_LEVELS_ENABLE();
    if(INERRUPT_LOW_PRIORITY== int_obj->priority){
        INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
        /* Set RBx External Interrupt Priority to Low Priority */
        External_RBx_LowPrioritySet();
    }
    else if(INERRUPT_HIGH_PRIORITY== int_obj->priority){
        INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
        /* Set RBx External Interrupt Priority to High Priority */
        External_RBx_HighPrioritySet();
    }
    else{/* NO THING */}
#else
            INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif        
            /* initialize the RBx pin to be input */
            ret = gpio_pin_intialize(&(int_obj->mcu_pins));
            /* Initialize the CallBack function*/
            switch(int_obj->mcu_pins.pin){
                case pin4:
                    RB4_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                    RB4_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                    break;
                case pin5:
                    RB5_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                    RB5_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                    break;
                case pin6:
                    RB6_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                    RB6_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;                    break;
                case pin7:
                    RB7_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                    RB7_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;                    break;
                default: ret = E_NOT_OK;    
            }
        /* Set the interrupt enable for external interrupt ,RBx */
        External_RBx_InterruptEnable();
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
STD_ReturnType Interrupt_Rbx_DeInit(const interrupt_RBx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
    
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static STD_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 :
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
            INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
#else
            INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
            External_Int0_InterruptEnable();
            ret = E_OK;
            break;

            case INTERRUPT_EXTERNAL_INT1 :
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
                INTERRUPT_PRIORITY_LEVELS_ENABLE();
                if(INERRUPT_LOW_PRIORITY== int_obj->priority){
                    INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
                }
                else if(INERRUPT_HIGH_PRIORITY== int_obj->priority){
                    INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
                }
                else{/* NO THING */}
#else
            INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
            External_Int1_InterruptEnable();
            ret = E_OK;
            break;            

            case INTERRUPT_EXTERNAL_INT2 :
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
                INTERRUPT_PRIORITY_LEVELS_ENABLE();
                if(INERRUPT_LOW_PRIORITY== int_obj->priority){
                    INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
                }
                else if(INERRUPT_HIGH_PRIORITY== int_obj->priority){
                    INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
                }
                else{/* NO THING */}
#else
            INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
            External_Int2_InterruptEnable();
            ret = E_OK;
            break;            
        default: ret = E_NOT_OK;

        }
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static STD_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0:
                External_Int0_InterruptDisable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                External_Int1_InterruptDisable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                External_Int2_InterruptDisable();
                ret = E_OK;
                break;                
            }
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static STD_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        switch(int_obj->source){
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

            case INTERRUPT_EXTERNAL_INT1 :
                if(int_obj->priority == INERRUPT_LOW_PRIORITY){External_Int1_LowPrioritySet();}
                else if (int_obj->priority == INERRUPT_HIGH_PRIORITY){External_Int1_HighPrioritySet();}
                else { /* No Thing*/}
                ret = E_OK;
                break;                
            case INTERRUPT_EXTERNAL_INT2 :
                if(int_obj->priority == INERRUPT_LOW_PRIORITY){External_Int2_LowPrioritySet();}
                else if (int_obj->priority == INERRUPT_HIGH_PRIORITY){External_Int2_HighPrioritySet();}
                else { /* No Thing*/}
                ret = E_OK;
                break;
#endif
            default : ret = E_NOT_OK;     
        }
    }
    return ret;

}
/**
 * 
 * @param int_obj
 * @return 
 */
static STD_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0:
                if(INTERRUPT_FALLING_EDGE==int_obj->edge){
                    External_Int0_FallingEdgeSet();
                }
                else if(INTERRUPT_RISING_EDGE==int_obj->edge){
                    External_Int0_RisingEdgeSet();
                }
                else{/*  NO THING  */}
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                if(INTERRUPT_FALLING_EDGE==int_obj->edge){
                    External_Int1_FallingEdgeSet();
                }
                else if(INTERRUPT_RISING_EDGE==int_obj->edge){
                    External_Int1_RisingEdgeSet();
                }
                else{/*  NO THING  */}
                ret = E_OK;
                break; 
            case INTERRUPT_EXTERNAL_INT2:
                if(INTERRUPT_FALLING_EDGE==int_obj->edge){
                    External_Int2_FallingEdgeSet();
                }
                else if(INTERRUPT_RISING_EDGE==int_obj->edge){
                    External_Int2_RisingEdgeSet();
                }
                else{/*  NO THING  */}
                ret = E_OK;
                break;                
            default: ret = E_NOT_OK;    
        }    
    }
    return ret;

}
/**
 * 
 * @param int_obj
 * @return 
 */
static STD_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pins));
    }
    return ret;

}
/**
 * 
 * @param int_obj
 * @return 
 */
static STD_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0:
                External_Int0_InterruptFlagClear();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                External_Int1_InterruptFlagClear();
                ret = E_OK;
                break;                
            case INTERRUPT_EXTERNAL_INT2:
                External_Int2_InterruptFlagClear();
                ret = E_OK;
                break;        
            default: ret = E_NOT_OK;
        }
    }
    return ret;

}
/**
 * 
 * @param InterruptHandler
 * @return 
 */
static STD_ReturnType INT0_SetInterruptHandler(void(*InterruptHandler)(void)){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == InterruptHandler){
        ret =E_NOT_OK;
    }
    else{
        INT0_InterruptHandler=InterruptHandler;
        ret = E_OK;
    }
    return ret;

}
/**
 * 
 * @param InterruptHandler
 * @return 
 */
static STD_ReturnType INT1_SetInterruptHandler(void(*InterruptHandler)(void)){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == InterruptHandler){
        ret =E_NOT_OK;
    }
    else{
        INT1_InterruptHandler=InterruptHandler;
        ret = E_OK;    
    }
    return ret;

}
/**
 * 
 * @param InterruptHandler
 * @return 
 */
static STD_ReturnType INT2_SetInterruptHandler(void(*InterruptHandler)(void)){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == InterruptHandler){
        ret =E_NOT_OK;
    }
    else{
        INT2_InterruptHandler=InterruptHandler;
        ret = E_OK;    
    }
    return ret;

}
/**
 * 
 * @param int_obj
 * @return 
 */
static STD_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == int_obj){
        ret =E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0:
                ret = INT0_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1:
                ret = INT1_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
        
            case INTERRUPT_EXTERNAL_INT2:
                ret = INT2_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            default : ret = E_NOT_OK;   
        }   
    }
    return ret;
}
