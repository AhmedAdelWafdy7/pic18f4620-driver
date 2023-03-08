/* 
 * File:   mcal_interrupt_config.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 2:41 AM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H


/*---------------------includes-------------------------*/
#include "../proc/pic18f4620.h"
#include "mcal_interrupt_gen_cfg.h"
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
/*-------------------------Macro Declaration------------------*/
#define INTERRUPT_ENABLE 1
#define INTERRUPT_DISABLE 0
#define INTERRUPT_OCCUR 1
#define INTERRUPT_NOT_OCCUR 0
#define INTERRUPT_PRIORITY_ENABLE 1
#define INTERRUPT_PRIORITY_DISABLE 0
/*------------------Function Declaration------------------------*/
#if Interrupt_Priority_Levels_Enable==Interrupt_Feature_enable
#define INTERRUPT_PRIORITY_LEVELS_ENABLE()          (RCONbits.IPEN=1)
#define INTERRUPT_PRIORITY_LEVELS_DISABLE()          (RCONbits.IPEN=0)
/* Enable high priority global inetrrupts */
#define INTERRUPT_GLOPAL_INTERRUPT_HIGH_ENABLE()    (INTCONbits.GIEH=1)
/* Disable high priority global inetrrupts */
#define INTERRUPT_GLOPAL_INTERRUPT_HIGH_DISAPLE()   (INTCONbits.GIEH=0)
/* Enable low priority global inetrrupts */
#define INTERRUPT_GLOPAL_INTERRUPT_LOW_ENABLE()     (INTCONbits.GIEL=1)
/* Disable low priority global inetrrupts */
#define INTERRUPT_GLOPAL_INTERRUPT_LOW_DISAPLE()    (INTCONbits.GIEL=0)
#else
/* Enable global inetrrupts */
#define INTERRUPT_GLOPAL_INTERRUPT_ENABLE()  (INTCONbits.GIE=1)
/* Disable global inetrrupts */
#define INTERRUPT_GLOPAL_INTERRUPT_DISAPLE()  (INTCONbits.GIE=0)
/* Enable periphal inetrrupts */
#define INTERRUPT_PERIPHAL_INTERRUPT_ENABLE()  (INTCONbits.PEIE=1)
/* Disable periphal inetrrupts */
#define INTERRUPT_PERIPHAL_INTERRUPT_DISABLE()  (INTCONbits.PEIE=0)

#endif
/*------------------DataTypes Declaration------------------------*/
typedef enum{
    INERRUPT_LOW_PRIORITY=0,
    INERRUPT_HIGH_PRIORITY
}interrupt_priority_cfg;

#endif	/* MCAL_INTERRUPT_CONFIG_H */

