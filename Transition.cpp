/* 
 * File:   Transition.cpp
 * Author: ttdk
 * 
 * Created on June 5, 2016, 8:54 AM
 */

#include "Transition.h"
#include "PositiveGuard.h"
#include "StateMachineBuildException.h"

namespace VtX {
    namespace StateMachine {

//        Transition::Transition() {
//        }
//
//        Transition::Transition(const Transition& orig) {
//        }

        Transition::~Transition() {
        }

        /**
         * This is constructor with full parameters. 
         * If the input state and output state are same, it will create as an INTERNAL transition. 
         * Otherwise, it will create as an EXTERNAL transition.
         * @param name          - name of transition
         * @param event         - triggering event of transition
         * @param guard         - guard of transition
         * @param inputState    - input state
         * @param outputState   - output state
         * @param action        - action of transition
         */
        Transition::Transition(std::string name, BaseEvent *event, Guard* guard, State *inputState, State *outputState, BaseAction* action) {
            if (event == NULL) {
                throw StateMachineBuildException("The event of transition: " + name + " is NULL");
            }
            if (guard == NULL) {
                throw StateMachineBuildException("The guard of transition: " + name + " is NULL");
            }
            if (inputState == NULL) {
                throw StateMachineBuildException("The input state of transition: " + name + " is NULL");
            }
            if (outputState == NULL) {
                throw StateMachineBuildException("The output state of transition: " + name + " is NULL");
            }
            if (inputState == outputState) {
                init(name, INTERNAL_TRANSITION, event, guard, inputState, inputState, action);
            } else {
                init(name, EXTERNAL_TRANSITION, event, guard, inputState, outputState, action);
            }
        }

        /**
         * This is constructor without output state, the default output state value is input state and it will be created as an INTERNAL transition
         * @param name          - name of transition
         * @param event         - triggering event of transition
         * @param guard         - guard of transition
         * @param inputState    - input state
         * @param action        - action of transition
         */
        Transition::Transition(std::string name, BaseEvent *event, Guard* guard, State *inputState, BaseAction* action) {
            if (event == NULL) {
                throw StateMachineBuildException("The event of transition: " + name + " is NULL");
            }
            if (guard == NULL) {
                throw StateMachineBuildException("The guard of transition: " + name + " is NULL");
            }
            if (inputState == NULL) {
                throw StateMachineBuildException("The input state of transition: " + name + " is NULL");
            }
            init(name, INTERNAL_TRANSITION, event, guard, inputState, inputState, action);
        }

        /**
         * This function is used to initializing a transition with full attributes
         * @param name          - name of transition
         * @param type          - type of transition
         * @param event         - triggering event of transition
         * @param guard         - guard of transition
         * @param inputState    - input state
         * @param outputState   - output state
         * @param action        - action of transition
         */
        void Transition::init(std::string name, TransitionType type, BaseEvent* event, Guard* guard, State* inputState, State* outputState, BaseAction* action) {
            if (event == NULL) {
                throw StateMachineBuildException("The event of transition: " + name + " is NULL");
            }
            if (guard == NULL) {
                throw StateMachineBuildException("The guard of transition: " + name + " is NULL");
            }
            if (inputState == NULL) {
                throw StateMachineBuildException("The input state of transition: " + name + " is NULL");
            }
            if (outputState == NULL) {
                throw StateMachineBuildException("The output state of transition: " + name + " is NULL");
            }
            this->name = name;
            this->type = type;
            this->event = event;
            this->guard = guard;
            this->inputState = inputState;
            this->outputState = outputState;
            this->action = action;
        }

        /**
         * This function is used to checking suitable event for a transition
         * @param event
         * @return true if suitable, else false
         */
        bool Transition::accept(BaseEvent *event) {
            return guard->accept(event, inputState);
        }

    }
}



