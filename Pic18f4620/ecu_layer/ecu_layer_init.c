#include "ecu_layer_init.h"
#include <xc.h>
            /* 7SEGMENTS Configuration */
segment_t segment_obj = {.segment_pins[0].port = PORTC_INDEX,
                            .segment_pins[0].pin = pin0,
                            .segment_pins[0].direction = output,
                            .segment_pins[0].logic = low,
                            .segment_pins[1].port = PORTC_INDEX,
                            .segment_pins[1].pin = pin1,
                            .segment_pins[1].direction = output,
                            .segment_pins[1].logic = low,
                            .segment_pins[2].port = PORTC_INDEX,
                            .segment_pins[2].pin = pin2,
                            .segment_pins[2].direction = output,
                            .segment_pins[2].logic = low,
                            .segment_pins[3].port = PORTC_INDEX,
                            .segment_pins[3].pin = pin3,
                            .segment_pins[3].direction = output,
                            .segment_pins[3].logic = low,
                            .segment_type = SEGMENT_COMMON_ANODE};

pin_config_t segment_EN1 ={.port = PORTD_INDEX,
                           .pin = pin0,
                           .direction = output,
                           .logic = low};
pin_config_t segment_EN2 ={.port = PORTD_INDEX,
                           .pin = pin1,
                           .direction = output,
                           .logic = low};
pin_config_t segment_EN3 ={.port = PORTD_INDEX,
                           .pin = pin2,
                           .direction = output,
                           .logic = low};
pin_config_t segment_EN4 ={.port = PORTD_INDEX,
                           .pin = pin3,
                           .direction = output,
                           .logic = low};
pin_config_t segment_EN5 ={.port = PORTD_INDEX,
                           .pin = pin4,
                           .direction = output,
                           .logic = low};
pin_config_t segment_EN6 ={.port = PORTD_INDEX,
                           .pin = pin5,
                           .direction = output,
                           .logic = low};
            /* LCD Configuration */
chr_lcd_4bit_t lcd_obj = {.lcd_rs.port = PORTA_INDEX,
                        .lcd_rs.pin = pin0,
                        .lcd_rs.direction = output,
                        .lcd_rs.logic = low,
                        .lcd_en.port = PORTA_INDEX,
                        .lcd_en.pin = pin1,
                        .lcd_en.direction = output,
                        .lcd_en.logic = low,
                        .lcd_data[0].port = PORTC_INDEX,
                        .lcd_data[0].pin = pin4,
                        .lcd_data[0].direction = output,
                        .lcd_data[0].logic = low,
                        .lcd_data[1].port = PORTC_INDEX,
                        .lcd_data[1].pin = pin5,
                        .lcd_data[1].direction = output,
                        .lcd_data[1].logic = low,
                        .lcd_data[2].port = PORTC_INDEX,
                        .lcd_data[2].pin = pin6,
                        .lcd_data[2].direction = output,
                        .lcd_data[2].logic = low,
                        .lcd_data[3].port = PORTC_INDEX,
                        .lcd_data[3].pin = pin7,
                        .lcd_data[3].direction = output,
                        .lcd_data[3].logic = low};
            /* KEYPAD Configuration */
keypad_t keypad_obj = {.ecu_keypad_row_pins[0].port = PORTB_INDEX,
                        .ecu_keypad_row_pins[0].pin = pin0,
                        .ecu_keypad_row_pins[0].direction = output,
                        .ecu_keypad_row_pins[0].logic = low,
                        .ecu_keypad_row_pins[1].port = PORTB_INDEX,
                        .ecu_keypad_row_pins[1].pin = pin1,
                        .ecu_keypad_row_pins[1].direction = output,
                        .ecu_keypad_row_pins[1].logic = low,
                        .ecu_keypad_row_pins[2].port = PORTB_INDEX,
                        .ecu_keypad_row_pins[2].pin = pin2,
                        .ecu_keypad_row_pins[2].direction = output,
                        .ecu_keypad_row_pins[2].logic = low,
                        .ecu_keypad_row_pins[3].port = PORTB_INDEX,
                        .ecu_keypad_row_pins[3].pin = pin3,
                        .ecu_keypad_row_pins[3].direction = output,
                        .ecu_keypad_row_pins[3].logic = low,
                        .ecu_keypad_columns_pins[0].port = PORTB_INDEX,
                        .ecu_keypad_columns_pins[0].pin = pin4,
                        .ecu_keypad_columns_pins[0].direction = output,
                        .ecu_keypad_columns_pins[0].logic = low,
                        .ecu_keypad_columns_pins[1].port = PORTB_INDEX,
                        .ecu_keypad_columns_pins[1].pin = pin5,
                        .ecu_keypad_columns_pins[1].direction = output,
                        .ecu_keypad_columns_pins[1].logic = low,
                        .ecu_keypad_columns_pins[2].port = PORTB_INDEX,
                        .ecu_keypad_columns_pins[2].pin = pin6,
                        .ecu_keypad_columns_pins[2].direction = output,
                        .ecu_keypad_columns_pins[2].logic = low,
                        .ecu_keypad_columns_pins[3].port = PORTB_INDEX,
                        .ecu_keypad_columns_pins[3].pin = pin7,
                        .ecu_keypad_columns_pins[3].direction = output,
                        .ecu_keypad_columns_pins[3].logic = low};
void ecu_layer_inialize(void){
    STD_ReturnType ret = E_NOT_OK;
    ret = keypad_intialize(&keypad_obj);
    ret = lcd_4bit_initialize(&lcd_obj);
    ret = seven_segment_intialize(&segment_obj);
    ret = gpio_pin_intialize(&segment_EN1);
    ret = gpio_pin_intialize(&segment_EN2);
    ret = gpio_pin_intialize(&segment_EN3);
    ret = gpio_pin_intialize(&segment_EN4);
    ret = gpio_pin_intialize(&segment_EN5);
    ret = gpio_pin_intialize(&segment_EN6);

}
