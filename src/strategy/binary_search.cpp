#include <iostream>
#include <algorithm>
#include "strategy/binary_search.h"

void BinarySearch::add(std::vector<std::string> &list, std::string element) const
{
    auto it = std::lower_bound(list.begin(), list.end(), element);
    if (it == list.end() || *it != element) {
        list.insert(it, element);
    }
}

int BinarySearch::find(const std::vector<std::string> &list, std::string element) const
{
    //bool found = std::binary_search(list.begin(), list.end(), element);
    auto it = std::lower_bound(list.begin(), list.end(), element);
    return it != list.end()  && *it == element ? std::distance(list.begin(), it) : -1;
}