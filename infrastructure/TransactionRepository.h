//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_TRANSACTIONREPOSITORY_H
#define BANKKATA_TRANSACTIONREPOSITORY_H

#include <vector>
#include "../model/Transaction.h"

class TransactionRepository {
private:
    std::vector<model::Transaction *> transactions;

public:
    virtual ~TransactionRepository();
    virtual void add(model::Transaction *transaction);

    virtual std::vector<model::Transaction *> all();
};


#endif //BANKKATA_TRANSACTIONREPOSITORY_H
