/* 
 * File:   EventTypeGuard.h
 * Author: ttdk
 *
 * Created on June 9, 2016, 11:18 AM
 */

#ifndef EVENTTYPEGUARD_H
#define	EVENTTYPEGUARD_H

#include "Guard.h"


namespace VtX {
    namespace StateMachine {

        class EventTypeGuard : public Guard{
        public:
            EventTypeGuard(BaseEvent *event);
            EventTypeGuard(const EventTypeGuard& orig);
            virtual ~EventTypeGuard();
            virtual bool accept(BaseEvent* event, State* currentState);
        private:
            BaseEvent* event;
        };
    }
}



#endif	/* EVENTTYPEGUARD_H */

