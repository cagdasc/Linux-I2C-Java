#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++-4.6
CXX=g++-4.6
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/335960947/com_cacaosd_I2CHandler.o


# C Compiler Flags
CFLAGS=-shared -m32

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk dist/libI2CHandler.so

dist/libI2CHandler.so: ${OBJECTFILES}
	${MKDIR} -p dist
	${LINK.c} -o dist/libI2CHandler.so ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/_ext/335960947/com_cacaosd_I2CHandler.o: /home/cagdas/Dropbox/Workspace/NetBeansProjects/BegaleBone\ I2C\ Java\ Library/I2C/com_cacaosd_I2CHandler.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/335960947
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/jvm/java-7-oracle/include -I/usr/lib/jvm/java-7-oracle/include/linux -shared -m32 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/335960947/com_cacaosd_I2CHandler.o /home/cagdas/Dropbox/Workspace/NetBeansProjects/BegaleBone\ I2C\ Java\ Library/I2C/com_cacaosd_I2CHandler.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} dist/libI2CHandler.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
