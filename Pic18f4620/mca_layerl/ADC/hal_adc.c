#include "hal_adc.h"

#if ADC_interrupt_feature_enable==Interrupt_Feature_enable
static void (*ADC_INTERRUPT_HANDLER)(void)=NULL;
#endif
static inline void adc_input_port_configure(adc_channel_select_t channel);
static inline void adc_select_result_format(const adc_conf_t *_adc);
static inline void adc_configure_voltage_refernce(const adc_conf_t *_adc);

/**
 * 
 * @param _adc
 * @return 
 */
STD_ReturnType ADC_INIT(const adc_conf_t *_adc){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == _adc){
        ret =E_NOT_OK;
    }
    else{
        /* Disable ADC */
        ADC_CONVERSION_DISABLE();
        /* Configure the acquesation time */
        ADCON2bits.ACQT=_adc->acquestion_time;
        /* Configure the conversion clock */
        ADCON2bits.ADCS=_adc->conversion_clock;
        /* Configure the default channel */
        ADCON0bits.CHS=_adc->adc_channel;
        adc_input_port_configure(_adc->adc_channel);
        /* Configure the interrupt */
        #if ADC_interrupt_feature_enable==Interrupt_Feature_enable
        ADC_INTERRUPT_HANDLER = _adc->ADC_INTERRUPT_HANDLER;
        ADC_Interrupt_enable();
        INTERRUPT_GLOPAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHAL_INTERRUPT_ENABLE();
        ADC_Interrupt_flag_clear();
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
        if(INERRUPT_HIGH_PRIORITY == _adc->priority){
            ADC_HighPrioritySet();
        }
        else if(INERRUPT_LOW_PRIORITY == _adc->priority){
            ADC_LowPrioritySet();
        }
        else{ /* NOTHING */ }
#endif
        #endif
        /* configure the result format */
        adc_select_result_format(_adc);
        /* configure the voltage refernce */
        adc_configure_voltage_refernce(_adc);
        /* Enable the ADC */
        ADC_CONVERSION_ENABLE();
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _adc
 * @return 
 */
STD_ReturnType ADC_DEINIT(const adc_conf_t *_adc){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == _adc){
        ret =E_NOT_OK;
    }
    else{
        /* Disable the ADC */
        ADC_CONVERSION_DISABLE();
        /* Disable the interrupt */
        #if ADC_interrupt_feature_enable==Interrupt_Feature_enable
        ADC_Interrupt_disable();
        #endif
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _adc
 * @param channel
 * @return 
 */
STD_ReturnType ADC_SELECT_CHANNEL(const adc_conf_t *_adc,adc_channel_select_t channel){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == _adc){
        ret =E_NOT_OK;
    }
    else{
        ADCON0bits.CHS=channel;
        adc_input_port_configure(_adc->adc_channel);
    }
    return ret;
}
/**
 * 
 * @param _adc
 * @return 
 */
STD_ReturnType ADC_STARTING_CONVERSION(const adc_conf_t *_adc){
    STD_ReturnType ret =E_NOT_OK;
    if(NULL == _adc){
        ret =E_NOT_OK;
    }
    else{
        ret = ADC_START_CONVERSION();
    }
    return ret;
}
/**
 * 
 * @param _adc
 * @param conversion_status
 * @return 
 */
STD_ReturnType ADC_IsConversionDone(const adc_conf_t *_adc,uint8 *conversion_status){
    STD_ReturnType ret =E_NOT_OK;
    if( (NULL == _adc) || (NULL==conversion_status)){
        ret =E_NOT_OK;
    }
    else{
        *conversion_status = ADCON0bits.GO_nDONE;
        *conversion_status = (uint8)(!(ADCON0bits.GO_nDONE));
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _adc
 * @param conversion_result
 * @return 
 */
STD_ReturnType ADC_GetConversionResult(const adc_conf_t *_adc,adc_result *conversion_result){
    STD_ReturnType ret =E_NOT_OK;
    if( (NULL == _adc) || (NULL==conversion_result)){
        ret =E_NOT_OK;
    }
    else{
        if(ADC_RESULT_RIGHT == _adc->result_format){
            *conversion_result = (adc_result)((ADRESH<< 8 )+ ADRESL );
        }
        else if(ADC_RESULT_LEFT == _adc->result_format){
                    *conversion_result = (adc_result)(((ADRESH<< 8 )+ ADRESL ) >> 6);
        }
        else{
            *conversion_result = (adc_result)((ADRESH<< 8 )+ ADRESL );        
        }
    }
    return ret;
}
/**
 * 
 * @param _adc
 * @param channel
 * @param conversion_result
 * @return 
 */
STD_ReturnType ADC_GetConversion_Blooking(const adc_conf_t *_adc,adc_channel_select_t channel,adc_result *conversion_result){
    STD_ReturnType ret =E_NOT_OK;
    uint8 conversion_status=0;
    if( (NULL == _adc) || (NULL==conversion_result)){
        ret =E_NOT_OK;
    }
    else{
        /* Select the A/D channel */
        ret = ADC_SELECT_CHANNEL(_adc,channel);
        /* Start conversion */
        ret = ADC_STARTING_CONVERSION(_adc);
        /* check if conversion is completed */
        while(ADCON0bits.GO_nDONE);
        ret = ADC_GetConversionResult(_adc,conversion_result);
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @param channel
 * @param conversion_result
 * @return 
 */
STD_ReturnType ADC_GetConversion_Interrupt(const adc_conf_t *_adc,adc_channel_select_t channel){
    STD_ReturnType ret =E_NOT_OK;
    if( (NULL == _adc) ){
        ret =E_NOT_OK;
    }
    else{
        /* Select the A/D channel */
        ret = ADC_SELECT_CHANNEL(_adc,channel);
        /* Start conversion */
        ret = ADC_STARTING_CONVERSION(_adc);

    }
    return ret;
}



static inline void adc_input_port_configure(adc_channel_select_t channel){
    switch(channel){
        case ADC_CHANNEL_AN0 : SET_BIT(TRISA,_TRISA_RA0_POSN);break;
        case ADC_CHANNEL_AN1 : SET_BIT(TRISA,_TRISA_RA1_POSN);break;
        case ADC_CHANNEL_AN2 : SET_BIT(TRISA,_TRISA_RA2_POSN);break;
        case ADC_CHANNEL_AN3 : SET_BIT(TRISA,_TRISA_RA3_POSN);break;
        case ADC_CHANNEL_AN4 : SET_BIT(TRISA,_TRISA_RA4_POSN);break;
        case ADC_CHANNEL_AN5 : SET_BIT(TRISE,_TRISE_RE0_POSN);break;
        case ADC_CHANNEL_AN6 : SET_BIT(TRISE,_TRISE_RE1_POSN);break;
        case ADC_CHANNEL_AN7 : SET_BIT(TRISE,_TRISE_RE2_POSN);break;
        case ADC_CHANNEL_AN8 : SET_BIT(TRISB,_TRISB_RB2_POSN);break;
        case ADC_CHANNEL_AN9 : SET_BIT(TRISB,_TRISB_RB3_POSN);break;
        case ADC_CHANNEL_AN10 : SET_BIT(TRISB,_TRISB_RB1_POSN);break;
        case ADC_CHANNEL_AN11 : SET_BIT(TRISB,_TRISB_RB4_POSN);break;
        case ADC_CHANNEL_AN12 : SET_BIT(TRISB,_TRISB_RB0_POSN);break;
        default : break;
    }
}

static inline void adc_select_result_format(const adc_conf_t *_adc){
    if(ADC_RESULT_RIGHT == _adc->result_format){
        ADC_RESULT_RIGHT_FORMAT();
    }
    else if(ADC_RESULT_LEFT== _adc->result_format){
        ADC_RESULT_LEFT_FORMAT();
    }
    else{
        ADC_RESULT_RIGHT_FORMAT();    
    }
}

static inline void adc_configure_voltage_refernce(const adc_conf_t *_adc){
    if(ADC_VOLTAGE_REFERNCE_ENABLE == _adc->voltage_refernce){
        ADC_ENABLE_VOLTAGE_REFERNCE();
    }
    else if(ADC_VOLTAGE_REFERNCE_DISABLE== _adc->voltage_refernce){
        ADC_DISABLE_VOLTAGE_REFERNCE();
    }
    else{
        ADC_DISABLE_VOLTAGE_REFERNCE();    
    }
}

void ADC_ISR(void){
    ADC_Interrupt_flag_clear();
    if(ADC_INTERRUPT_HANDLER){
        ADC_INTERRUPT_HANDLER();
    }

}
