#ifndef BANKKATA_ACCOUNTSERVICE_H
#define BANKKATA_ACCOUNTSERVICE_H


#include "infrastructure/TransactionRepository.h"
#include "infrastructure/Clock.h"
#include "model/Transaction.h"
#include "StatementPrinter.h"

class AccountService {
private:
    TransactionRepository * transactionRepository;
    infrastructure::Clock * clock;
    StatementPrinter * statementPrinter;

    std::string todayAsString();

    void addTransaction(model::Transaction *pTransaction);
public:

    explicit AccountService(TransactionRepository *transactionRepository, infrastructure::Clock *clock,
                            StatementPrinter *statementPrinter);

    void deposit(int amount);

    void withdraw(int amount);

    void printStatement();
};


#endif //BANKKATA_ACCOUNTSERVICE_H
