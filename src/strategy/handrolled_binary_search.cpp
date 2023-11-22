#include <algorithm>
#include "strategy/handrolled_binary_search.h"

int find_place_to_insert(const std::vector<std::string> &list, std::string element)
{
    int low = 0;
    int high = list.size() -1;

    while (low <= high){
        int mid = low + (high-low)/2;

        if (list[mid] == element){
            return mid;
        } else if (list[mid] < element){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
   }

   return low;
}

void HandrolledBinarySearch::add(std::vector<std::string> &list, std::string element) const
{
    if (list.empty()){
        list.push_back(element);
        return;
    }
    int index = find_place_to_insert(list, element);
    if (index < list.size() && list[index] == element) {
        return;
    }
    list.insert(list.begin() + index, element);
}

int HandrolledBinarySearch::find(const std::vector<std::string> &list, std::string element) const
{
    int index = find_place_to_insert(list, element);
    if (index < list.size() && list[index] == element) {
        return index;
    }

    return -1;
}