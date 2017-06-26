/* 
 * File:   StateMachine.cpp
 * Author: ttdk
 * 
 * Created on June 5, 2016, 9:56 AM
 */

#include "StateMachine.h"
#include "StateMachineBuildException.h"
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>

namespace VtX {
    namespace StateMachine {

        StateMachine::StateMachine() {
            currentState = NULL;
            startState = NULL;
            maxTransition = MAX_TRANSITION_DEFAULT;
            transitionCounter = 0;
            initialized = false;
        }

        StateMachine::StateMachine(const StateMachine& orig) {
        }

        StateMachine::~StateMachine() {
        }

        /**
         * This function is used to adding a new state to state machine.
         * If the additional state have added or is the second starting state, 
         * it will throw an exception
         * @param state - new state
         */
        void StateMachine::addState(State *state) {
            if (state == NULL) {
                return;
            }
            if (checkExist(state)) {
                // throw exception: the state is already exist
                std::string err = "The state " + state->getName() + " is already exist";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            if (state->isStartState()) {
                if (startState != NULL) {
                    // throw exception: the initial state is already exist
                    std::string err = "We just have one start state";
                    std::cout << err << std::endl;
                    throw StateMachineBuildException(err);
                } else {
                    startState = state;
                }
            }
            states.push_back(state);
        }

        /**
         * This function is used to adding new transition  to state machine
         * If the input or output state of the new transition is not exist,
         * it will throw an exception
         * @param transition    - new transition
         */
        void StateMachine::addTransition(Transition *transition) {
            if (transition == NULL) {
                return;
            }
            if (!checkExist(transition->getInputState())) {
                // throw exception: the input state of this transition is not exist
                std::string err = "The input state: " + transition->getInputState()->getName() + " of transition: " + transition->getName() + " is not exist";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            if (!checkExist(transition->getOutputState())) {
                // throw exception: the output state of this transition is not exist
                std::string err = "The output state: " + transition->getOutputState()->getName() + " of transition: " + transition->getName() + " is not exist";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            transitions.push_back(transition);
        }

        /**
         * This function is used to building state machine before using.
         * It will throw some exceptions if match bellow case:
         *  - state machine has no state
         *  - state machine has no transition
         *  - state machine has no starting state
         *  - state machine has no ending state
         *  - state machine has some states that is unreachable
         *  - state machine has some states that is dead-end
         * @return true if build successful, else false
         */
        bool StateMachine::build() {
            //check state graph is not empty
            if (states.empty()) {
                // throw exception: State machine has no state
                std::string err = "State machine has no state";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            if (transitions.empty()) {
                // throw exception: State machine has no transition
                std::string err = "State machine has no transition";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            //Ensure we have a starting state
            if (startState == NULL) {
                // throw exception: State machine has no start state
                std::string err = "State machine has no starting state";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            //Ensure we have at least one ending state
            bool haveEndingState = false;
            for (int i = 0; i < states.size(); i++) {
                if (states.at(i)->isEndState()) {
                    haveEndingState = true;
                    break;
                }
            }
            if (!haveEndingState) {
                // throw exception: State machine has no ending state
                std::string err = "State machine has no ending state";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            //Ensure that every non-starting state has least one transition directly into it or to a its substate
            for (int i = 0; i < states.size(); i++) {
                State* state_tmp = states.at(i);
                if (state_tmp->isStartState()) {
                    continue;
                }
                bool hasTransitionInto = false;
                for (int j = 0; j < transitions.size(); j++) {
                    State* outputState = transitions.at(j)->getOutputState();
                    if (outputState->equal(state_tmp) || outputState->isSubstateOf(state_tmp)) {
                        hasTransitionInto = true;
                        break;
                    }
                }
                if (!hasTransitionInto) {
                    // throw exception: State has no inbound transition, hence is unreachable
                    std::string err = "State: " + state_tmp->getName() + " has no inbound transition, hence is unreachable";
                    std::cout << err << std::endl;
                    throw StateMachineBuildException(err);
                }
            }
            //Ensure that every non-ending state has least one transition go out of it or out of a its substate
            for (int i = 0; i < states.size(); i++) {
                State* state_tmp = states.at(i);
                if (state_tmp->isEndState()) {
                    continue;
                }
                bool hasTransitionOutOf = false;
                for (int j = 0; j < transitions.size(); j++) {
                    State* inputState = transitions.at(j)->getInputState();
                    if (inputState->equal(state_tmp) || inputState->isSubstateOf(state_tmp)) {
                        hasTransitionOutOf = true;
                        break;
                    }
                }
                if (!hasTransitionOutOf) {
                    // throw exception: State has no outbound transition, hence is dead-end
                    std::string err = "State: " + state_tmp->getName() + " has no outbound transition, hence is dead-end";
                    std::cout << err << std::endl;
                    throw StateMachineBuildException(err);
                }
            }
            //OK ready for use
            currentState = startState;
            initialized = true;
            std::cout << "State machine is build" << std::endl;
        }

        /**
         * This function is used to dispatching a event coming to state machine
         * @param event 
         * @return true if the event can made a transition, else false
         */
        bool StateMachine::dispatchEvent(BaseEvent *event) {
            if (event == NULL) {
                return false;
            }
            std::cout << "Dispatch event: " << event->getName() << " into State Machine" << std::endl;
            if (!initialized) {
                // throw exception: State machine is not build
                std::string err = "State machine is not build";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }

            if (maxTransition >= 0) {
                transitionCounter++;
                if (transitionCounter > maxTransition) {
                    // Max transition count exceeded
                    std::cout << "Max transition count exceeded at state: " << currentState->getName();
                    return false;
                }
            } else {
                std::string err = "Max transition is less than 0";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }

            //Find the next transition. This is guaranteed to be non-null
            Transition* transition_tmp = findTransition(event);
            if (transition_tmp == NULL) {
                // notify reject the input event
                std::cout << "Could not find any transition for input event: " << event->getName() << " at state: " << currentState->getName() << std::endl;
                return false;
            }

            //check type of transition
            if (transition_tmp->getType() == Transition::INTERNAL_TRANSITION) {
                // internal event
                // notify find the internal transition for event: in state:
                std::cout << "Find a internal transition: " << transition_tmp->getName() << " in state: " << currentState->getName() << std::endl;
                BaseEvent* nextEvent = NULL;
                if (transition_tmp->getAction() != NULL) {
                    BaseAction* action = transition_tmp->getAction();
                    // notify: execute action for transition: name
                    std::cout << "Execute action for transition: " << transition_tmp->getName() << std::endl;
                    nextEvent = action->doAction(event);
                }
                if (nextEvent != NULL) {
                    //notify the input event make a next event
                    std::cout << "The input event: " << event->getName() << " made a new event: " << nextEvent->getName() << std::endl;
                    //handle next event
                    dispatchEvent(nextEvent);
                }
            } else {
                // external event
                State* nextState = transition_tmp->getOutputState();
                std::cout << "Find a external transition: " << transition_tmp->getName() << " from state: " << currentState->getName() << " to state: " << nextState->getName() << std::endl;
                // notify find the external transition for event: from state: to state:
                int actionType = -1;
                //Find the least common parent between the current and next state
                State* leastCommonParentState = currentState->getLeastCommonParent(nextState);
                if (currentState != nextState) {
                    //Fire exit actions up to the state that has lower level than the least common parent state if it exist
                    State* exitState = currentState;
                    // notify: searching for exit actions for current state: 
                    std::cout << "Searching for exit actions for current state: " << currentState->getName() << std::endl;
                    while (exitState != NULL && exitState != leastCommonParentState) {
                        if (exitState->getExitAction() != NULL) {
                            BaseAction* exitAction = exitState->getExitAction();
                            actionType = BaseAction::EXIT_ACTION;
                            // notify: execute exit action for state: exit state
                            std::cout << "Execute exit action for state: " << exitState->getName() << std::endl;
                            exitAction->doAction(event);
                        }
                        exitState = exitState->getParent();
                    }
                }
                //Execute transition action if it exist
                BaseEvent* nextEvent = NULL;
                if (transition_tmp->getAction() != NULL) {
                    BaseAction* transitionAction = transition_tmp->getAction();
                    actionType = BaseAction::TRANSITION_ACTION;
                    // notify: execute action for transition: name
                    std::cout << "Execute action for transition: " << transition_tmp->getName() << std::endl;
                    nextEvent = transitionAction->doAction(event);
                }
                //Execute entry actions down to the least common parent state to the next state
                if (currentState != nextState) {
                    // notify: Searching for entry actions for next state
                    std::cout << "Searching for entry actions for the next state: " << nextState->getName() << std::endl;
                    //Fire entry actions from the state below the least common parent state (if there is one) to the next state
                    std::vector<State*> listEntryState = nextState->getHierarchy();
                    int startIndex = -1;
                    if (leastCommonParentState == NULL) {
                        startIndex = 0;
                    } else {
                        for (int i = 0; i < listEntryState.size(); i++) {
                            if (listEntryState.at(i) == leastCommonParentState) {
                                startIndex = i + 1;
                                break;
                            }
                        }
                    }
                    for (int i = startIndex; i < listEntryState.size(); i++) {
                        State* entryState = listEntryState.at(i);
                        if (entryState->getEntryAction() != NULL) {
                            BaseAction* entryAction = entryState->getEntryAction();
                            actionType = BaseAction::ENTRY_ACTION;
                            // notify: execute entry action for state: entry state
                            std::cout << "Execute entry action for state: " << entryState->getName() << std::endl;
                            entryAction->doAction(event);
                        }
                    }
                }

                //if we have changed state, move to the new state and notify to listener
                if (currentState != nextState) {
                    // notify: enter to new state
                    std::cout << "Enter to the new state " << nextState->getName() << std::endl;
                    State* prevState = currentState;
                    currentState = nextState;
                    // notify to listener
                    for(int i=0; i<changeStateListeners.size(); i++) {
                        changeStateListeners.at(i)->onChangeState(prevState,nextState);
                    }
                    //Check if event made a transition chain or not
                    Transition* nextTransition = findTransition(event);
                    if (nextTransition != NULL && nextTransition->getOutputState() != currentState) {
                        dispatchEvent(event);
                    }
                }

                if (nextEvent != NULL) {
                    //notify the input event make a next event
                    std::cout << "The input event: " << event->getName() << " made a new event: " << nextEvent->getName() << std::endl;
                    //handle next event
                    dispatchEvent(nextEvent);
                }
            }

            return true;
        }

        /**
         * This function is used to checking the exist of a state in State machine
         * @param state 
         * @return true if exist, else false
         */
        bool StateMachine::checkExist(State *state) {
            if (state == NULL) {
                return false;
            }
            for (int i = 0; i < states.size(); i++) {
                if (states.at(i)->equal(state)) {
                    return true;
                }
            }
            return false;
        }

        /**
         * This function is used to finding a transition that can make by input event
         * from current state and all its parent
         * @param event
         * @return a transition if exist, else NULL
         */
        Transition* StateMachine::findTransition(BaseEvent* event) {
            if (event == NULL) {
                return NULL;
            }
            State* matchingState = currentState;
            while (matchingState != NULL) {
                for (int i = 0; i < transitions.size(); i++) {
                    Transition* transition_tmp = transitions.at(i);
                    if (transition_tmp->accept(event) &&
                            (currentState->equal(transition_tmp->getInputState()) || currentState->isSubstateOf(transition_tmp->getInputState()))) {
                        return transition_tmp;
                    }
                }
                matchingState = currentState->getParent();
            }
            //reach here if do not find any transition for input event
            return NULL;
        }

    }
}



