//
// Created by mauro on 8/09/23.
//

#include "AccountService.h"
#include "model/Transaction.h"

void AccountService::deposit(int amount) {
    auto * transaction = new model::Transaction(this->todayAsString(), amount);
    this->addTransaction(transaction);
}

void AccountService::withdraw(int amount) {

}

void AccountService::printStatement() {

}

AccountService::AccountService(TransactionRepository *transactionRepository, infrastructure::Clock *clock) {
    this->transactionRepository = transactionRepository;
    this->clock = clock;
}

std::string AccountService::todayAsString() {
    return this->clock->todayAsString();
}

void AccountService::addTransaction(model::Transaction *pTransaction) {
    this->transactionRepository->add(pTransaction);
}
