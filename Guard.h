/* 
 * File:   Guard.h
 * Author: ttdk
 *
 * Created on June 5, 2016, 8:50 AM
 */

#ifndef GUARD_H
#define	GUARD_H

#include "BaseEvent.h"
#include "State.h"

namespace VtX {
    namespace StateMachine {
        class Guard {
        public:
            virtual bool accept(BaseEvent* event, State* currentState) = 0;
        };
    }
}

#endif	/* GUARD_H */

