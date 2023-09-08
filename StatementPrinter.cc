//
// Created by mauro on 8/09/23.
//

#include "StatementPrinter.h"
#include <string> // header file for string

void StatementPrinter::print(const std::vector<model::Transaction *> &transactions) {
    this->console->printLine(this->buildHeader());
    this->printTransactionList(transactions);
}

StatementPrinter::~StatementPrinter() = default;

std::string StatementPrinter::buildHeader() const {
    return "DATE | AMOUNT | BALANCE";
}

StatementPrinter::StatementPrinter(const infrastructure::Console *console) {
    this->console = console;
}

void StatementPrinter::printTransactionList(const std::vector<model::Transaction *> &transactions) const {
    int runningBalance = getInitialBalance(transactions);

    for (auto it = transactions.rbegin(); it != transactions.rend(); it++) {
        int currentTransactionAmount = (*it)->getAmount();
        this->console->printLine(this->formatTransaction(*it, runningBalance));
        runningBalance -= currentTransactionAmount;
    }
}

std::string StatementPrinter::formatTransaction(model::Transaction *pTransaction, int runningBalance) const {
    return pTransaction->getDate()
            .append(" | ")
            .append(formatNumber(pTransaction->getAmount()))
            .append(" | ")
            .append(formatNumber(runningBalance));
}

std::string StatementPrinter::formatNumber(int number) const {
    char buffer[50];

    std::sprintf(buffer, "%.2f", (float)number);

    return buffer;
}

int StatementPrinter::getInitialBalance(const std::vector<model::Transaction *> &transactions) const {
    int result = 0;

    for (auto it : transactions) {
        result += (*it).getAmount();
    }

    return result;
}
