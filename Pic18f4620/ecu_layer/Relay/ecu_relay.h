/* 
 * File:   ecu_relay.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 2:31 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

#include "ecu_relay_cfg.h"
/*---------------------------- Includes ---------------------*/
#include "ecu_relay_cfg.h"
#include "../../mca_layerl/GPIO/hal_gpio.h"

/*---------------------------- Macro Declaration---------------------*/
#define RELAY_ON_STATUS 0x01U
#define RELAY_OFF_STATUS 0x00U

/*---------------------------- Macro Function Declaration---------------------*/



/*---------------------------- Data Types Declaration ---------------------*/
typedef struct {
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;


/*---------------------------- Software Interfaces Declaration ---------------------*/
STD_ReturnType relay_intialize(const relay_t *relay);
STD_ReturnType relay_turn_on(const relay_t *relay);
STD_ReturnType relay_turn_off(const relay_t *relay);

#endif	/* ECU_RELAY_H */

