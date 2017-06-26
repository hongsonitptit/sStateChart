/*
 * File:   TestTransition.cpp
 * Author: ttdk
 *
 * Created on Jun 8, 2016, 4:39:46 PM
 */

#include "TestTransition.h"
#include "Transition.h"
#include "../StateMachineBuildException.h"
#include "../PositiveGuard.h"
#include "../NegativeGuard.h"
#include "MyGuard.h"

using namespace VtX::StateMachine;


CPPUNIT_TEST_SUITE_REGISTRATION(TestTransition);

TestTransition::TestTransition() {
}

TestTransition::~TestTransition() {
}

void TestTransition::setUp() {
}

void TestTransition::tearDown() {
}

void TestTransition::testTransition() {
    std::string name = "my transition";
    BaseEvent* event = NULL;
    Guard* guard = NULL;
    State* inputState = NULL;
    State* outputState = NULL;
    BaseAction* action = NULL;
    VtX::StateMachine::Transition* transition;

    CPPUNIT_ASSERT_THROW(transition = new Transition(name, event, guard, inputState, outputState, action), StateMachineBuildException);
    event = new BaseEvent(-1, NULL);
    CPPUNIT_ASSERT_THROW(transition = new Transition(name, event, guard, inputState, outputState, action), StateMachineBuildException);
    guard = new PositiveGuard();
    CPPUNIT_ASSERT_THROW(transition = new Transition(name, event, guard, inputState, outputState, action), StateMachineBuildException);
    inputState = new State("starting state", State::START, NULL, NULL);
    CPPUNIT_ASSERT_THROW(transition = new Transition(name, event, guard, inputState, outputState, action), StateMachineBuildException);
    outputState = new State("ending state", State::END, NULL, NULL);
    CPPUNIT_ASSERT_NO_THROW(transition = new Transition(name, event, guard, inputState, outputState, action));

}

void TestTransition::testTransition2() {
    std::string name = "transition 2";
    BaseEvent* event = NULL;
    Guard* guard = NULL;
    State* inputState = NULL;
    BaseAction* action = NULL;
    VtX::StateMachine::Transition* transition;
   
    CPPUNIT_ASSERT_THROW(transition = new Transition(name, event, guard, inputState, action),StateMachineBuildException);
    event = new BaseEvent(-1, "my event");
    CPPUNIT_ASSERT_THROW(transition = new Transition(name, event, guard, inputState, action),StateMachineBuildException);
    guard = new NegativeGuard();
    CPPUNIT_ASSERT_THROW(transition = new Transition(name, event, guard, inputState, action),StateMachineBuildException);
    inputState = new State("starting state", State::START, NULL, NULL);
    CPPUNIT_ASSERT_NO_THROW(transition = new Transition(name, event, guard, inputState, action));
}

void TestTransition::testAccept() {
    BaseEvent* event = new BaseEvent(10,"my event");
    VtX::StateMachine::Transition* transition1,*transition2,*transition3;
    std::string name = "transition 1";
    State* inputState = new State("starting state", State::START, NULL, NULL);
    transition1 = new Transition("transition1",event,new PositiveGuard(),inputState,NULL);    
    transition2 = new Transition("transition2",event,new NegativeGuard(),inputState,NULL);    
    MyGuard myGuard;
    transition3 = new Transition("transition2",event,&myGuard,inputState,NULL);
    CPPUNIT_ASSERT(transition1->accept(event));
    CPPUNIT_ASSERT(!transition2->accept(event));    
    CPPUNIT_ASSERT(!transition3->accept(event));
}

