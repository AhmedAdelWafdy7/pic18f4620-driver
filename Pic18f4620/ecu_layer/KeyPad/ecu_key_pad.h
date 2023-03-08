/* 
 * File:   ecu_key_pad.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 2:23 AM
 */

#ifndef ECU_KEY_PAD_H
#define	ECU_KEY_PAD_H



/*---------------------------- Includes ---------------------*/
#include "../../mca_layerl/GPIO/hal_gpio.h"
#include "ecu_key_pad_cfg.h"
/*---------------------------- Macro Declaration---------------------*/
#define ECU_KEYPAD_ROWS     4
#define ECU_KEYPAD_COLUMNS     4
#define _XTAL_FREQ 8000000UL

/*---------------------------- Macro Function Declaration---------------------*/
typedef struct{
    pin_config_t ecu_keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t ecu_keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;


/*---------------------------- Data Types Declaration ---------------------*/


/*---------------------------- Software Interfaces Declaration ---------------------*/
STD_ReturnType keypad_intialize(const keypad_t *_keypad_obj);
STD_ReturnType keypad_get_value(const keypad_t *_keypad_obj,uint8 *value);



#endif	/* ECU_KEY_PAD_H */

