/*
 * File:   TestStateMachineUnit.h
 * Author: ttdk
 *
 * Created on Jun 9, 2016, 9:24:07 AM
 */

#ifndef TESTSTATEMACHINEUNIT_H
#define	TESTSTATEMACHINEUNIT_H

#include <cppunit/extensions/HelperMacros.h>

class TestStateMachineUnit : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestStateMachineUnit);

    CPPUNIT_TEST(testStateMachine);
    CPPUNIT_TEST(testStateMachine2);
    CPPUNIT_TEST(testAddState);
    CPPUNIT_TEST(testAddTransition);
    CPPUNIT_TEST(testBuild);
    CPPUNIT_TEST(testDispatchEvent);

    CPPUNIT_TEST_SUITE_END();

public:
    TestStateMachineUnit();
    virtual ~TestStateMachineUnit();
    void setUp();
    void tearDown();

private:
    void testStateMachine();
    void testStateMachine2();
    void testAddState();
    void testAddTransition();
    void testBuild();
    void testDispatchEvent();

};

#endif	/* TESTSTATEMACHINEUNIT_H */

