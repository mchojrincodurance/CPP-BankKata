//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_NOTIMPLEMENTED_H
#define BANKKATA_NOTIMPLEMENTED_H


#include <exception>

class NotImplemented : public std::exception {
    const char * what() const noexcept override {
        return "The method is not implemented yet!";
    }
};


#endif //BANKKATA_NOTIMPLEMENTED_H
