#include <algorithm>
#include "strategy/handrolled_binary_search.h"

void HandrolledBinarySearch::add(std::vector<std::string> &list, std::string element) const
{
    if (list.empty()){
        list.push_back(element);
        return;
    }

    int low = 0;
    int high = list.size() -1;

    while (low <= high){
        int mid = low + (high-low)/2;

        if (list[mid] == element){
            // Already exists. Do nothing
            return;
        } else if (list[mid] < element){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
   }

   list.insert(list.begin() + low, element);
}

int HandrolledBinarySearch::find(const std::vector<std::string> &list, std::string element) const
{
    // TODO: is basically a copy paste of add. Should abstract
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

   return -1;
}