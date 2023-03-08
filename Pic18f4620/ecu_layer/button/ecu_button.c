/* 
 * File:   ecu_button.h
 * Author: Ahmed Adel
 * Linked in : https://www.linkedin.com/in/ahmed-wafdy-094567242/
 * Created on December 5, 2022, 2:27 AM
 */
#include "ecu_button.h"
STD_ReturnType button_intialize(const button_t *btn){
    STD_ReturnType ret= E_OK;
    if(NULL== btn){
        ret =E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_intialize(&(btn->button_pin));
        
    }
    return ret;

}
/**
 * @brief read the state of the button
 * @param btn pointer to the button configration
 * @param btn_state buton state @ref button_state_t
 * @return status of the function 
 *         (E_OK) : The function done successfully 
 *         (E_NOT_OK) : The function has issue 
 */
STD_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state){
    STD_ReturnType ret= E_OK;
    button_state_t btn_status = button_released;
    logic_t pin_logic_status = low;
    if(NULL== btn || NULL == btn_state){
        ret =E_NOT_OK;
    }
    else
    {
        gpio_pin_read_logic(&(btn->button_pin),&pin_logic_status);
        if(button_high == btn->button_connection){
            if(high == pin_logic_status){
                btn_status = button_pressed;
            }
            else{
                btn_status = button_released;
            }
        }
        else if(button_low == btn->button_connection){
            if(high == pin_logic_status){
                btn_status = button_released;
            }
            else{
                btn_status = button_pressed;
            }
        }
        else{/*nothing*/}
    }
    return ret;
}
