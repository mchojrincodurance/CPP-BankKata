//
// Created by mauro on 8/09/23.
//

#include "StatementPrinter.h"

void StatementPrinter::print(const std::forward_list<model::Transaction *> &transactions) {
    this->console->printLine(this->buildHeader());
}

StatementPrinter::~StatementPrinter() = default;

std::string StatementPrinter::buildHeader() const {
    return "DATE | AMOUNT | BALANCE";
}

StatementPrinter::StatementPrinter(const infrastructure::Console * console) {
    this->console = console;
}
