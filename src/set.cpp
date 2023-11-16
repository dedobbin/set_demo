#include <iostream>
#include "set.h"

Set::Set()
{
    strategy = std::make_unique<SimpleStrategy>();
}

Set::Set(Strategy* init_strategy)
{
    // Take ownership
    strategy = std::unique_ptr<Strategy>(init_strategy);
}

void Set::add(std::string element)
{
    strategy->add(inner, element);
}

bool Set::contains(std::string element) const
{
    std::cout << "Not implemented: contains\n";
    exit(1);
    return false;
}

void Set::remove(std::string element)
{
    std::cout << "Not implemented: remove\n";
    exit(1);
}


