//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_STATEMENTPRINTER_H
#define BANKKATA_STATEMENTPRINTER_H

#include <vector>
#include "model/Transaction.h"
#include "infrastructure/Console.h"

class StatementPrinter {
private:
    const infrastructure::Console *console;

    [[nodiscard]] std::string buildHeader() const;

public:
    explicit StatementPrinter(const infrastructure::Console * console);

    virtual ~StatementPrinter();

    virtual void print(const std::vector<model::Transaction *> &transactions);

    void printTransactionList(const std::vector<model::Transaction *> &transactions) const;

    std::string formatTransaction(model::Transaction *pTransaction, int runningBalance) const;

    std::string formatNumber(int number) const;

    int getInitialBalance(const std::vector<model::Transaction *> &transactions) const;
};


#endif //BANKKATA_STATEMENTPRINTER_H
