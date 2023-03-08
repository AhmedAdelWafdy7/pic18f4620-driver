

#include"ecu_key_pad.h"
static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] ={
                                                                {'7','8','9','/'},
                                                                {'4','5','6','*'},
                                                                {'1','2','3','-'},
                                                                {'c','0','=','+'}
                                                              };


/**
 * 
 * @param _keypad_obj
 * @return 
 */
STD_ReturnType keypad_intialize(const keypad_t *_keypad_obj){
    STD_ReturnType ret = E_OK;
    uint8 rows_counter=0,columns_counter=0; 
    if(NULL == _keypad_obj)
    {
        ret = E_NOT_OK;
    
    }
    else{
        for(rows_counter=0;rows_counter<ECU_KEYPAD_ROWS;rows_counter++){
            ret = gpio_pin_intialize(&(_keypad_obj->ecu_keypad_row_pins[rows_counter]));
        }
        for(columns_counter=0;columns_counter<ECU_KEYPAD_COLUMNS;columns_counter++){
                ret = gpio_pin_intialize(&(_keypad_obj->ecu_keypad_columns_pins[columns_counter]));
            
        }
        
        }
    
    return ret;
}
/**
 * 
 * @param _keypad_obj
 * @param value
 * @return 
 */
STD_ReturnType keypad_get_value(const keypad_t *_keypad_obj,uint8 *value){
    STD_ReturnType ret = E_OK;
    uint8 rows_counter=0,columns_counter=0;
    uint8 counter= 0;
    uint8 column_logic=0;
    if((NULL == _keypad_obj) || (NULL == value))
    {
        ret = E_NOT_OK;
    }
    else{
         for(rows_counter=0;rows_counter<ECU_KEYPAD_ROWS;rows_counter++){
            for(counter=0;counter<ECU_KEYPAD_ROWS;counter++){
               ret = gpio_pin_write_logic(&(_keypad_obj->ecu_keypad_row_pins[counter]),low);
            }
            gpio_pin_write_logic(&(_keypad_obj->ecu_keypad_row_pins[rows_counter]),high);
            __delay_ms(10);
            for(columns_counter=0;columns_counter<ECU_KEYPAD_COLUMNS;columns_counter++){
                ret = gpio_pin_read_logic(&(_keypad_obj->ecu_keypad_columns_pins[columns_counter]),&column_logic);
                if(high == column_logic ){
                    *value = btn_values[rows_counter][columns_counter];
                    
                }
            }}  
    
    }
    
    return ret;
}