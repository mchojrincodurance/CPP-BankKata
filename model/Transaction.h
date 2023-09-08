//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_TRANSACTION_H
#define BANKKATA_TRANSACTION_H

#include <string>

namespace model {

    class Transaction {
    public:
        Transaction(const std::string& date, int amount);
    };

} // model

#endif //BANKKATA_TRANSACTION_H
