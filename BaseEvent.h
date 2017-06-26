/* 
 * File:   BaseEvent.h
 * Author: ttdk
 *
 * Created on June 4, 2016, 9:05 AM
 */

#ifndef BASEEVENT_H
#define	BASEEVENT_H

#include <string>

#include "BaseObject.h"

namespace VtX {
    namespace StateMachine {

        class BaseEvent {
        public:
//            BaseEvent();
//            BaseEvent(const BaseEvent& orig);
            virtual ~BaseEvent();
            BaseEvent(int type, std::string name, BaseObject *data);
            BaseEvent(int type, std::string name);
            BaseEvent(int type, BaseObject *data);
            BaseEvent(std::string name, BaseObject *data);

            BaseObject* getData() const {
                return data;
            }

            std::string getName() const {
                return name;
            }

            int getType() const {
                return type;
            }

        private:
            int type;
            std::string name;
            BaseObject *data;
            void init(int type, std::string name, BaseObject *data);
        };
    }
}



#endif	/* BASEEVENT_H */

