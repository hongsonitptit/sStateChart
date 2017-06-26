/* 
 * File:   Transition.h
 * Author: ttdk
 *
 * Created on June 5, 2016, 8:54 AM
 */

#ifndef TRANSITION_H
#define	TRANSITION_H

#include "BaseEvent.h"
#include "Guard.h"
#include "BaseAction.h"
#include <string>

namespace VtX {
    namespace StateMachine {

        class Transition {
        public:

            enum TransitionType {
                //Internal transition: a response to an event that causes a change of state or a self-transition, together with a specified action. It may also cause the execution of exit and/or entry actions for states that are exited or entered
                INTERNAL_TRANSITION,
                //External transition: a response to an event that causes the execution of an action but does not cause a change of state or execution of exit or entry actions
                EXTERNAL_TRANSITION
            };

//            Transition();
//            Transition(const Transition& orig);
            virtual ~Transition();

            Transition(std::string name, BaseEvent* event, Guard *guard, State *inputState, State *outputState, BaseAction *action);
            Transition(std::string name, BaseEvent* event, Guard *guard, State *inputState, BaseAction *action);
            Transition(std::string name, BaseEvent* event, State *inputState, State* outputState, BaseAction *action);

            bool accept(BaseEvent *event);

            BaseAction* getAction() const {
                return action;
            }

            State* getInputState() const {
                return inputState;
            }

            BaseEvent* getEvent() const {
                return event;
            }

            Guard* getGuard() const {
                return guard;
            }

            State* getOutputState() const {
                return outputState;
            }

            TransitionType getType() const {
                return type;
            }

            std::string getName() const {
                return name;
            }

        private:
            TransitionType type;
            std::string name;
            BaseEvent *event;
            Guard *guard;
            State *inputState;
            State *outputState;
            BaseAction *action;

            void init(std::string name, TransitionType type, BaseEvent *event, Guard *guard, State *inputState, State *outputState, BaseAction *action);

        };
    }
}

#endif	/* TRANSITION_H */

