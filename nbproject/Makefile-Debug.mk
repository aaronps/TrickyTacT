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
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=mingw-w64-64-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/GridMap.o \
	${OBJECTDIR}/src/SEngine.o \
	${OBJECTDIR}/src/SSurface.o \
	${OBJECTDIR}/src/SText.o \
	${OBJECTDIR}/src/SVideo.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../libs/SDL2-2.0.3/x86_64-w64-mingw32/lib -L../../libs/SDL2_image-2.0.0/x86_64-w64-mingw32/lib -L../../libs/SDL2_ttf-2.0.12/x86_64-w64-mingw32/lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trickytact2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trickytact2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trickytact2 ${OBJECTFILES} ${LDLIBSOPTIONS} -lSDL2_ttf -lSDL2_image -lSDL2

${OBJECTDIR}/src/GridMap.o: src/GridMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -I../../libs/SDL2-2.0.3/include -I../../libs/SDL2_ttf-2.0.12/x86_64-w64-mingw32/include/SDL2 -I../../libs/SDL2_image-2.0.0/x86_64-w64-mingw32/include/SDL2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GridMap.o src/GridMap.cpp

${OBJECTDIR}/src/SEngine.o: src/SEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -I../../libs/SDL2-2.0.3/include -I../../libs/SDL2_ttf-2.0.12/x86_64-w64-mingw32/include/SDL2 -I../../libs/SDL2_image-2.0.0/x86_64-w64-mingw32/include/SDL2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SEngine.o src/SEngine.cpp

${OBJECTDIR}/src/SSurface.o: src/SSurface.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -I../../libs/SDL2-2.0.3/include -I../../libs/SDL2_ttf-2.0.12/x86_64-w64-mingw32/include/SDL2 -I../../libs/SDL2_image-2.0.0/x86_64-w64-mingw32/include/SDL2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SSurface.o src/SSurface.cpp

${OBJECTDIR}/src/SText.o: src/SText.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -I../../libs/SDL2-2.0.3/include -I../../libs/SDL2_ttf-2.0.12/x86_64-w64-mingw32/include/SDL2 -I../../libs/SDL2_image-2.0.0/x86_64-w64-mingw32/include/SDL2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SText.o src/SText.cpp

${OBJECTDIR}/src/SVideo.o: src/SVideo.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -I../../libs/SDL2-2.0.3/include -I../../libs/SDL2_ttf-2.0.12/x86_64-w64-mingw32/include/SDL2 -I../../libs/SDL2_image-2.0.0/x86_64-w64-mingw32/include/SDL2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SVideo.o src/SVideo.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -I../../libs/SDL2-2.0.3/include -I../../libs/SDL2_ttf-2.0.12/x86_64-w64-mingw32/include/SDL2 -I../../libs/SDL2_image-2.0.0/x86_64-w64-mingw32/include/SDL2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trickytact2.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
