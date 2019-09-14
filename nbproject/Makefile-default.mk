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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=007_Uart.c 006_Gpio.c 009_System.c 014_Md5.c 017_InnerFlash.c 000_Main.c 016_FlashOta.c 018_dsPICflash.s

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/007_Uart.o ${OBJECTDIR}/006_Gpio.o ${OBJECTDIR}/009_System.o ${OBJECTDIR}/014_Md5.o ${OBJECTDIR}/017_InnerFlash.o ${OBJECTDIR}/000_Main.o ${OBJECTDIR}/016_FlashOta.o ${OBJECTDIR}/018_dsPICflash.o
POSSIBLE_DEPFILES=${OBJECTDIR}/007_Uart.o.d ${OBJECTDIR}/006_Gpio.o.d ${OBJECTDIR}/009_System.o.d ${OBJECTDIR}/014_Md5.o.d ${OBJECTDIR}/017_InnerFlash.o.d ${OBJECTDIR}/000_Main.o.d ${OBJECTDIR}/016_FlashOta.o.d ${OBJECTDIR}/018_dsPICflash.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/007_Uart.o ${OBJECTDIR}/006_Gpio.o ${OBJECTDIR}/009_System.o ${OBJECTDIR}/014_Md5.o ${OBJECTDIR}/017_InnerFlash.o ${OBJECTDIR}/000_Main.o ${OBJECTDIR}/016_FlashOta.o ${OBJECTDIR}/018_dsPICflash.o

# Source Files
SOURCEFILES=007_Uart.c 006_Gpio.c 009_System.c 014_Md5.c 017_InnerFlash.c 000_Main.c 016_FlashOta.c 018_dsPICflash.s


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ1024GA606
MP_LINKER_FILE_OPTION=,--script=p24FJ1024GA606.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/007_Uart.o: 007_Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/007_Uart.o.d 
	@${RM} ${OBJECTDIR}/007_Uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  007_Uart.c  -o ${OBJECTDIR}/007_Uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/007_Uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/007_Uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/006_Gpio.o: 006_Gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/006_Gpio.o.d 
	@${RM} ${OBJECTDIR}/006_Gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  006_Gpio.c  -o ${OBJECTDIR}/006_Gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/006_Gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/006_Gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/009_System.o: 009_System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/009_System.o.d 
	@${RM} ${OBJECTDIR}/009_System.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  009_System.c  -o ${OBJECTDIR}/009_System.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/009_System.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/009_System.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/014_Md5.o: 014_Md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/014_Md5.o.d 
	@${RM} ${OBJECTDIR}/014_Md5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  014_Md5.c  -o ${OBJECTDIR}/014_Md5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/014_Md5.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/014_Md5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/017_InnerFlash.o: 017_InnerFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/017_InnerFlash.o.d 
	@${RM} ${OBJECTDIR}/017_InnerFlash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  017_InnerFlash.c  -o ${OBJECTDIR}/017_InnerFlash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/017_InnerFlash.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/017_InnerFlash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/000_Main.o: 000_Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/000_Main.o.d 
	@${RM} ${OBJECTDIR}/000_Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  000_Main.c  -o ${OBJECTDIR}/000_Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/000_Main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/000_Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/016_FlashOta.o: 016_FlashOta.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/016_FlashOta.o.d 
	@${RM} ${OBJECTDIR}/016_FlashOta.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  016_FlashOta.c  -o ${OBJECTDIR}/016_FlashOta.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/016_FlashOta.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/016_FlashOta.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/007_Uart.o: 007_Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/007_Uart.o.d 
	@${RM} ${OBJECTDIR}/007_Uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  007_Uart.c  -o ${OBJECTDIR}/007_Uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/007_Uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/007_Uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/006_Gpio.o: 006_Gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/006_Gpio.o.d 
	@${RM} ${OBJECTDIR}/006_Gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  006_Gpio.c  -o ${OBJECTDIR}/006_Gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/006_Gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/006_Gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/009_System.o: 009_System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/009_System.o.d 
	@${RM} ${OBJECTDIR}/009_System.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  009_System.c  -o ${OBJECTDIR}/009_System.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/009_System.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/009_System.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/014_Md5.o: 014_Md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/014_Md5.o.d 
	@${RM} ${OBJECTDIR}/014_Md5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  014_Md5.c  -o ${OBJECTDIR}/014_Md5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/014_Md5.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/014_Md5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/017_InnerFlash.o: 017_InnerFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/017_InnerFlash.o.d 
	@${RM} ${OBJECTDIR}/017_InnerFlash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  017_InnerFlash.c  -o ${OBJECTDIR}/017_InnerFlash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/017_InnerFlash.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/017_InnerFlash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/000_Main.o: 000_Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/000_Main.o.d 
	@${RM} ${OBJECTDIR}/000_Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  000_Main.c  -o ${OBJECTDIR}/000_Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/000_Main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/000_Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/016_FlashOta.o: 016_FlashOta.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/016_FlashOta.o.d 
	@${RM} ${OBJECTDIR}/016_FlashOta.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  016_FlashOta.c  -o ${OBJECTDIR}/016_FlashOta.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/016_FlashOta.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/016_FlashOta.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/018_dsPICflash.o: 018_dsPICflash.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/018_dsPICflash.o.d 
	@${RM} ${OBJECTDIR}/018_dsPICflash.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  018_dsPICflash.s  -o ${OBJECTDIR}/018_dsPICflash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/018_dsPICflash.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/018_dsPICflash.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/018_dsPICflash.o: 018_dsPICflash.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/018_dsPICflash.o.d 
	@${RM} ${OBJECTDIR}/018_dsPICflash.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  018_dsPICflash.s  -o ${OBJECTDIR}/018_dsPICflash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/018_dsPICflash.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/018_dsPICflash.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-ivt,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-ivt,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
	@echo Normalizing hex file
	@"C:/Program Files (x86)/Microchip/MPLABX/v5.20/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files (x86)/Microchip/MPLABX/v5.20/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.hex -odist/${CND_CONF}/${IMAGE_TYPE}/Mbtboot.${IMAGE_TYPE}.hex

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
