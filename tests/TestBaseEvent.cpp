/*
 * File:   TestBaseEvent.cpp
 * Author: ttdk
 *
 * Created on Jun 8, 2016, 4:15:38 PM
 */

#include "TestBaseEvent.h"
#include "BaseEvent.h"
#include "../BaseObject.h"

using namespace VtX::StateMachine;

CPPUNIT_TEST_SUITE_REGISTRATION(TestBaseEvent);

TestBaseEvent::TestBaseEvent() {
}

TestBaseEvent::~TestBaseEvent() {
}

void TestBaseEvent::setUp() {
}

void TestBaseEvent::tearDown() {
}

void TestBaseEvent::testBaseEvent() {
    int type = -1;
    std::string name = "my event";
    BaseObject* data = NULL;
    VtX::StateMachine::BaseEvent baseEvent(type, name, data);
    CPPUNIT_ASSERT(baseEvent.getType() == type);
    CPPUNIT_ASSERT(baseEvent.getName() == name);
    CPPUNIT_ASSERT(baseEvent.getData() == data);
}

void TestBaseEvent::testBaseEvent2() {
    int type = 10;
    std::string name = "new event";
    VtX::StateMachine::BaseEvent baseEvent(type, name);
    CPPUNIT_ASSERT(baseEvent.getType() == type);
    CPPUNIT_ASSERT(baseEvent.getName() == name);
    CPPUNIT_ASSERT(baseEvent.getData() == NULL);
}

void TestBaseEvent::testBaseEvent3() {
    int type = 100;
    BaseObject* data = NULL;
    VtX::StateMachine::BaseEvent baseEvent(type, data);
    CPPUNIT_ASSERT(baseEvent.getType() == type);
    CPPUNIT_ASSERT(baseEvent.getName() == "unknown event");
    CPPUNIT_ASSERT(baseEvent.getData() == NULL);
}

void TestBaseEvent::testBaseEvent4() {
    std::string name = "my event";
    BaseObject* data = NULL;
    VtX::StateMachine::BaseEvent baseEvent(name, data);
    CPPUNIT_ASSERT(baseEvent.getType() == -1);
    CPPUNIT_ASSERT(baseEvent.getName() == name);
    CPPUNIT_ASSERT(baseEvent.getData() == NULL);
}

