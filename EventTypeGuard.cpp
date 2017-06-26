/* 
 * File:   EventTypeGuard.cpp
 * Author: ttdk
 * 
 * Created on June 9, 2016, 11:18 AM
 */

#include "EventTypeGuard.h"

namespace VtX {
    namespace StateMachine {

        EventTypeGuard::EventTypeGuard(BaseEvent *event) {
            this->event = event;
        }

        EventTypeGuard::EventTypeGuard(const EventTypeGuard& orig) {
        }

        EventTypeGuard::~EventTypeGuard() {
        }

        bool EventTypeGuard::accept(BaseEvent* event, State* currentState) {
            if(this->event == NULL || event == NULL) {
                return false;
            } else if(this->event->getType() == event->getType()){
                return true;
            } 
            return false;
        }

    }
}



