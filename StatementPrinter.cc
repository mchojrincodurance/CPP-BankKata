//
// Created by mauro on 8/09/23.
//

#include "StatementPrinter.h"
#include <string> // header file for string

void StatementPrinter::print(const std::forward_list<model::Transaction *> &transactions) {
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

void StatementPrinter::printTransactionLists() const {
}

void StatementPrinter::printTransactionList(const std::forward_list<model::Transaction *> &transactions) const {
    auto reverseTransactions = std::forward_list<model::Transaction *> {};

    int runningBalance = 0;

    for (auto it: transactions) {
        reverseTransactions.push_front(it);
        runningBalance += it->getAmount();
    }

    for (auto it: reverseTransactions) {
        this->console->printLine(this->formatTransaction(it, runningBalance));
        runningBalance -= it->getAmount();
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
