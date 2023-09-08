//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_CONSOLE_H
#define BANKKATA_CONSOLE_H

#include <string>

namespace infrastructure {

    class Console {
    public:
        virtual ~Console();
        virtual void printLine(const std::string message) const;
    };

} // infrastructure

#endif //BANKKATA_CONSOLE_H
