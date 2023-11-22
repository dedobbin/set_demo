#include <iostream>
#include <algorithm>
#include "strategy/simple_strategy.h"

void SimpleStrategy::add(std::vector<std::string> &list, std::string element) const
{
    if (find(list, element) < 0){
        list.push_back(element);
    }
}

int SimpleStrategy::find(const std::vector<std::string> &list, std::string element) const
{
    auto it = std::find(list.begin(), list.end(), element);
    return it != list.end() ? std::distance(list.begin(), it) : -1;
}