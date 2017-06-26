/* 
 * File:   MyAction.h
 * Author: ttdk
 *
 * Created on June 8, 2016, 10:47 AM
 */

#ifndef MYACTION_H
#define	MYACTION_H

#include "BaseAction.h"

namespace VtX {
    namespace StateMachine {

        class MyAction : public BaseAction {
        public:
            MyAction();
            MyAction(const MyAction& orig);
            virtual ~MyAction();
            virtual BaseEvent* doAction(BaseEvent* event);

        private:

        };
    }
}



#endif	/* MYACTION_H */

