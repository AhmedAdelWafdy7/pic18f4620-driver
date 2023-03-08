/* 
 * File:   ecu_seven_segment.h
 * Author: user
 *
 * Created on March 4, 2023, 12:39 AM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/*----------------------- includes ------------------------*/
#include "../../mca_layerl/GPIO/hal_gpio.h"
/*------------------------ Macro Declaration --------------------*/
#define SEGEMENT_PIN0 0
#define SEGEMENT_PIN1 1
#define SEGEMENT_PIN2 2
#define SEGEMENT_PIN3 3
/*-------------------------Macro Function Declaration ------------------*/
/*---------------------------Data Types Declaration---------------------------*/
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE        
}segment_type_t;
typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;
/*-------------------------------software Declaration--------------------------*/
STD_ReturnType seven_segment_intialize(const segment_t *segment);
STD_ReturnType seven_segment_write_number(const segment_t *segment,uint8 number);


#endif	/* ECU_SEVEN_SEGMENT_H */



