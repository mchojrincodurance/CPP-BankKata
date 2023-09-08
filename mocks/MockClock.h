//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_MOCKCLOCK_H
#define BANKKATA_MOCKCLOCK_H

#include "../infrastructure/Clock.h"
#include <gmock/gmock.h>

class MockClock : public infrastructure::Clock {
    MOCK_METHOD(std::string, todayAsString, (), (override));
};


#endif //BANKKATA_MOCKCLOCK_H
