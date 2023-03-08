/* 
 * File:   ecu_dc_motor.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 2:20 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H


/*---------------------------- Includes ---------------------*/
#include "ecu_dc_motor_cfg.h"
#include "../../mca_layerl/GPIO/hal_gpio.h"

/*---------------------------- Macro Declaration---------------------*/
#define DC_MOTOR_ON_STATUS 0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

/*---------------------------- Macro Function Declaration---------------------*/



/*---------------------------- Data Types Declaration ---------------------*/


typedef struct {
    pin_config_t dc_motor_pin[2];
}dc_motor_t;

/*---------------------------- Software Interfaces Declaration ---------------------*/
STD_ReturnType dc_motor_intialize(const dc_motor_t *_dc_motor);
STD_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor);
STD_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor);
STD_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);



#endif	/* ECU_DC_MOTOR_H */

