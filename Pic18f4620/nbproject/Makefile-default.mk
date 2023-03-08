#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/New_Folder.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/New_Folder.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ecu_layer/button/ecu_button.c ecu_layer/chr_lcd/ecu_chr_lcd.c ecu_layer/dc_motor/ecu_dc_motor.c ecu_layer/KeyPad/ecu_key_pad.c ecu_layer/led/ecu_led.c ecu_layer/Relay/ecu_relay.c ecu_layer/ecu_layer_init.c mca_layerl/ADC/hal_adc.c mca_layerl/CCP/hal_ccp.c mca_layerl/EEPROM/hal_eeprom.c mca_layerl/EUSART/hal_usart.c mca_layerl/GPIO/hal_gpio.c mca_layerl/interrupt/mcal_interrupt_manager.c mca_layerl/interrupt/mcal_internal_interrupt.c mca_layerl/interrupt/mcal_external_interrupt.c mca_layerl/Timer0/timer0.c mca_layerl/Timer1/timer1.c mca_layerl/Timer2/timer2.c mca_layerl/Timer3/timer3.c mca_layerl/device_config.c Application.c ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.c mca_layerl/I2C/hal_i2c.c mca_layerl/SPI/hal_spi.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ecu_layer/button/ecu_button.p1 ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1 ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1 ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1 ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1 ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1 ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1 ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1 ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1 ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1 ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1 ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1 ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1 ${OBJECTDIR}/mca_layerl/device_config.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1 ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1 ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ecu_layer/button/ecu_button.p1.d ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1.d ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1.d ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1.d ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1.d ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1.d ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1.d ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1.d ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1.d ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1.d ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1.d ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1.d ${OBJECTDIR}/mca_layerl/device_config.p1.d ${OBJECTDIR}/Application.p1.d ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1.d ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1.d ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ecu_layer/button/ecu_button.p1 ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1 ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1 ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1 ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1 ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1 ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1 ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1 ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1 ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1 ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1 ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1 ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1 ${OBJECTDIR}/mca_layerl/device_config.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1 ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1 ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1

# Source Files
SOURCEFILES=ecu_layer/button/ecu_button.c ecu_layer/chr_lcd/ecu_chr_lcd.c ecu_layer/dc_motor/ecu_dc_motor.c ecu_layer/KeyPad/ecu_key_pad.c ecu_layer/led/ecu_led.c ecu_layer/Relay/ecu_relay.c ecu_layer/ecu_layer_init.c mca_layerl/ADC/hal_adc.c mca_layerl/CCP/hal_ccp.c mca_layerl/EEPROM/hal_eeprom.c mca_layerl/EUSART/hal_usart.c mca_layerl/GPIO/hal_gpio.c mca_layerl/interrupt/mcal_interrupt_manager.c mca_layerl/interrupt/mcal_internal_interrupt.c mca_layerl/interrupt/mcal_external_interrupt.c mca_layerl/Timer0/timer0.c mca_layerl/Timer1/timer1.c mca_layerl/Timer2/timer2.c mca_layerl/Timer3/timer3.c mca_layerl/device_config.c Application.c ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.c mca_layerl/I2C/hal_i2c.c mca_layerl/SPI/hal_spi.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/New_Folder.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ecu_layer/button/ecu_button.p1: ecu_layer/button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/button" 
	@${RM} ${OBJECTDIR}/ecu_layer/button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/button/ecu_button.p1 ecu_layer/button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/button/ecu_button.d ${OBJECTDIR}/ecu_layer/button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1: ecu_layer/chr_lcd/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/chr_lcd" 
	@${RM} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1 ecu_layer/chr_lcd/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.d ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1: ecu_layer/dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ecu_layer/dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1: ecu_layer/KeyPad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/KeyPad" 
	@${RM} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1 ecu_layer/KeyPad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.d ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/led/ecu_led.p1: ecu_layer/led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/led" 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ecu_layer/led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/led/ecu_led.d ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1: ecu_layer/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/Relay" 
	@${RM} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1 ecu_layer/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.d ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/ecu_layer_init.p1: ecu_layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer" 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1 ecu_layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/ecu_layer_init.d ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1: mca_layerl/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/ADC" 
	@${RM} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1 mca_layerl/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.d ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1: mca_layerl/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/CCP" 
	@${RM} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1 mca_layerl/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.d ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1: mca_layerl/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/EEPROM" 
	@${RM} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1 mca_layerl/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.d ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1: mca_layerl/EUSART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/EUSART" 
	@${RM} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1 mca_layerl/EUSART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.d ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1: mca_layerl/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/GPIO" 
	@${RM} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1 mca_layerl/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.d ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1: mca_layerl/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/interrupt" 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1 mca_layerl/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1: mca_layerl/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/interrupt" 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1 mca_layerl/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1: mca_layerl/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/interrupt" 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1 mca_layerl/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer0/timer0.p1: mca_layerl/Timer0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer0" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1 mca_layerl/Timer0/timer0.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer0/timer0.d ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer1/timer1.p1: mca_layerl/Timer1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer1" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1 mca_layerl/Timer1/timer1.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer1/timer1.d ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer2/timer2.p1: mca_layerl/Timer2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer2" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1 mca_layerl/Timer2/timer2.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer2/timer2.d ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer3/timer3.p1: mca_layerl/Timer3/timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer3" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1 mca_layerl/Timer3/timer3.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer3/timer3.d ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/device_config.p1: mca_layerl/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl" 
	@${RM} ${OBJECTDIR}/mca_layerl/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/device_config.p1 mca_layerl/device_config.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/device_config.d ${OBJECTDIR}/mca_layerl/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1: ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT" 
	@${RM} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1 ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.d ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1: mca_layerl/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/I2C" 
	@${RM} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1 mca_layerl/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.d ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1: mca_layerl/SPI/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/SPI" 
	@${RM} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1 mca_layerl/SPI/hal_spi.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.d ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ecu_layer/button/ecu_button.p1: ecu_layer/button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/button" 
	@${RM} ${OBJECTDIR}/ecu_layer/button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/button/ecu_button.p1 ecu_layer/button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/button/ecu_button.d ${OBJECTDIR}/ecu_layer/button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1: ecu_layer/chr_lcd/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/chr_lcd" 
	@${RM} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1 ecu_layer/chr_lcd/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.d ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/chr_lcd/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1: ecu_layer/dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ecu_layer/dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1: ecu_layer/KeyPad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/KeyPad" 
	@${RM} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1 ecu_layer/KeyPad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.d ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/KeyPad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/led/ecu_led.p1: ecu_layer/led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/led" 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ecu_layer/led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/led/ecu_led.d ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1: ecu_layer/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/Relay" 
	@${RM} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1 ecu_layer/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.d ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/ecu_layer_init.p1: ecu_layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer" 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1 ecu_layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/ecu_layer_init.d ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1: mca_layerl/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/ADC" 
	@${RM} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1 mca_layerl/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.d ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1: mca_layerl/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/CCP" 
	@${RM} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1 mca_layerl/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.d ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1: mca_layerl/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/EEPROM" 
	@${RM} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1 mca_layerl/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.d ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1: mca_layerl/EUSART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/EUSART" 
	@${RM} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1 mca_layerl/EUSART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.d ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/EUSART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1: mca_layerl/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/GPIO" 
	@${RM} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1 mca_layerl/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.d ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1: mca_layerl/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/interrupt" 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1 mca_layerl/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1: mca_layerl/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/interrupt" 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1 mca_layerl/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1: mca_layerl/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/interrupt" 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1 mca_layerl/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer0/timer0.p1: mca_layerl/Timer0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer0" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1 mca_layerl/Timer0/timer0.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer0/timer0.d ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer1/timer1.p1: mca_layerl/Timer1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer1" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1 mca_layerl/Timer1/timer1.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer1/timer1.d ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer2/timer2.p1: mca_layerl/Timer2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer2" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1 mca_layerl/Timer2/timer2.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer2/timer2.d ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/Timer3/timer3.p1: mca_layerl/Timer3/timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/Timer3" 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1 mca_layerl/Timer3/timer3.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/Timer3/timer3.d ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/Timer3/timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/device_config.p1: mca_layerl/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl" 
	@${RM} ${OBJECTDIR}/mca_layerl/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/device_config.p1 mca_layerl/device_config.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/device_config.d ${OBJECTDIR}/mca_layerl/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1: ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT" 
	@${RM} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1 ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.d ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/SEVEN_SEGMENT/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1: mca_layerl/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/I2C" 
	@${RM} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1 mca_layerl/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.d ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1: mca_layerl/SPI/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mca_layerl/SPI" 
	@${RM} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1 mca_layerl/SPI/hal_spi.c 
	@-${MV} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.d ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mca_layerl/SPI/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/New_Folder.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/New_Folder.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/New_Folder.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/New_Folder.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/New_Folder.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/New_Folder.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/New_Folder.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
