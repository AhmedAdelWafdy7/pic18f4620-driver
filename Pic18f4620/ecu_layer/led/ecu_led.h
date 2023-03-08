/* 
 * File:   ecu_led.h
 * Author: Ahmed Adel
 * Linked in : https://www.linkedin.com/in/ahmed-wafdy-094567242/ 
 * Created on September 19, 2022, 11:37 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/* section : includes*/

#include "../../mca_layerl/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/* section : Macro Declarations*/


/* section : Macro function Declaration*/


/* section : Data Types Declaration*/
typedef enum {
    LED_OFF,
    LED_ON
}led_status_t;


typedef struct {
    uint8 port_name : 4;
    uint8 pin : 3 ;
    uint8 led_direction : 1;
    uint8 led_status: 1;
}led_t;

/* section :function declaration*/
STD_ReturnType led_intialize(const led_t *led);
STD_ReturnType led_turn_on(const led_t *led);
STD_ReturnType led_turn_off(const led_t *led);
STD_ReturnType led_turn_toggle(const led_t *led);

#endif	/* ECU_LED_H */


