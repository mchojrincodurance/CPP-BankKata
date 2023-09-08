//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_CLOCKMOCK_H
#define BANKKATA_CLOCKMOCK_H

#include "../infrastructure/Clock.h"
#include <gmock/gmock.h>

class ClockMock : public infrastructure::Clock {
public:
    MOCK_METHOD(std::string, todayAsString, (), (override));
};


#endif //BANKKATA_CLOCKMOCK_H
