/*
 * File:   TestState.h
 * Author: ttdk
 *
 * Created on Jun 8, 2016, 5:03:53 PM
 */

#ifndef TESTSTATE_H
#define	TESTSTATE_H

#include <cppunit/extensions/HelperMacros.h>

class TestState : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestState);

    CPPUNIT_TEST(testState);
    CPPUNIT_TEST(testState2);
    CPPUNIT_TEST(testState3);
    CPPUNIT_TEST(testEqual);
    CPPUNIT_TEST(testGetLeastCommonParent);
    CPPUNIT_TEST(testHasChildren);
    CPPUNIT_TEST(testHasParent);
    CPPUNIT_TEST(testIsEndState);
    CPPUNIT_TEST(testIsStartState);
    CPPUNIT_TEST(testIsSubstate);
    CPPUNIT_TEST(testIsSubstateOf);

    CPPUNIT_TEST_SUITE_END();

public:
    TestState();
    virtual ~TestState();
    void setUp();
    void tearDown();

private:
    void testState();
    void testState2();
    void testState3();
    void testEqual();
    void testGetLeastCommonParent();
    void testHasChildren();
    void testHasParent();
    void testIsEndState();
    void testIsStartState();
    void testIsSubstate();
    void testIsSubstateOf();

};

#endif	/* TESTSTATE_H */

