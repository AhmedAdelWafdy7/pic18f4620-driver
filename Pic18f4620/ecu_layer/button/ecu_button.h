/* 
 * File:   ecu_button.h
 * Author: Ahmed Adel
 * Linked in : https://www.linkedin.com/in/ahmed-wafdy-094567242/
 * Created on December 5, 2022, 2:27 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* section: includes */
#include "ecu_button_cfg.h"
#include "../../mca_layerl/GPIO/hal_gpio.h"
/* section: macro declarations*/
/* section : macro function declaration*/
/*Data types declarations*/
typedef enum{
    button_pressed,
    button_released           
}button_state_t;

typedef enum {
    button_high,
    button_low
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;
/*software interfaces declarations */
STD_ReturnType button_intialize(const button_t *btn);
STD_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);


#endif	/* ECU_BUTTON_H */

