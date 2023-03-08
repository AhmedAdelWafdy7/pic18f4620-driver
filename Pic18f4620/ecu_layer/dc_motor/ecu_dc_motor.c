

#include "ecu_dc_motor.h"



/**
 * 
 * @param _dc_motor
 * @return 
 */
STD_ReturnType dc_motor_intialize(const dc_motor_t *_dc_motor){
    STD_ReturnType ret= E_OK;
    if(NULL== _dc_motor ){
        ret =E_NOT_OK;
    }
    else
    {

    gpio_pin_intialize(&(_dc_motor->dc_motor_pin[0]));
    gpio_pin_intialize(&(_dc_motor->dc_motor_pin[1]));
    }
    return ret;
}
/**
 * 
 * @param _dc_motor
 * @return 
 */
STD_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor){
    STD_ReturnType ret= E_OK;
    if(NULL== _dc_motor ){
        ret =E_NOT_OK;
    }
    else
    {
      
    gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),high);
    gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),low);
        

    }
    return ret;
}
/**
 * 
 * @param _dc_motor
 * @return 
 */
STD_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor){
    STD_ReturnType ret= E_OK;
    if(NULL== _dc_motor ){
        ret =E_NOT_OK;
    }
    else
    {
    gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),low);
    gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),high);
    }
    return ret;
}
/**
 * 
 * @param _dc_motor
 * @return 
 */
STD_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor){
    STD_ReturnType ret= E_OK;
    if(NULL== _dc_motor ){
        ret =E_NOT_OK;
    }
    else
    {
    gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),low);
    gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),low);
    }
    return ret; 
}