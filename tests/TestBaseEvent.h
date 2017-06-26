/*
 * File:   TestBaseEvent.h
 * Author: ttdk
 *
 * Created on Jun 8, 2016, 4:15:38 PM
 */

#ifndef TESTBASEEVENT_H
#define	TESTBASEEVENT_H

#include <cppunit/extensions/HelperMacros.h>

class TestBaseEvent : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestBaseEvent);

    CPPUNIT_TEST(testBaseEvent);
    CPPUNIT_TEST(testBaseEvent2);
    CPPUNIT_TEST(testBaseEvent3);
    CPPUNIT_TEST(testBaseEvent4);

    CPPUNIT_TEST_SUITE_END();

public:
    TestBaseEvent();
    virtual ~TestBaseEvent();
    void setUp();
    void tearDown();

private:
    void testBaseEvent();
    void testBaseEvent2();
    void testBaseEvent3();
    void testBaseEvent4();

};

#endif	/* TESTBASEEVENT_H */

