#pragma once

#include "strategy.h"

class SimpleStrategy : public Strategy
{
    public:
        int find(const std::vector<std::string> &list, std::string element) const;
        void add(std::vector<std::string> &list, std::string element) const;
};