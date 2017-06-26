/* 
 * File:   MyState.h
 * Author: ttdk
 *
 * Created on August 31, 2016, 9:39 AM
 */

#ifndef MYSTATE_H
#define	MYSTATE_H

#include "State.h"

using namespace VtX::StateMachine;

class MyState : public State {

public:
    MyState(std::string name, StateType type, State* parrent);
    MyState(const MyState& orig);
    virtual ~MyState();
private:
    //declare your state info here
    
    class MyStateEntryAction : public BaseAction {
    public:

        MyStateEntryAction(MyState* state) {
            this->compositeState = state;
        };

        virtual BaseEvent* doAction(BaseEvent* event) {
            //do entry action here 
            //this->compositeState do something
        };

    private:
        MyState* compositeState;
    };
    
    class MyStateExitAction : public BaseAction {
    public:
        MyStateExitAction(MyState* state) {
            this->compositeState = state;
        };

        virtual BaseEvent* doAction(BaseEvent* event) {
            //do exit action here
            //this->compositeState do something
        };

    private:
        MyState* compositeState;
    };
    
};

#endif	/* MYSTATE_H */

