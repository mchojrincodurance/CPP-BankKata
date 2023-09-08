#ifndef BANKKATA_ACCOUNTSERVICE_H
#define BANKKATA_ACCOUNTSERVICE_H


#include "infrastructure/TransactionRepository.h"
#include "infrastructure/Clock.h"
#include "model/Transaction.h"

class AccountService {
private:
    TransactionRepository * transactionRepository;
    infrastructure::Clock * clock;

    std::string todayAsString();

public:
    explicit AccountService(TransactionRepository *transactionRepository, infrastructure::Clock *clock);
    void deposit(int amount);

    void withdraw(int amount);

    void printStatement();

    void addTransaction(model::Transaction *pTransaction);
};


#endif //BANKKATA_ACCOUNTSERVICE_H
