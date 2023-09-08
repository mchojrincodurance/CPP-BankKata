//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_STATEMENTPRINTER_H
#define BANKKATA_STATEMENTPRINTER_H

#include <forward_list>
#include "model/Transaction.h"
#include "infrastructure/Console.h"

class StatementPrinter {
private:
    const infrastructure::Console *console;

    [[nodiscard]] std::string buildHeader() const;

public:
    explicit StatementPrinter(const infrastructure::Console * console);

    virtual ~StatementPrinter();

    virtual void print(const std::forward_list<model::Transaction *> &transactions);

    void printTransactionLists() const;

    void printTransactionList(const std::forward_list<model::Transaction *> &transactions) const;

    std::string formatTransaction(model::Transaction *pTransaction, int runningBalance) const;

    std::string formatNumber(int number) const;
};


#endif //BANKKATA_STATEMENTPRINTER_H
