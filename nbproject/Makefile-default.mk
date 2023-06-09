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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DoAn_TKLL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DoAn_TKLL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=button_matrix/button.c main.c timer/timer.c interrupt/interrupt.c lcd/lcd.c button_matrix/global.c button_matrix/i2c.c button_matrix/clock.c button_matrix/fsm.c button_matrix/custom_character.c button_matrix/animation_data.c button_matrix/animation_data1.c button_matrix/animation_data2.c button_matrix/animation_data3.c button_matrix/game_lcd.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/button_matrix/button.o ${OBJECTDIR}/main.o ${OBJECTDIR}/timer/timer.o ${OBJECTDIR}/interrupt/interrupt.o ${OBJECTDIR}/lcd/lcd.o ${OBJECTDIR}/button_matrix/global.o ${OBJECTDIR}/button_matrix/i2c.o ${OBJECTDIR}/button_matrix/clock.o ${OBJECTDIR}/button_matrix/fsm.o ${OBJECTDIR}/button_matrix/custom_character.o ${OBJECTDIR}/button_matrix/animation_data.o ${OBJECTDIR}/button_matrix/animation_data1.o ${OBJECTDIR}/button_matrix/animation_data2.o ${OBJECTDIR}/button_matrix/animation_data3.o ${OBJECTDIR}/button_matrix/game_lcd.o
POSSIBLE_DEPFILES=${OBJECTDIR}/button_matrix/button.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/timer/timer.o.d ${OBJECTDIR}/interrupt/interrupt.o.d ${OBJECTDIR}/lcd/lcd.o.d ${OBJECTDIR}/button_matrix/global.o.d ${OBJECTDIR}/button_matrix/i2c.o.d ${OBJECTDIR}/button_matrix/clock.o.d ${OBJECTDIR}/button_matrix/fsm.o.d ${OBJECTDIR}/button_matrix/custom_character.o.d ${OBJECTDIR}/button_matrix/animation_data.o.d ${OBJECTDIR}/button_matrix/animation_data1.o.d ${OBJECTDIR}/button_matrix/animation_data2.o.d ${OBJECTDIR}/button_matrix/animation_data3.o.d ${OBJECTDIR}/button_matrix/game_lcd.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/button_matrix/button.o ${OBJECTDIR}/main.o ${OBJECTDIR}/timer/timer.o ${OBJECTDIR}/interrupt/interrupt.o ${OBJECTDIR}/lcd/lcd.o ${OBJECTDIR}/button_matrix/global.o ${OBJECTDIR}/button_matrix/i2c.o ${OBJECTDIR}/button_matrix/clock.o ${OBJECTDIR}/button_matrix/fsm.o ${OBJECTDIR}/button_matrix/custom_character.o ${OBJECTDIR}/button_matrix/animation_data.o ${OBJECTDIR}/button_matrix/animation_data1.o ${OBJECTDIR}/button_matrix/animation_data2.o ${OBJECTDIR}/button_matrix/animation_data3.o ${OBJECTDIR}/button_matrix/game_lcd.o

# Source Files
SOURCEFILES=button_matrix/button.c main.c timer/timer.c interrupt/interrupt.c lcd/lcd.c button_matrix/global.c button_matrix/i2c.c button_matrix/clock.c button_matrix/fsm.c button_matrix/custom_character.c button_matrix/animation_data.c button_matrix/animation_data1.c button_matrix/animation_data2.c button_matrix/animation_data3.c button_matrix/game_lcd.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/DoAn_TKLL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
MP_PROCESSOR_OPTION_LD=18f4620
MP_LINKER_DEBUG_OPTION=-r=ROM@0xFDC0:0xFFFF -r=RAM@GPR:0xEF4:0xEFF -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/button_matrix/button.o: button_matrix/button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/button.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/button.o   button_matrix/button.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/button.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/timer/timer.o: timer/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/timer" 
	@${RM} ${OBJECTDIR}/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/timer/timer.o   timer/timer.c 
	@${DEP_GEN} -d ${OBJECTDIR}/timer/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/timer/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/interrupt/interrupt.o: interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/interrupt/interrupt.o   interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/interrupt/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupt/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/lcd/lcd.o: lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lcd" 
	@${RM} ${OBJECTDIR}/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/lcd/lcd.o   lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/lcd/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/global.o: button_matrix/global.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/global.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/global.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/global.o   button_matrix/global.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/global.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/global.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/i2c.o: button_matrix/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/i2c.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/i2c.o   button_matrix/i2c.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/clock.o: button_matrix/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/clock.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/clock.o   button_matrix/clock.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/clock.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/fsm.o: button_matrix/fsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/fsm.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/fsm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/fsm.o   button_matrix/fsm.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/fsm.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/fsm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/custom_character.o: button_matrix/custom_character.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/custom_character.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/custom_character.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/custom_character.o   button_matrix/custom_character.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/custom_character.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/custom_character.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data.o: button_matrix/animation_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data.o   button_matrix/animation_data.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data1.o: button_matrix/animation_data1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data1.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data1.o   button_matrix/animation_data1.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data1.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data2.o: button_matrix/animation_data2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data2.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data2.o   button_matrix/animation_data2.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data2.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data3.o: button_matrix/animation_data3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data3.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data3.o   button_matrix/animation_data3.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data3.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/game_lcd.o: button_matrix/game_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/game_lcd.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/game_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/game_lcd.o   button_matrix/game_lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/game_lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/game_lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/button_matrix/button.o: button_matrix/button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/button.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/button.o   button_matrix/button.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/button.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/timer/timer.o: timer/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/timer" 
	@${RM} ${OBJECTDIR}/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/timer/timer.o   timer/timer.c 
	@${DEP_GEN} -d ${OBJECTDIR}/timer/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/timer/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/interrupt/interrupt.o: interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/interrupt/interrupt.o   interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/interrupt/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupt/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/lcd/lcd.o: lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lcd" 
	@${RM} ${OBJECTDIR}/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/lcd/lcd.o   lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/lcd/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/global.o: button_matrix/global.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/global.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/global.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/global.o   button_matrix/global.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/global.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/global.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/i2c.o: button_matrix/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/i2c.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/i2c.o   button_matrix/i2c.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/clock.o: button_matrix/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/clock.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/clock.o   button_matrix/clock.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/clock.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/fsm.o: button_matrix/fsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/fsm.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/fsm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/fsm.o   button_matrix/fsm.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/fsm.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/fsm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/custom_character.o: button_matrix/custom_character.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/custom_character.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/custom_character.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/custom_character.o   button_matrix/custom_character.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/custom_character.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/custom_character.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data.o: button_matrix/animation_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data.o   button_matrix/animation_data.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data1.o: button_matrix/animation_data1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data1.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data1.o   button_matrix/animation_data1.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data1.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data2.o: button_matrix/animation_data2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data2.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data2.o   button_matrix/animation_data2.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data2.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/animation_data3.o: button_matrix/animation_data3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data3.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/animation_data3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/animation_data3.o   button_matrix/animation_data3.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/animation_data3.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/animation_data3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/game_lcd.o: button_matrix/game_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/game_lcd.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/game_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/game_lcd.o   button_matrix/game_lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/game_lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/game_lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/DoAn_TKLL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PICKIT2=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/DoAn_TKLL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/DoAn_TKLL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/DoAn_TKLL.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
