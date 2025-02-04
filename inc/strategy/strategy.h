#pragma once

#include <string>
#include <vector>



struct Strategy
{ 
    virtual int find(const std::vector<std::string> &list, std::string element) const = 0;
    virtual void add(std::vector<std::string> &list, std::string element) const = 0;
};