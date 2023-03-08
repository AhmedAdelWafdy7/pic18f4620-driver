
#include "ecu_relay.h"
/**
 * 
 * @param relay
 * @return 
 */
STD_ReturnType relay_intialize(const relay_t *relay){
    STD_ReturnType ret= E_OK;
    if(NULL== relay ){
        ret =E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {.port = relay->relay_port , .pin = relay->relay_pin ,.logic = relay->relay_status,.direction=output};
        gpio_pin_direction_intialize(&pin_obj);
    }
    return ret;
}
/**
 * 
 * @param relay
 * @return 
 */
STD_ReturnType relay_turn_on(const relay_t *relay){
    STD_ReturnType ret= E_OK;
    if(NULL== relay ){
        ret =E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {.port = relay->relay_port , .pin = relay->relay_pin ,.logic = relay->relay_status,.direction=output};
        gpio_pin_write_logic(&pin_obj,high);
    }
    return ret;

}
/**
 * 
 * @param relay
 * @return 
 */
STD_ReturnType relay_turn_off(const relay_t *relay){
    STD_ReturnType ret= E_OK;
    if(NULL== relay ){
        ret =E_NOT_OK;
    }
    else
    {
        pin_config_t pin_obj = {.port = relay->relay_port , .pin = relay->relay_pin ,.logic = relay->relay_status,.direction= output};
        gpio_pin_write_logic(&pin_obj,low);
    }
    return ret;
}