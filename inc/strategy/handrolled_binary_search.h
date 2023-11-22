#pragma once

#include "strategy.h"

struct HandrolledBinarySearch : Strategy
{
    int find(const std::vector<std::string> &list, std::string element) const;
    void add(std::vector<std::string> &list, std::string element) const;
};