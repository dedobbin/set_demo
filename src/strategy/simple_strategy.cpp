#include <iostream>
#include <algorithm>
#include "strategy/simple_strategy.h"

void SimpleStrategy::add(std::vector<std::string> &list, std::string element) const
{
    //TODO: get rid of duplicates since we are dealing with a set
    list.push_back(element);
}

int SimpleStrategy::find(const std::vector<std::string> &list, std::string element) const
{
    auto it = std::find(list.begin(), list.end(), element);
    return it != list.end() ? std::distance(list.begin(), it) : -1;
}