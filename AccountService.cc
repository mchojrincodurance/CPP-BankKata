//
// Created by mauro on 8/09/23.
//

#include "AccountService.h"
#include "model/Transaction.h"

void AccountService::deposit(int amount) {
    this->addTransaction(new model::Transaction(this->todayAsString(), amount));
}

void AccountService::withdraw(int amount) {
    this->addTransaction(new model::Transaction(this->todayAsString(), amount * -1));
}

void AccountService::printStatement() {
    this
    ->statementPrinter
    ->print(this->transactionRepository->all())
    ;
}

AccountService::AccountService(TransactionRepository *transactionRepository, infrastructure::Clock *clock,
                               StatementPrinter *statementPrinter) {
    this->transactionRepository = transactionRepository;
    this->clock = clock;
    this->statementPrinter = statementPrinter;
}

std::string AccountService::todayAsString() {
    return this->clock->todayAsString();
}

void AccountService::addTransaction(model::Transaction *pTransaction) {
    this->transactionRepository->add(pTransaction);
}
