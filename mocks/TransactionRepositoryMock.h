//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_TRANSACTIONREPOSITORYMOCK_H
#define BANKKATA_TRANSACTIONREPOSITORYMOCK_H
#include <gmock/gmock.h>

#include "../infrastructure/TransactionRepository.h"
#include "../model/Transaction.h"

class TransactionRepositoryMock : public TransactionRepository {
public:
    MOCK_METHOD(void, add, (const model::Transaction * transaction), (override))

    ;
};


#endif //BANKKATA_TRANSACTIONREPOSITORYMOCK_H
