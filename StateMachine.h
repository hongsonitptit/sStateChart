/* 
 * File:   StateMachine.h
 * Author: ttdk
 *
 * Created on June 5, 2016, 9:56 AM
 */

#ifndef STATEMACHINE_H
#define	STATEMACHINE_H

#include <vector>

#include "State.h"
#include "Transition.h"
#include "OnChangeStateListener.h"
#include "StateMachineBuildException.h"

namespace VtX {
    namespace StateMachine {

        class StateMachine {
        public:
            StateMachine();
            StateMachine(const StateMachine& orig);
            virtual ~StateMachine();

            void addState(State *state);
            void addTransition(Transition *transition);
            bool build();

            bool dispatchEvent(BaseEvent *event);

            State* getCurrentState() const {
                return currentState;
            }

            bool isEndState() {
                if (initialized) {
                    return currentState->isEndState();
                }
                throw StateMachineBuildException("State machine is not build");
            }

            void setMaxTransition(int maxTransition) {
                this->maxTransition = maxTransition;
            }

            void addChangeStateListener(OnChangeStateListener* listener) {
                if (listener != NULL) {
                    changeStateListeners.push_back(listener);
                }
            }

        private:

            static const int MAX_TRANSITION_DEFAULT = 1000;

            std::vector<State*> states;
            std::vector<Transition*> transitions;
            std::vector<OnChangeStateListener*> changeStateListeners;
            State *currentState;
            State *startState;

            int maxTransition;
            int transitionCounter;

            bool initialized;

            bool checkExist(State *state);
            Transition* findTransition(BaseEvent *event);
        };
    }
}



#endif	/* STATEMACHINE_H */

