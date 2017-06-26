/* 
 * File:   MyGuard.h
 * Author: ttdk
 *
 * Created on June 8, 2016, 4:56 PM
 */

#ifndef MYGUARD_H
#define	MYGUARD_H

#include "Guard.h"


namespace VtX {
    namespace StateMachine {

        class MyGuard : public Guard {
        public:
            MyGuard();
            MyGuard(const MyGuard& orig);
            virtual ~MyGuard();

            virtual bool accept(BaseEvent* event, State* currentState);

        private:

        };
    }
}



#endif	/* MYGUARD_H */

