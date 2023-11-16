#pragma once

#include <string>
#include <vector>



class Strategy{ // TODO: could be struct
public:
    virtual int find(std::vector<std::string> &list, std::string element) const = 0;
    virtual void add(std::vector<std::string> &list, std::string element) const = 0;
};