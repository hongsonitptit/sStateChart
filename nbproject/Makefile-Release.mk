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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BaseEvent.o \
	${OBJECTDIR}/BaseObject.o \
	${OBJECTDIR}/EventTypeGuard.o \
	${OBJECTDIR}/MyAction.o \
	${OBJECTDIR}/MyGuard.o \
	${OBJECTDIR}/MyState.o \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/StateMachine.o \
	${OBJECTDIR}/Transition.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/testStateMachine.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f1

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f5

${TESTDIR}/TestFiles/f5: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f5 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BaseEvent.o: BaseEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BaseEvent.o BaseEvent.cpp

${OBJECTDIR}/BaseObject.o: BaseObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BaseObject.o BaseObject.cpp

${OBJECTDIR}/EventTypeGuard.o: EventTypeGuard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventTypeGuard.o EventTypeGuard.cpp

${OBJECTDIR}/MyAction.o: MyAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyAction.o MyAction.cpp

${OBJECTDIR}/MyGuard.o: MyGuard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyGuard.o MyGuard.cpp

${OBJECTDIR}/MyState.o: MyState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyState.o MyState.cpp

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/StateMachine.o: StateMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StateMachine.o StateMachine.cpp

${OBJECTDIR}/Transition.o: Transition.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Transition.o Transition.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/testStateMachine.o: testStateMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testStateMachine.o testStateMachine.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/TestBaseEvent.o ${TESTDIR}/tests/mainBaseEvent.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/TestState.o ${TESTDIR}/tests/mainState.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/TestStateMachineUnit.o ${TESTDIR}/tests/mainStateMachine.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TestTransition.o ${TESTDIR}/tests/mainTransition.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`   


${TESTDIR}/tests/TestBaseEvent.o: tests/TestBaseEvent.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TestBaseEvent.o tests/TestBaseEvent.cpp


${TESTDIR}/tests/mainBaseEvent.o: tests/mainBaseEvent.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mainBaseEvent.o tests/mainBaseEvent.cpp


${TESTDIR}/tests/TestState.o: tests/TestState.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TestState.o tests/TestState.cpp


${TESTDIR}/tests/mainState.o: tests/mainState.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mainState.o tests/mainState.cpp


${TESTDIR}/tests/TestStateMachineUnit.o: tests/TestStateMachineUnit.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TestStateMachineUnit.o tests/TestStateMachineUnit.cpp


${TESTDIR}/tests/mainStateMachine.o: tests/mainStateMachine.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mainStateMachine.o tests/mainStateMachine.cpp


${TESTDIR}/tests/TestTransition.o: tests/TestTransition.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TestTransition.o tests/TestTransition.cpp


${TESTDIR}/tests/mainTransition.o: tests/mainTransition.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mainTransition.o tests/mainTransition.cpp


${OBJECTDIR}/BaseEvent_nomain.o: ${OBJECTDIR}/BaseEvent.o BaseEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BaseEvent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BaseEvent_nomain.o BaseEvent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BaseEvent.o ${OBJECTDIR}/BaseEvent_nomain.o;\
	fi

${OBJECTDIR}/BaseObject_nomain.o: ${OBJECTDIR}/BaseObject.o BaseObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BaseObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BaseObject_nomain.o BaseObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BaseObject.o ${OBJECTDIR}/BaseObject_nomain.o;\
	fi

${OBJECTDIR}/EventTypeGuard_nomain.o: ${OBJECTDIR}/EventTypeGuard.o EventTypeGuard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/EventTypeGuard.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EventTypeGuard_nomain.o EventTypeGuard.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/EventTypeGuard.o ${OBJECTDIR}/EventTypeGuard_nomain.o;\
	fi

${OBJECTDIR}/MyAction_nomain.o: ${OBJECTDIR}/MyAction.o MyAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MyAction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyAction_nomain.o MyAction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MyAction.o ${OBJECTDIR}/MyAction_nomain.o;\
	fi

${OBJECTDIR}/MyGuard_nomain.o: ${OBJECTDIR}/MyGuard.o MyGuard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MyGuard.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyGuard_nomain.o MyGuard.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MyGuard.o ${OBJECTDIR}/MyGuard_nomain.o;\
	fi

${OBJECTDIR}/MyState_nomain.o: ${OBJECTDIR}/MyState.o MyState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MyState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyState_nomain.o MyState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MyState.o ${OBJECTDIR}/MyState_nomain.o;\
	fi

${OBJECTDIR}/State_nomain.o: ${OBJECTDIR}/State.o State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/State.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State_nomain.o State.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/State.o ${OBJECTDIR}/State_nomain.o;\
	fi

${OBJECTDIR}/StateMachine_nomain.o: ${OBJECTDIR}/StateMachine.o StateMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/StateMachine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StateMachine_nomain.o StateMachine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/StateMachine.o ${OBJECTDIR}/StateMachine_nomain.o;\
	fi

${OBJECTDIR}/Transition_nomain.o: ${OBJECTDIR}/Transition.o Transition.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Transition.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Transition_nomain.o Transition.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Transition.o ${OBJECTDIR}/Transition_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/testStateMachine_nomain.o: ${OBJECTDIR}/testStateMachine.o testStateMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/testStateMachine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testStateMachine_nomain.o testStateMachine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/testStateMachine.o ${OBJECTDIR}/testStateMachine_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f5

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
