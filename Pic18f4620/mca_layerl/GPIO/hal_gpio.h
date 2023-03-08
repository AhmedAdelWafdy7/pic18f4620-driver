/* 
 * File:   hal_gpio.h
 * Author: Ahmed Adel
 *
 * Created on September 19, 2022, 6:22 PM
 */


#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/* section includes*/
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"
/* section : Macro Declarations*/
#define BIT_MASK (uint8)1
#define PORT_PIN_MAX_NUMBER 8
#define PORT_MAX_NUMBER 5

#define PORT_PIN_CONFIGRATION   CONFIG_ENABLE

/* section : Macro function Declaration*/
#define HWREG8 (*((volatile unsigned int *)(_x)))
#define SET_BIT(REG,BIT_POSN)         (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)       (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)      (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)        (REG >> BIT_POSN & BIT_MASK)

/* section : Data Types Declaration*/
typedef enum{
    low=0,
    high        
}logic_t;
typedef enum
{
    output=0,
    input        
}direction_t;

typedef enum{
    pin0=0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7
}pin_index_t;

typedef enum
{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;
typedef struct {
    unsigned int port : 3;
    unsigned int pin : 3;
    unsigned int direction : 1;
    unsigned int logic : 1;
   
}pin_config_t;
/* section :function declaration*/
STD_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);
STD_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *direction_status);
STD_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic);
STD_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic);
STD_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);
STD_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config);



STD_ReturnType gpio_port_direction_intialize(port_index_t port,uint8 direction);
STD_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status);
STD_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic);
STD_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic);
STD_ReturnType gpio_port_toggle_logic(port_index_t port);

#endif	/* HAL_GPIO_H */