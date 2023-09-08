//
// Created by mauro on 8/09/23.
//

#include "TransactionRepository.h"
#include "../model/Transaction.h"
#include "NotImplemented.h"

TransactionRepository::~TransactionRepository() {
    // @todo Delete all transaction objects in the repository
}

void TransactionRepository::add(const model::Transaction *transaction) {
    throw NotImplemented();
}

std::forward_list<model::Transaction *> TransactionRepository::all() {
    throw NotImplemented();
}
