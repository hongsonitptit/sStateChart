/* 
 * File:   OnChangeStateListener.h
 * Author: ttdk
 *
 * Created on June 13, 2016, 10:16 AM
 */

#ifndef ONCHANGESTATELISTENER_H
#define	ONCHANGESTATELISTENER_H

namespace VtX {
    namespace StateMachine {

        class OnChangeStateListener {
        public:
            virtual void onChangeState(State* oldState, State* newState) = 0;
        };
    }
}

#endif	/* ONCHANGESTATELISTENER_H */

