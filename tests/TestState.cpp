/*
 * File:   TestState.cpp
 * Author: ttdk
 *
 * Created on Jun 8, 2016, 5:03:53 PM
 */

#include "TestState.h"
#include "State.h"
#include "StateMachineBuildException.h"
#include "MyAction.h"

using namespace VtX::StateMachine;

CPPUNIT_TEST_SUITE_REGISTRATION(TestState);

TestState::TestState() {
}

TestState::~TestState() {
}

void TestState::setUp() {
}

void TestState::tearDown() {
}

void TestState::testState() {
    std::string name = "state 1";
    State::StateType type = State::START;
    BaseAction* entryAction = NULL;
    BaseAction* exitAction = NULL;
    State* parent = NULL;
    State* state1;
    CPPUNIT_ASSERT_NO_THROW(state1 = new State(name, type, entryAction, exitAction, parent));
    type = State::END;
    CPPUNIT_ASSERT_NO_THROW(state1 = new State(name, type, entryAction, exitAction, parent));
    type = State::ACTIVE;
    CPPUNIT_ASSERT_THROW(state1 = new State(name, type, entryAction, exitAction, parent),StateMachineBuildException);
    entryAction = new MyAction();
    CPPUNIT_ASSERT_THROW(state1 = new State(name, type, entryAction, exitAction, parent),StateMachineBuildException);
    exitAction = new MyAction();
    CPPUNIT_ASSERT_NO_THROW(state1 = new State(name, type, entryAction, exitAction, parent));
    
    CPPUNIT_ASSERT(state1->getName() == name);
    CPPUNIT_ASSERT(state1->getType() == State::ACTIVE);
    CPPUNIT_ASSERT(state1->getEntryAction() == entryAction);
    CPPUNIT_ASSERT(state1->getExitAction() == exitAction);
    CPPUNIT_ASSERT(state1->getParent() == NULL);
    
}

void TestState::testState2() {
    std::string name = "state 2";
    BaseAction* entryAction = NULL;
    BaseAction* exitAction = NULL;
    State* parent = NULL;
    State* state;
    CPPUNIT_ASSERT_THROW(state = new State(name,entryAction,exitAction,parent),StateMachineBuildException);
    entryAction = new MyAction();
    CPPUNIT_ASSERT_THROW(state = new State(name,entryAction,exitAction,parent),StateMachineBuildException);
    exitAction = new MyAction();
    CPPUNIT_ASSERT_NO_THROW(state = new State(name,entryAction,exitAction,parent));
    CPPUNIT_ASSERT(state->getName() == name);
    CPPUNIT_ASSERT(state->getType() == State::ACTIVE);
    CPPUNIT_ASSERT(state->getEntryAction() == entryAction);
    CPPUNIT_ASSERT(state->getExitAction() == exitAction);
    CPPUNIT_ASSERT(state->getParent() == NULL);
}

void TestState::testState3() {
    std::string name = "state3";
    State::StateType type = State::START;
    BaseAction* entryAction = NULL;
    BaseAction* exitAction = NULL;
//    VtX::StateMachine::State state(name, type, entryAction, exitAction);
    State* state;
    CPPUNIT_ASSERT_NO_THROW(state = new State(name,type,entryAction,exitAction));
    type = State::END;
    CPPUNIT_ASSERT_NO_THROW(state = new State(name,type,entryAction,exitAction));
    type = State::ACTIVE;
    CPPUNIT_ASSERT_THROW(state = new State(name,type,entryAction,exitAction),StateMachineBuildException);
    entryAction = new MyAction();
    CPPUNIT_ASSERT_THROW(state = new State(name,type,entryAction,exitAction),StateMachineBuildException);
    exitAction = new MyAction();
    CPPUNIT_ASSERT_NO_THROW(state = new State(name,type,entryAction,exitAction));
    CPPUNIT_ASSERT(state->getName() == name);
    CPPUNIT_ASSERT(state->getType() == State::ACTIVE);
    CPPUNIT_ASSERT(state->getEntryAction() == entryAction);
    CPPUNIT_ASSERT(state->getExitAction() == exitAction);
    CPPUNIT_ASSERT(state->getParent() == NULL);
}

void TestState::testEqual() {
    State* other = NULL;
    VtX::StateMachine::State* state = new State("state1", State::START);
    State* state2 = new State("state2",State::START);
    CPPUNIT_ASSERT(state->equal(other) == false);
    CPPUNIT_ASSERT(state->equal(state) == true);
    other = new State("other",State::END);
    CPPUNIT_ASSERT(state->equal(other) == false);
    CPPUNIT_ASSERT(state->equal(state2) == false);
}

void TestState::testGetLeastCommonParent() {
    State* superState = NULL;
    State* subState11 =  NULL,*subState12 = NULL;
    State* subState21 = NULL,*subState22 = NULL;
    superState = new State("super state",State::ACTIVE,new MyAction(),new MyAction(),NULL);
    subState11 = new State("state 11",State::ACTIVE,new MyAction(),new MyAction(),superState);
    subState12 = new State("state 12",State::ACTIVE,new MyAction(),new MyAction(),superState);
    subState21 = new State("state 21",State::ACTIVE,new MyAction(),new MyAction(),subState11);
    subState22 = new State("state 22",State::ACTIVE,new MyAction(),new MyAction(),subState12);
    CPPUNIT_ASSERT(superState->getLeastCommonParent(NULL) == NULL);
    CPPUNIT_ASSERT(superState->getLeastCommonParent(superState) == superState);
    CPPUNIT_ASSERT(subState11->getLeastCommonParent(subState22) == superState);
    CPPUNIT_ASSERT(subState21->getLeastCommonParent(subState22) == superState);
    CPPUNIT_ASSERT(subState22->getLeastCommonParent(new State("ending state",State::END)) == NULL);
}

void TestState::testHasChildren() {
    State* superState = NULL;
    State* subState11 =  NULL;
    superState = new State("super state",State::ACTIVE,new MyAction(),new MyAction(),NULL);
    subState11 = new State("state 11",State::ACTIVE,new MyAction(),new MyAction(),superState);
    CPPUNIT_ASSERT(superState->hasChildren() == true);
    CPPUNIT_ASSERT(subState11->hasChildren() == false);
}

void TestState::testHasParent() {
    State* superState = NULL;
    State* subState11 =  NULL;
    superState = new State("super state",State::ACTIVE,new MyAction(),new MyAction(),NULL);
    subState11 = new State("state 11",State::ACTIVE,new MyAction(),new MyAction(),superState);
    CPPUNIT_ASSERT(superState->hasParent() == false);
    CPPUNIT_ASSERT(subState11->hasParent() == true);
}

void TestState::testIsEndState() {
    State* endState = new State("s1",State::END);
    State* state = new State("s2",State::START);
    CPPUNIT_ASSERT(endState->isEndState() == true);
    CPPUNIT_ASSERT(state->isEndState() == false);
}

void TestState::testIsStartState() {
    State* endState = new State("s1",State::END);
    State* state = new State("s2",State::START);
    CPPUNIT_ASSERT(endState->isStartState() == false);
    CPPUNIT_ASSERT(state->isStartState() == true);
}

void TestState::testIsSubstate() {
    State* superState = NULL;
    State* subState11 =  NULL;
    superState = new State("super state",State::ACTIVE,new MyAction(),new MyAction(),NULL);
    subState11 = new State("state 11",State::ACTIVE,new MyAction(),new MyAction(),superState);
    CPPUNIT_ASSERT(superState->isSubstate() == false);
    CPPUNIT_ASSERT(subState11->isSubstate() == true);
}

void TestState::testIsSubstateOf() {
    State* superState = NULL;
    State* subState11 =  NULL;
    superState = new State("super state",State::ACTIVE,new MyAction(),new MyAction(),NULL);
    subState11 = new State("state 11",State::ACTIVE,new MyAction(),new MyAction(),superState);
    CPPUNIT_ASSERT(superState->isSubstateOf(NULL) == false);
    CPPUNIT_ASSERT(superState->isSubstateOf(superState) == false);
    CPPUNIT_ASSERT(subState11->isSubstateOf(superState) == true);
    CPPUNIT_ASSERT(superState->isSubstateOf(subState11) == false);
    CPPUNIT_ASSERT(subState11->isSubstateOf(new State("s2",State::END)) == false);
}

