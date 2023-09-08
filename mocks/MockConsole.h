//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_MOCKCONSOLE_H
#define BANKKATA_MOCKCONSOLE_H
#include "../infrastructure/Console.h"
#include <gmock/gmock.h>

using namespace infrastructure;

class [[maybe_unused]] MockConsole : public Console {
public:
    MOCK_METHOD(void, printLine, (std::string message), (override));
};


#endif //BANKKATA_MOCKCONSOLE_H
