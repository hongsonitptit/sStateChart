/* 
 * File:   TestStateMachine.cpp
 * Author: ttdk
 * 
 * Created on June 7, 2016, 10:54 AM
 */

#include "TestStateMachine.h"
#include "StateMachineBuildException.h"
#include "MyAction.h"
#include "PositiveGuard.h"

TestStateMachine::TestStateMachine() {
}

TestStateMachine::TestStateMachine(const TestStateMachine& orig) {
}

TestStateMachine::~TestStateMachine() {
}

/**
 * Confirm that State machine will throw a StateMachineBuildException 
 * if you attempt to build a state machine with no states
 */
void TestStateMachine::testNoState() {
    StateMachine sm;
    try {
    sm.build();
    
    cout<<"Test no state fail"<<endl;
    } catch(StateMachineBuildException e) {
        cout<<"Test pass : "<<e.what()<<endl;
    }
}

/**
 * Confirm that State machine will throw a StateMachineBuildException 
 * if you attempt to build a state machine with no starting state
 */
void TestStateMachine::testNoStartingState() {
//    StateMachine sm;
//    try {
//        State* sA = new State("A",new MyAction(),new MyAction(),NULL);
//        State* sEnd = new State("END",State::END,new MyAction(),new MyAction());
//        Transition* tT = new Transition("T",new BaseEvent(1,"e1"),new PositiveGuard(),sA, new MyAction());
//        sm.addState(sA);
//        sm.addState(sEnd);
//        sm.addTransition(tT);
//        sm.build();
//        cout<<"Test no starting state fail"<<endl;
//    } catch(StateMachineBuildException e) {
//        cout<<"Test pass: "<<e.what()<<endl;
//    }
}

/**
 * Confirm that State machine will throw a StateMachineBuildException 
 * if you attempt to build a state machine with no ending state
 */
void TestStateMachine::testNoEndingState() {
//StateMachine sm;
//    try {
//        State* sStart = new State("START",State::START,new MyAction(),new MyAction());
//        State* sA = new State("A",new MyAction(),new MyAction(),NULL);
//        Transition* tT = new Transition("T",new BaseEvent(1,"e1"),new PositiveGuard(),sA, new MyAction());
//        sm.addState(sA);
//        sm.addState(sStart);
//        sm.addTransition(tT);
//        sm.build();
//        cout<<"Test no starting state fail"<<endl;
//    } catch(StateMachineBuildException e) {
//        cout<<"Test pass: "<<e.what()<<endl;
//    }
}

/**
 * Confirm that State machine will throw a StateMachineBuildException 
 * if there exists at least a non-state with no inbound transition
 */
void TestStateMachine::testNoTransitionIn() {
    
}

/**
 * Confirm that State machine will throw a StateMachineBuildException 
 * if there exists at least a non-state with no outbound transition
 */
void TestStateMachine::testNoTransitionOut() {

}

/**
 * Confirm that State machine have state relationships correctly
 */
void TestStateMachine::testStateRelationship() {

}

/**
 * Confirm that State machine will do nothing if it can not find 
 * any suitable transition
 */
void TestStateMachine::testNoTransitionFound() {

}

/**
 * Confirm that State machine will do a transition if it can find
 * a suitable transition
 */
void TestStateMachine::testAlternatePaths() {

}

/**
 * Confirm that State machine will do the first matched transition 
 * if there are more than one suitable transitions
 */
void TestStateMachine::testFirstAlternateTransition() {

}

/**
 * Confirm that State machine will do nothing if transition counter
 * more than max transition count
 */
void TestStateMachine::testMaxTransitionCount() {

}

/**
 * Confirm that State machine will do an internal transition if match
 */
void TestStateMachine::testInternalTransition() {

}

/**
 * Confirm that State machine will do an external transition if match
 */
void TestStateMachine::testExternalTransition() {

}

/**
 * Confirm that State machine will handle next event that was made by
 * an internal transition after execute this transition
 */
void TestStateMachine::testInternalTransitionMadeNextEvent() {

}

/**
 * Confirm that State machine will handle next event that was made by
 * an external transition after execute this transition
 */
void TestStateMachine::testExternalTransitionMadeNextEvent() {

}

/**
 * Confirm that State machine will do a transition from a super-state
 * to sub-state by UML rules: 
 *  - come in through entry actions of sub-states until reach the target sub-state
 */
void TestStateMachine::testTransitionFromParentToSubstate() {

}

/**
 * Confirm that State machine will do a transition from a sub-state 
 * to super-state by UML rules:
 *  - go out through exit actions of parents until reach the target super-state
 */
void TestStateMachine::testTransitionFromSubstateToParent() {

}

/**
 * Confirm that State machine will do a transition from a sub-state to another
 * by UML rules:
 *  - go out through exit actions of parents until reach the least common state
 *  - come in through entry actions of sub-states until reach the target state
 */
void TestStateMachine::testTransitionFromSubstateToSubstate() {

}










