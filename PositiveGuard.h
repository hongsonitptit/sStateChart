/* 
 * File:   PositiveGuard.h
 * Author: ttdk
 *
 * Created on June 6, 2016, 11:11 AM
 */

#ifndef POSITIVEGUARD_H
#define	POSITIVEGUARD_H

#include "Guard.h"


namespace VtX {
    namespace StateMachine {
        class PositiveGuard : public Guard {

            virtual bool accept(BaseEvent* event, State* currentState) {
                //always accept every event to every state
                return true;
            };

        };
    }
}


#endif	/* POSITIVEGUARD_H */

