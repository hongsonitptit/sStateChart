/*
 * File:   TestTransition.h
 * Author: ttdk
 *
 * Created on Jun 8, 2016, 4:39:45 PM
 */

#ifndef TESTTRANSITION_H
#define	TESTTRANSITION_H

#include <cppunit/extensions/HelperMacros.h>

class TestTransition : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestTransition);

    CPPUNIT_TEST(testTransition);
    CPPUNIT_TEST(testTransition2);
    CPPUNIT_TEST(testAccept);

    CPPUNIT_TEST_SUITE_END();

public:
    TestTransition();
    virtual ~TestTransition();
    void setUp();
    void tearDown();

private:
    void testTransition();
    void testTransition2();
    void testAccept();

};

#endif	/* TESTTRANSITION_H */

