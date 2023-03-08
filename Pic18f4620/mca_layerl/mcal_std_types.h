/* 
 * File:   mcal_std_types.h
 * Author: Ahmed Adel
 *
 * Created on December 5, 2022, 2:07 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

#include "compiler.h"
#include "mcal_std_libraries.h"
/* section : Macro Declarations*/
#define STD_HIGH       0x01
#define STD_LOW        0x00


#define _XTAL_FREQ 8000000UL

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00
#define E_OK         (STD_ReturnType)0x01
#define E_NOT_OK     (STD_ReturnType)0x00
/* section : Macro function Declartion*/


/* section : Data Types Declartion*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef uint8 STD_ReturnType; 

/* section :function declartion*/

#endif	/* MCAL_STD_TYPES_H */

