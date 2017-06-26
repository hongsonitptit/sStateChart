/* 
 * File:   MyAction.cpp
 * Author: ttdk
 * 
 * Created on June 8, 2016, 10:47 AM
 */

#include "MyAction.h"
#include <iostream>

namespace VtX {
    namespace StateMachine {

        MyAction::MyAction() {
        }

        MyAction::MyAction(const MyAction& orig) {
        }

        MyAction::~MyAction() {
        }

        BaseEvent* MyAction::doAction(BaseEvent* event) {
            std::cout<<"Do something"<<std::endl;
//            return new BaseEvent(2,"e2");
            return NULL;
        }

    }
}



