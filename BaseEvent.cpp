/* 
 * File:   BaseEvent.cpp
 * Author: ttdk
 * 
 * Created on June 4, 2016, 9:05 AM
 */

#include "BaseEvent.h"

namespace VtX {
    namespace StateMachine {

//        BaseEvent::BaseEvent() {
//        }
//
//        BaseEvent::BaseEvent(const BaseEvent& orig) {
//        }

        BaseEvent::~BaseEvent() {
        }

        /**
         * This function is constructor within full parameter
         * @param type  - type of event
         * @param name  - name of event
         * @param data  - data of event
         */
        BaseEvent::BaseEvent(int type, std::string name, BaseObject* data) {
            init(type, name, data);
        }

        /**
         * This function is constructor without data. 
         * @param type  - type of event
         * @param name  - name of event
         */
        BaseEvent::BaseEvent(int type, std::string name) {
            init(type, name, NULL);
        }

        /**
         * This function is constructor without name. The default name is unknown event
         * @param type  - type of event
         * @param data  - data of event
         */
        BaseEvent::BaseEvent(int type, BaseObject* data) {
            init(type, "unknown event", data);
        }

        /**
         * This function is constructor without type. The default type value is -1
         * @param name  - name of event
         * @param data  - data of event
         */
        BaseEvent::BaseEvent(std::string name, BaseObject* data) {
            init(-1, name, data);
        }

        /**
         * This function is used to initializing object with full attributes
         * @param type  - type of event
         * @param name  - name of event
         * @param data  - data of event
         */
        void BaseEvent::init(int type, std::string name, BaseObject* data) {
            this->type = type;
            this->name = name;
            this->data = data;
        }

    }
}



