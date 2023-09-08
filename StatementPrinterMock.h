//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_STATEMENTPRINTERMOCK_H
#define BANKKATA_STATEMENTPRINTERMOCK_H

#include <gmock/gmock.h>
#include "StatementPrinter.h"

class StatementPrinterMock : public StatementPrinter {
public:
    explicit StatementPrinterMock(const infrastructure::Console *console)
            : StatementPrinter(console) {
    }
    MOCK_METHOD(void, print, (const std::forward_list<model::Transaction *> & transactions), (override));
};


#endif //BANKKATA_STATEMENTPRINTERMOCK_H
