//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_TRANSACTIONREPOSITORY_H
#define BANKKATA_TRANSACTIONREPOSITORY_H
#include "../model/Transaction.h"

class TransactionRepository {
public:
    virtual ~TransactionRepository();
    virtual void add(const model::Transaction *transaction);
};


#endif //BANKKATA_TRANSACTIONREPOSITORY_H
