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
        int size() const;
        std::vector<std::string> get_inner_cpy() const;
        friend std::ostream& operator<<(std::ostream& os, const Set& obj);
    private:
        // Even though lifetime is same as parent, we need ptr for inheritance
        std::unique_ptr<Strategy> strategy;
        std::vector<std::string> inner;
};