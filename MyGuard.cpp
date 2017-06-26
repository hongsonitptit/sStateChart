/* 
 * File:   MyGuard.cpp
 * Author: ttdk
 * 
 * Created on June 8, 2016, 4:56 PM
 */

#include "MyGuard.h"

namespace VtX {
    namespace StateMachine {

        MyGuard::MyGuard() {
        }

        MyGuard::MyGuard(const MyGuard& orig) {
        }

        MyGuard::~MyGuard() {
        }

        bool MyGuard::accept(BaseEvent* event, State* currentState) {
            if(event != NULL && event->getType() == 5) {
                return true;
            }
            return false;
        }

    }
}



