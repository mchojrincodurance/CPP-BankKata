//
// Created by mauro on 8/09/23.
//

#include "TransactionRepository.h"
#include "../model/Transaction.h"
#include "NotImplemented.h"

TransactionRepository::~TransactionRepository() {
    // @todo Delete all transaction objects in the repository
}

void TransactionRepository::add(model::Transaction *transaction) {
    if (this->transactions.empty()) {
        this->transactions.assign({transaction});
    } else {
        this->transactions.insert_after(this->transactions.begin(), (model::Transaction *const) transaction);
    }
}

std::forward_list<model::Transaction *> TransactionRepository::all() {
    return this->transactions;
}
