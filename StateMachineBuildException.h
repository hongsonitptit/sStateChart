/* 
 * File:   StateMachineBuildException.h
 * Author: ttdk
 *
 * Created on June 6, 2016, 9:14 AM
 */

#ifndef STATEMACHINEBUILDEXCEPTION_H
#define	STATEMACHINEBUILDEXCEPTION_H

#include <exception>
#include <string>

namespace VtX {
    namespace StateMachine {

        class StateMachineBuildException : public std::exception {
        public:

            StateMachineBuildException(std::string message) {
                this->message = message;
            };

            virtual ~StateMachineBuildException() throw () {
            };

            virtual const char* what() const throw () {
                return message.c_str();
            };
        private:
            std::string message;
        };
    }
}



#endif	/* STATEMACHINEBUILDEXCEPTION_H */

