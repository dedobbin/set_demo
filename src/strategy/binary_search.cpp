#include <iostream>
#include <algorithm>
#include "strategy/binary_search.h"

void BinarySearch::add(std::vector<std::string> &list, std::string element) const
{
    //TODO: get rid of duplicates since we are dealing with a set
    auto it = std::find_if(list.begin(), list.end(), [&](const std::string& str) {
        return str > element;
    });
    
    if (it!=list.end()){
        list.insert(it, element);
    } else {
        list.push_back(element);
    }
}

int BinarySearch::find(const std::vector<std::string> &list, std::string element) const
{
    //bool found = std::binary_search(list.begin(), list.end(), element);
    auto it = std::lower_bound(list.begin(), list.end(), element);
    return it != list.end()  && *it == element ? std::distance(list.begin(), it) : -1;
}