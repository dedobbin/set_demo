#pragma once

#include <memory>
#include "strategy/strategy.h"
#include "strategy/simple_strategy.h"

class Set {
    public:
        Set();
        Set(Strategy* stratergy);
        // TODO: copy constructor and move constructor
        void add(std::string element);
        bool contains(std::string element) const;
        void remove(std::string element);
    private:
        // Even though lifetime is same as parent, we need ptr for inheritance
        std::unique_ptr<Strategy> strategy;
        std::vector<std::string> inner;
};