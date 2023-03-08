/* 
 * File:   ccp_cfg.h
 * Author: Ahmed Adel
 *
 * Created on February 19, 2023, 8:27 PM
 */

#ifndef CCP_CFG_H
#define	CCP_CFG_H

/* ----------------- Includes -----------------*/

/* ----------------- Macro Declarations -----------------*/
#define CCP_CFG_CAPTURE_MODE_SELECTED  0x00
#define CCP_CFG_COMPARE_MODE_SELECTED  0x01
#define CCP_CFG_PWM_MODE_SELECTED      0x02

#define CCP1_CFG_SELECTED_MODE (CCP_CFG_COMPARE_MODE_SELECTED)
#define CCP2_CFG_SELECTED_MODE (CCP1_CFG_CAPTURE_MODE_SELECTED)

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/
#endif	/* CCP_CFG_H */

