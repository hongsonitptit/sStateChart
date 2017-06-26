/* 
 * File:   BaseObject.h
 * Author: ttdk
 *
 * Created on June 4, 2016, 9:03 AM
 */

#ifndef BASEOBJECT_H
#define	BASEOBJECT_H

namespace VtX {
    namespace StateMachine {

        class BaseObject {
        public:
            BaseObject();
            BaseObject(const BaseObject& orig);
            virtual ~BaseObject();
        private:

        };
    }
}



#endif	/* BASEOBJECT_H */

