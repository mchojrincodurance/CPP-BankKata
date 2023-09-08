//
// Created by mauro on 8/09/23.
//

#ifndef BANKKATA_CLOCK_H
#define BANKKATA_CLOCK_H

#include <string>

namespace infrastructure {

    class Clock {
    public:
        virtual ~Clock();
        virtual std::string todayAsString();
    };

} // infrastructure

#endif //BANKKATA_CLOCK_H
