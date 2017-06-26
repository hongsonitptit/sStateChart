/* 
 * File:   State.cpp
 * Author: ttdk
 * 
 * Created on June 5, 2016, 8:10 AM
 */

#include "State.h"
#include "StateMachineBuildException.h"

namespace VtX {
    namespace StateMachine {

        State::State() {
        }
        //        //
        //        //        State::State(const State& orig) {
        //        //        }
        //

        State::~State() {
        }
        //
        //        /**
        //         * This function is constructor with full parameters
        //         * @param name          - name of state
        //         * @param type          - type of state
        //         * @param entryAction   - entry action
        //         * @param exitAction    - exit action   
        //         * @param parent        - parent of state
        //         */
        //        State::State(std::string name, StateType type, BaseAction* entryAction, BaseAction* exitAction, State* parent) {
        //            init(name, type, entryAction, exitAction, parent);
        //        }
        //
        //        /**
        //         * This function is constructor without state type. The default state type is ACTIVE
        //         * @param name          - name of state
        //         * @param entryAction   - entry action
        //         * @param exitAction    - exit action
        //         * @param parent        - parent of state
        //         */
        //        State::State(std::string name, BaseAction* entryAction, BaseAction* exitAction, State* parent) {
        //            init(name, ACTIVE, entryAction, exitAction, parent);
        //        }
        //
        //        /**
        //         * This function is constructor without parent
        //         * @param name          - name of state 
        //         * @param type          - type of state
        //         * @param entryAction   - entry action
        //         * @param exitAction    - exit action
        //         */
        //        State::State(std::string name, StateType type, BaseAction* entryAction, BaseAction* exitAction) {
        //            init(name, type, entryAction, exitAction, NULL);
        //        }
        //
        //        /**
        //         * This function is constructor for STARTING/ENDING state that is not required entry and exit actions
        //         * @param name  - name of state
        //         * @param type  - type of state
        //         */
        //        State::State(std::string name, StateType type) {
        //            if(type == START || type == END) {
        //                init(name,type,NULL,NULL,NULL);
        //            } else {
        //                throw StateMachineBuildException("Cannot build state because missing entry action and exit action");
        //            }
        //        }

        /**
         * This function is used to initializing object within full attributes
         * Note: 
         *  - Every ACTIVE states must have entry action and exit action.
         *  - The START state and END state can have or not
         * @param name          - name of state
         * @param type          - type of state
         * @param entryAction   - entry action
         * @param exitAction    - exit action
         * @param parent        - parent of state
         */
        void State::init(std::string name, StateType type, BaseAction* entryAction, BaseAction* exitAction, State* parent) {
            this->name = name;
            this->type = type;
            this->entryAction = entryAction;
            this->exitAction = exitAction;
            this->parent = parent;

            //if this state is ACTIVE, it must have entry and exit action
            if (type == ACTIVE) {
                if (entryAction == NULL) {
                    throw StateMachineBuildException("The entry action of state: " + name + " is NULL");
                }
                if (exitAction == NULL) {
                    throw StateMachineBuildException("The exit action of state: " + name + " is NULL");
                }
            }

            //if the parent is exist, add this to set of its sub-state and add prefix name
            if (parent != NULL) {
                parent->addChild(this);
                this->name = parent->getName() + ":" + name;
                this->hierarchy = parent->getHierarchy();
            }
            hierarchy.push_back(this);
        }

        /**
         * This function is used to checking whether this state has parent or not
         * @return true if state has a parent, else false
         */
        bool State::hasParent() {
            return parent != NULL;
        }

        /**
         * This function is used to checking whether this state has children or not
         * @return true if state has children, else false
         */
        bool State::hasChildren() {
            return !substates.empty();
        }

        /**
         * This function is used to add a new sub-state to this state.
         * If this state is sub-state's parent and the sub-state is this state's parent,
         * it will throw an exception that notify a bad design
         * @param substate  - new sub-state
         */
        void State::addChild(State* substate) {
            if (substate == NULL) {
                return;
            }
            if (this->isSubstateOf(substate)) {
                // notify: it is the bad hierarchy design
                std::string err = "This is circle inheritance in state, hence make a bad design";
                std::cout << err << std::endl;
                throw StateMachineBuildException(err);
            }
            for (int i = 0; i < substates.size(); i++) {
                if (substate->equal(this)) {
                    // this sub-state already is exist
                    std::cout << "The new sub-state: " << substate->getName() << "is already exist" << std::endl;
                    return;
                }
            }
            substates.push_back(substate);
        }

        /**
         * This function is used to checking whether this state is sub-state or not
         * @return true if this state is sub-state, else false
         */
        bool State::isSubstate() {
            return parent != NULL;
        }

        /**
         * This function is used to checking whether this state is starting state or not
         * @return true if this state is starting state, else false
         */
        bool State::isStartState() {
            return type == START;
        }

        /**
         * This function is used to checking whether this state is ending state or not
         * @return true if this state is ending state, else false
         */
        bool State::isEndState() {
            return type == END;
        }

        /**
         * This function is used to comparing this state with another by unique name
         * @param other - other state
         * @return true if equal, else false
         */
        bool State::equal(State* other) {
            if (other != NULL && this == other) {
                return name.compare(other->name) == 0;
            }
            return false;
        }

        /**
         * This function is used to checking whether this state is sub-state of anther or not
         * @param other     - other state
         * @return true if this state is sub-state of other state, else false
         */
        bool State::isSubstateOf(State* other) {
            if (other == NULL) {
                return false;
            }
            if (parent == NULL) {
                return false;
            } else if (parent == other) {
                return true;
            } else {
                return parent->isSubstateOf(other);
            }
        }

        /**
         * This function is used to finding the least common parent between this state and other
         * @param other - other state
         * @return parent state if exits, else NULL
         */
        State* State::getLeastCommonParent(State* other) {
            if (other == NULL) {
                return NULL;
            }
            State* commonParentState = NULL;
            std::vector<State*> otherHierarchy = other->getHierarchy();
            for (int i = 0; i<this->hierarchy.size(); i++) {
                if (otherHierarchy.size() <= i) {
                    break;
                } else if (this->hierarchy.at(i) == otherHierarchy.at(i)) {
                    commonParentState = this->hierarchy.at(i);
                } else {
                    break;
                }
            }
            return commonParentState;
        }

    }
}


