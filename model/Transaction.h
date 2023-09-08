//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_TRANSACTION_H
#include <string>

namespace model {
#define BANKKATA_TRANSACTION_H

    class Transaction {
    private:
        std::string date;
        int amount;

    public:
        Transaction(const std::string& date, int amount);
        [[nodiscard]] std::string getDate() const;

        [[nodiscard]] int getAmount() const;
    };
}

#endif //BANKKATA_TRANSACTION_H
