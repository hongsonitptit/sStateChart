/* 
 * File:   NegativeGuard.h
 * Author: ttdk
 *
 * Created on June 6, 2016, 4:47 PM
 */

#ifndef NEGATIVEGUARD_H
#define	NEGATIVEGUARD_H

#include "Guard.h"

namespace VtX {
    namespace StateMachine {
        class NegativeGuard : public Guard {

            virtual bool accept(BaseEvent* event, State* currentState) {
                //always reject every event to every state
                return false;
            };
        };
    }
}


#endif	/* NEGATIVEGUARD_H */

