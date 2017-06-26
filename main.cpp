/* 
 * File:   main.cpp
 * Author: ttdk
 *
 * Created on June 4, 2016, 9:03 AM
 */

#include <cstdlib>
#include <iostream>

#include "TestStateMachine.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TestStateMachine testSM;
    testSM.testNoState();
    testSM.testNoStartingState();
    testSM.testNoEndingState();
    return 0;
}

