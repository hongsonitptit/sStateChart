/* 
 * File:   BaseAction.h
 * Author: ttdk
 *
 * Created on June 5, 2016, 7:49 AM
 */

#ifndef BASEACTION_H
#define	BASEACTION_H

#include "BaseEvent.h"

namespace VtX {
    namespace StateMachine {

        class BaseAction {
        public:
            static const int ENTRY_ACTION = 1;
            static const int EXIT_ACTION = 2;
            static const int TRANSITION_ACTION = 3;
            
//            BaseAction();
//            BaseAction(const BaseAction& orig);
            virtual ~BaseAction() {};
            virtual BaseEvent* doAction(BaseEvent* event) = 0;
        private:

        };
    }
}

#endif	/* BASEACTION_H */

