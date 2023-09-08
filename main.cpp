#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mocks/MockClock.h"
#include "mocks/MockConsole.h"
#include "AccountService.h"

using ::testing::Return;
using ::testing::InSequence;

TEST(PrintStatementFeature, print_statement_containing_all_transactions) {
    auto myClock = new MockClock;
    auto myConsole = new MockConsole;

    EXPECT_CALL(*myClock, todayAsString())
            .WillOnce(Return("01/04/2019"))
            .WillOnce(Return("02/04/2019"))
            .WillOnce(Return("10/04/2019"));

    auto accountService = new AccountService();

    accountService->deposit(1000);
    accountService->withdraw(100);
    accountService->deposit(500);

    accountService->printStatement();

    {
        InSequence inSequence;
        EXPECT_CALL(*myConsole, printLine("DATE | AMOUNT | BALANCE")).Times(1);
        EXPECT_CALL(*myConsole, printLine("10/04/2019 | 500.00 | 1400.00")).Times(1);
        EXPECT_CALL(*myConsole, printLine("02/04/2019 | -100.00 | 900.00")).Times(1);
        EXPECT_CALL(*myConsole, printLine("01/04/2019 | 1000.00 | 1000.00")).Times(1);
    }

    delete myClock;
    delete myConsole;
    delete accountService;
}
