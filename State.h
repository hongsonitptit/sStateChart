/* 
 * File:   State.h
 * Author: ttdk
 *
 * Created on June 5, 2016, 8:10 AM
 */

#ifndef STATE_H
#define	STATE_H

#include "BaseAction.h"

#include <vector>
#include <string>
#include <iostream>

namespace VtX {
    namespace StateMachine {

        class State {
        public:

            enum StateType {
                START,
                ACTIVE,
                END
            };

//            State();
//            State(const State& orig);
            virtual ~State();
            
            
//            State(std::string name, StateType type, BaseAction *entryAction, BaseAction *exitAction, State *parent);
//            State(std::string name, BaseAction *entryAction, BaseAction *exitAction, State *parent);
//            State(std::string name, StateType type, BaseAction *entryAction, BaseAction *exitAction);
//            State(std::string name, StateType type);
            
            BaseAction* getEntryAction() const {
                return entryAction;
            }

            BaseAction* getExitAction() const {
                return exitAction;
            }

            std::string getName() const {
                return name;
            }

            State* getParent() const {
                return parent;
            }

            std::vector<State*> getSubstates() const {
                return substates;
            }

            StateType getType() const {
                return type;
            }
            
            std::vector<State*> getHierarchy() const {
                return hierarchy;
            }

            bool hasParent();
            bool isSubstate();
            bool hasChildren();
            bool isStartState();
            bool isEndState();
            bool equal(State* other);
            bool isSubstateOf(State *other);
            
            State* getLeastCommonParent(State *other);
                        
        private:
            std::string name;
            StateType type;
            BaseAction *entryAction;
            BaseAction *exitAction;
            State *parent;
            std::vector<State*> substates;
            std::vector<State*> hierarchy;
            void addChild(State *substate);
        protected:
            void init(std::string name, StateType type, BaseAction *entryAction, BaseAction *exitAction, State *parent);
            State();
        };
    }
}

#endif	/* STATE_H */

