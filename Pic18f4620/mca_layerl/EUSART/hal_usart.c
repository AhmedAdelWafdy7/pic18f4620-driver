#include "hal_usart.h"

#if EUSART_TX_interrupt_feature_enable == Interrupt_Feature_enable
	void (*EUSART_TxInterruptHandler)(void) = NULL;
#endif

#if EUSART_RX_interrupt_feature_enable == Interrupt_Feature_enable
    void (*EUSART_RxInterruptHandler)(void) = NULL;
    void (*EUSART_FramingErrorHandler)(void) = NULL;
    void (*EUSART_OverrunErrorHandler)(void) = NULL;
#endif    
void EUSART_TX_ISR(void){
    EUSART_TX_Interrupt_disable();
    if(EUSART_TxInterruptHandler){
        EUSART_TxInterruptHandler();
    }
    else{
    }
}
void EUSART_RX_ISR(void){
        if(EUSART_RxInterruptHandler){
        EUSART_RxInterruptHandler();
    }
    else{
    }    if(EUSART_FramingErrorHandler){
        EUSART_FramingErrorHandler();
    }
    else{
    }    if(EUSART_OverrunErrorHandler){
        EUSART_OverrunErrorHandler();
    }
    else{
    }
}

/* Helper function */
static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart);
static void EUSART_ASYNC_TX_Init(const usart_t *_eusart);
static void EUSART_ASYNC_RX_Init(const usart_t *_eusart);
/**
 * 
 * @param usart
 * @return 
 */
STD_ReturnType EUSART_ASYNC_Init(const usart_t *eusart ){
   STD_ReturnType ret = E_OK;
    
   if(NULL == eusart)
   {
       ret = E_NOT_OK;
   }
   else{
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE; /* Disable EUSART Module */
       TRISCbits.RC7 = 1;                 
       TRISCbits.RC6 = 1;
       EUSART_Baud_Rate_Calculation(eusart);
       EUSART_ASYNC_TX_Init(eusart);
       EUSART_ASYNC_RX_Init(eusart);
       RCSTAbits.SPEN = EUSART_MODULE_ENABLE;  /* Enable EUSART Module */
       ret = E_OK;
   }   
   return ret;
}
/**
 * 
 * @param usart
 * @return 
 */
STD_ReturnType EUSART_ASYNC_DeInit(const usart_t *eusart ){
   STD_ReturnType ret = E_OK;
    
   if(NULL == eusart)
   {
       ret = E_NOT_OK;
   }
   else{
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE; /* Disable EUSART Module */
       ret = E_OK;
   }
      return ret;
}
/**
 * 
 * @param usart
 * @return 
 */
STD_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *data){
   STD_ReturnType ret = E_OK;
   while(!PIR1bits.RCIF);
   *data = RCREG;
   return ret;
}
/**
 * 
 * @param usart
 * @return 
 */
STD_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *data){
   STD_ReturnType ret = E_OK;
   if(1 == PIR1bits.RCIF){
    *data = RCREG;
    ret = E_OK;
   }
   else{
       ret = E_NOT_OK;
   }
   return ret;
}
/**
 * 
 * @return 
 */
STD_ReturnType EUSART_ASYNC_Rx_Restart(void){
    STD_ReturnType ret = E_OK;
    RCSTAbits.CREN = 0; /* Disables receiver */
    RCSTAbits.CREN = 1; /* Enables receiver */
    return ret;
}
/**
 * 
 * @param data
 * @return 
 */
STD_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 data){
    STD_ReturnType ret = E_OK;
    while(!TXSTAbits.TRMT);
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    EUSART_TX_Interrupt_enable();
#endif
    TXREG = data;
    return ret;
}
/**
 * 
 * @param data
 * @param str_len
 * @return 
 */
STD_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *data,uint16 str_len){
    STD_ReturnType ret = E_OK;
    uint16 char_counter = 0;
    for(char_counter=0; char_counter < str_len; char_counter++){
        ret = EUSART_ASYNC_WriteByteBlocking(data[char_counter]);
    }
    return ret;
}


static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart){
   float Baud_Rate_Temp=0;
   switch(_eusart->baudrate_gen_gonfig){
        case BAUDRATE_ASYN_8BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 64) - 1;
            break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_8BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_16BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        default : ;
    }
    SPBRG = (uint8)((uint32)Baud_Rate_Temp);
    SPBRGH = (uint8)(((uint32)Baud_Rate_Temp) >> 8);   
}

static void EUSART_ASYNC_TX_Init(const usart_t *_eusart){
    if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_enable){
        TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_ENABLE;
        EUSART_TxInterruptHandler = _eusart->EUSART_TxDefaultInterruptHandler;
        /* Transmit Interrupt Configuration */
        if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_interrupt_enable){
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE            
            EUSART_TX_Interrupt_enable();
            /* Interrupt priority Configuration */
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=_eusart->usart_tx_cfg.usart_tx_int_priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           EUSART_TX_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==_eusart->usart_tx_cfg.usart_tx_int_priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           EUSART_TX_LowPrioritySet();
       }
       else { /* NO THING */ }
#else 
       INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
       INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
       
#endif
        }
        else if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_interrupt_enable){
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE;
        }
        else{}
        /* EUSART  9-Bit Transmit Configuration */
        if(EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable){
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE;
        }
        else if(EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable){
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE;
        }
        else{ /* Nothing */}    
    }
    else{ /* Nothing */ }
}

static void EUSART_ASYNC_RX_Init(const usart_t *_eusart){
    if(EUSART_ASYNCHRONOUS_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_enable){
        RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE;
        EUSART_RxInterruptHandler = _eusart->EUSART_RxDefaultInterruptHandler;
        EUSART_FramingErrorHandler = _eusart->EUSART_FramingErrorHandler;
        EUSART_OverrunErrorHandler = _eusart->EUSART_OverrunErrorHandler;
        /* Receiver Interrupt Configuration */
        if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_interrupt_enable){
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE;
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE            
            EUSART_RX_Interrupt_enable();
            /* Interrupt priority Configuration */
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
       INTERRUPT_PRIORITY_LEVELS_ENABLE();
       if(INERRUPT_HIGH_PRIORITY=_eusart->usart_rx_cfg.usart_rx_int_priority){
           /* Enable all high priority interrupts */
           INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE();
           EUSART_RX_HighPrioritySet();
       }
       else if(INERRUPT_LOW_PRIORITY==_eusart->usart_rx_cfg.usart_rx_int_priority){
           /* Enable all unmasked peripheral interrupts*/
           INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE();
           EUSART_RX_LowPrioritySet();
       }
       else { /* NO THING */ }
#else 
       INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
       INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
#endif
       
#endif
        }
        else if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_interrupt_enable){
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE;
        }
        else{}
        /* EUSART  9-Bit Transmit Configuration */
        if(EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable){
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE;
        }
        else if(EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable){
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE;
        }
        else{ /* Nothing */}    
    }
    else{ /* Nothing */ }
}