//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_STATEMENTPRINTER_H
#define BANKKATA_STATEMENTPRINTER_H

#include <forward_list>
#include "model/Transaction.h"


class StatementPrinter {
public:
    virtual ~StatementPrinter();
    virtual void print(const std::forward_list<model::Transaction *> *transactions);
};


#endif //BANKKATA_STATEMENTPRINTER_H
