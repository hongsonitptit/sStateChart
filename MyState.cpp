/* 
 * File:   MyState.cpp
 * Author: ttdk
 * 
 * Created on August 31, 2016, 9:39 AM
 */

#include "MyState.h"

MyState::MyState(std::string name, StateType type, State* parrent) {
        MyStateEntryAction* entryAction = new MyStateEntryAction(this);
        MyStateExitAction* exitAction = new MyStateExitAction(this);
        init(name,type,entryAction,exitAction,parrent);
        //set action here
};

MyState::MyState(const MyState& orig) {
}
    
MyState::~MyState() {
}

