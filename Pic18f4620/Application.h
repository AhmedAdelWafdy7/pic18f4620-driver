/* 
 * File:   Application.h
 * Author: Ahmed Adel Wafdy
 * Linked in : https://www.linkedin.com/in/ahmed-wafdy-094567242/
 * Created on December 5, 2022, 2:09 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "ecu_layer/ecu_layer_init.h"
#include "mca_layerl/GPIO/hal_gpio.h"
#include "mca_layerl/Timer0/timer0.h"
/* section : Macro Declarations*/


/* section : Macro function Declartion*/


/* section : Data Types Declaration*/
extern chr_lcd_4bit_t lcd_obj;
extern keypad_t keypad_obj;
extern segment_t segment_obj;
extern pin_config_t segment_EN1;
extern pin_config_t segment_EN2;
extern pin_config_t segment_EN3;
extern pin_config_t segment_EN4;
extern pin_config_t segment_EN5;
extern pin_config_t segment_EN6;

/* section :function declaration*/
void application_intialize(void);
void ecu_layer_inialize(void);

#endif	/* APPLICATION_H */

