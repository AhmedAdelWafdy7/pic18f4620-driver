
#include "ecu_chr_lcd.h"

/**
 * 
 * @param lcd
 * @return 
 */
#define _XTAL_FREQ 8000000UL
void *memset(void *str, int c, size_t n);

STD_ReturnType lcd_4bit_initialize(const chr_lcd_4bit_t *lcd){
   STD_ReturnType ret = E_OK;
   uint8 data_pins_counter=0; 
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = gpio_pin_intialize(&(lcd->lcd_rs));
       ret = gpio_pin_intialize(&(lcd ->lcd_en));
       for(data_pins_counter=0;data_pins_counter<4;data_pins_counter++){
           ret = gpio_pin_intialize(&(lcd->lcd_data[data_pins_counter]));
       }
       __delay_ms(20);
       ret = lcd_4bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
       __delay_ms(5);
       ret = lcd_4bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
       __delay_ms(150);
       ret = lcd_4bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
       
       ret = lcd_4bit_send_command(lcd ,_LCD_CLEAR);
       ret = lcd_4bit_send_command(lcd ,_LCD_RETURN_HOME);
       ret = lcd_4bit_send_command(lcd ,_LCD_ENTERY_MODE_INC_SHIFT_OFF);
       ret = lcd_4bit_send_command(lcd ,_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
       ret = lcd_4bit_send_command(lcd ,_LCD_4BIT_MODE_2_LINE);
       ret = lcd_4bit_send_command(lcd ,0x80);
    }
   return ret;
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
STD_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd,uint8 command){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = gpio_pin_write_logic(&(lcd->lcd_rs),low);
       ret = lcd_send_4bits(lcd,command >> 4);
       ret = lcd_4bit_send_enable_signal(lcd);
       ret = lcd_send_4bits(lcd,command);
       ret = lcd_4bit_send_enable_signal(lcd);       
   }
   return ret;

}

/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
STD_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd,uint8 data){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
   ret = gpio_pin_write_logic(&(lcd->lcd_rs),high);
   ret = lcd_send_4bits(lcd,data >> 4);
   ret = lcd_4bit_send_enable_signal(lcd);
   ret = lcd_send_4bits(lcd,data);
   ret = lcd_4bit_send_enable_signal(lcd);   
   }
   return ret;

}
STD_ReturnType lcd_4bit_send_char_dat_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 coulmn,uint8 data){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = lcd_4bit_set_cursor(lcd,row,coulmn);
       ret = lcd_4bit_send_char_data(lcd,data);
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
STD_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd,uint8 *str){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
      while(*str){
       ret = lcd_4bit_send_char_data(lcd,*str++);
      }  
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return 
 */
STD_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd,uint8 row,uint8 coulmn,uint8 *str){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = lcd_4bit_set_cursor(lcd,row,coulmn);
       while(*str){
       ret = lcd_4bit_send_char_data(lcd,*str++);
      }  
        
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return 
 */
STD_ReturnType lcd_4bit_send_custome_char(const chr_lcd_4bit_t *lcd,uint8 row,uint8 coulmn,const uint8 _chr[],uint8 mem_pos){
   STD_ReturnType ret = E_OK;
   uint8 counter =0; 
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = lcd_4bit_send_command(lcd,(_LCD_CGRAM_START +(mem_pos*8)) ); 
       for (counter=0;counter<=7;counter++){
           ret = lcd_4bit_send_char_data(lcd,_chr[counter]);
       }
       ret = lcd_4bit_send_char_dat_pos(lcd,row,coulmn,mem_pos);
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @return 
 */
STD_ReturnType lcd_8bit_initialize(const chr_lcd_8bit_t *lcd){
   STD_ReturnType ret = E_OK;
   uint8 data_pins_counter=0; 
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = gpio_pin_intialize(&(lcd->lcd_rs));
       ret = gpio_pin_intialize(&(lcd ->lcd_en));
       for(data_pins_counter=0;data_pins_counter<4;data_pins_counter++){
           ret = gpio_pin_intialize(&(lcd->lcd_data[data_pins_counter]));
       }
       ret = lcd_8bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
       __delay_ms(5);
       ret = lcd_8bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
       __delay_ms(150);
       ret = lcd_8bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
       
       ret = lcd_8bit_send_command(lcd ,_LCD_CLEAR);
       ret = lcd_8bit_send_command(lcd ,_LCD_RETURN_HOME);
       ret = lcd_8bit_send_command(lcd ,_LCD_ENTERY_MODE_INC_SHIFT_OFF);
       ret = lcd_8bit_send_command(lcd ,_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
       ret = lcd_8bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
       ret = lcd_8bit_send_command(lcd ,0x80);       
   }
   return ret;
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
STD_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd,uint8 command){
   STD_ReturnType ret = E_OK;
   int counter = 0;  
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = gpio_pin_write_logic(&(lcd->lcd_rs),low);
       for(counter=0;counter<8;counter++){
           ret = gpio_pin_write_logic(& (lcd->lcd_data[counter]),(command >> counter) &(uint8)0x01);
       }
       ret = lcd_8bit_send_enable_signal(lcd);       
   }
   return ret;
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
STD_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd,uint8 data){
   STD_ReturnType ret = E_OK;
   uint8 counter = 0; 
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),high);
        for(counter=0;counter<8;++counter){
            ret = gpio_pin_write_logic(&(lcd->lcd_data[counter]),(data >> counter) & (uint8)0x01);
        }
        ret = lcd_8bit_send_enable_signal(lcd);           
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return 
 */
STD_ReturnType lcd_8bit_send_char_dat_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 coulmn,uint8 data){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
        ret = lcd_8bit_set_cursor(lcd,row,coulmn);
        ret = lcd_8bit_send_char_data(lcd,data);
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
STD_ReturnType lcd_8bit_send_string(const chr_lcd_8bit_t *lcd,uint8 *str){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       while(*str){
           ret = lcd_8bit_send_char_data(lcd,*str++);
       }
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return 
 */
STD_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd,uint8 row,uint8 coulmn,uint8 *str){
   STD_ReturnType ret = E_OK;
    
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = lcd_8bit_set_cursor(lcd,row,coulmn);       
       while(*str){
           ret = lcd_8bit_send_char_data(lcd,*str++);
       }        
   }
   return ret;

}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return 
 */
STD_ReturnType lcd_8bit_send_custome_char(const chr_lcd_8bit_t *lcd,uint8 row,uint8 coulmn,const uint8 _chr[],uint8 mem_pos){
   STD_ReturnType ret = E_OK;
   uint8 counter=0; 
   if(NULL == lcd)
   {
       ret = E_NOT_OK;
    
   }
   else{
       ret = lcd_8bit_send_command(lcd,(_LCD_CGRAM_START +(mem_pos*8)) ); 
       for (counter=0;counter<=7;counter++){
           ret = lcd_8bit_send_char_data(lcd,_chr[counter]);
       }
       ret = lcd_8bit_send_char_dat_pos(lcd,row,coulmn,mem_pos);       
   }
   return ret;
}

/**
 * 
 * @param value
 * @param str
 */
STD_ReturnType convert_uint8_to_string(uint8 value,uint8 *str){
   
    STD_ReturnType ret = E_OK;
  if(NULL == str)
   {
       ret = E_NOT_OK;
    
   }
   else{
      memset(str,'\0',4);
      sprintf(str,"%i",value);
   }
    return ret;
}
/**
 * 
 * @param value
 * @param str
 */
STD_ReturnType convert_uint16_to_string(uint8 value,uint8 *str){
    STD_ReturnType ret = E_OK;
  if(NULL == str)
   {
       ret = E_NOT_OK;
    
   }
   else{
      memset(str,'\0',6);
      sprintf(str,"%i",value);
   }
    return ret;

}
/**
 * 
 * @param value
 * @param str
 */
STD_ReturnType convert_uint32_to_string(uint8 value,uint8 *str){
     STD_ReturnType ret = E_OK;
  if(NULL == str)
   {
       ret = E_NOT_OK;
    
   }
   else{
      memset(str,'\0',11);
      sprintf(str,"%i",value);
   }
    return ret;
}
static STD_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd,uint8 _data_command){
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_data[0]),(_data_command >> 0)&(uint8)0x01);
    ret = gpio_pin_write_logic(&(lcd->lcd_data[1]),(_data_command >> 1)&(uint8)0x01);
    ret = gpio_pin_write_logic(&(lcd->lcd_data[2]),(_data_command >> 2)&(uint8)0x01);
    ret = gpio_pin_write_logic(&(lcd->lcd_data[3]),(_data_command >> 3)&(uint8)0x01);    
    return ret;
}   
static STD_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd){
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en),high);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en),low);
    return ret;    
    
}
static STD_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd){
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en),high);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en),low);
    return ret;    
    
}
static STD_ReturnType lcd_4bit_set_cursor(const chr_lcd_8bit_t *lcd,uint8 row,uint8 coulmn){
    STD_ReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_4bit_send_command(lcd,(0x80+coulmn)); break;
        case ROW2 : ret = lcd_4bit_send_command(lcd,(0xC0+coulmn)); break;
        case ROW3 : ret = lcd_4bit_send_command(lcd,(0x94+coulmn)); break;
        case ROW4 : ret = lcd_4bit_send_command(lcd,(0xD4+coulmn)); break;
        default : ;
    }
    return ret;
}
static STD_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd,uint8 row,uint8 coulmn){
    STD_ReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_8bit_send_command(lcd,(0x80+coulmn)); break;
        case ROW2 : ret = lcd_8bit_send_command(lcd,(0xC0+coulmn)); break;
        case ROW3 : ret = lcd_8bit_send_command(lcd,(0x94+coulmn)); break;
        case ROW4 : ret = lcd_8bit_send_command(lcd,(0xD4+coulmn)); break;
        default : ;

    }
    return ret;
}