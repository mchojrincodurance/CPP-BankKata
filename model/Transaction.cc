//
// Created by mauro on 8/09/23.
//

#include "Transaction.h"

model::Transaction::Transaction(const std::string& date, int amount) {
    this->date = date;
    this->amount = amount;
}

std::string model::Transaction::getDate() const {
    return date;
}

int model::Transaction::getAmount() const {
    return this->amount;
}
