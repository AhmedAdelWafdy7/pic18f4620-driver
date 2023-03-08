/* 
 * File:   hal_adc.h
 * Author: Ahmed Adel
 * Linked in : https://www.linkedin.com/in/ahmed-wafdy-094567242/
 * Created on December 5, 2022, 3:09 AM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H


/*---------------------------- Includes ---------------------*/
#include "hal_adc_cfg.h"
#include "../proc/pic18f4620.h"
#include "../../mca_layerl/mcal_std_types.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_gpio.h"
/*---------------------------- Macro Declaration---------------------*/
#define ADC_AN0_ANALOG_FUNCIONALTY          0x0E
#define ADC_AN1_ANALOG_FUNCIONALTY          0x0D
#define ADC_AN2_ANALOG_FUNCIONALTY          0x0C
#define ADC_AN3_ANALOG_FUNCIONALTY          0x0B
#define ADC_AN4_ANALOG_FUNCIONALTY          0x0A
#define ADC_AN5_ANALOG_FUNCIONALTY          0x09
#define ADC_AN6_ANALOG_FUNCIONALTY          0x08
#define ADC_AN7_ANALOG_FUNCIONALTY          0x07
#define ADC_AN8_ANALOG_FUNCIONALTY          0x06
#define ADC_AN9_ANALOG_FUNCIONALTY          0x05
#define ADC_AN10_ANALOG_FUNCIONALTY         0x04
#define ADC_AN11_ANALOG_FUNCIONALTY         0x03
#define ADC_AN12_ANALOG_FUNCIONALTY         0x02
#define ADC_ALL_ANALOG_FUNCIONALTY          0x00
#define ADC_ALL_DIGITAL_FUNCIONALTY         0x0F



#define ADC_VOLTAGE_REFERNCE_ENABLE         0x01
#define ADC_VOLTAGE_REFERNCE_DISABLE        0x00

#define ADC_RESULT_RIGHT             0x01
#define ADC_RESULT_LEFT              0x00


/*---------------------------- Macro Function Declaration---------------------*/

#define ADC_RESULT_RIGHT_FORMAT()                   (ADCON2bits.ADFM=1)
#define ADC_RESULT_LEFT_FORMAT()                    (ADCON2bits.ADFM=0)

/* Conversion status */
#define ADC_CONVERSION_STATUS()     (ADCON0bits.GO_nDONE)
/* ADC Starting conversion */
#define ADC_START_CONVERSION()     (ADCON0bits.GO_nDONE=1)

/*ANALOG to DIGETAL control */
#define ADC_CONVERSION_ENABLE()     (ADCON0bits.ADON=1)
#define ADC_CONVERSION_DISABLE()     (ADCON0bits.ADON=0)

/* Voltage Refernce conversion */
/* Enable voltage Refernce =========> Vref+,Vref- */
#define ADC_ENABLE_VOLTAGE_REFERNCE()       do{ADCON1bits.VCFG1=1;\
                                               ADCON1bits.VCFG0=1;\
                                               }while(0)
/* Disable Voltage Refernce =======> vdd,vss */
#define ADC_DISABLE_VOLTAGE_REFERNCE()       do{ADCON1bits.VCFG1=0;\
                                               ADCON1bits.VCFG0=0;\
                                               }while(0)

#define ADC_ANALOG_DIGITAL_FUNCITONALTY_CONFIG(_config)     (ADCON1bits.PCFG=_config)


/*---------------------------- Data Types Declaration ---------------------*/
typedef uint16 adc_result;

typedef enum {
    ADC_CHANNEL_AN0=0,
    ADC_CHANNEL_AN1,        
    ADC_CHANNEL_AN2,        
    ADC_CHANNEL_AN3,        
    ADC_CHANNEL_AN4,        
    ADC_CHANNEL_AN5,        
    ADC_CHANNEL_AN6,        
    ADC_CHANNEL_AN7,        
    ADC_CHANNEL_AN8,        
    ADC_CHANNEL_AN9,        
    ADC_CHANNEL_AN10,        
    ADC_CHANNEL_AN11,        
    ADC_CHANNEL_AN12        
}adc_channel_select_t;

typedef enum{
    ADC0_TAD=0,
    ADC2_TAD,
    ADC4_TAD,
    ADC6_TAD,
    ADC8_TAD,
    ADC12_TAD,
    ADC16_TAD,
    ADC20_TAD
}adc_acquisation_time_t;

typedef enum{
    ADC_CONVERSION_CLOCK_FOSC_DIV2=0,
    ADC_CONVERSION_CLOCK_FOSC_DIV8,
    ADC_CONVERSION_CLOCK_FOSC_DIV32,
    ADC_CONVERSION_CLOCK_FOSC_DIVfrc,
    ADC_CONVERSION_CLOCK_FOSC_DIV4,
    ADC_CONVERSION_CLOCK_FOSC_DIV16,
    ADC_CONVERSION_CLOCK_FOSC_DIV64,
}adc_conversion_clock_t;

typedef struct{
    #if ADC_interrupt_feature_enable==Interrupt_Feature_enable
    void (*ADC_INTERRUPT_HANDLER)(void);
    interrupt_priority_cfg priority;
    #endif
    adc_acquisation_time_t  acquestion_time;
    adc_conversion_clock_t  conversion_clock;
    adc_channel_select_t    adc_channel;
    uint8 voltage_refernce :1;
    uint8 result_format :1;
    uint8 adc_reversed :6;
}adc_conf_t;
/*---------------------------- Software Interfaces Declaration ---------------------*/
STD_ReturnType ADC_INIT(const adc_conf_t *_adc);
STD_ReturnType ADC_DEINIT(const adc_conf_t *_adc);
STD_ReturnType ADC_SELECT_CHANNEL(const adc_conf_t *_adc,adc_channel_select_t channel);
STD_ReturnType ADC_STARTING_CONVERSION(const adc_conf_t *_adc);
STD_ReturnType ADC_IsConversionDone(const adc_conf_t *_adc,uint8 *conversion_status);
STD_ReturnType ADC_GetConversionResult(const adc_conf_t *_adc,adc_result *conversion_result);
STD_ReturnType ADC_GetConversion_Blooking(const adc_conf_t *_adc,adc_channel_select_t channel,adc_result *conversion_result);
STD_ReturnType ADC_GetConversion_Interrupt(const adc_conf_t *_adc,adc_channel_select_t channel);


#endif	/* HAL_ADC_H */

