#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <forward_list>

#include "AccountService.h"

#include "mocks/ClockMock.h"
#include "mocks/ConsoleMock.h"
#include "mocks/TransactionRepositoryMock.h"
#include "model/Transaction.h"
#include "StatementPrinterMock.h"

using ::testing::Return;
using ::testing::InSequence;
using ::testing::Property;
using ::testing::Eq;
using ::testing::ElementsAre;

model::Transaction *transaction(const char *date, int amount) {
    return new model::Transaction(date, amount);
}

MATCHER_P(IsTransactionEquivalent, originalTransaction, "") {
    return arg->getDate() == originalTransaction->getDate() && arg->getAmount() == originalTransaction->getAmount();
}

TEST(PrintStatementFeature, print_statement_containing_all_transactions) {
    auto myClock = new ClockMock;
    auto myConsole = new ConsoleMock;
    auto myTransactionRepository = new TransactionRepository;

    EXPECT_CALL(*myClock, todayAsString())
            .WillOnce(Return("01/04/2019"))
            .WillOnce(Return("02/04/2019"))
            .WillOnce(Return("10/04/2019"));

    const auto statementPrinter = new StatementPrinter(myConsole);
    auto accountService = new AccountService(myTransactionRepository, myClock, statementPrinter);

    accountService->deposit(1000);
    accountService->withdraw(100);
    accountService->deposit(500);

    InSequence inSequence;
    EXPECT_CALL(*myConsole, printLine("DATE | AMOUNT | BALANCE")).Times(1);
    EXPECT_CALL(*myConsole, printLine("10/04/2019 | 500.00 | 1400.00")).Times(1);
    EXPECT_CALL(*myConsole, printLine("02/04/2019 | -100.00 | 900.00")).Times(1);
    EXPECT_CALL(*myConsole, printLine("01/04/2019 | 1000.00 | 1000.00")).Times(1);

    accountService->printStatement();

    delete myClock;
    delete myConsole;
    delete accountService;
    delete myTransactionRepository;
    delete statementPrinter;
}

TEST(AccountServiceShould, accept_a_deposit) {
    auto myClock = new ClockMock;
    ON_CALL(*myClock, todayAsString()).WillByDefault(Return("01/09/2019"));

    auto transactionRepository = new TransactionRepositoryMock;
    EXPECT_CALL(
            *transactionRepository,
            add(
                    IsTransactionEquivalent(transaction("01/09/2019", 1000))
            )
    )
            .Times(1);

    auto accountService = new AccountService(transactionRepository, myClock, nullptr);

    accountService->deposit(1000);

    delete myClock;
    delete accountService;
    delete transactionRepository;
}

TEST(AccountServiceShould, accept_a_withdrawal) {
    auto myClock = new ClockMock;
    ON_CALL(*myClock, todayAsString()).WillByDefault(Return("02/09/2019"));

    auto transactionRepository = new TransactionRepositoryMock;
    EXPECT_CALL(
            *transactionRepository,
            add(
                    IsTransactionEquivalent(transaction("02/09/2019", -500))
            )
    )
            .Times(1);

    auto accountService = new AccountService(transactionRepository, myClock, nullptr);

    accountService->withdraw(500);

    delete myClock;
    delete accountService;
    delete transactionRepository;
}

TEST(AccountServiceShould, print_a_statement_containing_all_transactions) {
    auto transactionRepository = new TransactionRepositoryMock;
    auto transactionList = new std::vector<model::Transaction *>;
    auto myConsole = new infrastructure::Console;

    auto statementPrinter = new StatementPrinterMock(myConsole);

    transactionList->assign({transaction("22/12/2019", 1000)});

    ON_CALL(
            *transactionRepository,
            all()
    )
            .WillByDefault(Return(*transactionList));

    Clock *myClock = new Clock;

    auto accountService = new AccountService(transactionRepository, myClock, statementPrinter);

    EXPECT_CALL(*statementPrinter, print(Eq(*transactionList)));

    accountService->printStatement();

    delete accountService;
    delete transactionRepository;
    delete myClock;
    delete statementPrinter;
}

TEST(StatementPrinterShould, always_print_the_header) {
    auto console = new ConsoleMock;
    auto statementPrinter = new StatementPrinter(console);
    auto emptyTransactionList = new std::vector<model::Transaction *>;

    EXPECT_CALL(*console, printLine(Eq("DATE | AMOUNT | BALANCE")));

    statementPrinter->print(*emptyTransactionList);

    delete statementPrinter;
    delete console;
    delete emptyTransactionList;
}

TEST(StatementPrinterShould, print_transactions_in_reverse_chronological_order) {
    auto transactions = new std::vector<model::Transaction *> {
        transaction("01/04/2019", 1000),
        transaction("02/04/2019", -100),
        transaction("10/04/2019", 500),
    };

    auto console = new ConsoleMock;
    auto statementPrinter = new StatementPrinter(console);

    InSequence inSequence;

    EXPECT_CALL(*console, printLine(Eq("DATE | AMOUNT | BALANCE")));
    EXPECT_CALL(*console, printLine(Eq("10/04/2019 | 500.00 | 1400.00")));
    EXPECT_CALL(*console, printLine(Eq("02/04/2019 | -100.00 | 900.00")));
    EXPECT_CALL(*console, printLine(Eq("01/04/2019 | 1000.00 | 1000.00")));

    statementPrinter->print(*transactions);

    delete statementPrinter;
    delete console;
}

TEST(TransactionRepositoryShould, store_transactions) {
    model::Transaction *deposit = transaction("01/04/2019", 1000);
    model::Transaction *withdrawal = transaction("02/04/2019", -100);

    const auto transactionRepository = new TransactionRepository;

    transactionRepository->add(deposit);
    transactionRepository->add(withdrawal);

    auto actualTransactions = transactionRepository->all();

    ASSERT_THAT(actualTransactions, ElementsAre(deposit, withdrawal));

    delete transactionRepository;
}