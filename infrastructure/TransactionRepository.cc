//
// Created by mauro on 8/09/23.
//

#include "TransactionRepository.h"
#include "../model/Transaction.h"

TransactionRepository::~TransactionRepository() {
    // @todo Delete all transaction objects in the repository
}

void TransactionRepository::add(model::Transaction *transaction) {
    this->transactions.push_back(transaction);
}

std::vector<model::Transaction *> TransactionRepository::all() {
    return this->transactions;
}
