/*
 * File:   TestStateMachineUnit.cpp
 * Author: ttdk
 *
 * Created on Jun 9, 2016, 9:24:07 AM
 */

#include "TestStateMachineUnit.h"
#include "StateMachine.h"
#include "MyAction.h"
#include "StateMachineBuildException.h"
#include "PositiveGuard.h"
#include "NegativeGuard.h"
#include "EventTypeGuard.h"

using namespace VtX::StateMachine;

CPPUNIT_TEST_SUITE_REGISTRATION(TestStateMachineUnit);

TestStateMachineUnit::TestStateMachineUnit() {
}

TestStateMachineUnit::~TestStateMachineUnit() {
}

void TestStateMachineUnit::setUp() {
}

void TestStateMachineUnit::tearDown() {
}

void TestStateMachineUnit::testStateMachine() {

}

void TestStateMachineUnit::testStateMachine2() {

}

void TestStateMachineUnit::testAddState() {
    StateMachine sm;
    State* state1 = new State("s1", State::ACTIVE, new MyAction(), new MyAction(), NULL);
    State* state2 = new State("s2", State::START);
    State* state3 = new State("s3", State::START);
    CPPUNIT_ASSERT_NO_THROW(sm.addState(NULL));
    CPPUNIT_ASSERT_NO_THROW(sm.addState(state1));
    CPPUNIT_ASSERT_NO_THROW(sm.addState(state2));
    CPPUNIT_ASSERT_THROW(sm.addState(state1), StateMachineBuildException);
    CPPUNIT_ASSERT_THROW(sm.addState(state3), StateMachineBuildException);
}

void TestStateMachineUnit::testAddTransition() {
    StateMachine sm;
    State* state1 = new State("s1", State::ACTIVE, new MyAction(), new MyAction(), NULL);
    State* state2 = new State("s2", State::START);
    State* state3 = new State("s3", State::END);
    sm.addState(state1);
    sm.addState(state2);
    Transition* tran1 = new Transition("t1", new BaseEvent(1, "e1"), new PositiveGuard(), state1, state2, NULL);
    Transition* tran2 = new Transition("t2", new BaseEvent(1, "e2"), new NegativeGuard(), state1, state3, NULL);
    Transition* tran3 = new Transition("t3", new BaseEvent(1, "e3"), new PositiveGuard(), state3, state1, NULL);
    CPPUNIT_ASSERT_NO_THROW(sm.addTransition(NULL));
    CPPUNIT_ASSERT_NO_THROW(sm.addTransition(tran1));
    CPPUNIT_ASSERT_THROW(sm.addTransition(tran2), StateMachineBuildException);
    CPPUNIT_ASSERT_THROW(sm.addTransition(tran3), StateMachineBuildException);
}

void TestStateMachineUnit::testBuild() {
    StateMachine sm;
    State* state1 = new State("s1", State::ACTIVE, new MyAction(), new MyAction(), NULL);
    State* state2 = new State("start", State::START);
    State* state3 = new State("s3", State::ACTIVE, new MyAction(), new MyAction(), NULL);
    State* state4 = new State("end", State::END);
    Transition* tran1 = new Transition("t1", new BaseEvent(1, "e1"), new PositiveGuard(), state2, state1, NULL);
    Transition* tran2 = new Transition("t2", new BaseEvent(1, "e2"), new NegativeGuard(), state1, state3, NULL);
    Transition* tran3 = new Transition("t3", new BaseEvent(1, "e3"), new PositiveGuard(), state3, state1, NULL);
    Transition* tran4 = new Transition("t4", new BaseEvent(1, "e4"), new PositiveGuard(), state3, state4, NULL);

    CPPUNIT_ASSERT_THROW(sm.build(), StateMachineBuildException);
    sm.addState(state1);
    sm.addState(state3);
    CPPUNIT_ASSERT_THROW(sm.build(), StateMachineBuildException);
    sm.addTransition(tran2);
    CPPUNIT_ASSERT_THROW(sm.build(), StateMachineBuildException);
    sm.addState(state2);
    CPPUNIT_ASSERT_THROW(sm.build(), StateMachineBuildException);
    sm.addState(state4);
    CPPUNIT_ASSERT_THROW(sm.build(), StateMachineBuildException);
    sm.addTransition(tran3);
    CPPUNIT_ASSERT_THROW(sm.build(), StateMachineBuildException);
    sm.addTransition(tran4);
    CPPUNIT_ASSERT_THROW(sm.build(), StateMachineBuildException);
    sm.addTransition(tran1);
    CPPUNIT_ASSERT_NO_THROW(sm.build());
}

void TestStateMachineUnit::testDispatchEvent() {
    StateMachine sm;
    State* sStart = new State("start", State::START);
    State* s1 = new State("s1", State::ACTIVE, new MyAction(), new MyAction(), NULL);
    State* s2 = new State("s2", State::ACTIVE, new MyAction(), new MyAction(), NULL);
    State* s21 = new State("s21", State::ACTIVE, new MyAction(), new MyAction(), s2);
    State* s22 = new State("s22", State::ACTIVE, new MyAction(), new MyAction(), s2);
    State* sEnd = new State("end", State::END);
    BaseEvent* e1 = new BaseEvent(1, "e1");
    BaseEvent* e2 = new BaseEvent(2, "e2");
    BaseEvent* e3 = new BaseEvent(3, "e3");
    BaseEvent* e4 = new BaseEvent(4, "e4");
    BaseEvent* e5 = new BaseEvent(5, "e5");
    BaseEvent* ie = new BaseEvent(6, "ie");
    Transition* start_s1 = new Transition("start_s1", e1, new EventTypeGuard(e1), sStart, s1, new MyAction());
    Transition* s1_s2 = new Transition("s1_s2", e2, new EventTypeGuard(e2), s1, s2, new MyAction());
    Transition* start_s2 = new Transition("start_s2", e3, new EventTypeGuard(e3), sStart, s2, new MyAction());
    Transition* s2_end = new Transition("s2_end", e4, new EventTypeGuard(e4), s2, sEnd, new MyAction());
    Transition* s1_end = new Transition("s1_end", e5, new EventTypeGuard(e5), s1, sEnd, new MyAction());
    Transition* s1_s1_ie = new Transition("s1_s1_ie", ie, new EventTypeGuard(ie), s1, new MyAction());
    Transition* s2_s21 = new Transition("s2_s21", e3, new EventTypeGuard(e3),s2,s21, NULL);
    Transition* s21_s1 = new Transition("s21_s1", e5, new EventTypeGuard(e5),s21,s1,NULL);
    Transition* s21_s22 = new Transition("s21_s22", e1, new EventTypeGuard(e1),s21,s22,NULL);
    Transition* s22_end = new Transition("s22_end",e1,new EventTypeGuard(e1),s22,sEnd,NULL);
    
    CPPUNIT_ASSERT(sm.dispatchEvent(NULL) == false);
    CPPUNIT_ASSERT_THROW(sm.dispatchEvent(e1), StateMachineBuildException);
    sm.addState(sStart);
    sm.addState(s1);
    sm.addState(s2);
    sm.addState(s21);
    sm.addState(s22);
    sm.addState(sEnd);
    sm.addTransition(start_s1);
    sm.addTransition(s1_s2);
    sm.addTransition(start_s2);
    sm.addTransition(s2_end);
    sm.addTransition(s1_end);
    sm.addTransition(s1_s1_ie);
    sm.addTransition(s2_s21);
    sm.addTransition(s21_s1);
    sm.addTransition(s21_s22);
    sm.addTransition(s22_end);
    sm.setMaxTransition(-1);
    sm.build();
    CPPUNIT_ASSERT_THROW(sm.dispatchEvent(e1), StateMachineBuildException);
    sm.setMaxTransition(0);
    CPPUNIT_ASSERT(sm.dispatchEvent(e1) == false);
    sm.setMaxTransition(100);
    CPPUNIT_ASSERT(sm.getCurrentState() == sStart);
    CPPUNIT_ASSERT(sm.dispatchEvent(e5) == false);
    CPPUNIT_ASSERT(sm.getCurrentState() == sStart);
    CPPUNIT_ASSERT(sm.dispatchEvent(e1) == true);
    CPPUNIT_ASSERT(sm.getCurrentState() == s1);
    CPPUNIT_ASSERT(sm.dispatchEvent(ie) == true);
    CPPUNIT_ASSERT(sm.getCurrentState() == s1);
    CPPUNIT_ASSERT(sm.dispatchEvent(e2) == true);
    CPPUNIT_ASSERT(sm.getCurrentState() == s2);
    CPPUNIT_ASSERT(sm.dispatchEvent(e3) == true);
    CPPUNIT_ASSERT(sm.getCurrentState() == s21);
    CPPUNIT_ASSERT(sm.dispatchEvent(e1) == true);
    CPPUNIT_ASSERT(sm.getCurrentState() == sEnd);
}

