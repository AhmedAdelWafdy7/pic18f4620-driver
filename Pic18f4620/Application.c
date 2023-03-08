/* 
 * File:   Application.c
 * Author: Ahmed Adel Wafdy
 * Linked in : https://www.linkedin.com/in/ahmed-wafdy-094567242/
 * Created on December 5, 2022, 2:09 AM
 */
#include "application.h"

int main() { 
    STD_ReturnType ret = E_NOT_OK;
    application_intialize();

    while(1){
 
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    STD_ReturnType ret = E_NOT_OK;
    ecu_layer_inialize();
}

