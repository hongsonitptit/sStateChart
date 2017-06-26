/* 
 * File:   TestStateMachine.h
 * Author: ttdk
 *
 * Created on June 7, 2016, 10:54 AM
 */

#ifndef TESTSTATEMACHINE_H
#define	TESTSTATEMACHINE_H

#include "StateMachine.h"

using namespace VtX::StateMachine;
using namespace std;

class TestStateMachine {
public:
    TestStateMachine();
    TestStateMachine(const TestStateMachine& orig);
    virtual ~TestStateMachine();
    
    void testNoState();
    void testNoStartingState();
    void testNoEndingState();
    void testNoTransitionIn();
    void testNoTransitionOut();
    void testStateRelationship();
    void testNoTransitionFound();
    void testAlternatePaths();
    void testFirstAlternateTransition();
    void testMaxTransitionCount();
    void testInternalTransition();
    void testExternalTransition();
    void testInternalTransitionMadeNextEvent();
    void testExternalTransitionMadeNextEvent();
    void testTransitionFromSubstateToSubstate();
    void testTransitionFromSubstateToParent();
    void testTransitionFromParentToSubstate();
    
private:

};

#endif	/* TESTSTATEMACHINE_H */

