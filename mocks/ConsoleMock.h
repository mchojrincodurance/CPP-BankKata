//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_CONSOLEMOCK_H
#define BANKKATA_CONSOLEMOCK_H
#include "../infrastructure/Console.h"
#include <gmock/gmock.h>

using namespace infrastructure;

class [[maybe_unused]] ConsoleMock : public Console {
public:
    MOCK_METHOD(void, printLine, (const std::string message), (const, override));
};


#endif //BANKKATA_CONSOLEMOCK_H
