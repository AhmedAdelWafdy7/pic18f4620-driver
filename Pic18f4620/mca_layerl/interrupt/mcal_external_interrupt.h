/* 
 * File:   mcal_external_interrupt.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 3:04 AM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H


/*---------------------includes-------------------------*/

#include "mcal_interrupt_config.h"
/*------------------Function Declaration------------------------*/
#if External_Interrupt_INTx_Feature_Enable==Interrupt_Feature_enable
/* Clear the interrupt enable for external interrupt ,INT0 */
#define External_Int0_InterruptDisable()        (INTCONbits.INT0IE=0)
/* Set the interrupt enable for external interrupt ,INT0 */
#define External_Int0_InterruptEnable()         (INTCONbits.INT0IE=1)
/* Clear the interrupt flag for external interrupt ,INT0 */
#define External_Int0_InterruptFlagClear()      (INTCONbits.INT0IF=0)
/* Set the edge detect of the external interrupt to egative edge for external interrupt ,INT0 */
#define External_Int0_RisingEdgeSet()     (INTCON2bits.INTEDG0=1)
/* Set the edge detect of the external interrupt to positive edge for external interrupt ,INT0 */
#define External_Int0_FallingEdgeSet()     (INTCON2bits.INTEDG0=0)


/* Clear the interrupt enable for external interrupt ,INT1 */
#define External_Int1_InterruptDisable()        (INTCON3bits.INT1IE=0)
/* Set the interrupt enable for external interrupt ,INT1 */
#define External_Int1_InterruptEnable()         (INTCON3bits.INT1IE=1)
/* Clear the interrupt flag for external interrupt ,INT1 */
#define External_Int1_InterruptFlagClear()      (INTCON3bits.INT1IF=0)
/* Set the edge detect of the external interrupt to negative edge for external interrupt ,INT1 */
#define External_Int1_RisingEdgeSet()           (INTCON2bits.INTEDG0=1)
/* Set the edge detect of the external interrupt to positive edge for external interrupt ,INT1 */
#define External_Int1_FallingEdgeSet()          (INTCON2bits.INTEDG0=0)

/* Clear the interrupt enable for external interrupt ,INT2 */
#define External_Int2_InterruptDisable()        (INTCON3bits.INT2IE=0)
/* Set the interrupt enable for external interrupt ,INT2 */
#define External_Int2_InterruptEnable()         (INTCON3bits.INT2IE=1)
/* Clear the interrupt flag for external interrupt ,INT2 */
#define External_Int2_InterruptFlagClear()      (INTCON3bits.INT2IF=0)
/* Set the edge detect of the external interrupt to negative edge for external interrupt ,INT2 */
#define External_Int2_RisingEdgeSet()           (INTCON2bits.INTEDG0=1)
/* Set the edge detect of the external interrupt to positive edge for external interrupt ,INT2 */
#define External_Int2_FallingEdgeSet()          (INTCON2bits.INTEDG0=0)

#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
/* Set INT1 External Interrupt Priority to High Priority */
#define External_Int1_HighPrioritySet()         (INTCON3bits.INT1IP=1)
/* Set INT1 External Interrupt Priority to Low Priority */
#define External_Int1_LowPrioritySet()          (INTCON3bits.INT1IP=0)

/* Set INT2 External Interrupt Priority to High Priority */
#define External_Int2_HighPrioritySet()         (INTCON3bits.INT2IP=1)
/* Set INT2 External Interrupt Priority to Low Priority */
#define External_Int2_LowPrioritySet()          (INTCON3bits.INT2IP=0)
#endif

#endif



#if External_Interrupt_OnChange_Feature_Enable==Interrupt_Feature_enable

/* Clear the interrupt enable for external interrupt ,RBx */
#define External_RBx_InterruptDisable()         (INTCONbits.RBIE=0)
/* Set the interrupt enable for external interrupt ,RBx */
#define External_RBx_InterruptEnable()          (INTCONbits.RBIE=1)
/* Clear the interrupt flag for external interrupt ,RBx */
#define External_RBx_InterruptFlagClear()       (INTCONbits.RBIF=0)


#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable

/* Set RBx External Interrupt Priority to High Priority */
#define External_RBx_HighPrioritySet()         (INTCON2bits.RBIP=1)
/* Set RBx External Interrupt Priority to Low Priority */
#define External_RBx_LowPrioritySet()          (INTCON2bits.RBIP=0)

#endif

#endif



/*------------------DataTypes Declaration------------------------*/
typedef enum{
    INTERRUPT_FALLING_EDGE=0,
    INTERRUPT_RISING_EDGE        
}interrupt_INTx_edge;
typedef enum{
    INTERRUPT_EXTERNAL_INT0=0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
}interrupt_INTx_src;


typedef struct{
    void (* EXT_InterruptHandler)(void);
    pin_config_t mcu_pins;
    interrupt_INTx_edge edge;
    interrupt_INTx_src source;
    interrupt_priority_cfg priority;
}interrupt_INTx_t;
typedef struct{
    void (* EXT_InterruptHandler_HIGH)(void);
    void (* EXT_InterruptHandler_LOW)(void);    
    pin_config_t mcu_pins;
    interrupt_priority_cfg priority;
}interrupt_RBx_t;


/*----------------------------------SoftWareInterface--------------------*/
STD_ReturnType Interrupt_INTx_init(const interrupt_INTx_t *int_obj);
STD_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);
STD_ReturnType Interrupt_RBx_init(const interrupt_RBx_t *int_obj);
STD_ReturnType Interrupt_Rbx_DeInit(const interrupt_RBx_t *int_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

